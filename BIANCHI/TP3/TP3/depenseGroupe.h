/********************************************
* Titre: Travail pratique #3 - depenseGroupe.h
* Date premiere version : 2 octobre 2018
* Auteur: David Dratwa
*******************************************/


#ifndef DEPENSE_GROUPE_H
#define DEPENSE_GROUPE_H

#include "depense.h"
#include <vector>

using namespace std;

class DepenseGroupe : public Depense {
public:
	// Constructeur
	DepenseGroupe(const string& nom = "", double montant = 0, const string& lieu = "Montreal");
	DepenseGroupe(const DepenseGroupe& depense);
	DepenseGroupe(const Depense& depense); // Rajout de se constructeur pou faciliter le static_cast

	// Getters 
	unsigned int getNombreParticipants() const;
	double getMontantPersonnel() const;

	// Setters
	void setNombreParticipants(unsigned int nombre);

	// Surcharge 
	friend ostream& operator<<(ostream& os, const DepenseGroupe& depense);

private:
	// Les utilisateurs qui partageront la depense
	unsigned int  nombreParticipants_;
};
#endif // !DEPENSE_GROUPEE_H
