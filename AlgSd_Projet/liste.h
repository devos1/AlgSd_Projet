/**
 * Header des fonctions primitives des listes (liste.h)
 * Oscar Da Silva et Quentin Walter, HEIG-VD, mars 2014
 */
#include "fonctions.h"

/* Type des �l�ments stock�s dans le champ donn�e */
typedef typeEtudiant typeDonnee;

/* Structure pour repr�senter un �l�ment de la liste */
typedef struct elt {
	typeDonnee val;        // Champ donn�e
	struct elt *suivant;   // Pointeur sur l'�l�ment suivant
} typeElt;

/* Initialise la liste : pas d'�l�ment */
void initListe (typeElt **ptPrem);

/* Allouer la m�moire pour un nouvel �l�ment */
/* Initialiser le champ val */
typeElt *creerElt (typeDonnee valeur);

/* Lire la valeur stock�e dans l'�l�ment */
typeDonnee valElt (typeElt *element);

/* Lire le pointeur suivant dans l'�l�ment */
typeElt *suivantElt (typeElt *element);

/* Ins�rer un �l�ment apr�s l'�l�ment courant */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* courant sera �gal � NULL si on veut ins�rer en d�but de liste */
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau);

/* D�truire l'�l�ment plac� derri�re l'�l�ment courant */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* courant vaut NULL s'il faut enlever le premier */
void detruireElt (typeElt **ptPrem, typeElt *courant);