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
	Utilisateur();
	Utilisateur(const string& nom = "", MethodePaiement methodePaiement = Interac, const string& courriel = "", const string& idPaypal= "");
	//*--je ne mets virtual qu'au methode qui pourrait etre utilise
		//par la classe fille ou qui pourrait la modifier'
	//destructeur

	
	// Methodes d'accès

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
	//les frais peuvent etre  par surchargé par utilisateur premium ou regulier
	virtual void modifierBalanceTranferts(double montant);
	virtual void modifierBalanceFrais(double montant);

	Utilisateur& operator+=(Depense* depense);
	
	// TODO--implementer la methode  print de l'utilisateur
	
	virtual void print(ostream& os) const=0;
	
	// Methode d'affichage-pas besoin de le mettre virtula car les classes dérivés ne modifieront pas cette methode
	 

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