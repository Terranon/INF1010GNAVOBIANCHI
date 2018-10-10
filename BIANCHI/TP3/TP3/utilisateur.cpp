/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() :
	nom_(""),
	type_(Regulier) {
}
Utilisateur::Utilisateur(const string& nom = "", TypeUtilisateur type = Regulier) :
	nom_(nom),
	type_(type) {
}
Utilisateur::Utilisateur(const Utilisateur& utilisateur) {
	*this = utilisateur;
}

Utilisateur::~Utilisateur() {
	unsigned int nombreDeDepenses = depenses_.size();
	for (unsigned int i = 0; i < nombreDeDepenses; i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
	depenses_.clear();
	depenses_.shrink_to_fit();
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}
double Utilisateur::getTotalDepenses() const {
	return totalDepenses_;
}
TypeUtilisateur Utilisateur::getType() const {
	return type_;
}
double Utilisateur::getInteret() const {
	return interet_;
}
unsigned int Utilisateur::getNombreDepenses() const {
	return depenses_.size();
}
vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_;
}

//Methodes de modification
void Utilisateur::setInteret(const double& interet) {
	interet_ = interet;
}
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}
void Utilisateur::setType(const TypeUtilisateur& type) {
	type_ = type;
}
void Utilisateur::setDepenses(const vector <Depense*> depenses) {
	unsigned int nombreDeDepenses = getNombreDepenses();
	for (unsigned int i = 0; i < nombreDeDepenses; i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
	depenses_.clear();
	depenses_.shrink_to_fit();
	for (unsigned int j = 0; nombreDeDepenses; j++) {
		depenses_.push_back(depenses[j]);
	}
}
void Utilisateur::calculerTotalDepenses() {
	totalDepenses_ = 0;
	for (unsigned int i = 0; i < getNombreDepenses(); i++) {
		totalDepenses_ += depenses_[i]->getMontant();
	}
}
void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

// Operateurs
Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
}
Utilisateur& Utilisateur::operator=(Utilisateur* utilisateur) {
	setInteret(utilisateur->getInteret());
	setNom(utilisateur->getNom());
	setType(utilisateur->getType());
	setDepenses(utilisateur->getDepenses());
	calculerTotalDepenses();
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur) {
	os << "L'utilisateur " << utilisateur.getNom() << " avec un interet de "
		<< utilisateur.getInteret() << "$ a les depenses suivantes: " << endl;
	unsigned int nombreDeDepenses = utilisateur.getNombreDepenses();
	for (unsigned int i = 0; i < nombreDeDepenses; i++) {
		os << utilisateur.depenses_[i] << endl;
	}
	return os;
}
