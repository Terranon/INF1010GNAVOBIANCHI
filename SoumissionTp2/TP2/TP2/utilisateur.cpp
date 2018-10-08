/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifier par: Serge Gnavo
*			  : Maximilien Bianchi
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() :
	nom_("") {
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom) {
}

Utilisateur::Utilisateur(const Utilisateur& objetCopie) {
	if (this != &objetCopie) {
		nom_ = objetCopie.getNom();
		depenses_ = objetCopie.depenses_;
	}
}
//Destructeur
Utilisateur::~Utilisateur() {
	for (unsigned int i = 0; i < depenses_.size(); i++) {
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

unsigned int Utilisateur::getNombreDepense() const {
	return depenses_.size();
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}

Utilisateur& Utilisateur::operator=(const Utilisateur& utilisateur) {
	if (this != &utilisateur) {
		nom_ = utilisateur.nom_;
		for (unsigned int i = 0; i < depenses_.size(); i++) {
			delete depenses_[i];
			depenses_[i] = nullptr;
		}
		depenses_.clear();
		depenses_.shrink_to_fit();
		for (unsigned int i = 0; i < depenses_.size(); i++) {
			depenses_.push_back(utilisateur.depenses_[i]);
		}
	}
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur) {
	os << "Utilisateur :" << utilisateur.getNom() << " a depense pour un total de: " << utilisateur.getTotalDepenses() << endl;
	os << "\t Liste de depenses : " << endl;
	for (unsigned int i = 0; i < utilisateur.depenses_.size(); i++) {
		os << "\t\t" << *utilisateur.depenses_[i] << endl;
	}
	return os;
}