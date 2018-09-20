
#include <iostream>
#include "groupe.h"

using namespace std; 

int main(int argc, const char * argv[]) {
    cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
    // Creer un  groupe pour  6 depenses et 4 utilisateurs.
	string nomEvenement;
	cout << "Entrer le titre de l'evenement: ";
	cin >> nomEvenement;

	Groupe groupe(nomEvenement, 6, 4);
    
    // Creer 5 utlisateurs.
	string nomUtilisateur;
	unsigned int rang= 0;
	Utilisateur** listeTempUtilisateur = new Utilisateur*[5];
	while (rang < 5) {
		cout << endl << "Entrer le nom du participant " << rang << " :";
		cin >> nomUtilisateur;
		Utilisateur* utilisateur = new Utilisateur(nomUtilisateur);
		listeTempUtilisateur[rang] = utilisateur;
		delete utilisateur;
		utilisateur = nullptr;
	}

    //Creer 7 dépenses.
	string titreDepense;
	double montantDepense;
	rang = 0;
	while (rang < 7) {
		cout << endl << "Maintenant nous allons entrez les depense pour chaque participant." << endl
			<< "Entrer le nom du participant qui a fait la depense: ";
		cin >> nomUtilisateur;
		bool utilisateurTrouve = false;
		for (unsigned int i = 0; i < 5 || utilisateurTrouve; i++) {
			if (listeTempUtilisateur[i]->getNom == nomUtilisateur) {
				utilisateurTrouve = true;
				cout << endl << "Entrer le titre de la depense " << rang << ": ";
				cin >> titreDepense;
				cout << endl << "Entrer le montant de la depense " << rang << ": ";
				cin >> montantDepense;
				Depense* depense = new Depense(titreDepense, montantDepense);
				groupe.ajouterDepense(depense, listeTempUtilisateur[i]);
				delete depense;
				depense = nullptr;
			}
			if (i == 4 && utilisateurTrouve == false) {
				cout << endl << "Ce participant n'est pas dans la liste";
				rang--;
			}
		}
	}

    
    //ajouter les utilisateurs au groupe
    

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
