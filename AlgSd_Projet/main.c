/**
 * Ce programme gere des etudiants, leurs notes et leur moyenne.
 *
 * Au demarrage, la liste des etudiants est recuperee depuis un fichier.
 * Il est possible de (1) ajouter des notes depuis un fichier en indiquant son nom,
 * (2) afficher la liste des etudiants, leurs notes et leur moyenne et (0) generer
 * un fichier des etudiants classe par moyenne, cette action arrete le programme.
 *
 * Oscar Da Silva et Quentin Walter, HEIG-VD, mars 2014
 */
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"
#include "liste.h"

/**
 * Recupere les etudiants depuis le fichier FICHIER_ETUDIANT
 * ptPrem, pointeur qui pointe sur le premier element de la liste
 * Retourne VRAI (1) si il n'y a pas d'erreur, sinon FAUX (0).
 */
int recupererEtudiantsFichier(typeElt **ptPrem);
/**
 * Insere un etudiant dans la liste ptPrem
 * ptPrem, pointeur qui pointe sur le premier element de la liste
 * etudiant, structure qui contient les informations de l'etudiant
 * Retourne VRAI (1) si il n'y a pas d'erreur, sinon FAUX (0).
 */
int insererEtudiant(typeElt **ptPrem, typeEtudiant etudiant);
/**
 * Recupère les notes depuis un fichier
 * ptPrem, pointeur du premier element de la liste
 * Retourne VRAI (1) si il n'y a pas d'erreur, sinon FAUX (0).
 */
int recupererNotesFichier(typeElt *ptPrem);
/**
 * Permet la saisie d'une valeur entiere
 * Retourne la valeur saisie
 */
int insererEntier();
/**
 * Permet la saisie d'une valeur flottante
 * Retourne la valeur saisie
 */
float insererFlottant();
/**
 * Affiche la liste des etudiants, leurs notes et leur moyenne
 * listeEtudiants, pointeur sur le premier element de la liste des etudiants
 */
void imprimerEtudiants(typeElt *listeEtudiants);
/**
 * Detruit les elements de la liste
 * ptPrem, pointeur qui pointe sur le premier element de la liste
 */
void detruireListe(typeElt **ptPrem);
/**
 * Initialise la liste et permet l'execution des commandes :
 * (1) ajouter des notes depuis un fichier en indiquant son nom
 * (2) afficher la liste des etudiants, leurs notes et leur moyenne
 * (0) generer un fichier des etudiants classe par moyenne (fin du programme)
 * Affiche la liste des commandes en cas d'erreur de saisie
 */
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
					puts("Commande inconnue");
					puts("(1) ajouter des notes depuis un fichier en indiquant son nom");
					puts("(2) afficher la liste des etudiants, leurs notes et leur moyenne");
					puts("(0) generer un fichier des etudiants classe par moyenne (fin du programme)");
			}
			printf("Commande : ");
			commande = insererEntier();
		}
	}
	
	detruireListe(&listeEtudiants);
	system("pause");
}