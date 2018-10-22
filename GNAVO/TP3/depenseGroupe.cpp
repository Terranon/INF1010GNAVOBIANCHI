#include "pch.h"
#include "depenseGroupe.h"



DepenseGroupe::DepenseGroupe(const string& nom , double montant , const string& lieu ): Depense(nom , montant , lieu),nombreParticipants_( 0)
//appel au constructeur de depense 
{

	setType(groupe);
	
}
DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense):Depense(depense),nombreParticipants_(depense.nombreParticipants_)
{
    setType(groupe);
}

unsigned int DepenseGroupe:: getNombreParticipants() const {

	return nombreParticipants_;

}


double DepenseGroupe::getMontantPersonnel() const {
	double montantpersonnel;
	
	if (nombreParticipants_ == 0)
		montantpersonnel = 0;
	else
		montantpersonnel=getMontant() / nombreParticipants_;
	return montantpersonnel;
}

//setters
void  DepenseGroupe::setNombreParticipants(unsigned int nombre)
{
	nombreParticipants_ = nombre;
}



ostream& operator<<(ostream& os, DepenseGroupe* depense)
{
	
	os <<"Depense de groupe: "<< static_cast<Depense*>(depense) << " le nombre de participants est de " << depense->getNombreParticipants()<< " et le montant par personne est : " << depense->getMontantPersonnel();
		return os;
		
 }

	