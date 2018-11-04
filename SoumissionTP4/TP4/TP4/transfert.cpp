/********************************************
* Titre: Travail pratique #4 - transfert.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) :
	montant_(montant), 
	expediteur_(expediteur), 
	receveur_(receveur) {
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

void Transfert::effectuerTransfert() {
	expediteur_->modifierBalanceTranferts(getMontant());
	if (dynamic_cast<UtilisateurRegulier*>(expediteur_)) {
		expediteur_->modifierBalanceFrais(getFraisTransfert());
	}
	else {
		expediteur_->modifierBalanceFrais(-getMontant()*TAUX_EPARGNE);
		//on retire au receveurcar c'est un montant qu'ON Lui doit
	}
	receveur_->modifierBalanceTranferts(-getMontant());
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
ostream& operator<<(ostream& os, const Transfert& transfert) {
	return os << transfert.getExpediteur()->getNom() << "->" << transfert.getReceveur()->getNom() 
		<< ":" << transfert.getMontant() << "$" << endl;
}
