/********************************************************************************
 * Auteurs		: Quentin Walter et Oscar Da Silva
 * Date			: Mars 2014
 * Nom			: main.c
 * Description	: TP AlgSd, HEIG-VD Fee
 * Resume		:
 *		Le but du TP est d'ecrire un programme qui gere les donnees des etudiants
 *		l'integration des notes et le calcul des moyennes, ensuite exporter dans
 *		le fichier moyenne.txt
 *
 * Description algorithme principal:
 *		Au demarrage, la liste des etudiants est recuperee depuis le fichier 
 *		"etudiant.txt". Elle est ensuite inseree dans une liste chainee par 
 *		la fonction "recupererEtudiantsFichier"
 *		Si cette premirere etape s'est bien passee, on affiche le menu avec les 
 *		3 choix ci-dessous:
 *				1. Ajouter des notes depuis un fichier en indiquant son nom
 *				2. Afficher la liste des etudiants, leurs notes et leurs moyennes
 *				0. Generer un fichier des etudiants classe par moyenne et termine 
 *				   le programme
 *		A la fin du programme on detruit les listes
 *		
 * Options choisies:
 *		Les primitives utilisees sont celles du fichier liste.c utilise durant 
 *		le cours. Nous avons cree un fichier "fonctions.c" pour contenir 
 *		les fonctions propres au projet.
 *		Les prototypes sont dans le "fonction.h" et dans le "main.c".
 *		Utilisation des puts au lieu des printf autant que possible. 	
 *		Si possible nous avons essaye d'utiliser des #define
 *		(comme par exemple VRAI et FAUX)
 *		Utilisation le plus possible de fonctions ou bouts de code utilés en classe
 *
 *********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

#pragma region "PROTOTYPES DE FONCTION"
/**********************************************************************************
 * Description	: Recupere les etudiants depuis le fichier "FICHIER_ETUDIANT"
 * Parametres	: listeEtudiants, pointeur qui pointe sur le debut de la liste
 * Retour		: VRAI (1) si il n'y a pas d'erreur, sinon FAUX (0)
 **********************************************************************************/
int recupererEtudiantsFichier(typeElt **listeEtudiants);

/***********************************************************************************
* Description	: Insere un etudiant dans la liste "listeEtudiants"
* Parametres	: listeEtudiants, pointeur qui pointe sur le debut de la liste
*				  etudiant, structure qui contient les informations de l'etudiant
* Retour		: VRAI (1) si il n'y a pas d'erreur, sinon FAUX (0)
************************************************************************************/
int insererEtudiant(typeElt **listeEtudiants, typeEtudiant *etudiant);

/***********************************************************************************
* Description	: Trie la liste des etudiants selon leur moyenne
* Parametres	: listeEtudiants, pointeur qui pointe sur le debut de la liste
* Retour		: Pointeur sur une nouvelle liste créée dans la fonction
************************************************************************************/
typeElt *trierEtudiantsMoyenne(typeElt **listeEtudiants);

/************************************************************************************
* Description	: Genere un fichier de moyenne a partir d'une liste
* Parametres	: listeEtudiants, pointeur qui pointe sur le premier element 
*				  de la liste
* Retour		: VRAI (1) si il n'y a pas d'erreur, sinon FAUX (0).
************************************************************************************/
int genererFichierMoyenne(typeElt *listeEtudiants);

/************************************************************************************
* Description	: Recupère les notes depuis un fichier
* Parametres	: listeEtudiants, pointeur qui pointe sur le premier element 
*				  de la liste
* Retour		: VRAI (1) si il n'y a pas d'erreur, sinon FAUX (0).
************************************************************************************/
int recupererNotesFichier(typeElt *listeEtudiants);

/************************************************************************************
* Description	: Affiche les etudiants, leurs notes et leur moyenne
* Parametres	: listeEtudiants, pointeur qui pointe sur le premier element 
*				  de la liste
* Retour		: -
************************************************************************************/
void imprimerEtudiants(typeElt *listeEtudiants);

/************************************************************************************
* Description	: Permet la saisie d'une valeur entiere
* Parametres	: -
* Retour		: Un entier3 comme valeur saisie
************************************************************************************/
int insererEntier();

/************************************************************************************
* Description	: Permet la saisie d'une valeur flottante
* Parametres	: -
* Retour		: Un flottant comme valeur saisie
************************************************************************************/
float insererFlottant();

/************************************************************************************
* Description	: Destruction liste etudiants
* Parametres	: listeEtudiants, pointeur qui pointe sur le debut de la liste
* Retour		: -
************************************************************************************/
void detruireListeEtudiants(typeElt **listeEtudiants);

/************************************************************************************
* Description	: Detruit les elements de la liste des etudiants
* Parametres	: listeEtudiants, pointeur qui pointe sur le debut de la liste
* Retour		: -
************************************************************************************/
void detruireListeEtudiants(typeElt **listeEtudiants);
#pragma endregion

/************************************************************************************
* Description	: Initialise la liste et permet l'execution des commandes :
*				  (1) ajouter des notes depuis un fichier en indiquant son nom
*				  (2) afficher la liste des etudiants, leurs notes et leur moyenne
*				  (0) generer un fichier des etudiants classe par moyenne (fin du programme)
*				  Affiche la liste des commandes en cas d'erreur de saisie
* Parametres	: -
* Retour		: -
**************************************************************************************/

void main()
{
	typeElt *listeEtudiants, *listeEtudiantsTriee;
	int commande;
	
	// Initialisation de la liste
	initListe(&listeEtudiants);

	// On contrôle que la recupération se passe bien, si oui on continue
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

	// Recuperation d'une liste triee selon les moyennes
	listeEtudiantsTriee = trierEtudiantsMoyenne(&listeEtudiants);

	// Creation du fichier "moyenne.txt"
	genererFichierMoyenne(listeEtudiantsTriee);

	// Détruit les listes
	detruireListeEtudiants(&listeEtudiants);
	listeEtudiantsTriee = NULL;

	system("pause");
}