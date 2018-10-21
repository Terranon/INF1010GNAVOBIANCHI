/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type) :
	interet_(0),
	nom_(nom),
	type_(type)	{
}
Utilisateur::Utilisateur(const Utilisateur& utilisateur) :
	interet_(utilisateur.interet_),
	nom_(utilisateur.nom_),
	type_(utilisateur.type_) {
	setDepenses(utilisateur.depenses_);
}

Utilisateur::~Utilisateur() {
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
void Utilisateur::setDepenses(const vector<Depense*> depenses) {
	
	for (unsigned int i = 0; i < getNombreDepenses(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
	depenses_.clear();
	depenses_.shrink_to_fit();
	for (unsigned int j = 0; j < depenses.size(); j++) {
		depenses_.push_back(new Depense(*depenses[j]));
	}
}
void Utilisateur::calculerTotalDepenses() {
	totalDepenses_ = 0;
	for (unsigned int i = 0; i < getNombreDepenses(); i++) {
		if (individuelle == depenses_[i]->getType()) {
			totalDepenses_ += depenses_[i]->getMontant();
		}
		else {
			totalDepenses_ += static_cast<DepenseGroupe*>(depenses_[i])->getMontantPersonnel();
		}
	}
}
void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

// Operateurs
Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}
Utilisateur& Utilisateur::operator=(Utilisateur* utilisateur) {
	if (this != utilisateur) {
		setInteret(utilisateur->getInteret());
		setNom(utilisateur->getNom());
		setType(utilisateur->getType());
		setDepenses(utilisateur->getDepenses());
		calculerTotalDepenses();
	}
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur) {
	os << "L'utilisateur " << utilisateur.getNom() << " qui dois un interet de "
		<< utilisateur.getInteret() << "$, a fait les depenses suivantes:" << endl;
	unsigned int nombreDeDepenses = utilisateur.getNombreDepenses();
	for (unsigned int i = 0; i < nombreDeDepenses; i++) {
		os << utilisateur.depenses_[i] << endl;
	}
	return os;
}
