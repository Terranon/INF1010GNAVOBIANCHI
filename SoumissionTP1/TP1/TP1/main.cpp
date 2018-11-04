/******************************************************************************\
* Authors:     Serge Gnavo 1869985
*			   Maximilien Bianchi 1893352
* Name:        TP1 INF1010 main.cpp
* Description: Contient la fonction main() qui fait operer le programme
* Convention:  Boucles qui gere les utilisateur utiliseront i pour compter
*			   Boucles qui gere les depenses utiliseront j pour compter
* Version: 7.0
\******************************************************************************/
#include <iostream>

#include "groupe.h"


using namespace std;

static const unsigned int TAILLEDEPENSEFINAL = 6;
static const unsigned int NOMBREDEPENSEFINAL = 7;
static const unsigned int TAILLEUTILISATEURFINAL = 4;
static const unsigned int NOMBREUTILISATEURFINAL = 5;


int main(int argc, const char * argv[]) {
	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
	
	// Votre ligne de code sera insérée ici.
	


	// Creer un evenement pour 6 depenses et 4 utilisateurs.
	string name;
	cout << "entrez un nom pour le groupe" << endl;
	cin >> name; 
	unsigned int tailleTabDepenses = TAILLEDEPENSEFINAL; 
	unsigned int tailleTabUtilisateurs = TAILLEUTILISATEURFINAL;
	Groupe evenement(name, tailleTabDepenses, tailleTabUtilisateurs);

	// Creer 5 utlisateurs.
	string nom;
	Utilisateur** listeUtilisateurs = new Utilisateur*[NOMBREUTILISATEURFINAL];
	for (unsigned int i = 0; i < NOMBREUTILISATEURFINAL; i++) {
		listeUtilisateurs[i] = new Utilisateur();
		// on rajoute le rang de l'utilisateur nous avons fait la liste de 1 a 5 au lieux de 0 a 4
		// pour faciliter l'ergonomie du programme
		cout << "Entrez le nom de l'utilisateur: " << i + 1 << endl;
		cin >> nom;
		listeUtilisateurs[i]->setNom(nom);
	}
	
	//Creer 7 dépenses.
	Depense** listeDepenses = new Depense*[NOMBREUTILISATEURFINAL];
	string titre;
	double montant;
	// Ici nous avons fait un petit tableau pour savoir quel utilisateur a fait quel depense
	// avec se tableau, la personne qui utilise le programme poura choisir qui a fait la depense
	unsigned int ordreDeDepense[NOMBREDEPENSEFINAL]; 
	for (unsigned int j = 0; j < NOMBREDEPENSEFINAL; j++) {
		listeDepenses[j] = new Depense();
		cout << "Entrez le nom de la depense: " << j + 1 << endl;
		cin >> titre;
		listeDepenses[j]->setTitre(titre);
		cout << "Entrez la valeur de la depense: " << j + 1 << endl;
		cin >> montant;
		listeDepenses[j]->setMontant(montant);
		unsigned int rangUtilisateur;
		cout << "Qui a fait la depense?" << endl;
		for (unsigned int i = 0; i < NOMBREUTILISATEURFINAL; i++) {
			cout << "pour " << listeUtilisateurs[i]->getNom() << " entrer: " << i + 1 << endl;
		}
		/*cout << "pour " << listeUtilisateurs[0]->getNom() << " entrer 1" << endl;
		cout << "pour " << listeUtilisateurs[1]->getNom() << " entrer 2" << endl;
		cout << "pour " << listeUtilisateurs[2]->getNom() << " entrer 3" << endl;
		cout << "pour " << listeUtilisateurs[3]->getNom() << " entrer 4" << endl;
		cout << "pour " << listeUtilisateurs[4]->getNom() << " entrer 5" << endl;*/
		cin >> rangUtilisateur;
		ordreDeDepense[j] = (rangUtilisateur - 1); // rangUtilisateur - 1 pour ecrire le bon rang dans le tableau
	}
	//ajouter les utilisateurs a l'evenement
	for (unsigned int i = 0; i < NOMBREUTILISATEURFINAL; i++) {
		evenement.ajouterUtilisateur(listeUtilisateurs[i]);
	}

	//ajouter les depenses a l'evenement
	for (unsigned int j = 0; j < NOMBREDEPENSEFINAL; j++) {
		// ici nous avons reutiliser le tableau de rang de depense creer plus haut pours bien assigner
		// les depense a l'utilisateur approprie
		evenement.ajouterDepense(listeDepenses[j], listeUtilisateurs[ordreDeDepense[j]]);
	}

	//calculer le total de l'evenement et de chaque utilisateur
	for (unsigned int i = 0; i < NOMBREUTILISATEURFINAL; i++) {
		listeUtilisateurs[i]->calculerTotal();
	}
	evenement.calculerTotalDepenses();

	//Afficher le groupe
	cout << "voici le groupe avant de faire l'equilibration: " << endl;
	for (unsigned int i = 0; i < NOMBREUTILISATEURFINAL; i++) {
		listeUtilisateurs[i]->afficherUtilisateur();
	}
	evenement.afficherGroupe();

	//Equilibrer les comptes
	evenement.equilibrerComptes();

	//Afficher le groupe
	cout << "voici le groupe apres de faire l'equilibration: " << endl;
	for (unsigned int i = 0; i < NOMBREUTILISATEURFINAL; i++) {
		listeUtilisateurs[i]->afficherUtilisateur();
	}
	evenement.afficherGroupe();

	//Empeche le programme de terminer trop tot
	bool terminerProgramme = false;
	while (terminerProgramme == false) {
		char reponse;
		cout << endl << "Terminer le programme? (O pour oui, N pour non): ";
		cin >> reponse;
		if (reponse == 'O') {
			terminerProgramme = true;
		}
		else {
			terminerProgramme = false;
		}
	}

	//terminer le programme correctement
	// Desallouer la liste d'utilisateur
	for (unsigned int i = 0; i < NOMBREUTILISATEURFINAL; i++) {
		delete listeUtilisateurs[i];
	}
	delete[] listeUtilisateurs;

	// Desallouer la liste de depense
	for (unsigned int j = 0; j < NOMBREDEPENSEFINAL; j++) { 
		delete listeDepenses[j];
	}
	delete[] listeDepenses;
	return 0;
};