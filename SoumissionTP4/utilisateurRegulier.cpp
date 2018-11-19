/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom, MethodePaiement methodePaiement, 
	const string & courriel, const string & idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), 
	possedeGroupe_(false) {
}

UtilisateurRegulier::~UtilisateurRegulier() {}

bool UtilisateurRegulier::getPossedeGroupe() const {
	return possedeGroupe_;
}

void UtilisateurRegulier::setPossedeGroupe(bool possedeGroupe) {
	possedeGroupe_ = possedeGroupe;
}

void UtilisateurRegulier::print(ostream& os) const {
	if (getPossedeGroupe()) {
		os << "\t- Utilisateur(regulier, dans un groupe) " << getNom() << " :" << endl
			<< "\t\tTotal a payer: " << getTotalATransferer() << " (" << getBalance() << "$ de frais)" << endl;
		Utilisateur::print(os);
	}
	else {
		os << "\t- Utilisateur(regulier dans aucun groupe) " << getNom() << " :" << endl;
	}
}