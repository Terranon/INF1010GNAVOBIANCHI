#include "pch.h"// il reste les methodes d'acces//fini
#include "utilisateur.h"

//constructeur par defaut
 //nomdelaclasse::nomdelaclasse(){instructions}

Utilisateur::Utilisateur()
{
	nom_="unknown";
	tailleTabDepense_=5;
	nombreDepenses_=0;
	totalDepense_=0;
	listeDepenses_ = new Depense*[5];//nullptr ;// initialiser par defaut a nullptr?

}
Utilisateur::Utilisateur(string& nom)
{
	nom_ = nom;
	tailleTabDepense_ = 5;
	nombreDepenses_ = 0;
	totalDepense_ = 0;
	listeDepenses_ =new Depense*[5] ;

}
Utilisateur::~Utilisateur()
{
}

//Methode d'acces
string Utilisateur::getNom()const {
	return nom_;
}
unsigned int Utilisateur::getNombreDepense()const
{
	return nombreDepenses_;
}

double Utilisateur::getTotal()const
{
	return totalDepense_;
}

//methode de modifications
void Utilisateur::setNom(string&nom)  //toujours mettre le type en parametre aussi
{	
	nom_ = nom;

}
//methode d'ajout de depenses
void Utilisateur::ajouterDepense(Depense* uneDepense)
{
	if (nombreDepenses_ > tailleTabDepense_) {//si le nombre de depense est superieur a celle de la liste
											 //////////////	{
		Depense** temp = new Depense*[tailleTabDepense_+ 5];//ajouter un element depense* a la liste de depense										 //////////////		
		for (unsigned int i = 0; i < tailleTabDepense_; i++) {//efface les espaces inutiles dans le tableau
			temp[i] = listeDepenses_[i];
			listeDepenses_ = temp;
				delete [] temp;
		}
		
	}
		listeDepenses_[nombreDepenses_] = uneDepense;
		nombreDepenses_++;// vu que le nombre de depenses 
	//n'atteint pas la taille du tableau   il faut mettre la prochaine valeur directement a sa suite
		//mm si il ayyeint la taille du tableau

	//for (unsigned int i = 0; i < tailleTabDepense_; i++) {//efface les espaces inutiles dans le tableau
	//	if (listeDepenses_[i] != nullptr)
	//		delete listeDepenses_[i];
	//}
		 // ajout de la depense a la position de la taille du tableau
	
	//je propose : if (nombreDepenses_<=tailleTabDepense_)
	//                 listeDepenses_[nombreDepenses_] = uneDepense;
//////////////	n'oublie pas de delete	----non pas necessaire car on ajoute et le pointeur n'a fait qu'etre utiliser ds la fonction
	/*for (int i = 0; i<nombreDepenses_; i++)
		delete listeDepenses_[i]*/

}
// méthode calculerTotal(), qui calcule le montant total des dépenses effectuées.
void Utilisateur::calculerTotal() 
{
	for (unsigned int i = 0; i < nombreDepenses_; i++)
		totalDepense_ = totalDepense_+listeDepenses_[i]->getMontant();//car le pc m'a propose l'heperluette
	// ici il faut utiliser une methode pour acceder aux attributs prives de Depenses de depense
}

// methode d'affichage
void Utilisateur ::afficherUtilisateur()
{
	cout << nom_ << "a effectuer" << nombreDepenses_ << "depenses d'un montant total de" << totalDepense_ << endl;
}
