/**
 * Header des fonctions primitives des listes (liste.h)
 * Oscar Da Silva et Quentin Walter, HEIG-VD, mars 2014
 */
#include "fonctions.h"

/* Type des éléments stockés dans le champ donnée */
typedef typeEtudiant typeDonnee;

/* Structure pour représenter un élément de la liste */
typedef struct elt {
	typeDonnee val;        // Champ donnée
	struct elt *suivant;   // Pointeur sur l'élément suivant
} typeElt;

/* Initialise la liste : pas d'élément */
void initListe (typeElt **ptPrem);

/* Allouer la mémoire pour un nouvel élément */
/* Initialiser le champ val */
typeElt *creerElt (typeDonnee valeur);

/* Lire la valeur stockée dans l'élément */
typeDonnee valElt (typeElt *element);

/* Lire le pointeur suivant dans l'élément */
typeElt *suivantElt (typeElt *element);

/* Insèrer un élément après l'élément courant */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* courant sera égal à NULL si on veut insérer en début de liste */
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau);

/* Détruire l'élément placé derrière l'élément courant */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* courant vaut NULL s'il faut enlever le premier */
void detruireElt (typeElt **ptPrem, typeElt *courant);