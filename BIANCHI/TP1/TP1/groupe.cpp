/******************************************************************************\
* Authors:     Maximilien Bianchi
* Name:        groupe.cpp
* Description:
* Version: 1.0
\******************************************************************************/
#include "groupe.h"

/**
* \brief constructeurs par défaut et parametres
* \param nom					: le nom du groupe
*		 tailleTabDepenses		: le nombre estime de depenses
*		 tailleTabUtilisateurs	: le nombre estime d'utilisateurs
* \return groupe
*/
Groupe::Groupe() :
	tailleTabDepenses_(5),
	tailleTabUtilisateurs_(10),
	nombreUtilisateurs_(0),
	nombreDepenses_(0) {
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
}
Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) :
	nom_(nom),
	tailleTabDepenses_(tailleTabDepenses),
	tailleTabUtilisateurs_(tailleTabUtilisateurs),
	nombreUtilisateurs_(0),
	nombreDepenses_(0) {
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
}

/**
* \brief destructeur pour groupe
*/
Groupe::~Groupe() {
	for (unsigned int i = 0; i < tailleTabDepenses_; i++) { // desallouer le tableau de depense
		delete listeDepenses_[i];
		listeDepenses_[i] = nullptr;
	}
	delete listeDepenses_;
	listeDepenses_ = nullptr;
	for (unsigned int j = 0; j < tailleTabUtilisateurs_; j++) { // desallouer le tableau d'utilisateurs
		delete listeUtilisateurs_[j];
		listeUtilisateurs_[j] = nullptr;
	}
	delete listeUtilisateurs_;
	listeUtilisateurs_ = nullptr;
	for (unsigned int k = 0; k < nombreUtilisateurs_; k++) { // desallouer le tableau de transfert
		delete listeTransferts_[k];
		listeTransferts_[k] = nullptr;
	}
	delete listeTransferts_;
	listeTransferts_ = nullptr;
	delete comptes_;			// desallouer les comptes
	comptes_ = nullptr;
}

/**
* \brief retourne le nom du groupe
* \return string
*/
string Groupe::getNom()const {
	return nom_;
}

/**
* \brief retourne le nombre de depenses du groupe
* \return unsigned int
*/
unsigned int Groupe::getNombreDepenses()const {
	return nombreDepenses_;
}

/**
* \brief retourne le total des depenses du groupe
* \return string
*/
double Groupe::getTotal()const {
	return totalDepenses_;
}

/**
* \brief modifie le nom du groupe
* \param string
*/
void Groupe::setNom(string& nom) {
	nom_ = nom;
}

/**
* \brief ajoute une depense associe a un utilisateur au tableau de depense
* \param uneDepense : le titre et le montant d'une depense
*		 payePar	: l'utilisateur qui a fait la depense
*/
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar) {
	bool depenseAjouterUtilisateur = false;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		if (listeUtilisateurs_[i]->getNom() == payePar->getNom()) {
			depenseAjouterUtilisateur = true;
			listeUtilisateurs_[i]->ajouterDepense(uneDepense);
			cout << "depense de " << uneDepense->getMontant() << " fait par "
				 << payePar->getNom() << endl;
		}
	}
	if (tailleTabDepenses_ <= nombreDepenses_) {
		tailleTabDepenses_ = (tailleTabDepenses_ * 2);
		Depense** listeDepensesTemporaire = new Depense*[tailleTabDepenses_];
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
			listeDepensesTemporaire[i] = listeDepenses_[i];
		}
		delete listeDepenses_;
		listeDepenses_ = listeDepensesTemporaire;
	}
	listeDepenses_[nombreDepenses_] = uneDepense;
	nombreDepenses_++;
	if (depenseAjouterUtilisateur == false) {
		cout << "Incapable de trouver l'utilisateur" << endl;
	}
}

/**
* \brief verifie si on peut ajoute un Utilisateur au tableau de d'utilisateurs
*		 si oui: rajoute l'utilisateur
*		 si non: double la taille du tableau et rajoute l'utilisateur
* \param unUtilisateur : l'utilisateur a rajouter a la liste
*/
void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
	if (tailleTabUtilisateurs_ <= nombreUtilisateurs_) {
		tailleTabUtilisateurs_ = (tailleTabUtilisateurs_ * 2);
		Utilisateur** listeUtilisateurTemporaire = new Utilisateur*[tailleTabUtilisateurs_];
		for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) {
			listeUtilisateurTemporaire[i] = listeUtilisateurs_[i];
		}
		delete listeUtilisateurs_;
		listeUtilisateurs_ = listeUtilisateurTemporaire;
	}
	listeUtilisateurs_[nombreUtilisateurs_] = unUtilisateur;
	nombreUtilisateurs_++;
}

/**
* \brief calcul le total de toutes depense fais par tout utilisateurs dans le groupe
*/
void Groupe::calculerTotalDepenses() {
	totalDepenses_ = 0;
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		totalDepenses_ += listeDepenses_[i]->getMontant();
	}
	for (unsigned int j = 0; j < nombreUtilisateurs_; j++) {
		listeUtilisateurs_[j]->calculerTotal();
	}
}

/**
* \brief equilibre les comptes entre les utilisateur
*	premiere boucle for : rajoute les montants que chaques utilisateur doit au groupe
*	deuxieme boucle for : egalise les montants pour que chaques utilisateur doit 0$
*/
void Groupe::equilibrerComptes() {
	comptes_ = new double[nombreUtilisateurs_];
	listeTransferts_ = new Transfert*[nombreUtilisateurs_];
	calculerTotalDepenses();
	double depenseMoyen = totalDepenses_ / nombreUtilisateurs_;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		listeUtilisateurs_[i]->calculerTotal();
		comptes_[i] = listeUtilisateurs_[i]->getTotal() - depenseMoyen;
	}
	nombreTransferts_ = 0;
	for (int i = 0; i < nombreUtilisateurs_; i++) {
		if (comptes_[i] < 0) {
			for (unsigned int j = 0; j < nombreUtilisateurs_ || comptes_[i] == 0; j++) {
				if (i != j && comptes_[j] > 0) {
					if ((-comptes_[i]) >= comptes_[j]) {
						listeTransferts_[nombreTransferts_]->setMontant(comptes_[j]);
						comptes_[i] = comptes_[i] + comptes_[j];
						comptes_[j] = 0;
					}
					else if ((-comptes_[i]) < comptes_[j]) {
						listeTransferts_[nombreTransferts_]->setMontant(-comptes_[i]);
						comptes_[i] = 0;
						comptes_[j] = comptes_[i] + comptes_[j];
					}
					listeTransferts_[nombreTransferts_]->setDonneur(listeUtilisateurs_[i]);
					listeTransferts_[nombreTransferts_]->setReceveur(listeUtilisateurs_[j]);
					nombreTransferts_++;
				}
			}
			i--; // on recule de 1 dans le tableau de compte pour etre sur qu'il est a zero
		}
	}
}

/**
* \brief affiche les depenses du groupe et explique les transfert requis pour egaliser
*		 tout les comptes.
*/
void Groupe::afficherGroupe() {
	cout << "L'evenement: " << getNom() 
		 << " a coute un total pour le groupe de: " << getTotal() << endl;
	cout << "Voici les depenses:" << endl;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		listeUtilisateurs_[i]->afficherUtilisateur;
	}
	cout << "pour equilibrer les comptes: " << endl;
	for (unsigned int k = 0; k < nombreTransferts_; k++) {
		cout << "Transfert de " << listeTransferts_[k]->getDonneur() << " a "
			<< listeTransferts_[k]->getReceveur() << " d'un montant de: "
			<< listeTransferts_[k]->getMontant() << endl;
	}
}