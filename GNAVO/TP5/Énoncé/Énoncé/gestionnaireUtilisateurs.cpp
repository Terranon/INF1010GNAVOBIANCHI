/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include "iostream"//&&&&
#include <algorithm>
#include <iterator>
//#include <functional>

using namespace std;//&&&&
using namespace std::placeholders;


//GestionnaireUtilisateurs::GestionnaireUtilisateurs() {
//
//
//	//ajouter les utilisateurs de l present dans le groupe????
//
//
//
//
//
//
//};
vector<double> GestionnaireUtilisateurs::getComptes() const {/*return ...*/
	
	
	//Premiere version:
	/*vector<double>compte;
	for (unsigned int i = 0; i < getNombreElements(); i++) {
		//pas n�cessaire on connait le nombre d'�l�ment du conteneur if (estExistant(getConteneur().begin()+i))//si l'utilisateur existe pusher son compte
       
        compte[i]= getElementParIndex(i).second;//pour obtenir le deuxieme champs des pairs retourn�s par l'index
	 }		
	return compte;*/
	//2eme version
	vector<double>compte;
	
	unsigned int index  = 0;
	for (auto it = conteneur_.begin(); it !=conteneur_.end() ; it++) {
		//pas n�cessaire on connait le nombre d'�l�ment du conteneur if (estExistant(getConteneur().begin()+i))//si l'utilisateur existe pusher son compte

		compte.push_back( getElementParIndex(index).second);//pour obtenir le deuxieme champs des pairs retourn�s par l'index
		index++;
	}

	return compte;

	/*	vector<double> compte;
	copy(conteneur_.begin()->second, conteneur_.end()->second, back_inserter(compte));//copie les doubles du conteneur dans le compte

	return compte;*///refuse par le compilateur

};
/*cette m�thode pourrait etre rempla�� par une m�thode que nous enverra les charg�s de lab*/
bool GestionnaireUtilisateurs::estExistant(Utilisateur* payePar) const {
	//parcourir le conteneur 
	auto fin = conteneur_.end();
	for (auto i = conteneur_.begin(); i != fin; i++) {
    //chercher une cle utilisateur correspondant a 'payePar' ) 
		
		if (i->first == payePar) //si le 1er element du contenu pointe par l'iterateur correspond a paye par 
			
			return true;
		
	}

	return false;



};
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant) {



	/*Met � jour 
les comptes avec le montant pass� en param�tre. (
R�f�rez
-
vous � la m�thode 
ajouterDepense de la classe Groupe)*/
 

	//verifier que payepar existe dans le conteneur
	if(estExistant(payePar)){
		
		

	
	    //pour garder la variable payeur
		auto payeur = conteneur_.begin();
		auto it = conteneur_.begin();
		auto fin = conteneur_.end();
		for (it; it != fin; it++) {//parcourir le conteneur
			if (it->first == payePar)
				payeur = it;//variable locales d'ou la necessit� de declarer payeur plus haut
		
		}
	//mis a jour des comptes
	double montantReparti = montant / getNombreElements();
		//lui rajouter a son compte le montant qu'il a paye moins le montant du groupe
	payeur->second += montant - montantReparti;

	//parcourir la boucle et retirer a tous les elements suf le payeur le montant reparti
	//auto fin = conteneur_.end();
		for ( it = conteneur_.begin(); it != fin; it++)
		{
			//if (it->first != payePar)//si le champ Utilisateur de it est different  de l'adresse de paye par 
			if(it!=payeur)//si l'iterateur it est different de l'iterateur payeur
				it->second -= montantReparti;

		}
	 
			//rajouter a tous le monde sauf lui le montant reparti 

	}
	
	

	


};
pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const {


	

	
	auto fin = conteneur_.end();
	auto it = conteneur_.begin();
	double max = it->second;//initialisation de la valeur max a la valeur du compte du premier utilisateur
	Utilisateur* umax = it->first;
	for (it ;it != fin; it++)//parcourir le conteneur (map)
	{
	    //chercher la valeur de compte la plus �lev� 
		if (it->second > max)
		{
			max = it->second;//sauvegarde dans la variable max la valeur de compte superieur apres la comparaison
			umax = it->first;//sauvegarde dans la variable umax l'adresse de l'utilisateur adequat
			///////////////////////////////????une meilleure maniere serait de retourner l'iterateur it non car il retournerait le premier �l�ment qui serait sup�rieur a max


		}
			
	}
	
	//apres avoir parcouru le conteneur ,pour la valeur max qui correspond a un utilisateur  creer une paire
	pair < Utilisateur*, double>pairemax = make_pair(umax, max);

	
	 return pairemax;


	
	//comment retourner l'it�rator en entier *it pour avoir un retour d'une r�f�rence par param�tre  //retuen *it; le compilateur le refuse t'il parce que c'est une erreur ou quoi?

};
pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const {


	auto fin = conteneur_.end();
	auto it = conteneur_.begin();
	double min = it->second;//initialisation de la valeur maxa la valeur du compte du premier utilisateur
	Utilisateur* umin = it->first;
	for (it; it != fin; it++)//parcourir le conteneur (map)
	{
		//chercher la valeur de compte la plus basse 
		if (it->second < min)
		{

			min = it->second;//sauvegarde dans la variable max la valeur de compte superieur apres la comparaison
			umin = it->first;//sauvegarde dans la variable umax l'adresse de l'utilisateur adequat
			

		}

	}

	//apres avoir parcouru le conteneur ,pour la valeur max qui correspond a un utilisateur  creer une paire
	pair < Utilisateur*, double>pairemin = make_pair(umin, min);


	return pairemin;



	//comment retourner l'it�rator en entier *it pour avoir un retour d'une r�f�rence par param�tre  //retuen *it; le compilateur le refuse t'il parce que c'est une erreur ou quoi?





};
Utilisateur * GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const {


	
	pair<Utilisateur*,double> p = make_pair(utilisateur,montant);

	auto iterateurcourant = find_if(conteneur_.begin(), conteneur_.end(), bind(equal_to<pair<Utilisateur*,double>>(),_1,p));//il trouve directemeent l"utilisateur qui suit/
	//auto trouve = iterateurcourant;//retourne toujours le meme utilisateur sans l'ajouter
	 iterateurcourant++;//faire pointer l'it�rateur courant sur le prochain

	//Utilisateur* suivant = trouve->first;//suivant est l'utilisateur de la paire sur laquelle pointe l'it�rateur trouv�
 Utilisateur* suivant = iterateurcourant->first;

	//chercher l'iterateur correspondant et le dereferencer pour le comparer avec le pointeur d'utilisateur
	if (estExistant(suivant))
	{
		return suivant;	// retourner l'utilisateur suivant puisqu'il existe
	}
	else  //afficher un message d'erreur et retourner l'utilisateur courant
	{
		cout << "Erreur!L'utilisateur " << suivant->getNom() << "est le dernier utilisateur de la liste.Il n'y aucun autre qui le suit ." << endl;
		return iterateurcourant->first;
	}
	


};
vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {

	vector<pair<Utilisateur*, double>> utilisateurentre ;
	
	 copy_if(conteneur_.begin(), conteneur_.end(),back_inserter(utilisateurentre),FoncteurIntervalle  (borneInf, borneSup));//on fait un "push_back' de l"element dans le conteneur si le predicat p est vrai
	//copy_if(conteneur_.begin(), conteneur_.end(), ostream_iterator<pair<Utilisateur*, double>>(cout), FoncteurIntervalle(borneInf, borneSup));//on fait un "push_back' de l"element dans le conteneur si le predicat p est vrai
	return utilisateurentre;

};
GestionnaireUtilisateurs& GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double>p) {


	//verifier que l'utilisateur existe
	if (estExistant(p.first)) {
	
		//parcourir le conteneur a la recherche de l'utilisateur

		
		//auto utilisateur=find_if(conteneur_.begin(), conteneur_.end(), bind(equal_to <pair<Utilisateur*,double>>(), _1, p));//le premier bind renvoie true si il trouve l'iterateur en question*/
		auto it = conteneur_.begin();
		auto fin = conteneur_.end();
		double montant = p.second;
		for (it; it != fin; it++) {//parcourir le conteneur
			if (it->first == p.first)
				it->second = p.second;//#le contenu du champs double devient egale au compte en param�tre
		
		
		}

	
	}
	

	
	return *this;

};
