/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertPaypal.h"

TransfertPaypal::TransfertPaypal(double montant, Utilisateur * expediteur, Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur) {
	setId(expediteur->getIdPaypal());
}

TransfertPaypal::~TransfertPaypal() {};

string TransfertPaypal::getId() const {
	return id_;
}

void TransfertPaypal::setId(string id) {
	id_ = id;
}

double TransfertPaypal::getFraisTransfert() const {
	if (dynamic_cast<UtilisateurPremium*>(getExpediteur())) {
		return 0;
	}
	else {//L'utilisateur est premium
		return (getMontant()*COMMISSION + FRAIS);
	}
}