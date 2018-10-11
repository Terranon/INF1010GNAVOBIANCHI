#include "pch.h"// il reste les methodes d'acces//fini
/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "utilisateur.h"

// Constructeurs

//--to do
/*
Utilisateur::Utilisateur() {

	nom_ = "";
	interet_ = 0;
	type_ = Regulier;


}*/Utilisateur::Utilisateur(const Utilisateur& utilisateur):nom_(utilisateur.nom_),depenses_(utilisateur.depenses_),type_(utilisateur.type_)
{
	for (int i=0;i<depenses_.size();i++)
		depenses_[i] = utilisateur.depenses_[i];

}
Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type):interet_(0)
{


}
Utilisateur::~Utilisateur() {
//depenses_.clear;//retire tous les eleemenst du vecteur
	for (int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_.pop_back();//retire le dernier eleement du tableau}
	}

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

	for(unsigned int i=0;i<getNombreDepenses();i++)
	{
		return depenses_;
	
	}
	
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::calculerTotalDepenses() {
	double totalDepense = 0;
	for (unsigned int i = 0; i < getNombreDepenses(); i++)
	{
		
		totalDepense_ += depenses_[i]->getMontant();
	}
}

Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur)
{
	if (this !=  utilisateur)//on delete si ils sont < la même adresse
	{
		//L'adresse ici est celle de l'objet courant soit u1=u2 ici this est l'adresse de u1

		delete utilisateur;
		//si il sont a la meme adresse on desaaloue
		this->nom_ = utilisateur->nom_;
	this->interet_ = utilisateur->interet_;
	this->depenses_ = utilisateur->depenses_;
	this->type_ = utilisateur->type_;
	}
	
	
	return *this;//retourne l'objet pointé
}


void Utilisateur::ajouterInteret(double montant) 
{
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {

	//ajouter toujours une depense
	depenses_.push_back(depense);
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)

{
	os << "l'utilisateur"<<utilisateur.nom_<<"a un interet de"<<utilisateur.interet_<<"et une depense total de"<<utilisateur.getTotalDepenses();
	return os;
}
