/********************************************************************************
* Auteurs		: Quentin Walter et Oscar Da Silva
* Date			: Mars 2014
* Nom			: fonctions.h
* Description	: TP AlgSd, HEIG-VD Fee
* Resume		: Header du fichier contenant divers fonctions utilisées 
*				  dans ce projet
/*******************************************************************************/
#define NOMBRE_NOTES_MAX 5

// Structure pour contenir la date
typedef struct {
	int jour;	// Jour (1-31)
	int mois;	// Mois (1-12)
	int annee;	// Année (aaaa)
} typeDate;

// Structure pour contenir un etudiant
typedef struct {
	int matricule;				// Matricule de l'étudiant (numéro unique)
	char nom[20];				// Nom d'étudiant
	char prenom[20];			// Prénom d'étudiant
	typeDate dateNaissance;		// Date de naissance de l'étudiant
	int nombreNotes;			// Nombre de notes de l'étudiant
	float tableauNotes[NOMBRE_NOTES_MAX];	// Tableau des notes de l'étudiant (max. 5)
	float moyenneNotes;			// Moyenne des notes de l'étudiant
} typeEtudiant;

/********************************************************************************
* Description	: Permet la saisie d'une chaine de caracteres
* Parametres	: -
* Retour		: Pointeur sur la chaine saisie
*********************************************************************************/
char *insererChaine();

/*********************************************************************************
* Description	: Calcule la moyenne des notes
* Parametres	: tableauNotes, tableau avec les notes
*				  nombreNotes, nombre de notes (superieur à 0)
* Retour		: Flottant avec la moyenne des notes
**********************************************************************************/
float calculerMoyenne(float tableauNotes[NOMBRE_NOTES_MAX], int nombreNotes);

/**********************************************************************************
* Description	: Ajoute une note a un etudiant
* Parametres	: etudiant, pointeur sur la structure d'un etudiant
*				  note, valeur a ajouter
* Retour		: VRAI (1) si la note a ete ajoutee, sinon FAUX (0)
***********************************************************************************/
int insererNote(typeEtudiant *etudiant, float note);