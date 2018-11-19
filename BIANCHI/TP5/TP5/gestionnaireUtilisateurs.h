/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <vector>

class GestionnaireUtilisateurs : public GestionnaireGenerique<Utilisateur*, vector<Utilisateur*>, 
	pair<Utilisateur*, double>, AjouterUtilisateur> {
public: 
	// Methodes d'access
	vector<Utilisateur*> getUtilisateurs() const;
	int getNombreUtilisateurs() const;
	Utilisateur * getUtilisateurParIndex(int i) const;
	int getIndexDe(Utilisateur* utilisateur) const;

	// Methode de modification
	GestionnaireUtilisateurs& ajouterUtilisateur(Utilisateur* utilisateur);

private:
	vector<Utilisateur*> utilisateurs_;
};