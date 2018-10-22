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
	unsigned int nombreDepenses = getNombreDepenses();
	if (taux_ != 0) {
		taux_ = TAUX_REGULIER;
		if (taux_ <= 0) {
			taux_ = 0;
		}
		else {
			taux_ -= (0.01)*(nombreDepenses / 2);
		}
	}
}
// Operateurs
UtilisateurPremium& UtilisateurPremium::operator= (Utilisateur* utilisateur) {
	if (this != utilisateur) {
		*this = utilisateur;
		if (utilisateur->getType() == Premium) {
			setJoursRestants(static_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants());
			setTaux(static_cast<UtilisateurPremium*>(utilisateur)->getTaux());
		}
	}
	return *this;
}

ostream& operator << (ostream& os, UtilisateurPremium* utilisateur) {
	os << static_cast<Utilisateur*>(utilisateur) << "(Taux final de : " 
		<< (utilisateur->getTaux()*100) << "% | Nombre de jours Premium restant : " 
		<< utilisateur->joursRestants_ << ")" << endl;
	return os;
}