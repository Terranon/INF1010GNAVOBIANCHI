#include "pch.h"//fini
#include "transfert.h"
#include "utilisateur.h"

Transfert::Transfert(){		montant_=0.0; donneur_=new Utilisateur[5]; receveur_=new Utilisateur[5];	}
//Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour):montant_(montant),donneur_ = (de),receveur_ = (pour)//{//	//}Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour){	montant_ = montant; donneur_ = de; receveur_ = pour;}//Les m�thodes d�acc�s.
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
	//pour l'utiliser il faut effectuer une surcharge d'operateur
	//cout << "le montant transfer� par " << donneur_ << "a"<< receveur_ << "est" << montant_;
	cout << "Le montant du transfert est " << montant_ << endl;
}
//Transfert::Transfert() :montant_(0.0), donneur_(new Utilisateur[3]), receveur_(new Utilisateur[3])//{////////}//Transfert::Transfert(double montant,Utilisateur* de,Utilisateur* pour)//{//	montant_=(montant); donneur_=(de); receveur_=(pour);//}