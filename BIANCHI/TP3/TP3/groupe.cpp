/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
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
	for(unsigned int i = 0; i < utilisateurs_.size(); i++) {
		delete utilisateurs_[i];
		utilisateurs_[i] = nullptr;
	}
	utilisateurs_.clear();
	utilisateurs_.shrink_to_fit();
	for(unsigned int j = 0; j < depenses_.size(); j++) {
		delete depenses_[j];
		depenses_[j] = nullptr;
	}
	depenses_.clear();
	depenses_.shrink_to_fit();
	for(unsigned int k = 0; k < transferts_.size(); k++) {
		delete transferts_[k];
		transferts_[k] = nullptr;
	}
	transferts_.clear();
	transferts_.shrink_to_fit();
	comptes_.clear();
	comptes_.shrink_to_fit();
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const {
	return utilisateurs_;
}
unsigned int Groupe::getNombreUtilisateurs() const {
	unsigned int nombreDUtilisateurs = utilisateurs_.size();
	return nombreDUtilisateurs;
}

vector<DepenseGroupe*> Groupe::getDepenses() const {
	return depenses_;
}
unsigned int Groupe::getNombreDepenses() const {
	unsigned int nombreDeDepenses = depenses_.size();
	return nombreDeDepenses;
}

vector<Transfert*> Groupe::getTransferts() const {
	return transferts_;
}
unsigned int Groupe::getNombreTransferts() const {
	unsigned int nombreDeTransferts = transferts_.size();
	return nombreDeTransferts;
}
double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour) {
	// TODO: Verifier que tous les utilisateurs concern�s soient l�.
	bool utilisateurTrouve = false;
	string nomUtilisateursEntre = payePar->getNom();
	for (unsigned int i = 0; i < getNombreUtilisateurs() || !utilisateurTrouve; i++) {
		if (utilisateurs_[i]->getNom() == nomUtilisateursEntre) {
			utilisateurTrouve = true;
		}
	}
	if (!utilisateurTrouve) { // TODO: Sinon affiche une erreur
		cout << "Erreur: L'utilisateur qui fait la depense est introuvable.";
	}
	else {
		unsigned int nombreDUtilisateurValide = 0;
		for (unsigned int j = 0; j < getNombreUtilisateurs(); j++) {
			if (utilisateurs_[j]->getNom() == payePour[j]->getNom()) {
				nombreDUtilisateurValide++;
			}
		}
		if (getNombreUtilisateurs() != nombreDUtilisateurValide) { // TODO: Sinon affiche une erreur
			cout << "Erreur: Le groupe d'utilisateur ne correspond pas au groupe present.";
		}
		else { // TODO: Verifie que la d�pense soit bien une DepenseGroupe
			if (depense->getType() != groupe) { // TODO: Sinon affiche une erreur
				cout << "Erreur: La depense n'est pas de type 'DepenseGroupe'.";
			}
			else { // TODO: Si tout est bon : Ajoute la d�pense aux utilisateurs concern�s
				DepenseGroupe* depenseGroupe;
				*depenseGroupe = static_cast<DepenseGroupe>(*depense);
				depenseGroupe->setNombreParticipants(payePour.size());
				*payePar += depenseGroupe;
				// TODO: Mets � jour les comptes des utilisateurs concern�s
				calculerTotalDepense();
				equilibrerComptes();
				// TODO: Ajoute la d�pense au groupe
				depenses_.push_back(depenseGroupe);
			}
		}
	}
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur) {

}

void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < utilisateurs_.size(); i++) {
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
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;

		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;


		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}

}

void Groupe::calculerTotalDepense() {


}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe) {

}
