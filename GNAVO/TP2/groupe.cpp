#include "pch.h"//fonctio ajouter depenses 
/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() :
	nom_("")
	
{
}

Groupe::Groupe(const string& nom):
	nom_(nom)

{
}


Groupe::~Groupe() {
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
		transferts_[i] = nullptr;
	}

	

	/*delete[] depenses_;
	depenses_ = nullptr;*/  //c'est a la classe de depense de dtruire les elements de depenses


	//delete[] utilisateurs_;
	//utilisateurs_ = nullptr;

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
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) {
	//if (nombreDepenses_ >= tailleTabDepenses_) {

	//	tailleTabDepenses_ *= 2;

	//	Depense** listeTemp = new Depense*[tailleTabDepenses_];

	//	for (unsigned int i = 0; i < nombreDepenses_; i++) {
	//		listeTemp[i] = depenses_[i];
	//	}
	//	delete[] depenses_;

	//	depenses_ = listeTemp;
	//}
	depenses_.push_back(depense);

	//depenses_[nombreDepenses_++] = depense;
	*utilisateur+=depense;/////////////////////////////////fauxxx
	return *this;
}
Groupe& Groupe::operator+=( Utilisateur* utilisateur) {

	utilisateurs_.push_back( utilisateur);

	return *this;

}

//void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
//	/*if (nombreUtilisateurs_ >= tailleTabUtilisateurs_) {
//		tailleTabUtilisateurs_ *= 2;
//
//		Utilisateur** listeTemp = new Utilisateur*[tailleTabUtilisateurs_];
//
//		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
//			listeTemp[i] = utilisateurs_[i];
//		}
//		delete[] utilisateurs_;
//
//		utilisateurs_ = listeTemp;
//	}
//	utilisateurs_[nombreUtilisateurs_++] = unUtilisateur;*/
//	utilisateurs_.push_back(unUtilisateur);
//


void Groupe::calculerComptes()
{
	double moyenne = getTotalDepenses() / utilisateurs_.size();
	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		comptes_.push_back ((utilisateurs_[i]->getTotalDepenses()) - moyenne);
	}
}

void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
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
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else {
			transferts_.push_back( new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
	        comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= (utilisateurs_.size()) - 1) {
			calcul = false;
		}
	}
}


// Methode d'affichage//}

ostream& operator<<(ostream& os, const Groupe& groupe) 
{
	
	os << "L'evenement " << groupe.nom_ << " a couté un total  de "<< groupe.getTotalDepenses() << " :  \n\n";
	for (unsigned int i = 0; i < (groupe.utilisateurs_).size(); i++) {
		os<< *groupe.utilisateurs_[i] << endl;;
	}
	

	if (groupe.transferts_.size() != 0) {
		os<< "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
		for (unsigned int i = 0; i < groupe.transferts_.size(); i++) {
			os << "\t";
			 os<<*groupe.transferts_[i] ;
		}
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	os << endl;
	return os;
}

//void Groupe::afficherGroupe() const {
//	cout << "L'evenement " << nom_ << " a coute un total de " << getTotalDepenses() << " :  \n\n";
//	for (int i = 0; i < nombreUtilisateurs_; i++) {
//		utilisateurs_[i]->afficherUtilisateur();
//	}
//	cout << endl;
//
//	if (nombreTransferts_ != 0) {
//		cout << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
//		for (int i = 0; i < nombreTransferts_; i++) {
//			cout << "\t";
//			transferts_[i]->afficherTransfert();
//		}
//	}
//	else {
//		cout << "Les comptes ne sont pas equilibres" << endl << endl;
//	}
//	cout << endl;
//}

