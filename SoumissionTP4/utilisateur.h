/********************************************
* Titre: Travail pratique #4 - utilisateur.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

#include "depense.h"

using namespace std;

enum MethodePaiement { Paypal, Interac };

class Utilisateur {
public:
	// Constructeurs
	Utilisateur(const string& nom = "", MethodePaiement methodePaiement = Interac, const string& courriel = "", const string& idPaypal = "");

	// Methodes d'acc�s
	string getNom() const;
	vector<Depense*> getDepenses() const;
	string getCourriel() const;
	string getIdPaypal() const;
	MethodePaiement getMethodePaiement() const;
	double getTotalATransferer() const;
	double getBalance() const;

	// Methodes de modification
	void setNom(const string& nom);
	void setCourriel(const string& courriel);
	void setIdPaypal(const string idPaypal);
	void setMethodePaiement(MethodePaiement methodePaiement);
	virtual void modifierBalanceTranferts(double montant);
	virtual void modifierBalanceFrais(double montant);

	Utilisateur& operator+=(Depense* depense);

	// Methode d'affichage
	virtual void print(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Utilisateur& user);

protected:
	MethodePaiement methodePaiement_;
	string nom_;
	vector <Depense*> depenses_;
	string courriel_;
	string idPaypal_;
	double balanceFrais_;
	double balanceTransferts_;
};
#endif