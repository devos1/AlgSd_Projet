//Commentaires

#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

int recupererEtudiantsFichier(typeElt **ptPrem);
int recupererNotesFichier(char *nomFichier);
int insererEtudiant(typeElt **ptPrem, typeDonnee etudiant);

void main()
{
	typeElt *listeEtudiants;
	int result;
	
	initListe(&listeEtudiants);

	result = recupererEtudiantsFichier(listeEtudiants);

	//printf("%d", result);
	puts("Hello World");
	


	system("pause");
}