/******************************************************************************\
* Authors:     Maximilien Bianchi
* Name:        groupe.cpp
* Description:
* Version: 1.0
\******************************************************************************/
#include "groupe.h"

//Constructeurs
Groupe::Groupe() :
	nombreUtilisateurs_(5),
	nombreDepenses_(10) {
	listeUtilisateurs_ = new Utilisateur*[nombreUtilisateurs_];
	listeDepenses_ = new Depense*[nombreDepenses_];
}
Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) :
	nom_(nom),
	nombreDepenses_{

}

//Destructeur
Groupe::~Groupe() {

}

//methode d'acces
string Groupe::getNom()const {

}
unsigned int Groupe::getNombreDepenses()const {

}
double Groupe::getTotal()const {

}

//Methodes de modification
void Groupe::setNom(string& nom) {

}

//Methodes d'ajout
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar) {

}
void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {

}

//Méthode de calcul
void Groupe::calculerTotalDepenses() {

}
void Groupe::equilibrerComptes() {

}

//methode d'affichage
void Groupe::afficherGroupe() {

}