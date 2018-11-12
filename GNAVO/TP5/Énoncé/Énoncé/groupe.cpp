/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"

#include <functional>
//#include  <iostream>
#include <algorithm>
//using namespace std; 
using namespace std::placeholders;
// Constructeurs
Groupe::Groupe() {
	nom_ = "";
	gestionnaireDepenses_ = new GestionnaireDepenses();  ////////////////////////////////////me faut il des constructeurs????
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const string& nom) : nom_(nom) {
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::~Groupe() {
	vector<Depense*> depenses = gestionnaireDepenses_->getConteneur();
	for (int i = 0; i < depenses.size(); i++) {
		delete depenses[i];
	}
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

// TODO : À modifier :---fait

vector<Depense*> Groupe::getDepenses() const  //essaie j'enleve le onst
{
	return gestionnaireDepenses_->getConteneur();//retourne le conteneur en question 
	//le compilateur  refuse gestionnaireDepenses_->getConteneur()
}

// TODO : À modifier :fait-----revoir ce qui est copié dans le conteneur
vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	vector<Utilisateur*>tabUtilisateur;

	//comment faire la même chose par un copy
	//auto fin = gestionnaireUtilisateurs_->getConteneur().end();
	unsigned int index = 0;
	for (auto it = gestionnaireUtilisateurs_->getConteneur().begin(); it != gestionnaireUtilisateurs_->getConteneur().end(); it++) {
		tabUtilisateur.push_back(gestionnaireUtilisateurs_->getElementParIndex(index).first);
		index++;
	}
	
	return tabUtilisateur;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

// TODO : À modifier : fait
vector<double> Groupe::getComptes() const {

	vector<double>compte;
	/*auto argument1 = gestionnaireUtilisateurs_->getConteneur().begin()->second;
	auto argument2 = gestionnaireUtilisateurs_->getConteneur().end()->second;
//	copy(argument1,argument2 , back_inserter(compte));*/
	
	//auto fin = gestionnaireUtilisateurs_->getConteneur().end();//->second;
	//	copy(argument1,argument2 , back_inserter(compte));
	for (auto it =gestionnaireUtilisateurs_->getConteneur().begin();it != gestionnaireUtilisateurs_->getConteneur().end();it++) {
		compte.push_back(it->second);

	}

	return compte;
}

double Groupe::getTotalDepenses() const {
	return gestionnaireDepenses_->getTotalDepenses();
}

GestionnaireUtilisateurs * Groupe::getGestionnaireUtilisateurs()
{
	return gestionnaireUtilisateurs_;
}

GestionnaireDepenses * Groupe::getGestionnaireDepenses()
{
	return gestionnaireDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
// TODO : À modifier :
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu)
{
	// Trouver l'index de l'auteur de la depense--*----verifier si existe
	/*int indexPayePar = gestionnaireUtilisateurs_->getIndexDe(payePar);

	if (indexPayePar == -1) {
		return *this;
	}*/
	//verifier si l'utilisateur existe 
	if (!gestionnaireUtilisateurs_->estExistant(payePar))//si l'utilisateur n'existe pas retourner l'objet courant sans aucune modification
	{
		return *this;
	}
	Depense* depense = new Depense(nom, montant, lieu);

	// Modifié :
	// depenses_.push_back(depense);

	// Ajouté :
	//gestionnaireDepenses_->ajouter(depense)//fonction créer pour cela

	*payePar += depense;

	// Mise a jour des comptes
	/*double montantReparti = depense->getMontant() / gestionnaireUtilisateurs_->getNombreUtilisateur();
	comptes_[indexPayePar] += depense->getMontant() - montantReparti;
	for (int i = 0; i < gestionnaireUtilisateurs_->getNombreUtilisateurs(); i++) {
		if (i != indexPayePar) {
			comptes_[i] -= montantReparti;
		}
	}*/

	pair<Utilisateur*, double>p = make_pair(payePar,montant);
//	auto fin = gestionnaireUtilisateurs_->getConteneur().end();
	auto payeur = find_if(gestionnaireUtilisateurs_->getConteneur().begin(), gestionnaireUtilisateurs_->getConteneur().end(), bind(equal_to <pair<Utilisateur*,double>>(), _1,p ));
	double montantReparti = montant/ gestionnaireUtilisateurs_->getNombreElements();
	//lui rajouter a son compte le montant qu'il a paye moins le montant du groupe
	payeur->second += montant - montantReparti;

	//parcourir la boucle et retirer a tous les elements suf le payeur le montant reparti
	//auto fin = gestionnaireUtilisateurs_->getConteneur().end();
	for (auto it = gestionnaireUtilisateurs_->getConteneur().begin(); it != gestionnaireUtilisateurs_->getConteneur().end(); it++)
	{
		//if (it->first != payePar)//si le champ Utilisateur de it est different  de l'adresse de paye par 
		if (it != payeur)//si l'iterateur it est different de l'iterateur payeur
			it->second -= montantReparti;

	}

	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	// Ajouté :
	//gestionnaireUtilisateurs_->ajouter(utilisateur);

	comptes_.push_back(0);
	return *this;
}

// TODO : À modifier :
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < gestionnaireUtilisateurs_->getNombreElements(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {

			if (gestionnaireUtilisateurs_->getElementParIndex(indexMin).first->getMethodePaiement() == Interac) {
				
				TransfertInterac* transfert = new TransfertInterac(-min, gestionnaireUtilisateurs_->getElementParIndex(indexMin).first, gestionnaireUtilisateurs_->getElementParIndex(indexMax).first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				
				TransfertPaypal* transfert = new TransfertPaypal(-min, gestionnaireUtilisateurs_->getElementParIndex(indexMin).first, gestionnaireUtilisateurs_->getElementParIndex(indexMax).first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else if (-min > max  && min != 0 && max != 0) {
			if (gestionnaireUtilisateurs_->getElementParIndex(indexMin).first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(max, gestionnaireUtilisateurs_->getElementParIndex(indexMin).first, gestionnaireUtilisateurs_->getElementParIndex(indexMax).first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(max, gestionnaireUtilisateurs_->getElementParIndex(indexMin).first, gestionnaireUtilisateurs_->getElementParIndex(indexMax).first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getNombreElements() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
// TODO : À modifier :
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	/*os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (int i = 0; i < groupe.gestionnaireUtilisateurs_->getNombreElements(); i++) {
		os << "\t- " << *(groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first);
	}
	os << endl;*/
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (auto it = groupe.gestionnaireUtilisateurs_->getConteneur().begin(); it != groupe.gestionnaireUtilisateurs_->getConteneur().end();it++) {
		os << "\t- " << it->first;// *(groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first);
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (int i = 0; i < groupe.comptes_.size(); i++) {
			os << groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first->getNom() << " : " << groupe.comptes_[i] << endl;
		}
	}

	os << endl;
	return os;
}
