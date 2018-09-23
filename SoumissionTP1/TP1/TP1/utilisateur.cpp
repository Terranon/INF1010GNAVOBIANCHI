/******************************************************************************\
* Authors:     Serge Gnavo 1869985
*			   Maximilien Bianchi 1893352
* Name:        utilisateur.cpp - TP1 INF1010
* Description: contient les definitions des methodes de la classe
* Version: 1.0
\******************************************************************************/
#include "utilisateur.h"

/**
* \brief constructeurs par défaut et parametres
* \param string	: represente le nom de l'utilisateur
* \return depense
*/
Utilisateur::Utilisateur() :
	nom_("unknown"),
	tailleTabDepense_(TAILLEDEPENSEINITIALE),
	nombreDepenses_(0),
	totalDepense_(0) {
	listeDepenses_ = new Depense*[TAILLEDEPENSEINITIALE];
	for (unsigned int i = 0; i < TAILLEDEPENSEINITIALE; i++) {
		listeDepenses_[i] = nullptr; // initialiser chaque depense dans le tableau a nullptr
	}


}
Utilisateur::Utilisateur(string& nom) :
	nom_(nom),
	tailleTabDepense_(TAILLEDEPENSEINITIALE),
	nombreDepenses_(0),
	totalDepense_(0) {
	listeDepenses_ = new Depense*[TAILLEDEPENSEINITIALE];
	for (unsigned int i = 0; i < TAILLEDEPENSEINITIALE; i++) {
		listeDepenses_[i] = nullptr; // initialiser chaque depense dans le tableau a nullptr
	}
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
	if (nombreDepenses_ >= tailleTabDepense_) { //si le nombre de depense est superieur ou egale a celle de la liste
		tailleTabDepense_ += 5;
		Depense** temp = new Depense*[tailleTabDepense_]; // tableau temporaire
		for (unsigned int i = 0; i < tailleTabDepense_; i++) { // copier le tabeau existant dans le tableau temp
			temp[i] = nullptr; // initialiser chaque element du tableau temp
			temp[i] = listeDepenses_[i]; // copier les elements un a un dans le tableau temp
		}
		delete[] listeDepenses_; //supprime le tableau liste depense: il ne pointe plus sur rien

		listeDepenses_ = temp; //liste depense et temp pointe sur les mm choses donc pas de fuite de memoire
	}
	listeDepenses_[nombreDepenses_] = uneDepense;
	nombreDepenses_++;
}

/**
* \brief calculer le total des depenses d'un utilisateur
*/
void Utilisateur::calculerTotal(){
	totalDepense_ = 0;//pour eviter un ajout de total depense a chaque fois
					  //que la methode est nouvellement calcule
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		totalDepense_ += listeDepenses_[i]->getMontant();
	}
}

/**
* \brief afficher l'utilisateur et ses depenses
*/
void Utilisateur::afficherUtilisateur() {
	cout << nom_ << " a un total de depenses de " << getTotal() << endl;
	cout << "Liste de depenses:" << endl;
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		listeDepenses_[i]->afficherDepense();
	}

}
