#include "pch.h"//fini
/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "depense.h"
#include <string>
// Constucteurs
using namespace std;
Depense::Depense() : nom_(""), montant_(0),lieu_(nullptr)
{
}
//le nom devrait donc avoir ete crer avant d'utiliser la reference constante;;;
//passer le nom par refernce constante dans ma tet veut dire qu'on n'effectue pas de copie donc il copie dans nom_ directement la valeur entree en parametre?
Depense::Depense(const string& nom, double montant,  string& lieu) : nom_(nom), montant_(montant),lieu_(&lieu)//pour que le lieu soit une adresse
{//lieu est un pointeur et sa variable affecte doit etre auusi un pointeur
	//passer par reference constance implique t'il que 
	//l'argument est une adresse??==c'est a dire un passage 
	//d'un objet par reference constante signifie t'il
	//que l'objet dans la liste d'initialisation est une adresse?
}
Depense::Depense(const Depense& objetCopie) : nom_(objetCopie.nom_), montant_(objetCopie.montant_), lieu_(nullptr)
{
	//lieu_(objetCopie->lieu_ pourquoi ne puis je mettre cette synthaxe dans la liste d'initialisation?
	//Reponse:pour eviter que ce soit juste le pointeur de lieu qui soit copié
	lieu_ = new string(objetCopie.getLieu());
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}
string Depense::getLieu() const {
	return *lieu_;//retourene la valeur a laquelle pointe lieu
}
// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}
void Depense::setLieu( string& lieu) {
	lieu_ = &lieu;//copie l'adreese de lieu dans l'attribue lieu
}
Depense& Depense::operator=(const Depense & objetCopie)//il s'agit de definir un = pour l'attribution
//doit je creer un nouvelle objet Depsense(exepmle depense objet) ou reutilsise  la depense ObjetCopie?
//Reponse non ,je crois que l'operateur =copie un objet existant ;
//Depense &operator=(const Depense & objetCopie) sous cette forme ce sera uniquement l'objetCopie qui sera
//utilise a chque fois que j'utiliserai l'operateur=

//realite: le prof a mis la synthaxe que je refuse Depense &operator=(const Depense & objetCopie)
{//nouvelle question:Si j'avais ecrit la synthaxe Depense &operator=(const Depense & objet) objet et objet copie  le resultat aurait t'il etet le memeÉ
	//reponse:je crois que oui mais un nouvelle espace aurait été crée pour objet....

//que veut t'on faire avec la methode operator=?
//on veut pouvoir attribuer des valeurs d'une depenses existante a une depense de notre choix(qu'elle soit existante ou non)
	

	//je vois l'utiliter de this ;c'est l'objet depense dont a besoin :)
	if (this != &objetCopie) //si l'adreesse l'objet courant est different de l'adresse de l'objet copie
	{
		delete lieu_;//on delete les anciens pointeurs  delete this->lieu_;
		//pour eviter la fuite de memoire
		//est ce que les correspondantes lignes en vert sont corrects?//
		nom_ = objetCopie.nom_;

	
		//objetCopie->lieu_; pourquoi ne puis je pas accceder au contenu pointer par cette methode

		//car objet copie n'est pas un pointeur on ne peut que faire objetCopie.lieu_;
		lieu_ = new string (*(objetCopie.lieu_));//on met le resultat a une nouvelle adresse
		montant_ = objetCopie.montant_;
		/*	this.nom_ = objetCopie.nom_;//non this est un pointeur de pointeur (this->nom;)
		this->lieu_ = objetCopie->lieu;//ici le resultat est mis a l'ancienne adresse de lieu qui avait ete dite invalide lors du delete lieu_
		this.montant_ = objetCopie.montant_;*/
		return *this;//pour permettre les appels en cascades *this est une reference a l'objet
	}

}
ostream& operator<<(ostream& os, const Depense& depense) //fonctions d'ou pas de Depnse ::
{
	
	//on veut pouvoir afficher les depenses 
	os << "Achat:" << depense.nom_ <<"Prix" << depense.montant_ << endl;

	return os;

}

// Methode d'affichage
//void Depense::afficherDepense() const {
//	cout << "Achat : " << nom_ << " Prix : " << montant_ << "; " << endl;
//}
