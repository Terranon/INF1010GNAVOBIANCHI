/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
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
	// TODO: Ajouter un constructeur par copie
	Utilisateur(const Utilisateur& objetCopie);
	// Destructeur
	~Utilisateur();

	// Methodes d'acc?s
	string getNom() const;
	unsigned int getNombreDepense() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);

	// TODO: Ajouter un operateur += et =
	void ajouterDepense(Depense* uneDepense);
	//ajouter utilisateur
	 Utilisateur& operator+=(Depense* depense);
	 Utilisateur& operator=(const Utilisateur& utilisateur);
	// TODO: Remplacer par une surcharge de l'operateur <<
	//void afficherUtilisateur() const;
	 friend ostream& operator<<(ostream& os,const Utilisateur& utilisateur);

private:
	string nom_;
	// TODO: Remplacer depenses_ par un vecteur
	//unsigned int tailleTabDepense_; 
	//a supprimer la taille est donner par un vector.size
	//unsigned int nombreDepenses_;
	//Depense ** depenses_; comment supprimer les anciennes
	vector <Depense*> depenses_;

};
#endif