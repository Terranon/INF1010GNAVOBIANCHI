/********************************************
* Titre: Travail pratique #2 - transfert.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifier par: Serge Gnavo
*			  : Maximilien Bianchi
*******************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H

#include "utilisateur.h"
#include <iostream>
#include <stdio.h>

class Transfert {
public:

	// Constructeurs
	Transfert();
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	// Destructeur
	~Transfert();

	// Methodes d'acces
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;

	// Methodes de modification
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);

	// Methodes d'affichage
	friend ostream& operator<<(ostream& os, const Transfert& transfert);

private:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;
};
#endif