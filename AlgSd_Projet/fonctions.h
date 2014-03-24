// fonctions.h
#define NOMBRE_NOTES_MAX 4

typedef struct {
	int jour;	// Jour (1-31)
	int mois;	// Mois (1-12)
	int annee;	// Ann�e (aaaa)
} typeDate;

typedef struct {
	int matricule;			// Matricule de l'�tudiant (num�ro unique)
	char nom[20];				// Nom d'�tudiant
	char prenom[20];			// Pr�nom d'�tudiant
	typeDate dateNaissance;	// Date de naissance de l'�tudiant
	int nombreNotes;		// Nombre de notes de l'�tudiant
	float tableauNotes[NOMBRE_NOTES_MAX];	// Tableau des notes de l'�tudiant (max. 5)
	float moyenneNotes;		// Moyenne des notes de l'�tudiant
} typeEtudiant;

char *insererChaine();