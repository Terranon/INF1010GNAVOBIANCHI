/********************************************
* Titre: Travail pratique #3 - depense.h
* Date premiere version : 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>



using namespace std;

enum TypeDepense { groupe, individuelle };

class Depense {
public:
	// Constructeurs
	
	Depense(const string& nom = "", double montant = 0, const string& lieu = "Montreal");
	Depense(const Depense& depense);

	// Destructeur 
	~Depense();

	// Methodes d'acces
	virtual string getNom() const;
	virtual double getMontant() const;
	virtual string* getLieu() const;
	virtual TypeDepense getType() const;

	// Methodes de modifications
	virtual void setNom(const string& nom);
	virtual void setMontant(double montant);
	virtual void setLieu(const string& lieu);
	virtual void setType(TypeDepense type);

	//operateurs
	Depense& operator=(const Depense& depense);

	// Affichage
	friend ostream& operator<<(ostream& os, Depense* depense);
private:
	string nom_;
	double montant_;
	string* lieu_;
	TypeDepense type_;

};
#endif