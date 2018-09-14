#include "pch.h"//fini
#include "transfert.h"
#include "utilisateur.h"

Transfert::Transfert(){	montant_ = 0;	donneur_ = new Utilisateur [1];	receveur_ = new Utilisateur[1];}
//Un constructeur par d�faut qui initialise les attributs aux valeurs par d�faut.//Transfert::Transfert()
//{
//	montant_ = 0;
//	donneur_ = nullptr;
//	receveur_ = nullptr;//}//Un constructeur par param�tres qui initialise les attributs aux valeurs correspondantes.Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour){	montant_ = montant;	donneur_ = de;	receveur_ = pour;}//Les m�thodes d�acc�s.
Utilisateur* Transfert::getDonneur()const // Definir utilisateur;
{
	return donneur_;
}
Utilisateur* Transfert::getReceveur()const
{
	return receveur_;


}
double Transfert::getMontant()const
{
	return montant_;
}


//- Les m�thodes de modification.

void Transfert::setDonneur(Utilisateur* donneur)
//le type dans la fonction peut t'il etre un pointeur
{
	donneur_ = donneur;

}

void Transfert::setMontant(double montant)
{
	montant_ = montant;
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
	cout << "Le montant du transfert est" << montant_ << endl;
}
