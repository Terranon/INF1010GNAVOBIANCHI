/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#pragma once
#include <map>
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include <vector>
#include <functional>
class AjouterDepense  {

public:
	//Constructeur
	AjouterDepense(vector<Depense*>&depense):conteneur_(depense) {};

	//OPERATOR()
	vector<Depense*>& operator()(Depense* depense) {conteneur_.push_back(depense);return conteneur_;};

private:
	vector<Depense*> conteneur_;
};

class AjouterUtilisateur {

public:
	//Constructeur :passage par réference constante 
	
	AjouterUtilisateur( map<Utilisateur*, double>& conteneur ):
		conteneur_(conteneur) {
	};
	
	map<Utilisateur*, double>& operator()(Utilisateur* utilisateur) {
		 if (dynamic_cast<UtilisateurPremium*>(utilisateur)) {
			 if (dynamic_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() != 0) {
				 conteneur_.insert(pair<Utilisateur*, double>(utilisateur, 0));
			 }
			 else {
				 cout << "l'utilisateur" << utilisateur->getNom() << "doit renouveller son abonnement" << endl;
			 }
		 }
		 else {
			 if (dynamic_cast<UtilisateurRegulier*>(utilisateur)->getPossedeGroupe() == 0) {
				 conteneur_.insert(make_pair(utilisateur, 0));
				 dynamic_cast<UtilisateurRegulier*>(utilisateur)->setPossedeGroupe(true);
			 }
			 else {
				 cout << "l'utilisateur" << utilisateur->getNom() << "est deja groupe" << endl;
			 }
		 }
		
		return conteneur_;
	};

private:
	map<Utilisateur*, double>& conteneur_;
};

class FoncteurIntervalle{
public:
	FoncteurIntervalle(double inf,double sup):borneInf_(inf),borneSup_(sup) {};
	bool operator()(const pair< Utilisateur*, double> &( utilisateur)) { //parametre passe par référence car l'utilisateur existe--quand je le passe par référence le compilateur le voit comme une erreur
	
                //si le compte associé a paire est compris entre l'intervalle donné  on retourne le booleen true
		if (utilisateur.second >= borneInf_ && utilisateur.second <= borneSup_) {
			return true;
		}	   
		return false;
	};

private:
double borneInf_, borneSup_;
};



