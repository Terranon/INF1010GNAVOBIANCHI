/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"

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

// TODO : � modifier :---fait

vector<Depense*> Groupe::getDepenses() const  //essaie j'enleve le onst
{
	return gestionnaireDepenses_->getConteneur();//retourne le conteneur en question 
	//le compilateur  refuse gestionnaireDepenses_->getConteneur()
}

// TODO : � modifier :fait
vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	vector<Utilisateur*>utilisateur;
	auto argument1 = gestionnaireUtilisateurs_->getConteneur().begin()->first;
	auto argument2 = gestionnaireUtilisateurs_->getConteneur().end()->first;
	copy(argument1,argument2 , back_inserter(utilisateur));


	return utilisateur;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

// TODO : � modifier : fait
vector<double> Groupe::getComptes() const {

	vector<double>compte;
	auto argument1 = gestionnaireUtilisateurs_->getConteneur().begin()->second;
	auto argument2 = gestionnaireUtilisateurs_->getConteneur().end()->second;
	copy(argument1,argument2 , back_inserter(compte));

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
// TODO : � modifier :
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

	// Modifi� :
	// depenses_.push_back(depense);

	// Ajout� :
	gestionnaireDepenses_->ajouter(depense)//fonction cr�er pour cela

	*payePar += depense;

	// Mise a jour des comptes
	double montantReparti = depense->getMontant() / gestionnaireUtilisateurs_->getNombreUtilisateur();
	comptes_[indexPayePar] += depense->getMontant() - montantReparti;
	for (int i = 0; i < gestionnaireUtilisateurs_->getNombreUtilisateurs(); i++) {
		if (i != indexPayePar) {
			comptes_[i] -= montantReparti;
		}
	}
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	// Ajout� :
	gestionnaireUtilisateurs_->ajouterUtilisateur(utilisateur);

	comptes_.push_back(0);
	return *this;
}

// TODO : � modifier :
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < gestionnaireUtilisateurs_->getNombreUtilisateurs(); i++) {
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
			if (gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMin)->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-min, gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMin), gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMax));
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(-min, gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMin), gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMax));
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else if (-min > max  && min != 0 && max != 0) {
			if (gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMin)->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(max, gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMin), gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMax));
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(max, gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMin), gestionnaireUtilisateurs_->getUtilisateurParIndex(indexMax));
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
		if (count >= gestionnaireUtilisateurs_->getNombreUtilisateurs() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
// TODO : � modifier :
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (int i = 0; i < groupe.gestionnaireUtilisateurs_->getNombreUtilisateurs(); i++) {
		os << "\t- " << *groupe.gestionnaireUtilisateurs_->getUtilisateurParIndex(i);
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
			os << groupe.gestionnaireUtilisateurs_->getUtilisateurParIndex(i)->getNom() << " : " << groupe.comptes_[i] << endl;
		}
	}

	os << endl;
	return os;
}
