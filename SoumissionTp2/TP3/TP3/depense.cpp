/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense(const string& nom = "", double montant = 0, const string& lieu = "Montreal") :
	type_(individuelle) {
}
Depense::Depense(const Depense& depense) {
	*this = depense;
}

Depense::~Depense() {
	if (lieu_ != nullptr)
		delete lieu_;
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}
double Depense::getMontant() const {
	return montant_;
}
string* Depense::getLieu() const {
	return lieu_;
}
TypeDepense Depense::getType() const {
	return type_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}
void Depense::setMontant(double montant) {
	montant_ = montant;
}
void Depense::setLieu(const string& nom) {
	delete lieu_;
	lieu_ = new string(nom);
}
void Depense::setType(TypeDepense type) {
	type_ = type;
}

//operateurs
Depense& Depense::operator=(const Depense & depense) {
	nom_ = depense.getNom();
	montant_ = depense.getMontant();
	lieu_ = depense.getLieu();
	type_ = depense.getType();
}

// Affichage
ostream& operator<<(ostream& os, const Depense& depense) {
	return os << depense.getNom() << " une depense de type " << depense.getType()
		<< " et de montant " << depense.getMontant() << "$ fait a " << depense.getLieu() << endl;
}