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
	Utilisateu

}*/
//Utilisateur::Utilisateur() {
//
//
//	nom_ = "";
//	type_ = Regulier;
//
//}
Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type):nom_(nom),interet_(0),type_(type)
{
	

}

Utilisateur::Utilisateur(const Utilisateur& utilisateur):nom_(utilisateur.nom_),depenses_(utilisateur.depenses_),type_(utilisateur.type_),interet_(utilisateur.interet_)
{
	 //tableau de vecteur...
	/*for (unsigned int i = 0; i < depenses_.size(); i++)
	{
		delete depenses_[i];
		depenses_.pop_back();
	
	}*/ //pare que on
	//crrer un vouvel objet utilisateur 
	//et l'objet doit necessairement etre vide

	for (unsigned int i = 0; i < utilisateur.depenses_.size(); i++)
	{

		depenses_.push_back(new Depense(*utilisateur.depenses_[i]));//pour tuer le shallow copy
	}
		


	/*for (unsigned int i=0;i<depenses_.size();i++)
		depenses_[i] = new Depense(utilisateur.depenses_[i]->getMontant());
*/
}

Utilisateur::~Utilisateur() {
//depenses_.clear;//retire tous les eleemenst du vecteur
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_ [i] = 0;
		depenses_.pop_back();//retire le dernier eleement du tableau}
	}
	depenses_.shrink_to_fit();//pour mettre le tableau a la taille et la size a 0
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

//Methodes de modification
void Utilisateur::setInteret(const double& interet) {
	interet_ = interet;

}void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}


void Utilisateur::setType(TypeUtilisateur type) {

	type_ = type;

}

void Utilisateur::calculerTotalDepenses() {
	double totalDepense = 0;
	for (unsigned int i = 0; i < getNombreDepenses(); i++)
	{
		
		totalDepense_ += depenses_[i]->getMontant();
	}
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
Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur)
{
	if (this !=  utilisateur)//on delete si ils sont < la même adresse
	{
		//L'adresse ici est celle de l'objet courant soit u1=u2 ici this est l'adresse de u1

		//delete utilisateur;
		setInteret(utilisateur->getInteret());
		//si il sont a la meme adresse on desaaloue
		this->nom_ = utilisateur->nom_;
		this->interet_ = utilisateur->interet_;
		this->depenses_ = utilisateur->depenses_;//faire une deep copy
		this->type_ = utilisateur->type_;
		calculerTotalDepenses();
	}
	
	
	return *this;//retourne l'objet pointé
}




// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)

{
	os << "l'utilisateur"<<utilisateur.nom_<<"a un interet de"<<utilisateur.interet_<<"et une depense total de"<<utilisateur.getTotalDepenses();
	return os;
}
