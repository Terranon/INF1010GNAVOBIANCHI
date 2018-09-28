/******************************************************************************\
* Authors:     Serge Gnavo 1869985
*			   Maximilien Bianchi 1893352
* Name:        depense.h - TP1 INF1010
* Description: contient les primitives(public), et attributs(prive) de la classe
* Version: 1.0
\******************************************************************************/
#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>


using namespace std;


class Depense {
public:

	// constructeurs par défaut et parametres
	Depense();
	Depense(string& titre, double montant);

	// methodes d'accès
	string getTitre()const;
	double getMontant() const;

	//methodes de modifications
	void setTitre(string& titre);
	void setMontant(double montant);


	//methode d'affichage
	void afficherDepense()const;

private:
	string titre_;
	double montant_;
};
#endif

