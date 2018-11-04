/********************************************
* Titre: Travail pratique #4 - transfertInterac.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertInterac.h"

// Constructeur
TransfertInterac::TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur)
	: Transfert(montant, expediteur, receveur) {
	setCourriel(receveur->getCourriel());
}

// Methodes d'acces
string TransfertInterac::getCourriel() const {
	return courriel_;
}

double TransfertInterac::getFraisTransfert() const {
	double frais = 0.0;
	if (dynamic_cast<UtilisateurPremium*>(expediteur_) == nullptr) { // SI l'utilisateur n'est pas Premium, il retournera un nullptr
		frais = FRAIS_TRANSFERT;
	}
	return frais;
}

// Methode de modification
void TransfertInterac::setCourriel(string courriel) {
	courriel_ = courriel;
}
