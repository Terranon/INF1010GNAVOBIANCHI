/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#pragma once
#include <map>//inclusion de la bibliothéque map
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include <vector>
#include<functional>
class AjouterDepense  {

public:
	//Constructeur
	AjouterDepense(vector<Depense*>&depense):conteneur_(depense) {};

	//OPERATOR()
	vector<Depense*>& operator()(Depense* depense) {conteneur_.push_back(depense);return conteneur_;};

	private:
	vector<Depense*> conteneur_;


};





/**/

class AjouterUtilisateur //

{

public:
	//Constructeur :passage par réference constante 
	
	AjouterUtilisateur( map<Utilisateur*, double>& conteneur ):conteneur_(conteneur) {
			//ici on peut directement faire cet 
	};//ici on peut utiliser this car les conteneurs ont le meme nom
	
	map<Utilisateur*, double>& operator()(Utilisateur* utilisateur) {
		//verifier si l'utilisateur est ajoutable
			//verifier si l'utilisateur existe deja dans la map également car chaque clé est unique /*
		 //auto fin = conteneur_.end();
		 //for ( auto i = conteneur_.begin() ; i != fin ; i++ )
	/*	 for(const pair<Utilisateur*, double> element : conteneur_) //il retourne chaque pair d'element du conteneur
		 {
			 if ( element.first == utilisateur )
			 {
				 cout << "cet utilisateur existe deja.Vous ne pouvez pas le réajouter" << endl;
				 return conteneur_;  //sortira directement de la classe sans avoir inserer la cle utilisateur
			 }
		 }
		 */
		//la valeur du double sera 0 car l'utilisateur vient d'etre ajouter;


		  
		 if (dynamic_cast<UtilisateurPremium*>(utilisateur)) {
			 if ( dynamic_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() != 0)
				 //conteneur_.insert(make_pair(utilisateur, 0));
				 conteneur_.insert(pair<Utilisateur*, double>(utilisateur, 0));//fonction insert map!!
			 //--un insert qui fait un make pair // implace(valeurs)
			 else
				 cout << "l'utilisateur" << utilisateur->getNom() << "doit renouveller son abonnement" << endl;
		 
		 
		 
		 
		 
		 }
		 else
		 {
			 if ( dynamic_cast<UtilisateurRegulier*>(utilisateur)->getPossedeGroupe() == 0) {//l'utilisateur n'a pas de groupe
				 //conteneur_.insert(pair<Utilisateur*, double>(utilisateur, 0));//fonction insert map!!
				 conteneur_.insert(make_pair(utilisateur, 0));
				 dynamic_cast<UtilisateurRegulier*>(utilisateur)->setPossedeGroupe(true);//l'utilisateur possede alors un groupe puisqu'il est ajouter au conteneur 
			 }
			 else
				 cout << "l'utilisateur" << utilisateur->getNom() << "est deja groupe" << endl;
		 }
		
		return conteneur_;
		//comment ajouter l'utilisateur deja fait par la vérification
	
	};

private:
map<Utilisateur*, double>& conteneur_;
};
//mettre le template egalement


class FoncteurIntervalle{
public:
	FoncteurIntervalle(double inf,double sup):borneInf_(inf),borneSup_(sup) {};
	bool operator()(const pair< Utilisateur*, double> &( utilisateur)) { //parametre passe par référence car l'utilisateur existe--quand je le passe par référence le compilateur le voit comme une erreur
	
                //si le compte associé a paire est compris entre l'intervalle donné  on retourne le booleen true
			if (utilisateur.second >=borneInf_ && utilisateur.second<=  borneSup_)
				   return true;
		return false;
	
	};

private:
double borneInf_, borneSup_;
};



