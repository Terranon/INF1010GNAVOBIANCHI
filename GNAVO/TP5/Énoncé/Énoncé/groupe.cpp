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
	gestionnaireDepenses_ = new GestionnaireDepenses();          //////////////////////////////////////// me faut il des constructeurs????
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

// TODO : À modifier : ---fait

vector<Depense*> Groupe::getDepenses() const  //essaie j'enleve le onst
{
	return gestionnaireDepenses_->getConteneur();//retourne le conteneur en question 
	//le compilateur  refuse gestionnaireDepenses_->getConteneur()
}

// TODO : À modifier :fait-----revoir ce qui est copié dans le conteneur
vector<Utilisateur*> Groupe::getUtilisateurs() const
{
vector<Utilisateur*>tabUtilisateur;
	
	//vector<pair<Utilisateur*, double>>tabUtilisateur;
	//comment faire la même chose par un copy
	//auto fin = gestionnaireUtilisateurs_->getConteneur().end();
	/*unsigned int index = 0;
	auto fin = (gestionnaireUtilisateurs_->getConteneur()).end();
	auto it = (gestionnaireUtilisateurs_->getConteneur()).begin();
	for (it; it != fin ; ++it) {
		if (it != fin ) //&& it->first != nullptr
			tabUtilisateur.push_back(gestionnaireUtilisateurs_->getElementParIndex(index).first);
			index++;
	}*/
			for (pair<Utilisateur*,double>element : gestionnaireUtilisateurs_->getConteneur()) {//parcourt le conteneur
					tabUtilisateur.push_back(element.first);
				
}

	/*if (gestionnaireUtilisateurs_->getConteneur().empty())
		cout << "oi";
	copy((gestionnaireUtilisateurs_->getConteneur()).begin(), (gestionnaireUtilisateurs_->getConteneur()).end(), back_inserter(tabUtilisateur));
	vector<Utilisateur*>tabUtilisateur1;
	return tabUtilisateur1;*/
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
	auto conteneur = gestionnaireUtilisateurs_->getConteneur();
	for (auto it = conteneur.begin(); it != conteneur.end();it++) {
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
		cout << "L'utilisateur auquel vous essayer d'ajouter une depense n'existe pas dans le groupe" << endl;

		return *this;

	}
	Depense* depense = new Depense(nom, montant, lieu);

	// Modifié :
	// depenses_.push_back(depense);

	// Ajouté :
	gestionnaireDepenses_->ajouter(depense);//fonction créer pour cela
	

	//ajouter la pair qui effectue la depense
//	pair <Utilisateur*, double>payeur = make_pair(payePar,montant);
		//gestionnaireUtilisateurs_->ajouter( payeur );
	//mettre a jour les comptes du gestionnaire utilisateur

	gestionnaireUtilisateurs_->mettreAJourComptes(payePar, montant);
	*payePar += depense;

	// Mise a jour des comptes
	/*double montantReparti = depense->getMontant() / gestionnaireUtilisateurs_->getNombreUtilisateur();
	comptes_[indexPayePar] += depense->getMontant() - montantReparti;
	for (int i = 0; i < gestionnaireUtilisateurs_->getNombreUtilisateurs(); i++) {
		if (i != indexPayePar) {
			comptes_[i] -= montantReparti;
		}
	}*/
	/*auto conteneur = gestionnaireUtilisateurs_->getConteneur();
	auto debut = conteneur.begin();
	auto fin = conteneur.end();//quand utiliser directement il refuse il faut mettre le conteneur dans une variable avant d'Y avoir acces
	//auto t =(gestionnaireUtilisateurs_->getConteneur()).begin();//meme comme ca t contien end
	//pair<Utilisateur*, double>p = make_pair(payePar,montant);
//	auto fin = gestionnaireUtilisateurs_->getConteneur().end();
	//auto payeur = find_if(gestionnaireUtilisateurs_->getConteneur().begin(), gestionnaireUtilisateurs_->getConteneur().end(), bind(equal_to <pair<Utilisateur*,double>>(), _1,p ));
	auto payeur = find_if(debut,fin, bind
	(equal_to <Utilisateur*>(), bind(&map<Utilisateur*, double>::value_type::first,placeholders::_1), payePar));//pour dire que je veux la valeur du premier élément
	double montantReparti = montant/ gestionnaireUtilisateurs_->getNombreElements();
	//lui rajouter a son compte le montant qu'il a paye moins le montant du groupe
	payeur->second += montant - montantReparti;

	//parcourir la boucle et retirer a tous les elements suf le payeur le montant reparti
	//auto fin = gestionnaireUtilisateurs_->getConteneur().end();
	for (auto it = conteneur.begin(); it != conteneur.end(); it++)
	{
		//if (it->first != payePar)//si le champ Utilisateur de it est different  de l'adresse de paye par 
		if (it != payeur)//si l'iterateur it est different de l'iterateur payeur
			it->second -= montantReparti;

	}*/
	
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	// Ajouté :
	//gestionnaireUtilisateurs_->ajouter(utilisateur);

	gestionnaireUtilisateurs_->ajouter(utilisateur);//;;,AjouterUtilisateur (utilisateur));
	/*if (dynamic_cast<UtilisateurRegulier*>(utilisateur)->getPossedeGroupe == false)//si l'utilisateur n'a pas de groupe l'ajouter puis mettre a true le fait qu'il possede un groupe
		dynamic_cast<UtilisateurRegulier*>(utilisateur)->setPossedeGroupe(true);
		
		--a faire dans le foncteur ou dans groupe:operator+= ?*/
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
			if (gestionnaireUtilisateurs_->getComptes()[i] > max) {
				max = gestionnaireUtilisateurs_->getComptes()[i];
				indexMax = i;
			}
			if (gestionnaireUtilisateurs_->getComptes()[i] < min) {
				min = gestionnaireUtilisateurs_->getComptes()[i];
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
			//changement dans les conteneurs des valeurs des comptes
			 //#declaration de variables

			auto indexmax= gestionnaireUtilisateurs_->getElementParIndex(indexMax);
		    indexmax.second +=min;	
			//comptes_[indexMax] += min;
			gestionnaireUtilisateurs_->setCompte(make_pair(indexmax.first, indexmax.second));
			//#déclaration de variables 

			auto indexmin = gestionnaireUtilisateurs_->getElementParIndex(indexMin);
			indexmin.second = 0;	
			//comptes_[indexMin] = 0;
			gestionnaireUtilisateurs_->setCompte(make_pair(indexmin.first, 0));
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
			//changement dans les conteneurs des valeurs des comptes
			  //declaration de variable pour préparer la paire
			auto indexmax = gestionnaireUtilisateurs_->getElementParIndex(indexMax);
			indexmax.second = 0;	
			//comptes_[indexMax] =0;

			gestionnaireUtilisateurs_->setCompte(make_pair(indexmax.first, 0));

			//declaration de variables pour préparer la paire

			auto indexmin = gestionnaireUtilisateurs_->getElementParIndex(indexMin);
			indexmin.second += max;	
			//comptes_[indexMin] +=max;
			gestionnaireUtilisateurs_->setCompte(make_pair(indexmin.first, indexmin.second));

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
	auto conteneur = groupe.gestionnaireUtilisateurs_->getConteneur();
	for (auto it = conteneur.begin(); it != conteneur.end();it++) {
		os << "\t- " << *it->first;// *(groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first);
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
