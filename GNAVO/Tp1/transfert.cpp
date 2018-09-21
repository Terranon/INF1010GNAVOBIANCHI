#include "pch.h"//fini
#include "transfert.h"


//Transfert::Transfert()//{//	montant_=0; //	donneur_=new Utilisateur[5];//si on le met a nullptr CA MARCHE PAS CAR IL DOIT ETRE UN TABLEAU//	//	receveur_=new Utilisateur[5];//	//}
Transfert::Transfert(){	montant_ = 0;	donneur_ = nullptr; 	receveur_ = nullptr;}//Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour):montant_(montant),donneur_ = (de),receveur_ = (pour)//{//	//}Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour){	montant_ = montant; 	donneur_ = de;	receveur_ = pour;}//Les méthodes d’accès.
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



//- Les méthodes de modification.

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
//Une méthode d’affichage
void Transfert::afficherTransfert()
{
	//pour l'utiliser il faut effectuer une surcharge d'operateur
	//cout << "le montant transferé par " << donneur_ << "a"<< receveur_ << "est" << montant_;
	cout <<donneur_->getNom()<<" doit donner "<< montant_ <<"$ a "  <<receveur_->getNom()<< endl;
}
