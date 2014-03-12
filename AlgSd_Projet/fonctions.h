// fonctions.h

typedef struct {
	int jour;	// Jour (1-31)
	int mois;	// Mois (1-12)
	int annee;	// Année (aaaa)
} typeDate;

typedef struct {
	int matricule;			// Matricule de l'étudiant (numéro unique)
	char *nom;				// Nom d'étudiant
	char *prenom;			// Prénom d'étudiant
	typeDate dateNaissance;	// Date de naissance de l'étudiant
	int nombreNotes;		// Nombre de notes de l'étudiant
	float tableauNotes[4];	// Tableau des notes de l'étudiant (max. 5)
	float moyenneNotes;		// Moyenne des notes de l'étudiant
} typeEtudiant;
