/********************************************
* Titre: Travail pratique #4 - transfertInterac.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertInterac.h"
 
//cette ligne pour inclure un utilisateur regulier

TransfertInterac::TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur)
	: Transfert(montant, expediteur, receveur)
{
	
	setcourriel(receveur->getCourriel());
	//le frais est fixe de 1 dollar
}
TransfertInterac::~TransfertInterac() {};
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
	//if (expediteur_->estRegulier())//si l'utilisateur possede un groupe
	if (dynamic_cast<UtilisateurPremium*>(getExpediteur()))
		 return 0;//return getExpediteur()->getBalance()
	else 
		return (FRAIS_TRANSFERT);
	

}