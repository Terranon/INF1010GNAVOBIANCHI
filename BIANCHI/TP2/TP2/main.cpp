/********************************************
* Titre: Travail pratique #2 - main.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include <iostream>
#include "depense.h";
#include "utilisateur.h"
#include  "transfert.h"
#include "groupe.h"

using namespace std;

int main() {

	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************************" << endl;

	// Initialisation des depenses
	string lieu1 = "IGA";
	Depense* d1 = new Depense("d1", 12, &lieu1);
	string lieu2 = "Provigo";
	Depense* d2 = new Depense("d2", 11, &lieu2);
	string lieu3 = "Jean-drapeau";
	Depense* d3 = new Depense("d3", 5, &lieu3);
	string lieu4 = "Vieux port";
	Depense* d4 = new Depense("d4", 23, &lieu4);
	string lieu5 = "Metro";
	Depense* d5 = new Depense("d5", 17, &lieu5);
	string lieu6 = "Desjardins";
	Depense* d6 = new Depense("d6", 29, &lieu6);
	// Exemple d'utilisation du constructeur par copie et de l'operateur d'assignation
	Depense* d7 = new Depense(*d5);
	d7->setNom("d7");
	string lieu7 = "Maisonnee";
	d7->setLieu(&lieu7);

	Depense* d8 = new Depense();
	*d8 = *d1;
	d8->setNom("d8");
	string lieu8 = "Banque scotia";
	d8->setLieu(&lieu8);

	// Initialisation des utilisateurs
	Utilisateur* u1 = new Utilisateur("Martin");
	Utilisateur* u2 = new Utilisateur("Franklin");
	Utilisateur* u3 = new Utilisateur("Geraldine");
	Utilisateur* u4 = new Utilisateur("Bernard");

	//Exemple d'utilisation de l'operateur d'assignation
	Utilisateur* u5 = new Utilisateur();
	*u5 = *u1;
	u5->setNom("Christian");

	// Initialisation du groupe
	Groupe* groupe = new Groupe("vacances");

	// Ajout des utilisateurs et des depenses au groupe
	((((*groupe += u1) += u2) += u3) += u4) += u5;

	groupe->ajouterDepense(d1, u1);
	groupe->ajouterDepense(d2, u1);
	groupe->ajouterDepense(d3, u2);
	groupe->ajouterDepense(d4, u3);
	groupe->ajouterDepense(d5, u4);
	groupe->ajouterDepense(d6, u5);
	groupe->ajouterDepense(d7, u3);
	groupe->ajouterDepense(d8, u4);
	cout << groupe;
	// Equilibrage des comptes
	groupe->equilibrerComptes();
	cout << groupe;

	// TODO: Terminez le programme correctement
	delete d1;
	d1 = nullptr;
	delete d2;
	d2 = nullptr;
	delete d3;
	d3 = nullptr;
	delete d4;
	d4 = nullptr;
	delete d5;
	d5 = nullptr;
	delete d6;
	d6 = nullptr;
	delete d7;
	d7 = nullptr;
	delete d8;
	d8 = nullptr;

	delete u1;
	u1 = nullptr;
	delete u2;
	u2 = nullptr;
	delete u3;
	u4 = nullptr;
	delete u4;
	u5 = nullptr;
	delete u5;
	u5 = nullptr;

	delete groupe;
	groupe = nullptr;
	return 0;
}
