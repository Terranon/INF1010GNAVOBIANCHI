/******************************************************************************\
* Authors:     Maximilien Bianchi
* Name:        utilisateur.cpp
* Description:
* Version: 1.0
\******************************************************************************/

#include "utilisateur.h"

/**
* \brief constructeurs par défaut et parametres
* \param nom	: le nom de l'utilisateur
* \return utilisateur
*/
Utilisateur::Utilisateur(){}
Utilisateur::Utilisateur(string& nom) :
	nom_(nom) {
}

/**
* \brief destructeur pour utilisateur
*/
Utilisateur::~Utilisateur() {
}

/**
* \brief retourne la valeur stocker dans l'attribut nom_
* \return string
*/
string Utilisateur::getNom()const {
	return nom_;
}

/**
* \brief retourne la valeur stocker dans l'attribut nombreDepense_
* \return unsigned int
*/
unsigned int Utilisateur::getNombreDepense()const {
	return nombreDepenses_;
}

/**
* \brief retourne la valeur stocker dans l'attribut totalDepense_
* \return double
*/
double Utilisateur::getTotal()const {
	return totalDepense_;
}

/**
* \brief Modifie la valeur de l'attribut prive nom_
* \param string
*/
void Utilisateur::setNom(string& nom) {
	nom_ = nom;
}

/**
* \brief ajoute une depense a listeDepense_
* \param depense
*/
void Utilisateur::ajouterDepense(Depense* uneDepense) {
	if (tailleTabDepense_ <= nombreDepenses_) {
		tailleTabDepense_ = (tailleTabDepense_ * 2);
		Depense** listeDepenseTemporaire = new Depense*[tailleTabDepense_];
		for (unsigned int i = 0; i < tailleTabDepense_; i++) {
			listeDepenseTemporaire[i] = listeDepenses_[i];
		}
		delete listeDepenses_;
		listeDepenses_ = listeDepenseTemporaire;
	}
	listeDepenses_[nombreDepenses_] = uneDepense;
	nombreDepenses_++;
}

//Methode de calcul total
void calculerTotal();

//Mathode d'affichage
void afficherUtilisateur();