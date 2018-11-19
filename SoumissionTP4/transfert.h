/********************************************
* Titre: Travail pratique #4 - transfert.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H

#include "utilisateur.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

#include <iostream>

#include <stdio.h>

class Transfert {
public:
	// Constructeurs
	Transfert(double montant = 0.0, Utilisateur* expediteur = nullptr, Utilisateur* receveur = nullptr);

	// Methodes d'acces
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;
	virtual double getFraisTransfert()const = 0;

	// Methodes de modification
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);

	void effectuerTransfert();

	// M�thodes d'affichage
	friend ostream& operator<<(ostream& os, const Transfert& transfert);

protected:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;
};
#endif