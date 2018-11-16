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
	
			for (pair<Utilisateur*,double>element : gestionnaireUtilisateurs_->getConteneur()) {//parcourt le conteneur
					tabUtilisateur.push_back(element.first);
				
             }
			//utiliser un foreach il travaillera avec une copie !!

	return tabUtilisateur;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

// TODO : À modifier : fait
vector<double> Groupe::getComptes() const {
	/**/
	vector<double>compte;
	
	auto conteneur = gestionnaireUtilisateurs_->getConteneur();
	for (auto it = conteneur.begin(); it != conteneur.end();it++) {
		//comptes_.push_back(it->second);comment le modifier?
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
	
	//modigier le compte 


	//comptes_.push_back(0);//le compte des utilisateurs
	return *this;
}

// TODO : À modifier :
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	
	while (calcul) {
		
		pair<Utilisateur*, double>pairemin  = gestionnaireUtilisateurs_->getMin();;
	pair<Utilisateur*, double> pairemax  = gestionnaireUtilisateurs_->getMax();;

		// On cherche le compte le plus eleve et le moins eleve
		

		//////////////////////////////////////////////////
	
	

        
		//pairemin = make_pair(gestionnaireUtilisateurs_->getMin().first,gestionnaireUtilisateurs_->getMin().second);
		//pairemax = make_pair(gestionnaireUtilisateurs_->getMax().first, gestionnaireUtilisateurs_->getMax().second);

		

		//////////////////////////////////////////////////


		// On cherche lequel des deux a la dette la plus grande
		if (-pairemin.second <= pairemax.second && pairemin.second != 0 && pairemax.second != 0) {

			if (pairemin.first->getMethodePaiement() == Interac) {
				
				TransfertInterac* transfert = new TransfertInterac(-pairemin.second, pairemin.first, pairemax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				
				TransfertPaypal* transfert = new TransfertPaypal(-pairemin.second, pairemin.first, pairemax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			//changement dans les conteneurs des valeurs des comptes
			 //#declaration de variables

			pairemax.second += pairemin.second;
			
			pairemin.second = 0;
			/*gestionnaireUtilisateurs_->setCompte(pairemax);
			gestionnaireUtilisateurs_->setCompte(pairemin);*/
			
		}
		else if (-pairemin.second > pairemax.second  && pairemin.second != 0 && pairemax.second != 0) {
			if (pairemin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(pairemax.second, pairemin.first, pairemax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(pairemax.second, pairemin.first, pairemax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			pairemin.second += pairemax.second;
			pairemax.second = 0;
			
			

		}

		gestionnaireUtilisateurs_->setCompte(pairemax);
			gestionnaireUtilisateurs_->setCompte(pairemin);
		// On incremente le nombre de comptes mis a 0
		count++;
		if (-pairemin.second == pairemax.second) {
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getNombreElements() - 1) {
			calcul = false;
		}
	}




	// On cherche le compte le plus eleve et le moins eleve
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
		for (int i = 0; i < groupe.getComptes().size(); i++) {
			os << groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first->getNom() << " : " << groupe.getComptes()[i] << endl;
		}
	}

	os << endl;
	return os;
}



