//Commentaires
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

int recupererEtudiantsFichier(typeElt **ptPrem);
int insererEtudiant(typeElt **ptPrem, typeEtudiant etudiant);
int recupererNotesFichier(typeElt *ptPrem);
int insererNote(typeEtudiant *etudiant, float note);
float calculerMoyenne(float tableauNotes[NOMBRE_NOTES_MAX], int nombreNotes);

int insererEntier();
float insererFlottant();

void imprimerEtudiants(typeElt *listeEtudiants);
void detruireListe(typeElt **premier);

void main()
{
	typeElt *listeEtudiants;
	int commande;
	
	initListe(&listeEtudiants);

	if (recupererEtudiantsFichier(&listeEtudiants))
	{
		printf("Commande : ");
		commande = insererEntier();
		while (commande != 0)
		{
			switch (commande)
			{
				case 1:
					recupererNotesFichier(listeEtudiants);
				break;
				case 2:
					imprimerEtudiants(listeEtudiants);
				break;
				default :
					printf("Commande inconnue\n1 : \n2 : \n0 : sortir\n");
			}
			printf("Commande : ");
			commande = insererEntier();
		}
	}
	
	detruireListe(&listeEtudiants);
	system("pause");
}