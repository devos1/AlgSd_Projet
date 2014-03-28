﻿/**
 * Fonctions du programme (fonctions.c)
 * Oscar Da Silva et Quentin Walter, HEIG-VD, mars 2014
 */
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "string.h"

#define FICHIER_ETUDIANTS "etudiant.txt"
#define FICHIER_MOYENNES "moyenne.txt"
#define LONGUEUR_LIGNE 80 
#define VRAI 1
#define FAUX 0
#define NOTE_MIN 1
#define NOTE_MAX 6

int recupererEtudiantsFichier(typeElt **ptPrem)
{
	typeEtudiant *etudiant;
	typeElt *courant;
	FILE *fichier;
	char ligne[LONGUEUR_LIGNE];
	int n, resultat, erreur;

	//Initialisation
	resultat = FAUX;
	erreur = FAUX;
	courant = NULL;

	// Ouverture des fichiers
	fichier = fopen(FICHIER_ETUDIANTS, "r");
	if (fichier == NULL)
	{
		printf("Le fichier %s n'existe pas ou n'est pas accessible\n", FICHIER_ETUDIANTS);
		erreur = VRAI;
	}
	else
	{
		fgets(ligne, LONGUEUR_LIGNE, fichier);
		while (!feof(fichier) && erreur == FAUX)
		{
			if (strlen(ligne) > 2)
			{
				etudiant = (typeEtudiant*) malloc (sizeof (typeEtudiant));
				n = sscanf(ligne, "%d %s %s %d %d %d", &etudiant->matricule, etudiant->nom, etudiant->prenom, &etudiant->dateNaissance.jour, &etudiant->dateNaissance.mois, &etudiant->dateNaissance.annee);
				if (n != 6)
				{
					puts("Erreur dans les donnees du fichier");
					erreur = VRAI;
				}
				else
				{
					// On initialise le nombre et la moyenne des notes à 0
					etudiant->nombreNotes = 0; // Ne s'initialise pas...
					etudiant->moyenneNotes = 0;
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

int insererEtudiant(typeElt **ptPrem, typeEtudiant *etudiant)
{
	typeElt *courant, *precedent, *nouveau;
	typeEtudiant *etudiantCourant;
	int resultat;
	int trouve;

	courant = *ptPrem;
	precedent = NULL;
	trouve = FAUX;
	resultat = FAUX;

	while (courant != NULL && trouve == FAUX) {
		etudiantCourant = valElt(courant);
		if (etudiant->matricule <= etudiantCourant->matricule) {
			trouve = VRAI;
		}
		else {
			precedent = courant;
			courant = suivantElt(courant);
		}
	}
	nouveau = creerElt(etudiant);

	if (nouveau != NULL) {
		insereElt(ptPrem, precedent, nouveau);
		resultat = VRAI;
	}
	return resultat;
}
int recupererNotesFichier(typeElt *ptPrem)
{
	typeElt *courant;
	typeEtudiant *etudiant;
	char *nomFichier, ligne[LONGUEUR_LIGNE];
	int n, resultat, trouve, erreur, matricule;
	float note;
	FILE *fichier;

	//Initialisation
	resultat = FAUX;
	erreur = FAUX;
	trouve = FAUX;
	courant = ptPrem;
	nomFichier = insererChaine();

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
						if (etudiant->matricule == matricule)
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
						if (insererNote(etudiant, note))
						{
							trouve = FAUX; // On remet le flag trouvé à FAUX
						}
						else
						{
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
	if (etudiant->nombreNotes < NOMBRE_NOTES_MAX)
	{
		if (note > NOTE_MAX || note < NOTE_MIN)
		{
			printf("La note doit etre comprise entre %d et %d\n", NOTE_MIN, NOTE_MAX);
		}
		else
		{
			etudiant->tableauNotes[etudiant->nombreNotes] = note;
			etudiant->nombreNotes++;
			etudiant->moyenneNotes = calculerMoyenne(etudiant->tableauNotes, etudiant->nombreNotes);
			resultat = VRAI;
		}
	}
	else
	{
		printf("L'etudiant %d a deja cinq notes\n", etudiant->matricule);
	}
	return resultat;
}
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
typeElt *trierEtudiantsMoyenne(typeElt **listeEtudiants)
{
	typeElt *listeEtudiantsTriee;
	typeElt *courant, *precedant, *courantTrie, *plusPetiteMoyenne, *precedantPlusPetiteMoyenne;
	typeEtudiant *etudiant;
	float moyenneNotes;

	/* Initialiser la liste */
	initListe(&listeEtudiantsTriee); // Initialiser la nouvelle liste
	courantTrie = NULL;     // Pointeur sur la nouvelle liste

	while (*listeEtudiants != NULL)
	{
		courant = *listeEtudiants; // Pointeur sur la liste initiale
		precedantPlusPetiteMoyenne = NULL;   // Elément précédant courant1
		
		etudiant = valElt(courant);
		moyenneNotes = etudiant->moyenneNotes;
		plusPetiteMoyenne = courant;
		courant = suivantElt(courant);

		while (courant != NULL)
		{
			etudiant = valElt(courant);
			if (etudiant->moyenneNotes < moyenneNotes)
			{
				precedantPlusPetiteMoyenne = precedant;
				plusPetiteMoyenne = courant;
				moyenneNotes = etudiant->moyenneNotes;
				courant = suivantElt(courant);
			}
			else
			{
				precedant = courant;
				courant = suivantElt(courant);
			}
		}
		insereElt(&listeEtudiantsTriee, courantTrie, plusPetiteMoyenne); // L'insérer dans la nouvelle liste
		detruireElt(listeEtudiants, precedantPlusPetiteMoyenne); // Le détruire dans la liste initiale
		courantTrie = plusPetiteMoyenne;
	}
	return listeEtudiantsTriee;
}
int genererFichierMoyenne(typeElt *listeEtudiants)
{
	FILE *fichier;
	int i, resultat, erreur;
	typeElt *courant;
	typeEtudiant *etudiant;

	resultat = FAUX;

	if (listeEtudiants != NULL)
	{
		fichier = fopen(FICHIER_MOYENNES, "w");
		if (fichier == NULL)
		{
			printf("Le fichier %s n'existe pas ou n'est pas accessible\n", FICHIER_MOYENNES);
			erreur = VRAI;
			
		}
		else
		{
			courant = listeEtudiants;
			while (courant != NULL)
			{
				etudiant = valElt(courant);
				fprintf(fichier, "%d %s %s %d %d %d ", etudiant->matricule, etudiant->nom, etudiant->prenom, etudiant->dateNaissance.jour, etudiant->dateNaissance.mois, etudiant->dateNaissance.annee);
				if (etudiant->nombreNotes > 0) // Si l'etudiant a au moins une note
				{
					for (i = 0; i < etudiant->nombreNotes; i++)
					{
						fprintf(fichier, "%3.1f ", etudiant->tableauNotes[i]);
					}
					fprintf(fichier, "%.1f\n", etudiant->moyenneNotes);
				}
				else
				{
					fprintf(fichier, "Aucune note\n");
				}
				courant = suivantElt(courant);
			}
			fclose(fichier);
			printf("Le fichier %s a ete genere.\n", FICHIER_MOYENNES);
		}
	}
	else
	{
		puts("Aucun etudiant");
	}

	if (!erreur)
	{
		resultat = VRAI;
	}

	return resultat;
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
	typeEtudiant *etudiant;
	int i;

	courant = listeEtudiants;

	while (courant != NULL)
	{
		etudiant = valElt(courant);
		printf("Etudiant %d\t%s %s\tne(e) le %02d.%02d.%4d\n", etudiant->matricule, etudiant->nom, etudiant->prenom, etudiant->dateNaissance.jour, etudiant->dateNaissance.mois, etudiant->dateNaissance.annee);
		if (etudiant->nombreNotes) // Si l'etudiant a au moins une note
		{
			for (i = 0; i < etudiant->nombreNotes; i++)
			{
				printf("%3.1f ", etudiant->tableauNotes[i]);
			}
			printf(" : %.1f\n", etudiant->moyenneNotes);
		}
		else
		{
			printf("Aucune note\n");
		}
		courant = suivantElt(courant);
	}
}
void detruireListeEtudiants(typeElt **listeEtudiants)
{
	typeEtudiant *etudiant;
	while (*listeEtudiants != NULL) {  // Tant qu'il reste un élément
		etudiant = valElt(*listeEtudiants);
		free(etudiant);
		detruireElt(listeEtudiants, NULL); // Detruire le premier
	}
	*listeEtudiants = NULL;
}