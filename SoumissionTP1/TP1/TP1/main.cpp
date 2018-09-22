/******************************************************************************\
* Authors:     Serge Gnavo 1869985
			   Maximilien Bianchi 1893352
* Name:        main.cpp - TP1 INF1010
* Description: contient la fonction main pour faire fonctionner le programme
* Version: 2.0
\******************************************************************************/

#include <iostream>
#include "groupe.h"

using namespace std;

// constantes pour faciliter les initialisations
static const unsigned int NOMBREUTILISATEUR = 5;
static const unsigned int NOMBREDEPENSE = 7;

// fonction main
int main(int argc, const char * argv[]) {
	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;

	// Creer un evenement pour  6 depenses et 4 utilisateurs.
	string name;
	cout << "entrez un nom pour le groupe" << endl;
	cin >> name; 
	unsigned int tailleTabDepenses = 6; 
	unsigned int tailleTabUtilisateurs = 4;
	Groupe evenement(name, tailleTabDepenses, tailleTabUtilisateurs);

	// Creer 5 utlisateurs.
	string nom;
	Utilisateur** listUtilisateurs = new Utilisateur*[NOMBREUTILISATEUR];
	for (unsigned int i = 0; i < NOMBREUTILISATEUR; i++) {
		cout << "Entrez le nom de l'utilisateur" << i << endl;
		cin >> nom;
		listUtilisateurs[i] = new Utilisateur();//il faut initialiser listutilsateur pour savoir qu'il existe un truc dedans
		listUtilisateurs[i]->setNom(nom);
	}

	//Creer 7 dépenses.
	Depense** listeDepenses = new Depense*[NOMBREDEPENSE];
	string titre;
	double montant;
	for (unsigned int i = 0; i < NOMBREDEPENSE; i++) {
		listeDepenses[i] = new Depense();
		cout << "Entrez le nom de la depense" << i << endl;
		cin >> titre;
		listeDepenses[i]->setTitre(titre);
		cout << "Entrez le montant de la depense" << i << endl;
		cin >> montant;
		listeDepenses[i]->setMontant(montant);
		unsigned int rangUtilisateur;
		cout << "Qui a fait la depense?" << endl;
		cout << "pour " << listUtilisateurs[0].getNom() << " entrer 0" << endl;
		cout << "pour " << listUtilisateurs[1].getNom() << " entrer 1" << endl;
		cout << "pour " << listUtilisateurs[2].getNom() << " entrer 2" << endl;
		cout << "pour " << listUtilisateurs[3].getNom() << " entrer 3" << endl;
		cout << "pour " << listUtilisateurs[4].getNom() << " entrer 4" << endl;
		cin >> rangUtilisateur;
		listUtilisateurs[rangUtilisateur].ajouterDepense(listeDepenses[i]);
	}
	
	//ajouter les utilisateurs au groupe
	for (unsigned int i = 0; i < NOMBREUTILISATEUR; i++)
	{
		cout << listUtilisateurs[i]->getNom() << endl;

		evenement.ajouterUtilisateur(listUtilisateurs[i]);
	}
	
	//ajouter les depenses a l'evenement
	for (unsigned int j = 0; j < NOMBREDEPENSE; j++) {
		cout << listeDepenses[j]->getTitre() << listUtilisateurs[j]->getNom() << endl;
		evenement.ajouterDepense(listeDepenses[j], listUtilisateurs[j]);
	}

	//calculer le total de l'evenement et de chaque utilisateur
	for (unsigned int i = 0; i < NOMBREUTILISATEUR; i++) {
		listUtilisateurs[i]->calculerTotal();
	}
	evenement.calculerTotalDepenses();

	//Equilibrer les comptes
	evenement.equilibrerComptes();

	//Afficher l'évenement
	for (int i = 0; i < NOMBREUTILISATEUR; i++) {
		listUtilisateurs[i]->afficherUtilisateur();
	}
	evenement.afficherGroupe();
	return 0;
}