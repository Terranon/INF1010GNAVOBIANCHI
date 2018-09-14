/******************************************************************************\
* Authors:     Maximilien Bianchi
* Name:        depense.h
* Description:
* Version: 1.0
\******************************************************************************/
#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>


using namespace std;


class Depense {
public:

	// constructeurs par d�faut et parametres
	Depense();
	Depense(string& titre, double montant);

	// methodes d'acc�s
	string getTitre();
	double getMontant();

	//methodes de modifications
	void setTitre(string& titre);
	void setMontant(double montant);


	//methode d'affichage
	void afficherDepense();

private:
	string titre_;
	double montant_;

};

#endif
