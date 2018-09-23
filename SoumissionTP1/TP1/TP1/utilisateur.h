/******************************************************************************\
* Authors:     Serge Gnavo 1869985
*			   Maximilien Bianchi 1893352
* Name:        utilisateur.h - TP1 INF1010
* Description: contient les constantes(global), primitives(public), 
*			   et attributs(prive) de la classe
* Version: 1.0
\******************************************************************************/
#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>

#include "depense.h"

using namespace std;

static const unsigned int TAILLEDEPENSEINITIALE = 5;

class Utilisateur {
public:
	// constructeurs
	Utilisateur();
	Utilisateur(string& nom);

	//Destructeur
	~Utilisateur();

	//Methodes d'accès
	string getNom()const;
	unsigned int getNombreDepense()const;
	double getTotal()const;

	//Methode de modification
	void setNom(string& nom);

	// Methode ajout de dépense
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
#endif





