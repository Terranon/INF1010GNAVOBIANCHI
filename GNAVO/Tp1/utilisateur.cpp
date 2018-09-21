#include "pch.h"// il reste les methodes d'acces//fini
#include "utilisateur.h"

//constructeur par defaut
 //nomdelaclasse::nomdelaclasse(){instructions}

Utilisateur::Utilisateur()
{
	nom_="unknown";
	tailleTabDepense_= TAILLEDEPENSEINITIALE;//BONNE PRATIQUE
	nombreDepenses_=0;
	totalDepense_=0;
	listeDepenses_ = new Depense*[5];//nullptr ;// initialiser par defaut a nullptr?
	for(unsigned int i =0;i<nombreDepenses_;i++) 
	{
		listeDepenses_[i] = nullptr;
	
	}
		

}
Utilisateur::Utilisateur(string& nom)
{
	nom_ = nom;
	tailleTabDepense_ = 5;
	nombreDepenses_ = 0;
	totalDepense_ = 0;
	listeDepenses_ =new Depense*[5] ;
	for (unsigned int i = 0; i < nombreDepenses_; i++)
	{
		listeDepenses_[i] = nullptr;

	}
}
Utilisateur::~Utilisateur()
{
	for (unsigned int i = 0; i < tailleTabDepense_; i++) 
	{//effacer la taille du tableau
		delete listeDepenses_[i];
		listeDepenses_[i] = nullptr;
	}
	delete listeDepenses_;
	listeDepenses_ = nullptr;

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
void Utilisateur::ajouterDepense(Depense* uneDepense)//le tableau de depense de l'utilisateur a assez de place
{
	if (nombreDepenses_ > tailleTabDepense_) {//si le nombre de depense est superieur a celle de la liste
		tailleTabDepense_ += 5;
		Depense** temp = new Depense*[tailleTabDepense_];//ajouter un element depense* a la liste de depense										 //////////////		
		for (unsigned int i = 0; i < tailleTabDepense_; i++){//efface les espaces inutiles dans le tableau
			
			temp[i] = nullptr;
			temp[i] = listeDepenses_[i];
		}

		delete [] listeDepenses_;//supprime le tableau liste de pense:il ne pointe plus sur rien

		listeDepenses_ = temp;//liste depense et temp pointe sur les mm choses donc pas de fuite de memoire
	}
		listeDepenses_[nombreDepenses_] = uneDepense;//listeDepenses_[nombreDepenses_++];
		nombreDepenses_++;
	
}
// méthode calculerTotal(), qui calcule le montant total des dépenses effectuées.
void Utilisateur::calculerTotal() 
{
	totalDepense_ = 0;//pour eviter un ajout de total depense a cahque fois
	//que la methode est nouvellemenrt calcule
	for (unsigned int i = 0; i < nombreDepenses_; i++) 
	{
		totalDepense_+=   listeDepenses_[i]->getMontant();
		
	}//car le pc m'a propose l'heperluette
	// ici il faut utiliser une methode pour acceder aux attributs prives de Depenses de depense
}

// methode d'affichage
void Utilisateur ::afficherUtilisateur()
{
//	cout << nom_ << " a effectuer " << nombreDepenses_ << " depenses d'un montant total de " << totalDepense_ << endl;
	
	cout << nom_ << " a un total de depenses de " << getTotal() << endl;
	cout << "Liste de depenses:" << endl;
	for (unsigned int i = 0; i < nombreDepenses_; i++)
	{
		listeDepenses_[i]->afficherDepense();
	}

}
