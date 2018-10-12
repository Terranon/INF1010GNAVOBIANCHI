#include "utilisateurPremium.h"

// Constructeurs 
UtilisateurPremium::UtilisateurPremium(const string& nom = "") :
	Utilisateur(nom),
	joursRestants_(30),
	taux_(0.05) {
}
UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur) :
	Utilisateur(utilisateur),
	joursRestants_(30),
	taux_(0.05) {
}

// Getters
unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}
double UtilisateurPremium::getTaux() const {
	return taux_;
}

// Setters 
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

// Methode de calcul 
void UtilisateurPremium::calculerTaux() {
	double nombreDeDepenses = getNombreDepenses();
	double nouveauTaux = taux_;
	for (unsigned int i = 0; i < getNombreDepenses(); i+=2) {
		nombreDeDepenses - 2;
		if (nombreDeDepenses < 0) {
			i = getNombreDepenses();
		}
		else {
			nouveauTaux - 0.01;
		}
	}
	if (nouveauTaux < 0.01) {
		taux_ = 0.01;
	}
	else {
		taux_ = nouveauTaux;
	}
}

// Operateurs
UtilisateurPremium& UtilisateurPremium::operator=(Utilisateur* utilisateur) {
	*this = utilisateur;
	joursRestants_ = 30;
	taux_ = 0.05;
}


ostream& operator<<(ostream& os, const UtilisateurPremium& utilisateur) {
	return os << "Membre Premium pour encore "
		<< utilisateur.getJoursRestants() << " jours, a un taux d'interet de "
		<< utilisateur.getTaux() << endl << utilisateur;
}