/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#pragma once
#include "foncteur.h"/// ne pas inclure le fichier foncteur
template<typename T,typename C,typename D ,typename FoncteurAjouter >
class GestionnaireGenerique
{
public:

	//consturcteur

	C  getConteneur() const {


		return conteneur_;

	};
	void ajouter(T t) {
	
		FoncteurAjouter foncteur (conteneur_);//appel du constructeur avec en parametre le constructeur
		
		conteneur_=foncteur(t);//changer le conteneur directement
	};
		
		
		
	

	int getNombreElements() const {//peut on juste retourner le conteneur.size()
		
		return conteneur_.size();
	};
	/*
	Parametres d'entree:int 
	Parametre de retour :D
	methode retourne le nombre d'elements
	*/
	D getElementParIndex(int i) const {		
		return *next(conteneur_.begin(), i);//il avance de i elements
		
		/*auto position = conteneur_.begin();
		for (int t=0;t<i;t++)
		position++;;//
		return *position;*/

		
	};

	protected :
	C conteneur_;
	




	};
	