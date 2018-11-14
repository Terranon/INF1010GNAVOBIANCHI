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
		/*unsigned compteur=0;
		auto fin = conteneur_.end();
		//C::iterator fin = conteneur_.end();renvoie une erreur --mieux vaut utiliser auto
	///	for (C::iterator debut = conteneur_.begin() : C::iterator fin = conteneur_.end())//parcourt chaque element du conteneur --syntaxe
		for (auto debut = conteneur_.begin(); debut != fin;debut++)

		{
			compteur++;
		} 
		return compteur;*/
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
		for (i; position != i; i++) { return *position; }//la fonctiion ne fera qu'augmenter l'itérateursans effectuer d'autres instructions*/
	/*	auto position = conteneur_.begin();
		position += i;//refusé par le compilateur pourquoi?
		return *position;*/
		//retourne le contenu pointé par l'itérateur
		
	};

	protected :
	C conteneur_;
	




	};
	