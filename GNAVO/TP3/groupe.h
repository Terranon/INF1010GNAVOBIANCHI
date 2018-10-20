/********************************************
* Titre: Travail pratique #2 - groupe.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include "depenseGroupe.h"
#include"utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include "transfert.h"

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	virtual string getNom() const;
	virtual vector<DepenseGroupe*> getDepenses() const;
	virtual vector<Utilisateur*> getUtilisateurs() const;
	virtual vector<Transfert*> getTransferts() const;
	virtual double getTotalDepenses() const;

	// Methodes de modification
	virtual void setNom(const string& nom);

	// Methodes d'ajout
	virtual Groupe& ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour);
	virtual Groupe& operator+=(Utilisateur* utilisateur);

	// Methodes de calcul
	virtual void equilibrerComptes();
	virtual void calculerTotalDepense();

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Groupe& groupe);

private:
	string nom_;
	vector<Utilisateur*> utilisateurs_;
	vector<DepenseGroupe*> depenses_;
	vector<Transfert*> transferts_;
	double totalDepenses_;
	vector<double> comptes_;
};

#endif
