#include "pch.h"
#include "depenseGroupe.h"



DepenseGroupe::DepenseGroupe(const string& nom , double montant , const string& lieu ,const string& type) : Depense(nom , montant , lieu)//appel au constructeur de depense 
{

	nombreParticipants_ = 0;


}
DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense):Depense(depense)
{


}

unsigned int DepenseGroupe:: getNombreParticipants() const {

	return nombreParticipants_;

}


double DepenseGroupe::getMontantPersonnel() const {
	if (nombreParticipants_ == 0)
		return  0;
	else
		return (Depense::getMontant()) / nombreParticipants_;
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
	os << static_cast<Depense>(depense) << "le nombre de personnes est" << depense.nombreParticipants_ << "et le montant personnel est :" << depense.getMontant();
		return os;
		//utiliser static cast
 }//erreur redefinir montant pour depense groupe

	