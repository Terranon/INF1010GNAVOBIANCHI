/********************************************
* Titre: Travail pratique #4 - depense.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	// TODO --ajout du constructeur par copie et implementation du constructeur par param�tre
	Depense(const string& nom = "", double montant = 0 , const string& lieu = "Montreal");
	Depense(const Depense & depense) ;
	//destructeur
	~Depense();
	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string* getLieu() const;

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);

	//op�rateur d'affectation

	 Depense& operator=(const Depense& depense);
	// Affichage

	friend ostream& operator<<(ostream& os, const Depense& depense);
private:
	string nom_;
	double montant_;
	string* lieu_;

};
#endif