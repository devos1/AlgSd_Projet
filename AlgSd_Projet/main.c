/*******************************************************************************************
 * Auteurs		: Quentin Walter et Oscar Da Silva
 * Date			: Mars 2014
 * Nom			: Main.c
 * Description	: TP AlgSd, HEIG-VD Fee
 * Resume		:
 *		Le but du TP est d'ecrire un programme qui gere les donnees des etudiants,
 *		l'integration des notes et le calcul des moyennes, ensuite exporter dans un 
 *		le fichier moyenne.txt
 *
 * Description algorithme principal:
 *		Au demarrage, la liste des etudiants est recuperee depuis le fichier "etudiant.txt".
 *		Elle est ensuite inseree dans une liste chainee par la fonction "recupererEtudiantsFichier"
 *		Si cette premirere etape s'est bien passee, ensuite on affiche le menu avec les 3 choix
 *				1. Ajouter des notes depuis un fichier en indiquant son nom
 *				2. Afficher la liste des etudiants, leurs notes et leurs moyennes
 *				3. Generer un fichier des etudiants classe par moyenne et termine le programme
 *		A la fin du programme on detruit les listes
 *		
 * Options choisies:
 *		Les primites utilisees sont celles du fichier liste.c utilise pendant les cours.
 *		Nous avons cree un fichier "fonctions.c" pour contenir les fonctions propres au projet.
 *		Les prototypes sont dans le "fonction.h" et dans le "main.c".
 *		Utilisation des puts au lieu des printf autant que possible. 	
 *		Si possible nous avons essaye d'utiliser des #define (comme par exemple VRAI et FAUX)
 *
 *********************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

#pragma region "PROTOTYPES DE FONCTION"
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
int insererEtudiant(typeElt **ptPrem, typeEtudiant *etudiant);
/**
 * 
 * 
 */
typeElt *trierEtudiantsMoyenne(typeElt **listeEtudiants);
/**
 * 
 * 
 */
int genererFichierMoyenne(typeElt *listeEtudiants);
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
void detruireListeEtudiants(typeElt **listeEtudiants);
/**
 * Detruit les elements de la liste des etudiants
 * ptPrem, pointeur qui pointe sur le premier element de la liste
 */
void detruireListeEtudiants(typeElt **ptPrem);
/**
 * Initialise la liste et permet l'execution des commandes :
 * (1) ajouter des notes depuis un fichier en indiquant son nom
 * (2) afficher la liste des etudiants, leurs notes et leur moyenne
 * (0) generer un fichier des etudiants classe par moyenne (fin du programme)
 * Affiche la liste des commandes en cas d'erreur de saisie
 */
#pragma endregion

void main()
{
	typeElt *listeEtudiants, *listeEtudiantsTriee;
	int commande;
	
	initListe(&listeEtudiants);

	if (recupererEtudiantsFichier(&listeEtudiants))
	{
		puts("MENU:");
		puts("(1) ajouter des notes depuis un fichier en indiquant son nom");
		puts("(2) afficher la liste des etudiants, leurs notes et leurs moyennes");
		puts("(0) generer un fichier des etudiants classe par moyenne et termine le programme");
		printf("Votre choix : ");
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
					puts("(0) generer un fichier des etudiants classe par moyenne et termine le programme");
			}
			printf("Votre choix : ");
			commande = insererEntier();
		}
	}

	listeEtudiantsTriee = trierEtudiantsMoyenne(&listeEtudiants);
	//imprimerEtudiants(listeEtudiantsTriee);
	genererFichierMoyenne(listeEtudiantsTriee);
	// Détruit les listes
	detruireListeEtudiants(&listeEtudiants);
	listeEtudiantsTriee = NULL;
	//detruireListeEtudiants(&listeEtudiantsTriee);		// Pas besoin de suppriemr les elements vu qu'ils ont ete supprimes avant
	system("pause");
}