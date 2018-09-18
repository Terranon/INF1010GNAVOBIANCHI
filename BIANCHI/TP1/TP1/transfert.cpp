/******************************************************************************\
* Authors:     Maximilien Bianchi
* Name:        transfert.cpp
* Description:
* Version: 1.0
\******************************************************************************/

#include "transfert.h"

/**
* \brief constructeurs par défaut et parametres
* \param montant: le montant a se faire transferer
*		 de		: l'utilisateur de ou vien le transfert d'argent
*		 pour	: l'utilisateur a qui on transfert l'argent
* \return transfert
*/
Transfert::Transfert(){
}
Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour) :
	montant_(montant),
	donneur_(de),
	receveur_(pour) {
}

/**
* \brief destructeur pour transfert
*/
Transfert::~Transfert() {
	delete donneur_;
	donneur_ = nullptr;
	delete receveur_;
	receveur_ = nullptr;
}

/**
* \brief retourne l'utilisateur qui donne le transfert
* \return utilisateur*
*/
Utilisateur* Transfert::getDonneur()const {
	return donneur_;
}

/**
* \brief retourne l'utilisateur qui recois le transfert
* \return utilisateur*
*/
Utilisateur* Transfert::getReceveur()const {
	return receveur_;
}

/**
* \brief retourne le montant qui est transfere
* \return double
*/
double Transfert::getMontant()const {
	return montant_;
}


/**
* \brief Modifie la valeur de l'attribut donneur_
* \param utilisateur*
*/
void Transfert::setDonneur(Utilisateur* donneur) {
	donneur_ = donneur;
}

/**
* \brief Modifie la valeur de l'attribut montant_
* \param double
*/
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

/**
* \brief Modifie la valeur de l'attribut receveur_
* \param utilisateur*
*/
void Transfert::setReceveur(Utilisateur* receveur) {
	receveur_ = receveur;
}

/**
* \brief Affiche le transfert
*/
void Transfert::afficherTransfert() {
	cout << donneur_->getNom() << " doit transferer " << getMontant() 
		 <<"$ a " << receveur_->getNom() << endl;
}