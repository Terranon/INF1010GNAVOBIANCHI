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
Utilisateur::Utilisateur() :
	tailleTabDepense_(5) {
	listeDepenses_ = new Depense*[tailleTabDepense_];
}
Utilisateur::Utilisateur(string& nom) :
	nom_(nom),
	tailleTabDepense_(5) {
	listeDepenses_ = new Depense*[tailleTabDepense_];
}

/**
* \brief destructeur pour utilisateur
*/
Utilisateur::~Utilisateur() {
	for (unsigned int i = 0; i < tailleTabDepense_; i++) {
		delete listeDepenses_[i];
		listeDepenses_[i] = nullptr;
	}
	delete listeDepenses_;
	listeDepenses_ = nullptr;
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

/**
* \brief calculer le total des depenses d'un utilisateur
*/
void Utilisateur::calculerTotal() {
	totalDepense_ = 0;
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		totalDepense_ += listeDepenses_[i]->getMontant();
	}
}

/**
* \brief afficher l'utilisateur et ses depense
*/
void Utilisateur::afficherUtilisateur() {
	calculerTotal();
	cout << nom_ << " a un total de depense de: " << getTotal() << endl;
	cout << "Liste de depense:" << endl;
	for (unsigned int j = 0; j < nombreDepenses_; j++) {
		listeDepenses_[j]->afficherDepense();
	}
}