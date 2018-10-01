/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() :
	nom_("") {
}

Groupe::Groupe(const string& nom) :
	nom_(nom) {
}


Groupe::~Groupe() {
	unsigned int nombreUtilisateurs = utilisateurs_.size();
	for (unsigned int i = 0; i < nombreUtilisateurs; i++) {
		delete utilisateurs_[i];
		utilisateurs_[i] = nullptr;
	}
	utilisateurs_.clear();
	utilisateurs_.shrink_to_fit();

	unsigned int nombreTransferts = transferts_.size();
	for (unsigned int i = 0; i < nombreTransferts; i++) {
		delete transferts_[i];
		transferts_[i] = nullptr;
	}
	transferts_.clear();
	transferts_.shrink_to_fit();

	unsigned int nombreDepenses = depenses_.size();
	for (unsigned int i = 0; i < nombreDepenses; i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
	depenses_.clear();
	depenses_.shrink_to_fit();

	comptes_.clear();
	comptes_.shrink_to_fit();
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const {
	return depenses_.size();
}

double Groupe::getTotalDepenses() const {
	double total = 0;
	unsigned int max = depenses_.size();
	for (unsigned int i = 0; i < max; i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) {
	depenses_.push_back(depense);
	*utilisateur += depense;
	return *this;
}

Groupe Groupe::operator+=(Utilisateur* unUtilisateur) {
	utilisateurs_.push_back(unUtilisateur);
	return *this;
}

void Groupe::calculerComptes() {
	unsigned int totalDepenses = getTotalDepenses();
	unsigned int nombreUtilisateurs = utilisateurs_.size();
	double moyenne = totalDepenses / nombreUtilisateurs;
	for (int i = 0; i < nombreUtilisateurs; i++) {
		comptes_.push_back((utilisateurs_[i]->getTotalDepenses()) - moyenne);
	}
}

void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	int count = 0;
	unsigned int nombreUtilisateurs = utilisateurs_.size();
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < nombreUtilisateurs; i++) {
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
		if (-min <= max) {
			Transfert transfertMin(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]);
			transferts_.push_back(&transfertMin);
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else {
			Transfert transfertMax(max, utilisateurs_[indexMin], utilisateurs_[indexMax]);
			transferts_.push_back(&transfertMax);
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= nombreUtilisateurs - 1) {
			calcul = false;
		}
	}
}


// Methode d'affichage
Groupe Groupe::operator<<(Groupe* groupe) const {
	cout << "L'evenement " << nom_ << " a coute un total de " << getTotalDepenses() << " :  \n\n";
	unsigned int nombreUtilisateurs = utilisateurs_.size();
	for (int i = 0; i < nombreUtilisateurs; i++) {
		cout << utilisateurs_[i];
	}
	cout << endl;

	unsigned int nombreTransferts = transferts_.size();
	if (nombreTransferts != 0) {
		cout << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
		for (int i = 0; i < nombreTransferts; i++) {
			cout << "\t";
			cout << transferts_[i];
		}
	}
	else {
		cout << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	cout << endl;
	return *this;
}
