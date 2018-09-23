#include "pch.h"//fonctio ajouter depenses 
#include "groupe.h"
//inclure les utilisateur


Groupe::Groupe():nom_ ( "unknown"),tailleTabDepenses_ ( 10),tailleTabUtilisateurs_ ( 5),nombreDepenses_ ( 0),nombreUtilisateurs_ ( 0),totalDepenses_ (0),nombreTrensferts_ ( 0)
{
	
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++) 
	{
		listeDepenses_[i] = nullptr;
	}
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int j=0;j<tailleTabUtilisateurs_;j++)
	{
		listeUtilisateurs_[j] = nullptr;
	}

	

}
Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs):nom_ ( nom),tailleTabDepenses_ ( tailleTabDepenses),tailleTabUtilisateurs_  (tailleTabUtilisateurs),nombreDepenses_ ( 0),nombreUtilisateurs_ ( 0),totalDepenses_  (0),nombreTrensferts_( 0)
	
{
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	for (unsigned int i = 0; i < tailleTabDepenses_; i++)
	{
		listeDepenses_[i] = nullptr;
	}
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	for (unsigned int j = 0; j < tailleTabUtilisateurs_; j++)
	{
		listeUtilisateurs_[j] = nullptr;
	}
}
//appel au destructeur
Groupe::~Groupe() {
	
	for (unsigned int i = 0; i < tailleTabDepenses_; i++) 
	{ // desallouer le tableau de depense
		delete listeDepenses_[i];
		listeDepenses_[i] = nullptr;
	}
	delete listeDepenses_;
	listeDepenses_ = nullptr;
	for (unsigned int j = 0; j < tailleTabUtilisateurs_; j++) 
	{ // desallouer le tableau d'utilisateurs
		delete listeUtilisateurs_[j];
		listeUtilisateurs_[j] = nullptr;
	}
	delete listeUtilisateurs_;
	listeUtilisateurs_ = nullptr;
	for (unsigned int k = 0; k < nombreUtilisateurs_; k++) 
	{ // desallouer le tableau de transfert
		delete listeTransferts_[k];
		listeTransferts_[k] = nullptr;
	}
	delete listeTransferts_;
	listeTransferts_ = nullptr;
	delete comptes_;			// desallouer les comptes
	comptes_ = nullptr;
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
	if (nombreUtilisateurs_ >= tailleTabUtilisateurs_)
	{
		tailleTabUtilisateurs_ += 5;
		Utilisateur** temp = new Utilisateur*[tailleTabUtilisateurs_];
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		{
			//declarer une liste
			temp[i] = listeUtilisateurs_[i];


		}
		delete[] listeUtilisateurs_;
		listeUtilisateurs_ = temp;
	}

	listeUtilisateurs_[nombreUtilisateurs_] = unUtilisateur;
	nombreUtilisateurs_++;
}
//methode d'ajout de depense
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar)

{
	if (nombreDepenses_ >= tailleTabDepenses_) {
						
		tailleTabDepenses_ += 5;
		Depense** temp = new Depense*[tailleTabDepenses_ ];										
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {
			
			temp[i] = listeDepenses_[i];
			

		}
		
		
		delete[] listeDepenses_;

		listeDepenses_ = temp;
	}

    listeDepenses_[nombreDepenses_] = uneDepense;
	payePar->ajouterDepense(uneDepense);
	nombreDepenses_++;


}



//- Une méthode calculerTotalDepenses()
void Groupe::calculerTotalDepenses()
{
	totalDepenses_ = 0;
	
	for (unsigned int i = 0; i < nombreDepenses_; i++)//calcule le total de chaque depense
	{
		totalDepenses_ +=  listeDepenses_[i]->getMontant();

	}
	for(unsigned int j=0;j<nombreUtilisateurs_;j++)//calcul le total de chaque utiliosateur
	{
		listeUtilisateurs_[j]->calculerTotal();
	}
	cout << totalDepenses_<<endl;
		double moyenne=totalDepenses_ / nombreUtilisateurs_;
		cout <<"La moyenne du groupe"<< moyenne<<endl;
		comptes_ = new double[nombreUtilisateurs_];
	for (unsigned int k = 0; k < nombreUtilisateurs_; k++) { // utiliser le nombre d'utilsateurs a la place de la tailletabutilisateur
		//cout << comptes_[i];
		comptes_[k] = listeUtilisateurs_[k]->getTotal()- moyenne;
		
	}
}

//- Une méthode équilibrerComptes()
void Groupe::equilibrerComptes()
{
	
		listeTransferts_ = new Transfert*[nombreUtilisateurs_];
		
		for (int k = 0; k < nombreUtilisateurs_; k++) 
		{
			listeTransferts_[k] = new Transfert  ();
			cout << " voici le compte  "<< k<<" " << comptes_[k]<<endl;
		}

	 

	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	{
		while (comptes_[i] >= 0.00001)// la valeur est diefferente de 0 pour supplanter le cas  des fractios irreductibles
		{
			
			

				/*cout << " voici le compte i " << comptes_[i]<<endl;*/
				for (unsigned int j = 0; j < nombreUtilisateurs_ || comptes_[j]== 0; j++)//utiliser while a la place j=1 car a j=0 il n,effecture rien
				//while ( j < nombreUtilisateurs_)
				{
				
					if(i!=j && comptes_[j] < 0){

						
							
							if (comptes_[i] > abs(comptes_[j]) )
							{
								listeTransferts_[nombreTrensferts_]->setDonneur(listeUtilisateurs_[j]);
								listeTransferts_[nombreTrensferts_]->setReceveur(listeUtilisateurs_[i]);
								listeTransferts_[nombreTrensferts_]->setMontant(abs(comptes_[j]));
						
								comptes_[i] = comptes_[i] + comptes_[j];
								comptes_[j] = 0;
								cout << " voici le compte j dans la boucle " << comptes_[j]<<endl;
								cout << " voici le compte i dans la boucle " << comptes_[i];
								
								nombreTrensferts_++;
						
								cout << " le nombre de transferts" << nombreTrensferts_ << endl;
								
							}
							else 
							
							{
								
								listeTransferts_[nombreTrensferts_]->setMontant(comptes_[i]);
								listeTransferts_[nombreTrensferts_]->setDonneur(listeUtilisateurs_[j]);
								listeTransferts_[nombreTrensferts_]->setReceveur(listeUtilisateurs_[i]);
								

						
								comptes_[j] = comptes_[i]+comptes_[j]; 
								comptes_[i] = 0;
								nombreTrensferts_++;
								
								
								
								cout << " le nombre de transferts" << nombreTrensferts_ << endl;
								
							}  
						
					}
					

					
				}
		}


	}

}




//Une méthode d’affichag
void Groupe::afficherGroupe()
{

	//Une méthode d’affichage qui affiche toutes les dépenses par utilisateur
	
	
	for (int i = 0; i < nombreUtilisateurs_; i++)
		listeUtilisateurs_[i]->afficherUtilisateur();
	//.les comptes(s’ilsne sont pas tous nuls),
	for (int j = 0; j < nombreUtilisateurs_; j++)
	{ 
		

		if (comptes_[j] != 0)
			cout <<"Le compte de  "<<listeUtilisateurs_[j]->getNom()<<" est: "<< comptes_[j]<<endl;
	 }

	
	for (int t = 0;t < nombreTrensferts_;t++)
	{
		if (listeTransferts_[t]->getMontant()!=0)
		cout << "Transfert fait par" << (listeTransferts_[t]->getDonneur())->getNom()<< " pour " << (listeTransferts_[t]->getReceveur())->getNom() << " d'un montant de "<< listeTransferts_[t]->getMontant() << endl;
	}



	

}

