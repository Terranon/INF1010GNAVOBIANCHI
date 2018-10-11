#include "pch.h"//fini
#include "depense.h"

//Constructeur par defaut depense
Depense::Depense():titre_ ( "unknown"),montant_ (0)
{
		
	
}

//Constructeur par parametre

Depense::Depense(string &titre,double montant):titre_(titre), montant_(montant)

{
	
}


double Depense::getMontant() const
{
	return montant_; 

}
string Depense::getTitre() const 
{
	return titre_;



}
//methodes de modifications

void Depense::setMontant(double montant)

{
	montant_ = montant;
}
void Depense::setTitre(string& titre)

{
	titre_ = titre;

}

// methode d'affichage  
void Depense::afficherDepense() const {
	cout << " La depense effectue est :" << montant_ << "$ pour" << titre_ << endl;
	

}