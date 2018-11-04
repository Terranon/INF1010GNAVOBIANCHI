/********************************************
* Titre: Travail pratique #4 - tranfertInterac.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/
#pragma once

#include "transfert.h"
#include "utilisateurPremium.h"

const double FRAIS_TRANSFERT = 1.0;

class TransfertInterac : public Transfert {
public:
	// Constructeur
	TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur);

	// Methodes d'acces
	string getCourriel() const;
	virtual double getFraisTransfert() const;

	// Methode de modification
	void setCourriel(string courriel);

private:
	string courriel_;
};