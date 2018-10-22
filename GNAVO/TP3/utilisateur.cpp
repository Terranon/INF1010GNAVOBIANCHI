#include "pch.h"// il reste les methodes d'acces//fini
/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "utilisateur.h"


Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type):
	nom_(nom),
	interet_(0),
	type_(type)
{
}


Utilisateur::Utilisateur(const Utilisateur& utilisateur):
	nom_(utilisateur.nom_),
	depenses_(utilisateur.depenses_),
	type_(utilisateur.type_),
	interet_(utilisateur.interet_)
{
	
	setDepenses(utilisateur.depenses_);

	/*for (unsigned int i=0;i<depenses_.size();i++)
		depenses_[i] = new Depense(utilisateur.depenses_[i]->getMontant());
*/
}

Utilisateur::~Utilisateur() {
//depenses_.clear;//retire tous les eleemenst du vecteur
	/*for (unsigned int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_ [i] = nullptr;
		depenses_.pop_back();//retire le dernier eleement du tableau}
	}
	depenses_.shrink_to_fit();//pour mettre le tableau a la taille et la size a 0
	*///car le destructeur d'utilisateur detruit les depenses qui sont deja detruites
}


// Methodes d'acces

string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalDepenses() const {
	
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_;
}

double Utilisateur::getInteret() const {
	return interet_;
}

unsigned int Utilisateur::getNombreDepenses() const {

	return depenses_.size();
}

vector <Depense*> Utilisateur::getDepenses() const 
{
return depenses_;

}

//Methodes de modification
void Utilisateur::setInteret(const double& interet) {
	interet_ = interet;

}
void Utilisateur::setDepenses(const vector<Depense*> depense) 
{

	for (unsigned int i = 0; i < getNombreDepenses(); i++)
	{
		delete depenses_[i];
		depenses_[i] = nullptr;
		//car les valeurs sont des pointeurs...
	}
	depenses_.clear();
	depenses_.shrink_to_fit();
	for (size_t i = 0; i < depense.size(); i++)
	{

		depenses_.push_back(new Depense(*depenses_[i]));//pour tuer le shallow copy
	}
}
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}


void Utilisateur::setType(TypeUtilisateur type) {

	type_ = type;

}

void Utilisateur::calculerTotalDepenses()
{
	 totalDepense_ = 0;

		for (unsigned int i = 0; i <getNombreDepenses(); i++)
	    {
			 if (this->depenses_[i]->getType() == groupe) {//utiliser this
			
				totalDepense_ += static_cast<DepenseGroupe*>(depenses_[i])->getMontantPersonnel();/// ?????????????????????????????????????
				//DepenseGroupe* toi= static_cast<DepenseGroupe*>(depenses_[i]);
				//static_cast<DepenseGroupe>(*depenses_[i]);//car le constructeur
				 
			}
			 else //if (depenses_[i]->getType() == individuelle )
			 {
				totalDepense_ += depenses_[i]->getMontant();
			
			 }
	    }
}
void Utilisateur::ajouterInteret(double montant) 
{
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {

	
	depenses_.push_back(depense);
	
	return *this;
}
Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur)
{
	if (this !=utilisateur)//on delete si ils sont < la même adresse
	{
		setInteret(utilisateur->getInteret());
		
		setNom(utilisateur->getNom());
		
		setDepenses(utilisateur->getDepenses());

		 setType(utilisateur->getType());
		calculerTotalDepenses();
	}
	
	
	return *this;//retourne l'objet pointé
}




// Methode d'affichage
ostream& operator<<(ostream& os, Utilisateur* utilisateur)

{//gettype donne le type en letttre
	if(utilisateur->getType()==Premium)
	os << "l'utilisateur " << utilisateur->getNom() << "(Premium)" << " a une depense total de " << utilisateur->getTotalDepenses() << ".Polycount prend  un interet de" << utilisateur->getInteret()<< endl;
	else
	os << "l'utilisateur " << utilisateur->getNom() << "(Regulier)" << " a une depense total de " << utilisateur->getTotalDepenses() << ".Polycount prend  interet de" << utilisateur->getInteret() << endl;

	os << "voici les depenses:";
	for (unsigned int i = 0; i < utilisateur->getDepenses().size(); i++)
	{

		if (utilisateur->getDepenses()[i]->getType() == groupe) 
		{
			
			DepenseGroupe *moi = static_cast<DepenseGroupe*>(utilisateur->depenses_[i]) ; 
			os  << static_cast<DepenseGroupe*>(utilisateur->depenses_[i]) << endl;
		}
		else
		{ 
			os << "voici les depenses:" << utilisateur->getDepenses()[i] << endl;
		}
			
	}

	return os;
	
}

