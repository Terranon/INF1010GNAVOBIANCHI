/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "utilisateur.h"
#include "GestionnaireGenerique.h"
#include <vector>
#include <map>
//T est un  utilisateur* C est une map <utilisateur*,double>,D est le type de retour est une pair <Utilisateur,double.
//en fait le veritable type de retour est un double..	quand on desindexe le conteneur on obtient un double
class GestionnaireUtilisateurs:public GestionnaireGenerique <Utilisateur*,map<Utilisateur*,double>, pair<Utilisateur*, double>> {
public:
	
	vector<double>getComptes() const;
	bool estExistant(Utilisateur* payePar) const;
	void mettreAJourComptes(Utilisateur* payePar, double montant);
	pair<Utilisateur*, double>&getMax() const;
	pair<Utilisateur*, double>&getMin() const;
	Utilisateur * getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;
	vector<pair<Utilisateur*, double>>getUtilisateursEntre(double borneInf, double borneSup) const;
	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double>p);


};