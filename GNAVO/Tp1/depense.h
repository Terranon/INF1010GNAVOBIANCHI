
#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>


using namespace std;


class Depense {
public:

	// constructeurs par défaut et parametres
	Depense();
	Depense(string& titre, double montant);//j'ai passe montant en parametre 
	//pour que le montant soitt modifie

	// methodes d'accès
	string getTitre()const; //methode constante pour éviter 
	//qu'elle ne change rien dans les attributs qu'elle retourne 
	double getMontant() const;

	//methodes de modifications
	void setTitre(string& titre) ;//je crois qu'il faut que la methode qui prenne soit constante
	void setMontant(double montant);


	//methode d'affichage
	void afficherDepense()const;

private:
	 string titre_;
	double montant_;

};

#endif

