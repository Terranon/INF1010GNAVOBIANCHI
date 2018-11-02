/********************************************
* Titre: Travail pratique #4 - transfertPaypal.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#pragma once

const double COMMISSION = 0.026;
const double FRAIS = 0.30;

#include "transfert.h"
#include "utilisateurPremium.h"


class TransfertPaypal : public Transfert {
public:
	// Constructeur
	// TODO: a modifier
	TransfertPaypal(double montant, Utilisateur* expediteur , Utilisateur* receveur) ;
	//destructeur
	~TransfertPaypal() ;
	string getId() const;
	void setId(string id);

	// TODO--PAS CONSTANT CAR MODIFICATION  A L'INTERIEUR DE L'OBJET// il retourne une copie de l'objet de leur classe de base modifié et non la leur
	virtual double getFraisTransfert()const ;

private:
	string id_;
};