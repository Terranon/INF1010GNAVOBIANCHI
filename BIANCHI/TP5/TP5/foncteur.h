/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#include<map>

class AjouterDepense {
public:
	AjouterDepense(vector<Depense*> &conteneur) :
		conteneur_(conteneur) {
	}
	vector<Depense*>& operator()(Depense* depense) {
		conteneur_.push_back(depense);
		return conteneur_;
	}

private:
	vector<Depense*> conteneur_;
};

class AjouterUtilisateur {
public:
	AjouterUtilisateur(map<Utilisateur*, double> map) :
		conteneur_(map) {
	}
	map<Utilisateur*, double>& operator()(Utilisateur* utilisateur, double index) {
		return conteneur_;
	}

private:
	map<Utilisateur*, double> conteneur_;
};

/*
Foncteur FoncteurIntervalle

Méthode :
Constructeur
bool operator()();

Attribut :
double borneInf_, borneSup_;
*/
