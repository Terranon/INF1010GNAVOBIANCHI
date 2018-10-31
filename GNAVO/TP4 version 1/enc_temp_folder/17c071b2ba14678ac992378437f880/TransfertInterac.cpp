/********************************************
* Titre: Travail pratique #4 - transfertInterac.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertInterac.h"


TransfertInterac::TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur)
	: Transfert(montant, expediteur, receveur)
{
	setcourriel("yves@polymtl.ca");

	expediteur->modifierBalanceFrais(FRAIS_TRANSFERT);//le frais est fixe de 1 dollar
}

string TransfertInterac::getCourriel() const
{
	return courriel_;
}

void TransfertInterac::setcourriel(string courriel)
{
	courriel_ = courriel;
}

double TransfertInterac::getFraisTransfert() const
{
	//pour rentrer dans cette méthode il faut avoir effectué un transfert ééun utilisateur regulier aura toujours sa balance qui aura
	//augmenter 
	
		return getExpediteur()->getBalance();

}