/**
 * Header des fonctions du programme (fonctions.h)
 * Oscar Da Silva et Quentin Walter, HEIG-VD, mars 2014
 */
#define NOMBRE_NOTES_MAX 5

typedef struct {
	int jour;	// Jour (1-31)
	int mois;	// Mois (1-12)
	int annee;	// Année (aaaa)
} typeDate;

typedef struct {
	int matricule;			// Matricule de l'étudiant (numéro unique)
	char nom[20];				// Nom d'étudiant
	char prenom[20];			// Prénom d'étudiant
	typeDate dateNaissance;	// Date de naissance de l'étudiant
	int nombreNotes;		// Nombre de notes de l'étudiant
	float tableauNotes[NOMBRE_NOTES_MAX];	// Tableau des notes de l'étudiant (max. 5)
	float moyenneNotes;		// Moyenne des notes de l'étudiant
} typeEtudiant;
/**
 * Permet la saisie d'une chaine de caracteres
 * Retourne la valeur saisie
 */
char *insererChaine();
/**
 * Calcule la moyenne des notes
 * tableauNotes, tableau des notes
 * nombreNotes, nombre de notes (superieur a 0)
 * Retourne la moyenne des notes
 */
float calculerMoyenne(float tableauNotes[NOMBRE_NOTES_MAX], int nombreNotes);
/**
 * Ajoute une note a un etudiant
 * etudiant, pointeur sur la structure d'un etudiant
 * note, valeur a ajouer
 * Retourne VRAI (1) si la note a ete ajoutee, sinon FAUX (0).
 */
int insererNote(typeEtudiant *etudiant, float note);