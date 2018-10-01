/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : 
	nom_("") {
}

Utilisateur::Utilisateur(const string& nom) : 
	nom_(nom) {
}

Utilisateur::Utilisateur(const Utilisateur& utilisateur) :
	nom_(utilisateur.getNom()),
	depenses_(utilisateur.depenses_) {
}

//Destructeur
Utilisateur::~Utilisateur() {
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

Depense* Utilisateur::getDepenses(unsigned int rang) const {
	return depenses_[rang];
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	unsigned int max = depenses_.size() - 1;
	for (unsigned int i = 0; i < max; i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

//void Utilisateur::ajouterDepense(Depense* depense) {
//	if (nombreDepenses_ == tailleTabDepense_) {
//		tailleTabDepense_ *= 2;
//
//		Depense** listeTemp = new Depense*[tailleTabDepense_];
//		for (unsigned int i = 0; i < nombreDepenses_; i++) {
//			listeTemp[i] = depenses_[i];
//		}
//		delete[] depenses_;
//
//		depenses_ = listeTemp;
//	}
//	depenses_[nombreDepenses_++] = depense;
//}

Utilisateur Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}

Utilisateur Utilisateur::operator=(const Utilisateur& utilisateur) {
	this->setNom(utilisateur.getNom());
	unsigned int max = this->depenses_.size();
	for (unsigned int i = 0; i < max; i++) {
		this->depenses_.pop_back();
	}
	this->depenses_ = utilisateur.depenses_;
	return *this;
}

// Methode d'affichage
Utilisateur Utilisateur::operator<<(const Utilisateur& utilisateur) {
	cout << "Utilisateur : " << nom_ << " a depense pour un total de : " << getTotalDepenses() << endl;
	cout << "\t Liste de depenses : " << endl;
	unsigned int max = this->depenses_.size();
	for (unsigned int i = 0; i < max; i++) {
		cout << "\t\t";
		cout << depenses_[i];
	}
}

//void Utilisateur::afficherUtilisateur() const {
//
//	cout << "Utilisateur : " << nom_ << " a depense pour un total de : " << getTotalDepenses() << endl;
//	cout << "\t Liste de depenses : " << endl;
//	for (int i = 0; i < nombreDepenses_; i++) {
//		cout << "\t\t";
//		depenses_[i]->afficherDepense();
//	}
//
//}
