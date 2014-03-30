/********************************************************************************
* Auteurs		: Quentin Walter et Oscar Da Silva
* Date			: Mars 2014
* Nom			: liste.c
* Description	: TP AlgSd, HEIG-VD Fee
* Resume		: Fichier avec les fonctions primitives vues en cours
/*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/* Initialise la liste : pas d'�l�ment */
void initListe (typeElt **ptPrem) {
	*ptPrem = NULL;
}

/* Allouer la m�moire pour un nouvel �l�ment */
/* Initialiser le champ val */
typeElt *creerElt (typeDonnee valeur){
	typeElt *nouveau;

	/* Allocation de la m�moire pour le nouvel �l�ment */
	nouveau = (typeElt *) malloc (sizeof (typeElt));
	if (nouveau != NULL) {
		nouveau->val = valeur; // Initialisation de la donn�e
	}
	return nouveau;
}

/* Lire la valeur stock�e dans l'�l�ment */
typeDonnee valElt (typeElt *element) {
	return (element->val);
}

/* Lire le pointeur suivant dans l'�l�ment */
typeElt *suivantElt (typeElt *element){
	return (element->suivant);
}

/* Ins�rer un �l�ment apr�s l'�l�ment courant */
/* Resultat : 1 si ok 0 si allocation m�moire impossible */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* courant sera �gal � NULL si on veut ins�rer en d�but de liste */
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau) {

	if (courant == NULL) {
		/* Le nouvel �l�ment doit �tre ins�r� en d�but de liste */
		nouveau->suivant = *ptPrem;
		*ptPrem = nouveau;
	} else {
		/* Le nouvel �l�ment est ins�r� derri�re l'elt courant */
		nouveau->suivant = courant->suivant; 
		courant->suivant = nouveau;
	}
}

/* D�truire l'�l�ment plac� derri�re l'�l�ment courant */
/* R�sultat : valeur stock�e dans l'�l�ment d�truit */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* Precedent sera �gal � NULL pour d�truire le premier de la liste */
void detruireElt (typeElt **ptPrem, typeElt *courant){
	typeElt *elt;

	if (courant == NULL) {
		/* Enlever le premier de la liste */
		elt = *ptPrem;                        /* Garder l'adresse du premier �l�ment */
		*ptPrem = elt->suivant;               /* Premier pointera sur le 2�me �l�ment */
	} else {
		elt = courant->suivant;                /* Element � enlever */
		courant->suivant = elt->suivant;       /* Modifier le pointeur du precedent */
	}
	free (elt);  /* Liberer la m�moire pour l'�l�ment d�truit */
}
