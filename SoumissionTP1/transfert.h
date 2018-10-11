/******************************************************************************\
* Authors:     Serge Gnavo 1869985
*			   Maximilien Bianchi 1893352
* Name:        transfert.h - TP1 INF1010
* Description: contient les primitives(public), et attributs(prive) de la classe
* Version: 1.0
\******************************************************************************/
#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>

#include <stdio.h>

class Transfert {
public:

	// Constructeurs
	Transfert();
	Transfert(double montant, Utilisateur* de, Utilisateur* pour);

	// Destructeur
	~Transfert();

	// Méthodes d'accès

	Utilisateur* getDonneur() const;//mettre des conste aopres 
	Utilisateur* getReceveur()const;
	double getMontant() const;


	//Méthode d'affichage
	void setDonneur(Utilisateur* donneur);
	void setMontant(double montant);
	void setReceveur(Utilisateur* receveur);

	void afficherTransfert();

private:
	double montant_;
	Utilisateur* donneur_;
	Utilisateur* receveur_;
};
#endif

