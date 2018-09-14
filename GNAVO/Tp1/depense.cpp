#include "pch.h"//fini
#include "depense.h"

//Constructeur par defaut depense
Depense::Depense()
{
	cout << "contructeur par defaut"<<endl;
	titre_ = "unknown";
	montant_ = 0;
}

//Constructeur par parametre

Depense::Depense(string &titre,double montant)// mmeyttre un const string
//l'eperluette
{
	cout << "contructeur par defaut"<<endl;
	titre_ = titre;
	montant_ = montant;
	//faut t'il considerer qu'il s'agisse d'une agregation ? non ce N'est pas l'utilisatuo
	//d'une classe par une autre


}

//methode d'acces aux attributs

//type nomdelaclasse::nomfonction(parametre)
double Depense::getMontant() const
{
	return montant_;// la methode  un acces direct au attributs de depense

}
string Depense::getTitre() const 
{
	return titre_;// la methode a acces aux attributs donc c'est autorisé



}
//methodes de modifications

void Depense::setMontant(double montant)//ne pas oublier de preciser a
//quelle classe appartient lamethode je vais ajouter l'herperluette?
{
	montant_ = montant;
}
void Depense::setTitre(string& titre)// l'eperluette pour un appel par parametre
//le titre est modifie a la source tandis que le montant est copie 
{
	titre_ = titre;

}

// methode d'affichage  //afficher en passant par des methodes constantes
void Depense::afficherDepense() const {
	cout << "la depense effectue est :" << montant_ << "par" << titre_;//on peut utiliser les attibuts 
	//prives car la fonction appartient a la classe//grace a la definition de la classe 
	//on aurait pu ecrire aussi :
	//cout << "la depense effectue est :" << getMontant()<< "par" << getTitre();

}