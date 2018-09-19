#include "pch.h"//fonctio ajouter depenses 
#include "groupe.h"
//inclure les utilisateur
#include "utilisateur.h"

Groupe:: Groupe()
{
	nom_ = "unknown";
	totalDepenses_ = 0;
	listeUtilisateurs_ = new Utilisateur*[5];
	nombreDepenses_=0;
	nombreUtilisateurs_=0;
	tailleTabUtilisateurs_=0;
	tailleTabDepenses_=5;
	listeDepenses_=new Depense*[5];
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
	listeDepenses_ = new Depense*[5];//toujoirs mettre des taILLES DS LES TABLEAUX
	comptes_ = new double[1];
	listeTransferts_ = new Transfert*[4];
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



}
//methode d'ajout de depense
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar)//verifiersi le tableau de depense du groupe a assez de place
// l'ajouter a la liste depense prend un utilisateur et les depenses
{
	if (nombreDepenses_ > tailleTabDepenses_) {//si le nombre de depense est superieur a celle de la liste
										 //////////////	{
		Depense** temp = new Depense*[tailleTabDepenses_ + 5];//ajouter un element depense* a la liste de depense										 //////////////		
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {//efface les espaces inutiles dans le tableau
			listeDepenses_ = new Depense*[5];
			temp[i] = listeDepenses_[i];


		}
		delete[] listeDepenses_;//supprime le tableau liste de pense:il ne pointe plus sur rien

		listeDepenses_ = temp;//liste depense et temp pointe sur les mm choses donc pas de fuite de memoire
	}

	//for (unsigned int i=0;i<;i++) verifier  l'utilisateur correspondantau nom donne
//	bool existe=true;
//	for (int i = 0; i > nombreUtilisateurs_; i++)
//	{
//		if (payePar == listeUtilisateurs_[i])
//			existe = true;
//		else
//			existe = false;
//
//	}
//	if (existe)
//	{
//		ajouterUtilisateur(payePar);
//
//	}
//	else
//	{
//		ajouterUtilisateur(payePar);
//
//	}
	payePar->ajouterDepense(uneDepense);
	nombreDepenses_++;
	
}



//- Une méthode calculerTotalDepenses()
void Groupe::calculerTotalDepenses()
{
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	{
		totalDepenses_= totalDepenses_+listeUtilisateurs_[i]->getTotal();	
	}
	double moyenne = (totalDepenses_/nombreUtilisateurs_);
	
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		
		// met la difference entre la depense totale de chaque utilisateur et la moyenne de depenses totales
		comptes_[i] = listeUtilisateurs_[i]-> getTotal() - moyenne;

		
	}
}




void Groupe::equilibrerComptes()
{//on cherche le compte max puis  les autres luis donnes
	Transfert** t = new Transfert*[5]();
	//nbfor (int i=0;i>nombreUtilisateurs_;i++)



	for (unsigned int i = 0; i < 2; i++) {//je sais pas encore comment minimiser les transferts
			//Utilisateur* code= listeTransferts_[i]->getReceveur();
			//cout << code;
			cout << "entrer1";
			
			/*if (max<comptes_[i])
			max = comptes_[i];*/
			//while (comptes_[i] != 0) {
		for (unsigned int j = 1; i < 5; i++)
		{
			//listeTransferts_[i] = *t;//initiaisation
		
				//listeTransferts_[i][i].setReceveur(listeUtilisateurs_[i]);//pourquoi je peux pas ecrire sdans la classe transfert
					 cout << " entrer 2 ";
				if ((comptes_[i]>comptes_[j]) && (comptes_[j]<0)) {
					cout << "entrer 3 ";
					//si i j alors envoie compte de j a compte i et diminue compte i a 0
					cout << listeUtilisateurs_[j];
					//ex le  compte a 4 frcs et le compte a -24frc ne peut lui donner que 4frcs
					if (comptes_[i] < abs(comptes_[j]))//le donneur est a 24 et le receveur a 4
					{
						cout << "entrer 4 ";
						
						listeTransferts_[i]->setMontant(comptes_[i]);
						listeTransferts_[i]->setDonneur(listeUtilisateurs_[j]);
						listeTransferts_[i]->setReceveur(listeUtilisateurs_[i]);
						nombreTrensferts_++;
						cout << "le compte le plus petit j" << j << " devient " << comptes_[j]+comptes_[i];
						comptes_[i] = 0;
						cout << "le compte le plus grand i" << i << " est " << comptes_[i];
						comptes_[j] =  comptes_[j] + comptes_[i];
						break;//sortir du for car le compte i est a 0;
					}
					if (comptes_[i] > abs(comptes_[j])) // receveur 56    donneur -4 
					
					{
						cout << " entrer 5";
						listeTransferts_[i]->setDonneur(listeUtilisateurs_[j]);
						listeTransferts_[i]->setReceveur(listeUtilisateurs_[i]);
						
						double t = abs(comptes_[j]);
						listeTransferts_[i] -> setMontant(4);
						
						
						nombreTrensferts_++;
						cout << "le compte le plus petit j" << j << "devient " << comptes_[j];
						comptes_[i] = comptes_[i] + comptes_[j];
						cout << "le compte le plus grand i" << i << "est " << comptes_[i];
						comptes_[j] = 0;
					}
					
					
					
					
					
				}	//travailler avec les valeurs min et max
				
				
					
					
				
			}


		


	}


}


//Une méthode d’affichage
void Groupe::afficherGroupe() 
{
	//for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
	//	listeUtilisateurs_[i]->afficherUtilisateur;

}




