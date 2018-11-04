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
	TransfertPaypal(double montant, Utilisateur* expediteur, Utilisateur* receveur);

	// Methodes d'acces
	string getId() const;
	double getFraisTransfert() const;

	// Methode de modification
	void setId(string id);

private:
	string id_;
};