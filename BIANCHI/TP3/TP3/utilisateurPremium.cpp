#include "utilisateurPremium.h"

// Constructeurs 
UtilisateurPremium::UtilisateurPremium(const string& nom) :
	Utilisateur(nom),
	joursRestants_(30),
	taux_(TAUX_REGULIER) {
	setType(Premium);
}
UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur) :
	Utilisateur(utilisateur) {
	if (utilisateur.getType() == Premium) {
		setJoursRestants(static_cast<UtilisateurPremium>(utilisateur).getJoursRestants());
		setTaux(static_cast<UtilisateurPremium>(utilisateur).getTaux());
	}
	else {
		setJoursRestants(30);
		setTaux(TAUX_REGULIER);
	}
	setType(Premium);
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
void UtilisateurPremium::setTaux(double taux) {
	taux_ = taux;
}

// Methode de calcul 
void UtilisateurPremium::calculerTaux() {
	if (taux_ != 0.00) {
		taux_ = TAUX_REGULIER; // on remet le taux a 5% parce que on ne sait pas si nous avons rajouter des depenses depuis le dernier calcul
		unsigned int nombreDeDepenses = getNombreDepenses();
		taux_ = taux_ - (nombreDeDepenses / 2)*(0.01);
		if (taux_ < 0.00) {
			taux_ = 0.00;
		}
	}
}

// Operateurs
UtilisateurPremium& UtilisateurPremium::operator=(Utilisateur* utilisateur) {
	if (this != utilisateur) {
		*this = utilisateur;
		if (utilisateur->getType() == Premium) {
			setJoursRestants(static_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants());
			setTaux(static_cast<UtilisateurPremium*>(utilisateur)->getTaux());
		}
	}
	return *this;
}


ostream& operator<<(ostream& os, const UtilisateurPremium& utilisateur) {
	return os << "Membre Premium pour encore "
		<< utilisateur.getJoursRestants() << " jours, a un taux d'interet de "
		<< utilisateur.getTaux() << endl << utilisateur;
}