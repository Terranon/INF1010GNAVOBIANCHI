/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurPremium.h"

// Constructeurs 
UtilisateurPremium::UtilisateurPremium(const string& nom, MethodePaiement methodePaiement,
	unsigned int joursRestants, const string& courriel, const string& idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), 
	joursRestants_(joursRestants) {
}

// Methodes d'acces
unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

// Methodes de modifications
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

// Methode d'affichage
void UtilisateurPremium::print(ostream& os) const {
	os << "- Utilisateur (premium) " << getNom() << " :" << '\n'
		<< '\t' << "Total a payer: " << getTotalATransferer()
		<< " (" << getBalance() << " economises)" << '\n'
		<< '\t' << '\t' << "Jours restants: " << getJoursRestants() << '\n';
	Utilisateur::print(os);
}