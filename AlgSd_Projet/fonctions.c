#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "string.h"

#define FICHIER_ETUDIANTS "etudiant.txt"
#define LONGUEUR_LIGNE 80 
#define VRAI 1
#define FAUX 0

int recupererEtudiantsFichier(typeElt **ptPrem)
{
	typeEtudiant etudiant;
	typeElt *courant, *nouveau;
	FILE *fichier;
	char ligne[LONGUEUR_LIGNE];
	int n, resultat, erreur;

	//Initialisation
	resultat = FAUX;
	erreur = FAUX;
	courant = NULL;

	// Ouverture des fichiers
	fichier = fopen(FICHIER_ETUDIANTS, "r");
	if (fichier == NULL) {
		printf("Le fichier %s n'existe pas ou n'est pas accessible\n", FICHIER_ETUDIANTS);
	}
	else
	{
		fgets(ligne, LONGUEUR_LIGNE, fichier);
		while (!feof(fichier) && erreur == FAUX)
		{
			if (strlen(ligne) > 2)
			{
				n = sscanf(ligne, "%d %s %s %d %d %d", &etudiant.matricule, etudiant.nom, etudiant.prenom, &etudiant.dateNaissance.jour, &etudiant.dateNaissance.mois, &etudiant.dateNaissance.annee);
				if (n != 6)
				{
					puts("Erreur dans les donnees du fichier");
					erreur = VRAI;
				}
				else
				{
					// On initialise le nombre et la moyenne des notes à 0
					etudiant.nombreNotes = 0;
					etudiant.moyenneNotes = 0;
					if (!insererEtudiant(ptPrem, etudiant))
					{
						puts("Erreur lors de l'insertion de l'etudiant dans la liste");
						erreur = VRAI;
					}
				}
			}
			fgets(ligne, LONGUEUR_LIGNE, fichier);
		}
		fclose(fichier);

		if (!erreur)
		{
			resultat = VRAI;
		}
	}
	return resultat;
}

/* Insere un ÈlÈment dans la liste */
/* Rend 1 si OK et 0 si l'insertion est impossible */
int insererEtudiant(typeElt **ptPrem, typeEtudiant etudiant)
{
	typeElt *courant, *precedent, *nouveau;
	typeDonnee etudiantCourant;
	int resultat;
	int trouve; // Vrai lorsqu'on trouve o˘ insÈrer

	/* Chercher l'ÈlÈment derriËre lequel il faut insÈrer */
	/* Se placer en tÍte de liste */
	courant = *ptPrem;
	precedent = NULL; // Il n'y a pas de precedant
	trouve = FAUX;
	resultat = FAUX;

	while (courant != NULL && trouve == FAUX) {
		etudiantCourant = valElt(courant);
		if (etudiant.matricule <= etudiantCourant.matricule) {
			trouve = VRAI; // On a trouvÈ o˘ insÈrer la nouvelle valeur
		}
		else {
			precedent = courant;      // On garde un pointeur sur le prÈcÈdent
			courant = suivantElt(courant); // On passe au suivant
		}
	}
	// A la fin de la boucle precedent pointe sur l'ÈlÈment derriËre lequel
	// on doit insÈrer un nouvel ÈlÈment ou est Ègal ‡ NULL si on insËre 
	// en dÈbut de liste
	nouveau = creerElt(etudiant);
	if (nouveau != NULL) {
		insereElt(ptPrem, precedent, nouveau);
		resultat = VRAI;
	}
	return resultat;
}
/**
 *	
 *	
 */
int recupererNotesFichier(typeElt *ptPrem)
{
	typeElt *courant;
	typeEtudiant etudiant;
	char *nomFichier, ligne[LONGUEUR_LIGNE];
	int n, resultat, trouve, erreur, matricule;
	float note;
	FILE *fichier;

	nomFichier = insererChaine();

	//Initialisation
	resultat = FAUX;
	erreur = FAUX;
	trouve = FAUX;
	courant = ptPrem;

	// Ouverture des fichiers
	fichier = fopen(nomFichier, "r");
	if (fichier == NULL)
	{
		printf("Le fichier %s n'existe pas ou n'est pas accessible\n", nomFichier);
	}
	else
	{
		fgets(ligne, LONGUEUR_LIGNE, fichier);
		while (!feof(fichier) && erreur == FAUX)
		{
			if (strlen(ligne) > 2)
			{
				n = sscanf(ligne, "%d %f", &matricule, &note);
				if (n == 2)
				{
					while (courant != NULL && trouve == FAUX)
					{
						etudiant = valElt(courant);
						if (etudiant.matricule == matricule)
						{
							trouve = VRAI;
						}
						else
						{
							courant = suivantElt(courant);
						}
					}
					if (trouve)
					{
						if (insererNote(&etudiant, note))
						{
							trouve = FAUX; // On remet le flag trouvé à FAUX
						}
						else
						{
							printf("L'etudiant %d a deja cinq notes\n", etudiant.matricule);
							erreur = VRAI;
						}
					}
					else
					{
						printf("L'etudiant %d n'existe pas\n", matricule);
						erreur = VRAI;
					}
				}
				else
				{
					puts("Erreur dans les donnees du fichier");
					erreur = VRAI;
				}
				courant = ptPrem; // On remet le pointeur au début de la liste
			}
			fgets(ligne, LONGUEUR_LIGNE, fichier);
		}
		fclose(fichier);

		if (!erreur)
		{
			resultat = VRAI;
		}
	}
	return resultat;
}

int insererNote(typeEtudiant *etudiant, float note)
{
	int resultat;

	resultat = FAUX;
	if (etudiant->nombreNotes <= NOMBRE_NOTES_MAX)
	{
		printf("%f\n", note);
		etudiant->tableauNotes[etudiant->nombreNotes - 1] = note;
		etudiant->nombreNotes++;
		etudiant->moyenneNotes = calculerMoyenne(etudiant->tableauNotes, etudiant->nombreNotes);
		resultat = VRAI;
	}
	return resultat;
}
/**
 *	
 *	nombreNotes doit être supérieur à 0
 */
float calculerMoyenne(float tableauNotes[NOMBRE_NOTES_MAX], int nombreNotes)
{
	float sommeNotes;
	int i;
	sommeNotes = 0;

	for (i = 0; i < nombreNotes; i++)
	{
		sommeNotes += tableauNotes[i];
	}
	return sommeNotes / nombreNotes;
}
int genererFichierMoyenne()
{
	
}
int insererEntier()
{
	int n, valeur;
	char ligne[LONGUEUR_LIGNE];

	fgets(ligne, LONGUEUR_LIGNE, stdin);
	n = sscanf(ligne, "%d", &valeur);
	while (n != 1)
	{
		printf ("Entrer une valeur entiere : ");
		fgets (ligne, LONGUEUR_LIGNE, stdin);
		n = sscanf (ligne, "%d", &valeur);
	}
	return valeur;
}
float insererFlottant()
{
	int n;
	float valeur;
	char ligne[LONGUEUR_LIGNE];

	fgets(ligne, LONGUEUR_LIGNE, stdin);
	n = sscanf(ligne, "%f", &valeur);
	while (n != 1)
	{
		printf ("Entrer une valeur flottante : ");
		fgets (ligne, LONGUEUR_LIGNE, stdin);
		n = sscanf (ligne, "%d", &valeur);
	}
	return valeur;
}
char *insererChaine()
{
	return "note1.txt";
}
void imprimerEtudiants(typeElt *listeEtudiants)
{
	typeElt *courant;
	typeDonnee etudiant;
	courant = listeEtudiants;
	while (courant != NULL) {
		etudiant = valElt(courant);
		printf ("\n%d\t%20s\t%20s\t%d/%d/%d\t%.1f", etudiant.matricule, etudiant.nom, etudiant.prenom, etudiant.dateNaissance.jour, etudiant.dateNaissance.mois, etudiant.dateNaissance.annee, etudiant.moyenneNotes);
		courant = suivantElt(courant);
	}
}
void detruireListe(typeElt **premier)
{
	while (*premier != NULL) {  // Tant qu'il reste un élément
		detruireElt(premier, NULL); // Detruire le premier
	}
	*premier = NULL;
}