/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifier par: Serge Gnavo
*			  : Maximilien Bianchi
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	Depense();
	Depense(const string& nom, double montant, const string& lieu);

	Depense(const Depense& objetCopie);

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string getLieu() const;

	// Methodes de modifications
	void setNom(const  string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);

	Depense &operator=(const Depense & objetCopie);//renvoie une depense qui ecrasera l'ancienne

												   // Methodes d'affichage
	friend ostream& operator<<(ostream& os, const Depense& depense);
	//on utilise friend lorsqu'il y a un parametre attribut prive et un autre public

private:
	string nom_;
	double montant_;
	string* lieu_;
};
#endif