#include "pch.h"//fonctio ajouter depenses 
#include "groupe.h"
//inclure les utilisateur
#include "utilisateur.h"

Groupe::Groupe()
{
	nom_ = "unknown";
	tailleTabDepenses_ = 10;
	tailleTabUtilisateurs_ = 5;
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	totalDepenses_ = 0;
	nombreTrensferts_ = 0;
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
	/*listeTransferts_ = new Transfert*[nombreUtilisateurs_];
	for (unsigned int k = 0; k < nombreUtilisateurs_; k++)
	{
		listeTransferts_[k] = nullptr;
	}*/



	
	
	
	
	
	
	//comptes_ = new double[nombreUtilisateurs_];
	
	

}
Groupe::Groupe(string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs)
{
	nom_ = nom;
	
	tailleTabDepenses_ = tailleTabDepenses;
	tailleTabUtilisateurs_ = tailleTabUtilisateurs;
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	totalDepenses_ = 0;
	nombreTrensferts_ = 0;
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
	if (nombreDepenses_ >= tailleTabDepenses_) {//si le nombre de depense est superieur a celle de la liste
						
		tailleTabDepenses_ += 5;
		Depense** temp = new Depense*[tailleTabDepenses_ ];//ajouter un element depense* a la liste de depense										 //////////////		
		for (unsigned int i = 0; i < tailleTabDepenses_; i++) {//efface les espaces inutiles dans le tableau
			
			temp[i] = listeDepenses_[i];
			

		}
		//ajouter la depense a l'evenement
		
		delete[] listeDepenses_;//supprime le tableau liste de pense:il ne pointe plus sur rien

		listeDepenses_ = temp;//liste depense et temp pointe sur les mm choses donc pas de fuite de memoire
	}

    listeDepenses_[nombreDepenses_] = uneDepense;
	payePar->ajouterDepense(uneDepense);
	nombreDepenses_++;


}



//- Une méthode calculerTotalDepenses()
void Groupe::calculerTotalDepenses()
{
	totalDepenses_ = 0;
	//for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	//{
	//	totalDepenses_ = totalDepenses_ + listeUtilisateurs_[i]->getTotal();

	//}
	// pas besoin de passer apr les classes utilisateurs ;le groupe a deja une liste de depenses
	for (unsigned int i = 0; i < nombreDepenses_; i++)//calcule le total de chaque depense
	{
		totalDepenses_ +=  listeDepenses_[i]->getMontant();

	}
	for(unsigned int j=0;j<nombreUtilisateurs_;j++)//calcul le total de chaque utiliosateur
	{
		listeUtilisateurs_[j]->calculerTotal();
	}
		double moyenne=totalDepenses_ / nombreUtilisateurs_;
		comptes_ = new double[nombreUtilisateurs_];
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) { // utiliser le nombre d'utilsateurs a la place de la tailletabutilisateur
		//cout << comptes_[i];
		comptes_[i] = listeUtilisateurs_[i]->getTotal()- moyenne;
		//cout<<comptes_[i]<<endl;
	}//pour avoir acces au 5 eme utilisateur
}

//- Une méthode équilibrerComptes()
void Groupe::equilibrerComptes()
{
	
	
		listeTransferts_ = new Transfert*[nombreUtilisateurs_];
		
		for (int i = 0; i < nombreUtilisateurs_; i++) 
		{
			listeTransferts_[i] = new Transfert  ();
		}

		listeTransferts_ == &(listeTransferts_[0]);
		cout << listeTransferts_;
		//donner a liste transfert l'adresse du premier element de son tableau tableau
	//Transfert** temp=new Transfert*[8];
	//Transfert **tempo = new Transfert*[8];

	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
	{
		while (comptes_[i] >= 1)//pour le faire passer la boucle
		{
			
			

				cout << " voici le compte i " << comptes_[i]<<endl;
				for (unsigned int j = 0; j < nombreUtilisateurs_ || comptes_[j]==0; j++)//utiliser while a la place j=1 car a j=0 il n,effecture rien
				//while ( j < nombreUtilisateurs_)
				{
					//if (comptes_[j] = 0)
						//break;
					cout << j<<" eme iterations "<<endl;
					cout << " voici le compte j " << comptes_[j];
					cout << " voici le compte i " << comptes_[i];
					if(i!=j && comptes_[j] < 0){

						
							
							if (comptes_[i] >= abs(comptes_[j]) )//utiliser -compte a la pace de abs
							{//si i `j alors envoie ompte de j a compte i et diminue compte i a 0
								cout << " 1er if" << endl;
								listeTransferts_[j]->setDonneur(listeUtilisateurs_[j]);
								listeTransferts_[j]->setReceveur(listeUtilisateurs_[i]);
								listeTransferts_[j]->setMontant(abs(comptes_[j]));
						
								comptes_[i] = comptes_[i] + comptes_[j];
								comptes_[j] = 0;
								/*cout << " voici le compte j dans la boucle " << comptes_[j]<<endl;
								cout << " voici le compte i dans la boucle " << comptes_[i];*/
								//travailler avec les valeurs min et max
								nombreTrensferts_++;
								//temp++;
								cout << " le nombre de transferts" << nombreTrensferts_ << endl;
								//j++;//pour qu'il fasse une iteration avant de break;
								//break;
							}// ce n'est^pas sans faille repetitition der comptes
							else 
								//if (comptes_[i] <= abs(comptes_[j]) )
							{
								/*cout << " 2eme if " << endl;*/
								/*temp->setMontant(abs(comptes_[i]));
								temp->setDonneur(listeUtilisateurs_[j]);
								temp->setReceveur(listeUtilisateurs_[i]);
								tempo[j] = temp;*/
								listeTransferts_[j]->setMontant(abs(comptes_[i]));
								listeTransferts_[j]->setDonneur(listeUtilisateurs_[j]);
								listeTransferts_[j]->setReceveur(listeUtilisateurs_[i]);//j envoie a utili i le montant de comte
								//travailler avec les valeurs min et max

						
								comptes_[j] = comptes_[i]+comptes_[j]; comptes_[i] = 0;
								nombreTrensferts_++;
								//temp++;//passer a une adresse de plus
								
								cout << " le nombre de transferts" << nombreTrensferts_ << endl;
								//j++;//pour une iterartion avant de break
								//break;
							}  
						
					}
					

					
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
	//for(int t=0;t<nombreTrensferts_;t++)
	//{
	//	
	//listeTransferts_[t] = temp[t+1];//copier toutes les adresse dans le tempo a la premiere adresse qu'il trouve
	//}
	//

}




//Une méthode d’affichag
void Groupe::afficherGroupe()
{

	//for (unsigned int i = 0; i < tailleTabUtilisateurs_; i++)
	//	listeUtilisateurs_[i]->afficherUtilisateur;
	//Une méthode d’affichage qui affiche toutes les dépenses par utilisateur
	
	
	for (int i = 0; i < nombreUtilisateurs_; i++)
		listeUtilisateurs_[i]->afficherUtilisateur();
	//.les comptes(s’ilsne sont pas tous nuls),
	for (int i = 0; i < nombreUtilisateurs_; i++)
	{ 
		//temp=listeTransferts_[i];

		if (comptes_[i] != 0)
			cout <<"comptes Utilisateur "<<listeUtilisateurs_[i]->getNom()<<" est: "<< comptes_[i]<<endl;
	 }
	   //les transferts(si comptes remis à 0),
	//for (int i = 0; i < nombreTrensferts_; i++)//il  ne m.affiche pas le quatrieme transferts
	//{
	//	cout << "Transfert fait par" << listeTransferts_[i]->getDonneur()->getNom() << endl;
	//}
	cout << "Le nombre de transferts est"<<  nombreTrensferts_;
	for (int i = 0;i < nombreTrensferts_;i++)
	{
		cout << "Transfert fait par" << (listeTransferts_[i]->getDonneur())->getNom()<< " pour " << (listeTransferts_[i]->getReceveur())->getNom() << " d'un montant de "<< listeTransferts_[i]->getMontant() <<endl;
	}



	//corriger le code pour qu'il reconnaisse le troisieme transfert

}

