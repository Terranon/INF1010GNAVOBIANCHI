/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#include <vector>

template<typename T, typename C, typename D, typename FoncteurAjouter>
class GestionnaireGenerique {
public:
	// Methodes d'access
	C getConteneur() const {
		return conteneur_;
	}
	int getNombreElements() const {
		return conteneur_.size();
	}
	D getElementParIndex(int i) const {
		return conteneur_[i];
	}

	// Methode de modification
	void ajouter(T t) {
		FoncteurAjouter foncteur(conteneur_);
		conteneur_ = foncteur(t);
	}

protected:
	C conteneur_;
};



