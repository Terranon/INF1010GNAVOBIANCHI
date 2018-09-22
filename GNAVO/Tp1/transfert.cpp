#include "pch.h"//fini
#include "transfert.h"


Transfert::Transfert():	montant_ ( 0),donneur_ ( nullptr), receveur_ (nullptr){}Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour) : montant_(montant), donneur_(de), receveur_(pour){}//Les m�thodes d�acc�s.
Utilisateur* Transfert::getDonneur()const   // Definir utilisateur;
{
	return donneur_;

}
double Transfert::getMontant()  const
{
	return montant_;
}	

Utilisateur* Transfert::getReceveur() const
{
	return receveur_;
}



//- Les m�thodes de modification.

void Transfert::setMontant(double montant)
{
	montant_= montant;
}

void Transfert::setDonneur(Utilisateur* donneur)
//le type dans la fonction peut t'il etre un pointeur
{
	donneur_= donneur;

}


void Transfert::setReceveur(Utilisateur* receveur)
{
	receveur_ = receveur;
}
//Une m�thode d�affichage
void Transfert::afficherTransfert()
{
	
	cout <<donneur_->getNom()<<" doit donner "<< montant_ <<"$ a "  <<receveur_->getNom()<< endl;
}
