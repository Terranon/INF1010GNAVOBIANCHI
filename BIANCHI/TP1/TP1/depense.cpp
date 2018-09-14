/******************************************************************************\
* Authors:     Maximilien Bianchi
* Name:        depense.cpp
* Description: 
* Version: 1.0
\******************************************************************************/

#include "depense.h"

/**
* \brief constructeurs par défaut et parametres
* \param titre	: represente le type de depense faite
*		 montant: represente le le montant de la depense
* \return depense
*/
Depense::Depense(){}
Depense::Depense(string& titre, double montant) :
	titre_(titre),
	montant_(montant) {
}

/**
* \brief retourne la valeur stocker dans l'attribut titre_
* \return string
*/
string Depense::getTitre()const {
	return titre_;
}

/**
* \brief retourne la valeur stocker dans l'attribut montant_
* \return double
*/
double Depense::getMontant()const {
	return montant_;
}

/**
* \brief Modifie la valeur de l'attribut prive titre_
* \param string
*/
void Depense::setTitre(string& titre) {
	titre_ = titre;
}

/**
* \brief Modifie la valeur de l'attribut prive montant_
* \param double
*/
void Depense::setMontant(double montant) {
	montant_ = montant;
}

/**
* \brief affiche le titre de la depense et son montant
*/
void Depense::afficherDepense()const {
	cout << montant_ << "$ pour " << titre_ << endl;
}