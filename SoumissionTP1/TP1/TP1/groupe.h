/******************************************************************************\
* Authors:     Serge Gnavo 1869985
*			   Maximilien Bianchi 1893352
* Name:        groupe.h - TP1 INF1010
* Description: contient les constantes(global), primitives(public),
*			   et attributs(prive) de la classe
* Version: 1.0
\******************************************************************************/
#ifndef GROUPE_H
#define GROUPE_H

#include "transfert.h"
#include <string>
using namespace std;

static const unsigned int TAILLEUTILISATEURGROUPE = 5;
static const unsigned int TAILLEDEPENSEGROUPE = 10;

class Groupe {
public:
	//Constructeurs
	Groupe();
	Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs);

	//Destructeur
	~Groupe();

	//methode d'acces
	string getNom()const;
	unsigned int getNombreDepenses()const;
	double getTotal()const;

	//Methodes de modification
	void setNom(string& nom);

	//Methodes d'ajout
	void ajouterDepense(Depense* uneDepense, Utilisateur* payePar);
	void ajouterUtilisateur(Utilisateur* unUtilisateur);

	//Méthode de calcul
	void calculerTotalDepenses();
	void equilibrerComptes();

	//methode d'affichage
	void afficherGroupe();

private:
	string nom_;
	double totalDepenses_;
	Utilisateur** listeUtilisateurs_;
	unsigned int nombreDepenses_;
	unsigned int nombreUtilisateurs_;
	unsigned int tailleTabUtilisateurs_;
	unsigned int tailleTabDepenses_;
	Depense** listeDepenses_;
	double* comptes_;
	Transfert** listeTransferts_;
	unsigned int nombreTransferts_;
};
#endif 
