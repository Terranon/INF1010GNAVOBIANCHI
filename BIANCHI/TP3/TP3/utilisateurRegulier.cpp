#include "utilisateurRegulier.h"

// Constructeurs
UtilisateurRegulier::UtilisateurRegulier(const string& nom = "") : 
	Utilisateur(nom),
	estGroupe_(false) {
}
UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur) :
	Utilisateur(utilisateur),
	estGroupe_(false) {
}

// Getters
bool UtilisateurRegulier::getEstGroupe() const {
	return estGroupe_;
}

// Setters
void UtilisateurRegulier::setEtatGroupe(bool etat) {
	estGroupe_ = etat;
}

// Surcharge
UtilisateurRegulier& UtilisateurRegulier::operator=(Utilisateur* utilisateur) {
	if (this != utilisateur) {
		*this = utilisateur;
		setEtatGroupe(false);
	}
	return *this;
}
ostream& operator<<(ostream& os, const UtilisateurRegulier& utilisateur) {
	if (utilisateur.getEstGroupe()) {
		os << "Membre d'un groupe, ";
	}
	else {
		os << "Non-membre d'un groupe, ";
	}
	os << utilisateur;
	return os;
}