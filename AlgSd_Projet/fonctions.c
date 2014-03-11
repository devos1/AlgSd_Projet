#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

#define FICHIER_ETUDIANTS "etudiant.txt"
#define VRAI 1
#define FAUX 0

int recupererEtudiantsFichier()
{
	// initListe

	// insererEtudiant
}
/* Insere un élément dans la liste */
/* Rend 1 si OK et 0 si l'insertion est impossible */
int insererEtudiant(typeElt **ptPrem,  typeDonnee etudiant)
{
	typeElt *courant, *precedent, *nouveau;
	int res = FAUX;
	int trouve; // Vrai lorsqu'on trouve où insérer

	/* Chercher l'élément derrière lequel il faut insérer */
	/* Se placer en tête de liste */
	courant = *ptPrem;
	precedent = NULL; // Il n'y a pas de precedant
	trouve = FAUX;
	while (courant != NULL && trouve == FAUX) {
		if (etudiant <= valElt(courant)) {
			trouve = VRAI; // On a trouvé où insérer la nouvelle valeur
		} else {
			precedent = courant;      // On garde un pointeur sur le précédent
			courant = suivantElt(courant); // On passe au suivant
		}
	}
	// A la fin de la boucle precedent pointe sur l'élément derrière lequel
	// on doit insérer un nouvel élément ou est égal à NULL si on insère 
	// en début de liste
	nouveau = creerElt (etudiant);
	if (nouveau != NULL) {
		insereElt (ptPrem, precedent, nouveau);
		res = VRAI; // C'est OK
	}
	return res;
}
int recupererNotesFichier(char *nomFichier)
{
	// insererNote
}
int insererNote(typeDonnee *etudiant)
{
	
}
float calculerMoyenne(int *tableauNotes)
{

}
int genererFichierMoyenne()
{
	
}

int insererEntier()
{

}
float insererFlottant()
{

}
char *insererChaine()
{
	
}