/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	// TODO: Ajouter l'attribut objet dans les constructeurs
	Depense();
	Depense(const string& nom, double montant, string* lieu);

	// TODO: Ajouter un constructeur par copie
	Depense(Depense& depense);

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string* getLieu();

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(string* lieu);

	// TODO: Ajouter une surcharge de l'operateur =
	Depense operator=(Depense& depense);

	// TODO: Remplacer par une surcharge de l'operateur <<
	void operator<<(Depense& depense);

	//void afficherDepense() const;

private:
	string nom_;
	double montant_;
	string* lieu_;
};
#endif