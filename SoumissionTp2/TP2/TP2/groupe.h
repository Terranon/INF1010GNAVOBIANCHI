/********************************************
* Titre: Travail pratique #2 - groupe.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifier par: Serge Gnavo
*			  : Maximilien Bianchi
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include "transfert.h"
#include <vector>

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	string getNom() const;
	unsigned int getNombreDepenses() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	Groupe& ajouterDepense(Depense* depense, Utilisateur* utilisateur);
	Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	void calculerComptes();
	void equilibrerComptes();

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Groupe& groupe_);

private:
	string nom_;
	vector < Utilisateur*>utilisateurs_;
	vector< Depense*> depenses_;
	vector<Transfert*> transferts_;
	vector <double> comptes_;
};
#endif
