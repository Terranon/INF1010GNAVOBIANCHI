#include "pch.h"// il reste les methodes d'acces//fini
/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_("")
{
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom){
}

Utilisateur::Utilisateur(const Utilisateur& objetCopie)
	
{
	if (this!=&objetCopie)

	{
		//delete depenses_;
		for (int i = 0; i < depenses_.size();i++)
		depenses_ [i]= new Depense(*(objetCopie.depenses_[i]));

     
	}

}
//Destructeur
Utilisateur::~Utilisateur() {
	for (int i = 0; i < depenses_.size(); i++)
	{
		delete depenses_[i]; depenses_[i] = nullptr;
	}
	
	// delete depenses_;
	//depenses_ = nullptr;
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
	for (int i = 0; i < depenses_.size(); i++) {
		
		total += depenses_[i]->getMontant();
	}
	return total;
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}
//
//void Utilisateur::ajouterDepense(Depense* depense) 
//{
//	
//		
//	
//}
Utilisateur& Utilisateur::operator+=(Depense* depense)
{

	//ajoute une depense a l.utilisateur

	//initialisons depense sinon message dèrreur
	//depense = new Depense();//dans le m
	//ain on utilisera un pointeur initialiser sur une depenses
    depenses_.push_back(depense);

	return *this;
 }

Utilisateur& Utilisateur::operator=(const Utilisateur& utilisateur)
{
	if (this != &utilisateur) {

		for (int i=0; i < depenses_.size(); i++)
			delete depenses_[i];
		//delete[] depenses_;//impossible car depenses est un tableau automatique de pointeur depenses* c'est un peu comme si on veut delete int car on a vector <int*>int
		nom_ = utilisateur.nom_;
		for (int i=0; i < depenses_.size(); i++)
			depenses_.push_back(utilisateur.depenses_[i]);//ajoute au tableau(depenses_) des pointeur de depenses

	}
	//ajoute une depense a l.utilisateur
	//verifions que l'adresse est differente d'abord n'est pas necessaire
	return *this;
}

// Methode d'affichage
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

 ostream& operator<<(ostream os, const Utilisateur& utilisateur)

{
	 os << "Utilisateur :" << utilisateur.getNom() << " a depense pour un total de: " << utilisateur.getTotalDepenses() << endl;
	 os<<"\t Liste de depenses : " << endl;
		 	for (int i = 0; i < utilisateur.depenses_.size(); i++) {
				os << "\t\t" << utilisateur.depenses_[i]<<endl;//vu que l'operateur a ete defini 
				//pour depense il l'affichera bien
	}
			return os;
}