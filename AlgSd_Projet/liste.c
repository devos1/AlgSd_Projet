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

/* Initialise la liste : pas d'élément */
void initListe (typeElt **ptPrem) {
	*ptPrem = NULL;
}

/* Allouer la mémoire pour un nouvel élément */
/* Initialiser le champ val */
typeElt *creerElt (typeDonnee valeur){
	typeElt *nouveau;

	/* Allocation de la mémoire pour le nouvel élément */
	nouveau = (typeElt *) malloc (sizeof (typeElt));
	if (nouveau != NULL) {
		nouveau->val = valeur; // Initialisation de la donnée
	}
	return nouveau;
}

/* Lire la valeur stockée dans l'élément */
typeDonnee valElt (typeElt *element) {
	return (element->val);
}

/* Lire le pointeur suivant dans l'élément */
typeElt *suivantElt (typeElt *element){
	return (element->suivant);
}

/* Insèrer un élément après l'élément courant */
/* Resultat : 1 si ok 0 si allocation mémoire impossible */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* courant sera égal à NULL si on veut insérer en début de liste */
void insereElt (typeElt **ptPrem, typeElt *courant, typeElt *nouveau) {

	if (courant == NULL) {
		/* Le nouvel élément doit être inséré en début de liste */
		nouveau->suivant = *ptPrem;
		*ptPrem = nouveau;
	} else {
		/* Le nouvel élément est inséré derrière l'elt courant */
		nouveau->suivant = courant->suivant; 
		courant->suivant = nouveau;
	}
}

/* Détruire l'élément placé derrière l'élément courant */
/* Résultat : valeur stockée dans l'élément détruit */
/* ptPrem est l'adresse du pointeur sur le premier de la liste */
/* Precedent sera égal à NULL pour détruire le premier de la liste */
void detruireElt (typeElt **ptPrem, typeElt *courant){
	typeElt *elt;

	if (courant == NULL) {
		/* Enlever le premier de la liste */
		elt = *ptPrem;                        /* Garder l'adresse du premier élément */
		*ptPrem = elt->suivant;               /* Premier pointera sur le 2ème élément */
	} else {
		elt = courant->suivant;                /* Element à enlever */
		courant->suivant = elt->suivant;       /* Modifier le pointeur du precedent */
	}
	free (elt);  /* Liberer la mémoire pour l'élément détruit */
}
