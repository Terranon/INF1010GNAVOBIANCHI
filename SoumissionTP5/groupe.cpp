/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"

#include <functional>
#include <algorithm>

using namespace std::placeholders;

// Constructeurs
Groupe::Groupe() {
	nom_ = "";
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const string& nom) : 
	nom_(nom) {
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::~Groupe() {
	vector<Depense*> depenses = gestionnaireDepenses_->getConteneur();
	for (int i = 0; i < depenses.size(); i++) {
		delete depenses[i];
	}
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<Depense*> Groupe::getDepenses() const {
	return gestionnaireDepenses_->getConteneur();
}

vector<Utilisateur*> Groupe::getUtilisateurs() const {
	vector<Utilisateur*>tabUtilisateur;
	
	for (pair<Utilisateur*,double>element : gestionnaireUtilisateurs_->getConteneur()) { //parcourt le conteneur
		tabUtilisateur.push_back(element.first);
	}
	return tabUtilisateur;
}

vector<Transfert*> Groupe::getTransferts() const {
	return transferts_;
}

vector<double> Groupe::getComptes() const {

	vector<double>compte;
	auto conteneur = gestionnaireUtilisateurs_->getConteneur();
	for (auto it = conteneur.begin(); it != conteneur.end();it++) {
		compte.push_back(it->second);
	}
	return compte;
}

double Groupe::getTotalDepenses() const {
	return gestionnaireDepenses_->getTotalDepenses();
}

GestionnaireUtilisateurs* Groupe::getGestionnaireUtilisateurs() {
	return gestionnaireUtilisateurs_;
}

GestionnaireDepenses* Groupe::getGestionnaireDepenses() {
	return gestionnaireDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu) {

	if (!gestionnaireUtilisateurs_->estExistant(payePar)) { 
		cout << "L'utilisateur auquel vous essayer d'ajouter une depense n'existe pas dans le groupe" << endl;
		return *this;
	}

	Depense* depense = new Depense(nom, montant, lieu);
	gestionnaireDepenses_->ajouter(depense);
	gestionnaireUtilisateurs_->mettreAJourComptes(payePar, montant);
	*payePar += depense;
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur) {

	gestionnaireUtilisateurs_->ajouter(utilisateur);
	return *this;
}

void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	
	while (calcul) {
		pair<Utilisateur*, double>pairemin  = gestionnaireUtilisateurs_->getMin();;
		pair<Utilisateur*, double> pairemax  = gestionnaireUtilisateurs_->getMax();;

		if (-pairemin.second <= pairemax.second && pairemin.second != 0 && pairemax.second != 0) {
			if (pairemin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-pairemin.second, pairemin.first, pairemax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				
				TransfertPaypal* transfert = new TransfertPaypal(-pairemin.second, pairemin.first, pairemax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			pairemax.second += pairemin.second;
			pairemin.second = 0;
		}
		else if (-pairemin.second > pairemax.second  && pairemin.second != 0 && pairemax.second != 0) {
			if (pairemin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(pairemax.second, pairemin.first, pairemax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(pairemax.second, pairemin.first, pairemax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			pairemin.second += pairemax.second;
			pairemax.second = 0;
		}

		gestionnaireUtilisateurs_->setCompte(pairemax);
		gestionnaireUtilisateurs_->setCompte(pairemin);
		count++;

		if (-pairemin.second == pairemax.second) {
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getNombreElements() - 1) {
			calcul = false;
		}
	}
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe) {
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	auto conteneur = groupe.gestionnaireUtilisateurs_->getConteneur();
	for (auto it = conteneur.begin(); it != conteneur.end();it++) {
		os << "\t- " << *it->first;
	}
	os << endl;
	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (int i = 0; i < groupe.getComptes().size(); i++) {
			os << groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first->getNom() << " : " << groupe.getComptes()[i] << endl;
		}
	}
	os << endl;
	return os;
}