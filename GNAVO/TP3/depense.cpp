#include "pch.h"//
/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "depense.h"

// Constucteurs
//defaut

//paramètre

Depense::Depense(const string& nom, double montant, const string& lieu) : nom_(nom),
montant_ (montant),type_(individuelle)


{

	if (lieu_ !=nullptr)
		delete lieu_;
	lieu_ = new string(lieu);
	
}

//copie

Depense::Depense(const Depense& depense):nom_(depense.nom_),montant_(depense.montant_),type_(depense.type_)
{

	if (lieu_ != nullptr)
		delete lieu_;
	lieu_ = new string(*(depense.lieu_));
	
}

Depense::~Depense()
{
	if (lieu_ != nullptr)
	{
		delete lieu_;
		lieu_ = nullptr;
	}
		
}


// Methodes d'acces
string Depense::getNom() const 
{
	return nom_;
}

double Depense::getMontant() const 
{
	return montant_;
}

string* Depense::getLieu() const
{
	return lieu_;
}

TypeDepense Depense::getType() const  
{
	return type_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& lieu)
{
	delete lieu_;
	lieu_ = new string(lieu);
}


void Depense::setType(TypeDepense type) {
	type_ = type;
}
//operator =

Depense& Depense::operator=(const Depense & depense)
{
	if (this != & depense)//this =adresse de depense
	{
		/*delete lieu_;
		this->lieu_ = new string (*depense.lieu_);
	this->nom_ = depense.nom_;
	this->montant_ = depense.montant_;
	this->type_ = depense.type_;*/
		setNom(depense.nom_);
	  setMontant(depense.montant_);
	  setLieu(*depense.lieu_);
	  setType(depense.type_);

	}
	
	return *this;
}
ostream& operator<<(ostream& os, const Depense& depense) 
{
	//return os<<"le montant est" <<depense.montant_<< " fait par" << depense.nom_ << "le type" << depense.type_<<"au lieu"<<*(depense.lieu_)<<endl;
	

	os << "le montant est" <<depense.montant_<< " fait par" << depense.nom_ << "le type" << depense.type_<<"au lieu"<<*(depense.lieu_)<<endl;
		return os;

}