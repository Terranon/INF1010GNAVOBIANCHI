#include "pch.h"//fonctio ajouter depenses 
/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() {
	nom_ = "";
}
Groupe::Groupe(const string& nom) : nom_(nom) {
}

Groupe::~Groupe() 
{
	for (unsigned int i = 0; i < transferts_.size(); i++) 
	{
		delete transferts_[i];
	}
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const
{
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}


double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{
	bool condition =true;
	//Verifier que tous les utilisateurs concernés soient là.
	if (payePar == nullptr)
		condition = false;
	for(unsigned int i =0;i<payePour.size();i++)
	{
		if (payePour[i] == nullptr)
			condition = false;
	}
	//Verifie que la dépense soit bien une DepenseGroupe
	if (depense->getType() != groupe)
		condition = false;
	



   //Si tout est bon
	if (condition == true)
	{
		//Ajoute la dépense aux utilisateurs concernés 
		for (unsigned int i = 0; i < payePour.size(); i++)
		{
			*payePour[i] += depense;

		//Mets à jour les comptes des utilisateurs concernés

			//depense de l'utilisateur - depense moyenne ;depense moyenne =depense total du groupe/bombre d'utilisateur
			//comptes_[i] = payePour[i]->getTotalDepenses() -( (getTotalDepenses() + depense->getMontant())/ payePour.size());
			
			comptes_.push_back(payePour[i]->getTotalDepenses() - ((getTotalDepenses() + depense->getMontant()) / payePour.size()));
		//Ajoute la dépense au groupe 
			//probleme le groupe neprend que des depenses personnels
			//comment  transformer en depense personnel
			

		}	
		//transformation en depense groupe --perte des methodes puiscopie avec constructeur parc poe
		DepenseGroupe* r((static_cast<DepenseGroupe*>(depense)));
		depenses_.push_back(r);
		//ajouter le nombre de participants
	//r
		//depenses_.push_back(depense);
		//essayer de transformer classe erivee en classe de base en utilisant le constructeur par copie
		//DepenseGroupe *p= new DepenseGroupe(depense->getNom(),depense->getMontant(),*depense->getLieu());
		//depenses_.push_back(p);
	
		//	depenses_.push_back(dynamic_cast<DepenseGroupe*>(depense));

		
				
		//ajouter une classe
	}	
	//Sinon affiche une erreur
	else
		cout << "Erreur.impossible d'ajouter depense " << endl;
		
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	//if((utilisateur->getType()==Premium)
	utilisateurs_.push_back(utilisateur);
	
	//if( (utilisateur->getType() == Regulier)&&(utilisateur.))
	return *this;
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

void Groupe::calculerTotalDepense() 
{
	totalDepenses_ = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++)
		totalDepenses_ += depenses_[i]->getMontantPersonnel();

}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	for (unsigned int i = 0; i < groupe.utilisateurs_.size(); i++)
		os << *groupe.utilisateurs_[i]<<endl;

	for (unsigned int i = 0; i < groupe.transferts_.size(); i++)
		os << *groupe.transferts_[i] << endl;


	for (unsigned int i = 0; i < groupe.comptes_.size(); i++)
	{ 
		if (groupe.comptes_[i] !=0)
		os <<"le compte"<<i<<"a pour valeur"<< groupe.comptes_[i] << endl;
	}


	return os;
}
