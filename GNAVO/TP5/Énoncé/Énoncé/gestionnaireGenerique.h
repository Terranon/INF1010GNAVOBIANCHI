/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#include "foncteur.h"/// ne pas inclure le fichier foncteur
template<typename T,typename C,typename D >
class GestionnaireGenerique
{
public:

	C getConteneur() const {


		return conteneur_;

	};
		template <typename FoncteurAjouter>
	void ajouter(T t) {
	

	 
	  FoncteurAjouter(t);
	
	};
		
		
		
	

	int getNombreElements() const {
		unsigned compteur=0;
		auto fin = conteneur_.end();
		//C::iterator fin = conteneur_.end();renvoie une erreur --mieux vaut utiliser auto
	///	for (C::iterator debut = conteneur_.begin() : C::iterator fin = conteneur_.end())//parcourt chaque element du conteneur --syntaxe
		for (auto debut = conteneur_.begin(); debut != fin;debut++)

		{
			compteur++;
		} 
		return compteur;
	};
	/*
	Parametres d'entree:int 
	Parametre de retour :D
	methode retourne le nombre d'elements
	*/
	D getElementParIndex(int i) const {		
//		return *next(conteneur_.begin(), i);//il avance de i elements
		/*auto position = conteneur_.begin();
		for (i; position != i; i++) { return *position; }//la fonctiion ne fera qu'augmenter l'itérateursans effectuer d'autres instructions*/
		auto position = conteneur_.begin();
		position += i;
		return *position;
		//retourne le contenu pointé par l'itérateur
		
	};

	protected :
	C conteneur_;





	};
	