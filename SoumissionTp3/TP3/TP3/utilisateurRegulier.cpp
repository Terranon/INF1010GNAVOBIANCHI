#include "utilisateurRegulier.h"

// Constructeur
UtilisateurRegulier::UtilisateurRegulier(const string& nom) :
	Utilisateur(nom),
	estGroupe_(false) {
}
UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur) :
	Utilisateur(utilisateur), 
	estGroupe_(false) {
}

// Methodes d'acces
bool UtilisateurRegulier::estGroupe() const {
	return estGroupe_;

}

// Methodes de modification
void UtilisateurRegulier::setEtatGroupe(bool etat) {
	estGroupe_ = etat;
}

// Surcharge
UtilisateurRegulier& UtilisateurRegulier::operator=(Utilisateur* utilisateur) {
	if (this != utilisateur) {
		*this = utilisateur;
		if (utilisateur->getType() == Regulier)
			setEtatGroupe(static_cast<UtilisateurRegulier*>(utilisateur)->estGroupe());
	}
	return *this;
}

ostream& operator<< (ostream& os, UtilisateurRegulier* utilisateur) {
	return os << static_cast<Utilisateur*>(utilisateur) << endl;
}