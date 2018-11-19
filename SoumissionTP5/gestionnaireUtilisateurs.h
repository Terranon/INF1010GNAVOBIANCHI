/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "utilisateur.h"
#include "GestionnaireGenerique.h"
#include <vector>
#include <map>

class GestionnaireUtilisateurs: public GestionnaireGenerique <Utilisateur*,map<Utilisateur*,double>, 
	pair<Utilisateur*, double>, AjouterUtilisateur> {
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