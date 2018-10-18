#include "depenseGroupe.h"

// Constucteurs
DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu) :
	Depense(nom, montant, lieu),
	nombreParticipants_(0) {
	setType(groupe);
}
DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense) :
	Depense(depense),
	nombreParticipants_(0) {
	setType(groupe);
}
DepenseGroupe::DepenseGroupe(const Depense& depense) :
	Depense(depense),
	nombreParticipants_(0) {
	setType(groupe);
}

//getters 
unsigned int DepenseGroupe::getNombreParticipants() const {
	return nombreParticipants_;
}
double DepenseGroupe::getMontantPersonnel() const {
	double montantPerso;
	if (getNombreParticipants() == 0) {
		montantPerso = 0;
	}
	else {
		montantPerso = (getMontant() / getNombreParticipants());
	}
	return montantPerso;
}

//setters
void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}

//surcharge 
DepenseGroupe& DepenseGroupe::operator=(const DepenseGroupe& depense) {
	setNom(depense.getNom());
	setMontant(depense.getMontant());
	setLieu(*depense.getLieu());
	setType(groupe);
	return *this;
}

ostream& operator<<(ostream& os, const DepenseGroupe& depense) {
	return os << depense.getNom() << " une depense de groupe fait par " << depense.getNombreParticipants() << endl
		<< " personnes qui doivent " << depense.getMontantPersonnel() << " chaques, pour un total de "
		<< depense.getMontant() << endl;
}