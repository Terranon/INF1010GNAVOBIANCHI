/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifier par: Serge Gnavo
*			  : Maximilien Bianchi
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom);
	Utilisateur(const Utilisateur& objetCopie);

	// Destructeur
	~Utilisateur();

	// Methodes d'acc?s
	string getNom() const;
	unsigned int getNombreDepense() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Surchage d'operateur
	Utilisateur& operator+=(Depense* depense);
	Utilisateur& operator=(const Utilisateur& utilisateur);

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Utilisateur& utilisateur);

private:
	string nom_;
	vector <Depense*> depenses_;
};
#endif