/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertPaypal.h"

// Constructeur
TransfertPaypal::TransfertPaypal(double montant, Utilisateur * expediteur, Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur) {
	setId(expediteur->getIdPaypal());
}

// Methodes d'acces
string TransfertPaypal::getId() const {
	return id_;
}

double TransfertPaypal::getFraisTransfert() const {
	double frais = 0.0;
	if (dynamic_cast<UtilisateurPremium*>(expediteur_) == nullptr) { // SI l'utilisateur n'est pas Premium, il retournera un nullptr
		frais = montant_*COMMISSION + FRAIS;
	}
	return frais;
}

// Methode de modification
void TransfertPaypal::setId(string id) {
	id_ = id;
}

