#include "pch.h"
#include "depenseGroupe.h"



DepenseGroupe::DepenseGroupe(const string& nom , double montant , const string& lieu ): Depense(nom , montant , lieu),nombreParticipants_( 0)
//appel au constructeur de depense 
{

	setType(groupe);
	
}
DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense):Depense(depense)
{
	/*setNom(depense.getNom());
	setMontant(depense.getMontant());*/
    setType(groupe);
}

unsigned int DepenseGroupe:: getNombreParticipants() const {

	return nombreParticipants_;

}


double DepenseGroupe::getMontantPersonnel() const {
	double montantpersonnel;
	/*if (nombreParticipants_ == 0)
		return   nombreParticipants_;
	else
		return getMontant() / nombreParticipants_;
		*/
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


//surcharge 
//surcharge fonction type de retour nomvariable(parametre)
//methode rtretour nomclasse::nomvaribale(parametre)
ostream& operator<<(ostream& os, const DepenseGroupe& depense)
{
	os << static_cast<Depense>(depense) << "le nombre de personnes est" << depense.nombreParticipants_ << "et le montant personnel est :" << depense.getMontantPersonnel();
		return os;
		//utiliser static cast
 }//erreur redefinir montant pour depense groupe

	