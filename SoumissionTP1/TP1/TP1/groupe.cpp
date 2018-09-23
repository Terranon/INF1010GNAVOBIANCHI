/******************************************************************************\
* Authors:     Serge Gnavo 1869985
*			   Maximilien Bianchi 1893352
* Name:        groupe.cpp - TP1 INF1010
* Description: contient les definitions des methodes de la classe
* Version: 1.0
\******************************************************************************/
#include "groupe.h"
//inclure les utilisateur
#include "utilisateur.h"

/**
* \brief constructeurs par défaut et parametres
* \param nom					: le nom du groupe
*		 tailleTabDepenses		: le nombre estime de depenses
*		 tailleTabUtilisateurs	: le nombre estime d'utilisateurs
* \return groupe
*/
Groupe::Groupe() :
	nom_("unknown"), 
	tailleTabDepenses_(TAILLEDEPENSEINITIALE), 
	tailleTabUtilisateurs_(TAILLEUTILISATEURINITIAL), 
	nombreDepenses_(0), 
	nombreUtilisateurs_(0), 
	totalDepenses_(0), 
	nombreTrensferts_(0) {
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
		listeDepenses_[i] = nullptr;
	}
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int j = 0; j<tailleTabUtilisateurs_; j++) {
		listeUtilisateurs_[j] = nullptr;
	}
}
Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) :
	nom_(nom), 
	tailleTabDepenses_(tailleTabDepenses), 
	tailleTabUtilisateurs_(tailleTabUtilisateurs), 
	nombreDepenses_(0), 
	nombreUtilisateurs_(0), 
	totalDepenses_(0), 
	nombreTrensferts_(0) {
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
		listeDepenses_[i] = nullptr;
	}
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int j = 0; j < tailleTabUtilisateurs_; j++){
		listeUtilisateurs_[j] = nullptr;
	}
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
unsigned Groupe::getNombreDepenses()const {
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
	if (nombreDepenses_ >= tailleTabDepenses_) {
		tailleTabDepenses_ += 5;
		Depense** temp = new Depense*[tailleTabDepenses_];
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
			temp[i] = listeDepenses_[i];
		}
		delete[] listeDepenses_;
		listeDepenses_ = temp;
	}
	listeDepenses_[nombreDepenses_] = uneDepense;
	payePar->ajouterDepense(uneDepense);
	nombreDepenses_++;
}

/**
* \brief verifie si on peut ajoute un Utilisateur au tableau de d'utilisateurs
*		 si oui: rajoute l'utilisateur
*		 si non: double la taille du tableau et rajoute l'utilisateur
* \param unUtilisateur : l'utilisateur a rajouter a la liste
*/
void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
	if (nombreUtilisateurs_ >= tailleTabUtilisateurs_) {
		tailleTabUtilisateurs_ += 5;
		Utilisateur** temp = new Utilisateur*[tailleTabUtilisateurs_];
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
			//declarer une liste
			temp[i] = listeUtilisateurs_[i];
		}
		delete[] listeUtilisateurs_;
		listeUtilisateurs_ = temp;
	}
	listeUtilisateurs_[nombreUtilisateurs_] = unUtilisateur;
	nombreUtilisateurs_++;
}

/**
* \brief calcul le total de toutes depense fais par tout utilisateurs dans le groupe
*/
void Groupe::calculerTotalDepenses() {
	totalDepenses_ = 0;
	for (unsigned int i = 0; i < nombreDepenses_; i++) { //calcule le total de chaque depense
		totalDepenses_ += listeDepenses_[i]->getMontant();

	}
	for (unsigned int j = 0; j<nombreUtilisateurs_; j++){ //calcul le total de chaque utiliosateur
		listeUtilisateurs_[j]->calculerTotal();
	}
	double moyenne = totalDepenses_ / nombreUtilisateurs_;
	comptes_ = new double[nombreUtilisateurs_];
	for (unsigned int k = 0; k < nombreUtilisateurs_; k++) { // utiliser le nombre d'utilsateurs a la place de la tailletabutilisateur
		comptes_[k] = listeUtilisateurs_[k]->getTotal() - moyenne;
	}
}

/**
* \brief equilibre les comptes entre les utilisateur egalise les montants pour
*        que chaques utilisateur doit 0$
*/
void Groupe::equilibrerComptes() {
	listeTransferts_ = new Transfert*[nombreUtilisateurs_];
	for (unsigned int k = 0; k < nombreUtilisateurs_; k++) {
		listeTransferts_[k] = new Transfert();
	}
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		while (comptes_[i] >= 1) {
			for (unsigned int j = 0; j < nombreUtilisateurs_ || comptes_[j] == 0; j++) {
				if (i != j && comptes_[j] < 0) {
					if (comptes_[i] > abs(comptes_[j])) {
						listeTransferts_[nombreTrensferts_]->setDonneur(listeUtilisateurs_[j]);
						listeTransferts_[nombreTrensferts_]->setReceveur(listeUtilisateurs_[i]);
						listeTransferts_[nombreTrensferts_]->setMontant(abs(comptes_[j]));

						comptes_[i] = comptes_[i] + comptes_[j];
						comptes_[j] = 0;
						cout << " voici le compte j dans la boucle " << comptes_[j] << endl;
						cout << " voici le compte i dans la boucle " << comptes_[i];

						nombreTrensferts_++;

						cout << " le nombre de transferts" << nombreTrensferts_ << endl;
					}
					else {
						listeTransferts_[nombreTrensferts_]->setMontant(comptes_[i]);
						listeTransferts_[nombreTrensferts_]->setDonneur(listeUtilisateurs_[j]);
						listeTransferts_[nombreTrensferts_]->setReceveur(listeUtilisateurs_[i]);

						comptes_[j] = comptes_[i] + comptes_[j];
						comptes_[i] = 0;
						nombreTrensferts_++;
						cout << " le nombre de transferts" << nombreTrensferts_ << endl;
					}
				}
			}
		}
	}
}

/**
* \brief affiche les depenses du groupe et explique les transfert requis pour egaliser
*		 tout les comptes.
*/
void Groupe::afficherGroupe() {
	for (int i = 0; i < nombreUtilisateurs_; i++) {
		listeUtilisateurs_[i]->afficherUtilisateur();
	}
	for (int j = 0; j < nombreUtilisateurs_; j++) {
		if (comptes_[j] != 0) {
			cout << "Le compte de  " << listeUtilisateurs_[j]->getNom() << " est: " 
				<< comptes_[j] << endl;
		}
	}
	for (int t = 0; t < nombreTrensferts_; t++) {
		if (listeTransferts_[t]->getMontant() != 0) {
			cout << "Transfert fait par" << (listeTransferts_[t]->getDonneur())->getNom() 
				<< " pour " << (listeTransferts_[t]->getReceveur())->getNom() 
				<< " d'un montant de " << listeTransferts_[t]->getMontant() << endl;
		}
	}
}

