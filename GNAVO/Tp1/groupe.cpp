#include "pch.h"//fonctio ajouter depenses 
#include "groupe.h"
//inclure les utilisateur
#include "utilisateur.h"

Groupe:: Groupe()
{
	nom_ = "unknown";
	totalDepenses_ = 0;
	listeUtilisateurs_ = new Utilisateur*[1];
	nombreDepenses_=0;
	nombreUtilisateurs_=0;
	tailleTabUtilisateurs_=0;
	tailleTabDepenses_=5;
	listeDepenses_=new Depense*[1];
	comptes_ = new double[1];
	listeTransferts_= new Transfert* [1];
	nombreTrensferts_=0;

}
Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs)
{
	nom_ =nom;
	totalDepenses_ = 0;
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs];//il faut toujoiurs initialiser les pointeurs
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabUtilisateurs_ = tailleTabUtilisateurs;
	tailleTabDepenses_ = tailleTabDepenses;
	listeDepenses_ = new Depense*[1];//toujoirs mettre des taILLES DS LES TABLEAUX
	comptes_ = new double[1];
	listeTransferts_ = new Transfert*[1];
	nombreTrensferts_ = 0;
}
//appel au destructeur
Groupe::~Groupe() {
	delete listeTransferts_;
	delete comptes_;
	delete listeUtilisateurs_;
}

//methode d'acces aux attributs
string Groupe::getNom()const {
	return nom_;
};
unsigned Groupe::getNombreDepenses()const {
	return nombreDepenses_;
}
double Groupe::getTotal()const
{
	return totalDepenses_;
};
//methodes de modifications
void Groupe::setNom(string& nom) 
{

	nom_ = nom;

};
void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur)

{
	//nouveau code
	if (nombreUtilisateurs_ > tailleTabUtilisateurs_)
	{
		Utilisateur** temp = new Utilisateur*[tailleTabUtilisateurs_ + 5];
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		{
			//declarer une liste
			temp[i] = listeUtilisateurs_[i];
			
			
		}
		delete [] listeUtilisateurs_;
		listeUtilisateurs_ = temp;
	}
	
	listeUtilisateurs_[nombreUtilisateurs_] = unUtilisateur;
	nombreUtilisateurs_++;
	//le mettre a l'interieur de if?
	
	//faire attention avec es declarartions globales et locales
	// ancien code
	//if (nombreUtilisateurs_ > tailleTabUtilisateurs_)
		//{//si le nombre de depense est superieur a celle de la liste
		//										 //////////////	{
		//	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_++];//ajouter un element depense* a la liste de depense										 //////////////		

		//	listeUtilisateurs_[tailleTabUtilisateurs_] = unUtilisateur;
		//}
		//else
		//	listeUtilisateurs_[nombreUtilisateurs_] = unUtilisateur;// vu que le nombre de depenses 
		////n'atteint pas la taille du tableau  il faut mettre la prochaine valeur directement a sa suite

		//for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) 
		//{//efface les espaces inutiles dans le tableau
		//	if (listeUtilisateurs_[i] != nullptr)
		//		delete listeUtilisateurs_[i];
		//}


}
//methode d'ajout de depense
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar)//verifiersi le tableau de depense du groupe a assez de place
// l'ajouter a la liste depense prend un utilisateur et les depenses
	{
	if (nombreDepenses_ > tailleTabDepenses_) {//si le nombre de depense est superieur a celle de la liste
										 //////////////	{
		Depense** temp = new Depense*[tailleTabDepenses_ + 5];//ajouter un element depense* a la liste de depense										 //////////////		
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {//efface les espaces inutiles dans le tableau
			listeDepenses_ = new Depense*[1];
			temp[i] = listeDepenses_[i];


		}
		delete[] listeDepenses_;//supprime le tableau liste de pense:il ne pointe plus sur rien

		listeDepenses_ = temp;//liste depense et temp pointe sur les mm choses donc pas de fuite de memoire
	}
	
	//for (unsigned int i=0;i<;i++) verifier  l'utilisateur correspondantau nom donne

	payePar -> ajouterDepense(uneDepense)  ;
	
	
}



//- Une méthode calculerTotalDepenses()
void Groupe::calculerTotalDepenses()
{
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
	{
		totalDepenses_ =  + listeUtilisateurs_[i]->getTotal();
		
		cout << totalDepenses_;
	}
	for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++) { // met la difference entre la depense totale de chaque utilisateur et la moyenne de depenses totales
		comptes_[i] = listeUtilisateurs_[i]->getTotal() - (totalDepenses_ / nombreUtilisateurs_);
		cout << comptes_[i];
	}
}

//
//- Une méthode équilibrerComptes()
void Groupe::equilibrerComptes()
{
	
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {//je sais pas encore comment minimiser les transferts
		while (comptes_[i] != 0) {
			for (unsigned int j = 0; i < nombreUtilisateurs_; i++) {
				if (comptes_[i] > comptes_[j]) {//si i `j alors envoie ompte de j a compte i et diminue compte i a 0
					listeTransferts_[i]->setMontant(comptes_[j]);
					listeTransferts_[i]->setDonneur(listeUtilisateurs_[j]);
					listeTransferts_[i]->setReceveur(listeUtilisateurs_[i]);//uti j envoie a utili i le montant de comte
					//travailler avec les valeurs min et max
					comptes_[j] = 0;
					comptes_[i] = comptes_[i] - comptes_[j];
				}// ce n'est^pas sans faille repetitition der comptes
			}
			
				
		}
					//fera lexcecution si compte i = omote j
			/*if (comptes_[i] < 0) {
			int montant = comptes_[i];
			string donneur
				= listeUtilisateurs_[i]->getNom();
			for (unsigned int i=i+1; i < nombreUtilisateurs_; i++)
				if (comptes_[i]==montant)*/

		}


	}




//Une méthode d’affichag
void Groupe::afficherGroupe() 
{
	//for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
	//	listeUtilisateurs_[i]->afficherUtilisateur;

}



//private:
//	string nom_;
//	double totalDepenses_;
//	Utilisateur** listeUtilisateurs_;
//	unsigned int nombreDepenses;           //1
//	unsigned int nombreUtilisateurs_;
//	unsigned int tailleTabUtilisateurs_;
//	unsigned int tailleTabDepenses_;         //1
//	Depense** listeDepenses_;                 ///1
//	double* comptes_;
//	Transfert** listeTransferts_;
//	unsigned int nombreTrensferts_;
//Methodes d'ajout
//////////////void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar)
//////////////{
//////////////	if (nombreDepenses_ < tailleTabDepenses_)//si le nombre de depense est superieur a celle de la liste
//////////////	{
//////////////		listeDepenses_=new Depense*[tailleTabDepenses_++];//ajouter un element depense* a la liste de depense
//////////////		
//////////////														  puis ajouter une element a la valeur pointer par le une depense (liste depense [0,1...])
//////////////
//////////////	}
//////////////
//////////////};



//////////////////void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
//////////////////
//////////////////
//////////////////}

//Une méthode calculerTotal(), qui calcule le montant total des dépenses effectuées.


// methode d'affichage

