/********************************************
* Titre: Travail pratique #4 - groupe.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe(const string& nom) : 
	nom_(nom) {
}

Groupe::~Groupe() {
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
	depenses_.clear();
	for (unsigned int j = 0; j < transferts_.size(); j++) {
		delete transferts_[j];
		transferts_[j] = nullptr;
	}
	transferts_.clear();
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<Depense*> Groupe::getDepenses() const {
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const {
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const {
	return transferts_;
}

vector<double> Groupe::getComptes() const {
	return comptes_;
}

double Groupe::getTotalDepenses() const {
	double totalDepenses = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		totalDepenses += depenses_[i]->getMontant();
	}
	return totalDepenses;
}

// Methode de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu) {
	//verifier que l'utilisateur appartient au groupe
	bool condition = false;
	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		if (utilisateurs_[i] == payePar) {
			condition = true;
		}
	}

	if (condition == true) {
		//creer une nouvelle depense
		Depense* depense = new Depense(nom, montant, lieu);

		//l'ajouter au groupe
		depenses_.push_back(depense);

		//l'ajouter au payeur
		*payePar += depense;

		//mettre a jour la valeur des comptes de tous les utilisateurs du groupe

		//ajouter l'utilisateur qui fait la depense au groupe
		for (unsigned int j = 0; j < utilisateurs_.size(); j++) {
			//le compte du payeur augmentera de la valeur de la depense
			if (utilisateurs_[j] == payePar) {
				comptes_[j] += montant - montant / utilisateurs_.size();
			}
			//le compte des autres personnes diminuera dela valeur du montant de la depense sur le nombre d'utilisateur 
			else {
				comptes_[j] -= montant / utilisateurs_.size();
			}
		}
	}
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur) {
	if ((dynamic_cast<UtilisateurRegulier*>(utilisateur))) {
		if ((dynamic_cast<UtilisateurRegulier*>(utilisateur))->getPossedeGroupe() == false) {
			utilisateurs_.push_back(utilisateur); 
			comptes_.push_back(0);
			(dynamic_cast<UtilisateurRegulier*>(utilisateur))->setPossedeGroupe(true);
		}
		else {
			cout << utilisateur->getNom() 
				<< " n'est pas un utilisateur premiun et ne peut pas etre ajoute car est deja groupe" << endl;
		}
	}
	else {//l'utilisateur est donc premium
		if ((dynamic_cast<UtilisateurPremium*>(utilisateur))->getJoursRestants() != 0) {
			utilisateurs_.push_back(utilisateur); comptes_.push_back(0);
		}
		else {
			cout << utilisateur->getNom() << " doit renouveler son abonnement premium" << endl;
		}
	}
	return *this;
}

// Methode de calcul
void Groupe::equilibrerComptes() {

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
		if (-min <= max && min != 0 && max != 0) {
			// Faire le transfert  du bon type--comment savoir le bon type il faut creer une fonction de type virtual dans la classe 
			//il faut voir le type en regardant le mode de paiement de l'utilisateur
			if (utilisateurs_[indexMin]->getMethodePaiement() == Interac) {
				Transfert* transfert = new TransfertInterac(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]);
				transfert->effectuerTransfert();
				transferts_.push_back(transfert);
			}
			else {
				Transfert* transfert = new TransfertPaypal(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]);
				transfert->effectuerTransfert();
				transferts_.push_back(transfert);
			}
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else if (-min > max  && min != 0 && max != 0) {
			// Faire le transfert du bon type
			if (utilisateurs_[indexMin]->getMethodePaiement() == Interac) {
				Transfert* transfert = new TransfertInterac(max, utilisateurs_[indexMin], utilisateurs_[indexMax]);
				transfert->effectuerTransfert();
				transferts_.push_back(transfert);
				//effectuer le transfert avant de l'ajouter
			}
			else {
				Transfert* transfert = new TransfertPaypal(max, utilisateurs_[indexMin], utilisateurs_[indexMax]);
				transfert->effectuerTransfert();
				transferts_.push_back(transfert);
			}
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}
		// On incremente le nombre de comptes initialise a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe) {
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (int i = 0; i < groupe.utilisateurs_.size(); i++) {
		os << "\t- " << *groupe.utilisateurs_[i];
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl;
		for (int i = 0; i < groupe.comptes_.size(); i++) {
			os << groupe.utilisateurs_[i]->getNom() << " : " << groupe.comptes_[i] << endl;
		}
	}
	os << endl;
	return os;
}
