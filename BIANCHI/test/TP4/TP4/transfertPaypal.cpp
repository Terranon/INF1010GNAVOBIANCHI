/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertPaypal.h"
//#include "utilisateurRegulier.h"// car on a utiliser dynamic cast
TransfertPaypal::TransfertPaypal(double montant, Utilisateur * expediteur, Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur)
{
	setId(expediteur->getIdPaypal());

}
TransfertPaypal::~TransfertPaypal() {};

string TransfertPaypal::getId() const
{
	return id_;
}

void TransfertPaypal::setId(string id)
{
	id_ = id;
}

/*
*/
double TransfertPaypal::getFraisTransfert() const {
	//pour rentrer dans cette méthode il faut avoir effectué un transfert ééun utilisateur regulier aura toujours sa balance qui aura
	//augmenter 
	//dynamic_cast<UtilisateurRegulier*>(getExpediteur());
	//if (expediteur_->estRegulier())//si l'utilisateur possede un groupe,il s'agit d'un utilisateur régulier
	if (dynamic_cast<UtilisateurPremium*>(getExpediteur())) //si le cast reussi il est regulier
															//	return getExpediteur()->getBalance();
		return 0;
	//que retourner si c'est pas un utilisateur regulier ses frais veritables??
	else //L'utilisateur est premium
		return (getMontant()*COMMISSION + FRAIS);


}