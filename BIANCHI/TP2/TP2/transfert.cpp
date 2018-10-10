/********************************************
* Titre: Travail pratique #2 - transfert.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() : 
	montant_(0), 
	expediteur_(nullptr), 
	receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) :
	montant_(montant), 
	expediteur_(expediteur), 
	receveur_(receveur) {
}

Transfert::~Transfert() {
	delete expediteur_;
	expediteur_ = nullptr;
	delete receveur_;
	receveur_ = nullptr;
}

// Methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

// Methodes de modifications
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}

//Methode affichage
Transfert Transfert::operator<<(const Transfert& transfert) {
	cout << "Transfert fait par " << expediteur_->getNom() << " vers " << receveur_->getNom()
		<< " d'un montant de " << montant_ << endl;
	return *this;
}

//void Transfert::afficherTransfert() const {
//	cout << "Transfert fait par " << expediteur_->getNom() << " vers " << receveur_->getNom()
//		<< " d'un montant de " << montant_ << endl;
//}