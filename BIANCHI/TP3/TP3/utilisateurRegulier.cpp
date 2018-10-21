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
bool UtilisateurRegulier::estGroupe() const {
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
		if (utilisateur->getType() == Regulier) {
			setEtatGroupe(static_cast<UtilisateurRegulier*>(utilisateur)->estGroupe());
		}
		else {
			setEtatGroupe(false);
		}
	}
	return *this;
}
ostream& operator<<(ostream& os, const UtilisateurRegulier& utilisateur) {
	if (utilisateur.estGroupe()) {
		os << "Membre d'un groupe, ";
	}
	else {
		os << "Non-membre d'un groupe, ";
	}
	os << utilisateur;
	return os;
}