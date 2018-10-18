/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense(const string& nom, double montant, const string& lieu) :
	nom_(nom),
	montant_(montant),
	lieu_(new string(lieu)),
	type_(individuelle) {
}
Depense::Depense(const Depense& depense) :
	nom_(depense.nom_),
	montant_(depense.montant_),
	lieu_(new string(*depense.getLieu())),
	type_(depense.type_) {
}

Depense::~Depense() {
	if (lieu_ != nullptr) {
		delete lieu_;
		lieu_ = nullptr;
	}
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
void Depense::setLieu(const string& lieu) {
	delete lieu_;
	lieu_ = new string(lieu);
}
void Depense::setType(TypeDepense type) {
	type_ = type;
}

//operateurs
Depense& Depense::operator=(const Depense& depense) {
	if (this != &depense) {
		setNom(depense.getNom());
		setMontant(depense.getMontant());
		setLieu(*depense.getLieu());
		setType(depense.getType());
		return *this;
	}
}

// Affichage
ostream& operator<<(ostream& os, const Depense& depense) {
	return os << depense.getNom() << " une depense de type " << depense.getType()
		<< " et de montant " << depense.getMontant() << "$ fait a " << depense.getLieu() << endl;
}