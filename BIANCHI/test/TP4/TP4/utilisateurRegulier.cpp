/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom, MethodePaiement methodePaiement, const string & courriel, const string & idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), possedeGroupe_(false)
{}

UtilisateurRegulier::~UtilisateurRegulier() {};

bool UtilisateurRegulier::getPossedeGroupe() const {
	return possedeGroupe_;
}

void UtilisateurRegulier::setPossedeGroupe(bool possedeGroupe) {
	possedeGroupe_ = possedeGroupe;
}

//on veut juste modifier la fonction  printf
// c'est logique vu qu'elle contilent des methodes a afficher que l'utilisateur n'a pas.
void UtilisateurRegulier::print(ostream& os) const {

	if (getPossedeGroupe()) {
		os << "Utilisateur(regulier dans un groupe)" << getNom() << ":" << endl << "Total  a payer:" << getTotalATransferer() << "(" << getBalance() << " de frais)" << endl << "-Depenses:" << endl;
		for (size_t i = 0; i < depenses_.size(); i++)
			os << *depenses_[i];
	}
	else
		os << "Utilisateur(regulier dans aucun groupe)" << getNom() << ":" << endl;




}