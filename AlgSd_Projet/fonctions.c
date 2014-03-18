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
		printf("Le fichier FICHIER_ETUDIANTS n'existe pas\n");
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
					insererEtudiant(&ptPrem, etudiant);
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
int insererEtudiant(typeElt **ptPrem, typeDonnee etudiant) {
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
		resultat = VRAI; // C'est OK
	}
	return resultat;
}



/* Insere un élément dans la liste */
/* Rend 1 si OK et 0 si l'insertion est impossible */
//int insererEtudiant(typeElt **ptPrem,  typeDonnee etudiant)
//{
//	typeElt *courant, *precedent, *nouveau;
//	int res = FAUX;
//	int trouve; // Vrai lorsqu'on trouve où insérer
//
//	/* Chercher l'élément derrière lequel il faut insérer */
//	/* Se placer en tête de liste */
//	courant = *ptPrem;
//	precedent = NULL; // Il n'y a pas de precedant
//	trouve = FAUX;
//	while (courant != NULL && trouve == FAUX) {
//		if (etudiant <= valElt(courant)) {
//			trouve = VRAI; // On a trouvé où insérer la nouvelle valeur
//		} else {
//			precedent = courant;      // On garde un pointeur sur le précédent
//			courant = suivantElt(courant); // On passe au suivant
//		}
//	}
//	// A la fin de la boucle precedent pointe sur l'élément derrière lequel
//	// on doit insérer un nouvel élément ou est égal à NULL si on insère 
//	// en début de liste
//	nouveau = creerElt (etudiant);
//	if (nouveau != NULL) {
//		insereElt (ptPrem, precedent, nouveau);
//		res = VRAI; // C'est OK
//	}
//	return res;
//}

int recupererNotesFichier(char *nomFichier)
{
	// insererNote
}

int insererNote(typeDonnee *etudiant, float note)
{
	int resultat;

	resultat = FAUX;

	if (etudiant->nombreNotes < 5)
	{
		etudiant->tableauNotes[etudiant->nombreNotes - 1] =  note;
		etudiant->nombreNotes++;
		resultat = VRAI;
	}
	return resultat;
}
/**
 *	
 *	nombreNotes doit être supérieur à 0
 */
float calculerMoyenne(float *tableauNotes, int nombreNotes)
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
	char ligne[80];

	fgets (ligne, 80, stdin);
	n = sscanf (ligne, "%d", &valeur);
	while (n != 1)
	{
		printf ("Entrer une valeur entiere : ");
		fgets (ligne, 80, stdin);
		n = sscanf (ligne, "%d", &valeur);
	}
	return valeur;
}
float insererFlottant()
{

}
char *insererChaine()
{
	
}