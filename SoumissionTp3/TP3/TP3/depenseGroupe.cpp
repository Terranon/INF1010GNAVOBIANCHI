#include "depenseGroupe.h"

// Constructeurs
DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu) : 
	Depense(nom, montant, lieu), 
	nombreParticipants_(0) {
	setType(groupe);
}
DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense) :
	Depense(depense), 
	nombreParticipants_(depense.nombreParticipants_) {
	setType(groupe);
}

// Methodes d'acces
unsigned int DepenseGroupe::getNombreParticipants() const {
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const {
	double montantpersonnel;
	if (nombreParticipants_ == 0)
		montantpersonnel = 0;
	else
		montantpersonnel = getMontant() / nombreParticipants_;
	return montantpersonnel;
}

// Methodes de modification
void  DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}

// Surcharge
ostream& operator<<(ostream& os, DepenseGroupe* depense) {
	return os << "Depense de groupe : " << static_cast<Depense*>(depense) << " Fait par : "
		<< depense->getNombreParticipants() << " personnes soit : " 
		<< depense->getMontantPersonnel() << " par personne." << endl; 
}

