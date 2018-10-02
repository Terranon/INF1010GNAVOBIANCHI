/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifier par: Serge Gnavo
*			  : Maximilien Bianchi
*******************************************/

#include "depense.h"
#include <string>

// Constucteurs
using namespace std;
Depense::Depense() :
	nom_(""),
	montant_(0),
	lieu_(nullptr) {
}

Depense::Depense(const string& nom, double montant, const string& lieu) :
	nom_(nom),
	montant_(montant),
	lieu_(new string(lieu)) {//pour que le lieu soit une adresse 
}

Depense::Depense(const Depense& objetCopie) :
	nom_(objetCopie.nom_),
	montant_(objetCopie.montant_),
	lieu_(nullptr) {
	lieu_ = new string(objetCopie.getLieu());
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}
string Depense::getLieu() const {
	return *lieu_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}
void Depense::setLieu(const string& lieu) {
	*lieu_ = lieu;
}
Depense& Depense::operator=(const Depense & objetCopie) {
	if (this != &objetCopie) { //si l'adresse l'objet courant est different de l'adresse de l'objet copie
		delete lieu_;
		nom_ = objetCopie.nom_;
		lieu_ = new string(*(objetCopie.lieu_));
		montant_ = objetCopie.montant_;
	}
	return *this;
}

ostream& operator<<(ostream& os, const Depense& depense) {
	os << "Achat: " << depense.nom_ << " Prix " << depense.montant_ << endl;
	return os;
}
