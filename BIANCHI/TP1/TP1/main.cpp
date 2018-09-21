
#include <iostream>
#include "groupe.h"

using namespace std;

static const unsigned int NOMBREUTILISATEUR = 5;
static const unsigned int NOMBREDEPENSE = 7;

int main(int argc, const char * argv[]) {
	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
	// Creer un  groupe pour  6 depenses et 4 utilisateurs.
	string nomEvenement;
	cout << "Entrer le titre de l'evenement: ";
	cin >> nomEvenement;

	Groupe groupe(nomEvenement, 6, 4);

	// Creer 5 utlisateurs.
	string nomUtilisateur;
	unsigned int rangUtilisateur = 0;
	Utilisateur** listeTempUtilisateur = new Utilisateur*[NOMBREUTILISATEUR];
	while (rangUtilisateur < NOMBREUTILISATEUR) {
		listeTempUtilisateur[rangUtilisateur] = nullptr;
		cout << endl << "Entrer le nom du participant " << rangUtilisateur << " :";
		cin >> nomUtilisateur;
		Utilisateur* utilisateurTemp = new Utilisateur(nomUtilisateur);
		utilisateurTemp->afficherUtilisateur();
		listeTempUtilisateur[rangUtilisateur] = utilisateurTemp;
		listeTempUtilisateur[rangUtilisateur]->afficherUtilisateur();
		rangUtilisateur++;
	}

	//Creer 7 dépenses.
	string titreDepense;
	double montantDepense;
	unsigned int rangDepense = 0;
	Depense** listeTempDepense = new Depense*[NOMBREDEPENSE];
	while (rangDepense < 7) {
		listeTempDepense[rangDepense] = nullptr;
		cout << endl << "Maintenant nous allons entrer les depense pour chaque participant." << endl
			<< "Entrer le titre de la premiere depense: ";
		cin >> titreDepense;
		cout << endl << "Entrer les montant de la premiere depense :";
		cin >> montantDepense;
		Depense* depenseTemp = new Depense(titreDepense, montantDepense);
		depenseTemp->afficherDepense();
		listeTempDepense[rangDepense] = depenseTemp;
		listeTempDepense[rangDepense]->afficherDepense();
		cout << endl << "Qui a fait la depense? " << endl;
		rangUtilisateur = 0;
		while (rangUtilisateur < NOMBREUTILISATEUR) {
			cout << "Pour " << listeTempUtilisateur[rangUtilisateur]->getNom() << " entrer " << rangUtilisateur << endl;
			rangUtilisateur++;
		}
		cin >> rangUtilisateur;
		groupe.ajouterDepense(depenseTemp, listeTempUtilisateur[rangUtilisateur]);
		groupe.afficherGroupe();
		rangDepense++;
	}


	//ajouter les utilisateurs au groupe
	rangUtilisateur = 0;
	while (rangUtilisateur < NOMBREUTILISATEUR) {
		Utilisateur* utilisateurTemp = new Utilisateur;
		utilisateurTemp = nullptr;
		utilisateurTemp = listeTempUtilisateur[rangUtilisateur];
		groupe.ajouterUtilisateur(utilisateurTemp);
		groupe.afficherGroupe();
		rangUtilisateur++;
	}
	
	//ajouter les depenses au groupe

	//calculer le total du groupe et de chaque utilisateur
	groupe.calculerTotalDepenses();

	//Afficher le groupe
	groupe.afficherGroupe();

	//Equilibrer les comptes
	groupe.equilibrerComptes();

	//Afficher le groupe
	groupe.afficherGroupe();

	//terminer le programme correctement
	for (unsigned int i = 0; i < 5; i++) {
		delete listeTempUtilisateur[i];
		listeTempUtilisateur[i] = nullptr;
	}
	delete listeTempUtilisateur;
	listeTempUtilisateur = nullptr;

	return 0;
}
