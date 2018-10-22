/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "utilisateur.h"

Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type) :
	nom_(nom),
	interet_(0),
	type_(type) {
}
Utilisateur::Utilisateur(const Utilisateur& utilisateur) :
	nom_(utilisateur.nom_),
	depenses_(utilisateur.depenses_),
	type_(utilisateur.type_),
	interet_(utilisateur.interet_) {
	setDepenses(utilisateur.depenses_);
}

Utilisateur::~Utilisateur() {
}


// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}
double Utilisateur::getTotalDepenses() const {

	return totalDepense_;
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

// Methodes de modification
void Utilisateur::setInteret(const double& interet) {
	interet_ = interet;

}
void Utilisateur::setDepenses(const vector<Depense*> depense) {
	for (unsigned int i = 0; i < getNombreDepenses(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
	depenses_.clear();
	depenses_.shrink_to_fit();
	for (unsigned int j = 0; j < depense.size(); j++) {
		depenses_.push_back(new Depense(*depenses_[j]));
	}
}
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}
void Utilisateur::setType(TypeUtilisateur type) {
	type_ = type;
}
void Utilisateur::calculerTotalDepenses() {
	totalDepense_ = 0;
	for (unsigned int i = 0; i <getNombreDepenses(); i++) {
		if (depenses_[i]->getType() == groupe) {
			totalDepense_ += static_cast<DepenseGroupe*>(depenses_[i])->getMontantPersonnel();
		}
		else {
			totalDepense_ += depenses_[i]->getMontant();
		}
	}
}
void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

// Surcharge
Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}
Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur) {
	if (this != utilisateur) {
		setInteret(utilisateur->getInteret());
		setNom(utilisateur->getNom());
		setDepenses(utilisateur->getDepenses());
		setType(utilisateur->getType());
		calculerTotalDepenses();
	}
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, Utilisateur* utilisateur) {
	if (utilisateur->getType() == Premium) {
		os << "l'utilisateur " << utilisateur->getNom() << " (Premium) a une depense total de : " 
			<< utilisateur->getTotalDepenses() << ", Polycount prend un interet de " 
			<< utilisateur->getInteret() << endl;
	}
	else {
		os << "l'utilisateur " << utilisateur->getNom() << "(Regulier) a une depense total de : " 
			<< utilisateur->getTotalDepenses() << ", Polycount prend un interet de " 
			<< utilisateur->getInteret() << endl;
	}
	os << "voici les depenses:" << endl;
	for (unsigned int i = 0; i < utilisateur->getDepenses().size(); i++) {
		if (utilisateur->getDepenses()[i]->getType() == groupe) {
			os << static_cast<DepenseGroupe*>(utilisateur->depenses_[i]) << endl;
		}
		else {
			os << utilisateur->getDepenses()[i] << endl;
		}
	}
	return os;
}

