/******************************************************************************\
* Authors:     Maximilien Bianchi
* Name:        utilisateur.h
* Description:
* Version: 1.0
\******************************************************************************/
#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>

#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// constructeurs
	Utilisateur();
	Utilisateur(string& nom);

	//Destructeur
	~Utilisateur();

	//Methodes d'acc�s
	string getNom()const;
	unsigned int getNombreDepense()const;
	double getTotal()const;

	//Methode de modification
	void setNom(string& nom);

	// Methode ajout de d�pense
	void ajouterDepense(Depense* uneDepense);

	//Methode de calcul total
	void calculerTotal();

	//Methode d'affichage
	void afficherUtilisateur();

private:
	string nom_;
	unsigned int tailleTabDepense_;
	unsigned int nombreDepenses_;
	double totalDepense_;
	Depense ** listeDepenses_;


};
#endif /* utilisateur_hpp */
