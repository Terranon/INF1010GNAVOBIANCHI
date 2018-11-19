/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurPremium.h"


UtilisateurPremium::UtilisateurPremium(const string& nom, MethodePaiement methodePaiement,
	unsigned int joursRestants, const string& courriel, const string& idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), 
	joursRestants_(joursRestants) {
}

UtilisateurPremium::~UtilisateurPremium() {}

unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

void UtilisateurPremium::print(ostream& os) const {
	double economie = 0;
	economie = balanceFrais_;
	if (getTotalATransferer() > 0)
		economie = TAUX_EPARGNE * getTotalATransferer();
	os << "\t- Utilisateur (premium) " << getNom() << " :" << endl 
		<< "\t\tTotal a payer: " << getTotalATransferer() << " (" << economie << "$ economises)" << endl 
		<< "\t\tJours restants: " << getJoursRestants() << endl;
	Utilisateur::print(os);
}