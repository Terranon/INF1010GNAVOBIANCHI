/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : 
	nom_(""), 
	montant_(0) {
}

Depense::Depense(const string& nom, double montant, string* lieu) :
	nom_(nom), 
	montant_(montant),
	lieu_(lieu) {
}

Depense::Depense(Depense& depense) :
	nom_(depense.getNom()),
	montant_(depense.getMontant()),
	lieu_(depense.getLieu()) {
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string* Depense::getLieu() {
	return lieu_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(string* lieu) {
	lieu_ = lieu;
}

// TODO: Ajouter une surcharge de l'operateur =
Depense Depense::operator=(Depense& depense) {
	this->setNom(depense.getNom());
	this->setMontant(depense.getMontant());
	this->setLieu(depense.getLieu());
	return *this;
}

// Methode d'affichage
void Depense::operator<<(Depense& depense) {
	cout << "Achat : " << depense.getNom() << " Prix : " << depense.getMontant() << 
		"Lieu : " << *depense.getLieu() << endl;
}

//void Depense::afficherDepense() const {
//	cout << "Achat : " << nom_ << " Prix : " << montant_ << "; " << endl;
//}
