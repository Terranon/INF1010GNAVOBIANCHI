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
	// TODO: --ajout de parametre par defaut 

	TransfertInterac(double montant = 0, Utilisateur* expediteur = nullptr, Utilisateur* receveur = nullptr);
	//destructeur
	~TransfertInterac();
	string getCourriel() const;
	void setcourriel(string courriel);

	// TODO--
	//quand je met un const cette ligne de code n'est jamais executer
	virtual double getFraisTransfert()const;
private:
	string courriel_;
};