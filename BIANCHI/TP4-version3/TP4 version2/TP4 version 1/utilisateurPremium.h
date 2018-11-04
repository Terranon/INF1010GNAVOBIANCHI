/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#ifndef UTILISATEUR_PREMIUM_H
#define UTILISATEUR_PREMIUM_H

#include "utilisateur.h"

const double TAUX_EPARGNE = 0.03;

class UtilisateurPremium : public Utilisateur {
public :

	// Constructeurs 
	UtilisateurPremium(const string& nom = "", MethodePaiement methodePaiement = Interac, unsigned int joursRestants = 0, const string& courriel = "", const string& idPaypal = "");
	//destructeur
  ~UtilisateurPremium();
	// Methodes d'acces
    unsigned int getJoursRestants() const; 

	// Methodes de modifications
	void setJoursRestants(unsigned int joursRestants); 
	//ajout de lamethde getbalancve frais afin de
	//toujours mettre les frais a zero

	// Methode d'affichage
	// TODO---effectue
	virtual void print(ostream& os) const;

private : 
	unsigned int joursRestants_;
};

#endif 
