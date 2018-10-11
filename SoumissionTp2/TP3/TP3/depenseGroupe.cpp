#include "depenseGroupe.h"

// Constucteurs
DepenseGroupe::DepenseGroupe() :
	Depense("",0,"Montreal"),
	nombreParticipants_(0) {
	setType(groupe);
}
DepenseGroupe::DepenseGroupe(const string& nom = "", double montant = 0, const string& lieu = "Montreal") :
	Depense(nom, montant, lieu),
	nombreParticipants_(0) {
	setType(groupe);
}
DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense) :
	Depense(depense),
	nombreParticipants_(0) {
}

//getters 
unsigned int DepenseGroupe::getNombreParticipants() const {
	return nombreParticipants_;
}
double DepenseGroupe::getMontantPersonnel() const {
	double montantPerso = (getMontant() / getNombreParticipants());
	return montantPerso;
}

//setters
void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}

//surcharge 
ostream& operator<<(ostream& os, const DepenseGroupe& depense) {
	return os << depense.getNom() << " une depense de groupe fait par " << depense.getNombreParticipants() << endl
		<< " personnes qui doivent " << depense.getMontantPersonnel() << " chaques, pour un total de "
		<< depense.getMontant() << endl;
}