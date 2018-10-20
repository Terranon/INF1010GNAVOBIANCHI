#include "pch.h"//fonctio ajouter depenses 
/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() {
	nom_ = "";
}
Groupe::Groupe(const string& nom) : nom_(nom) {
}

Groupe::~Groupe() 
{
	for (unsigned int i = 0; i < transferts_.size(); i++) 
	{
		delete transferts_[i];
		transferts_.pop_back();
	}
	transferts_.shrink_to_fit();
	/*for (unsigned int i = 0; i < depenses_.size(); i++)
	{
		delete depenses_[i];
		depenses_.pop_back();
	}
	depenses_.shrink_to_fit();*/
	
	/*for (unsigned int i = 0; i < utilisateurs_.size(); i++)//car ils sont deja deleté
	{
		delete utilisateurs_[i];
		utilisateurs_.pop_back();
	}
	utilisateurs_.shrink_to_fit();
	*/
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const
{
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}


double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{
	//faire des conditions imbriques avec ajout derreur a chaqe etape,,il resteras la fonction taux ,equilibrer comptes,et transferts..ecrire 2 fonctions et mettre la bonne variable au bon endroit concernant le compte
	bool condition = true;///verifier que le payeur n'est pas dans le vecteur d'utilisateur en parametre payepour
	
	////Verifie que la dépense soit bien une DepenseGroupe
	unsigned int compte=0;
	//Verifier que tous les utilisateurs concernés soient là.

	//if (payePar == nullptr)
	//	condition = false;
	//for(unsigned int i =0;i<payePour.size();i++)
	//{
	//	if (payePour[i] == nullptr)
	//		condition = false;
	//}}
		//Verifier que tous les utilisateurs concernés soient là.
		//et que les paye pour ausii appartiennent a la liste d'utilidateur groupe
		for (unsigned int j = 0; j < utilisateurs_.size(); j++)
		{
			if (payePar->getNom() == utilisateurs_[j]->getNom()) 
			{
				condition = true;
				break;
		    }
				
			else
				condition=false;
		
	    }
//	que le payepar appartient a la liste dutilitsateur du groupe 
	
	for (unsigned int i = 0; i < payePour.size(); i++)
	{
		for (unsigned int j = 0; j < utilisateurs_.size(); j++)
		{ 
			if (payePour[i]->getNom() == utilisateurs_[j]->getNom())//on peut aussi utiliser un break;
				compte++;//compter le nombre der utilisateur si pauye par est un utilisateur de depenses
			
		}
	}
		
	if (compte == payePour.size())
		condition = true;//sommez tous les trucs pour croire a cela
	else
		condition = false;
				
		
	if (depense->getType() != groupe)
		condition = false;//faire des si imbriquees

	if (payePar->getType()  == individuelle && static_cast<UtilisateurRegulier*>(payePar)->estGroupe()==true)
		condition = false;
	for (unsigned int i = 0; i < payePour.size(); i++)
	{
		if (payePour[i]->getType() == individuelle && static_cast<UtilisateurRegulier*>(payePour[i])->estGroupe() == true)
			condition = false;

	}
	
 	if (payePar->getType() == Premium  && static_cast<UtilisateurPremium*>(payePar)->getJoursRestants() == 0)
	{
		
			condition =false;
			cout << "L'utilisateur doit renouveler son abonnement " << endl;
		
	}//////////////////////etre en mesure d'ignorer louis
   //Si tout est bon
	if (condition == true)
	{

		DepenseGroupe* dgroup = (static_cast<DepenseGroupe*>(depense));
		dgroup->setNombreParticipants(1 + (payePour.size()));


		*payePar += dgroup;
		for (unsigned int i = 0; i < payePour.size(); i++)
		{
			//met le nombre de participants de la depene

			*payePour[i] += dgroup;//nomalement depense mais il y a eu un changemeng de type
			//le mettre dans le groupe
		//	cout << dgroup->getMontantPersonnel()  << endl;


		}	//
		//Mets à jour les comptes des utilisateurs concernés
	//dans lordre des paye pour ajoute...
		payePar->calculerTotalDepenses();
		if (payePar->getType() == Regulier)
			static_cast<UtilisateurRegulier*>(payePar)->setEtatGroupe(true);
		for (unsigned int i = 0; i < payePour.size(); i++) {
			//for (unsigned int i = 0; i < payePour[i]->getDepenses().size(); i++)
			payePour[i]->calculerTotalDepenses();
			if (payePour[i]->getType() == Regulier)
				static_cast<UtilisateurRegulier*>(payePour[i])->setEtatGroupe(true);
		}
		/////////////////////////////////////////////////////////////////////////////////////////

			//presque trouver les bonnes valeurs du comptes
		
		//for (unsigned int i = 0; i < utilisateurs_.size(); i++)
		//{
		//	if (payePar->getNom() == utilisateurs_[i]->getNom())
		//		comptes_.push_back( depense->getMontant() - payePar->getTotalDepenses());
		//	for (unsigned int j = 0; j < payePour.size(); j++)
		//	{
		//		if (payePour[j]->getNom() == utilisateurs_[i]->getNom())
		//		{
		//			comptes_.push_back( -payePour[j]->getTotalDepenses());//comptes_.push_back();//mettre au bon index;;;;
		//		}
		//		cout << "voici les comptes " << i << " " << comptes_[i] << endl;
		//	}
		//}
	
		//}
			//Ajoute la dépense au groupe 
			depenses_.push_back(dgroup);
		
		//si tu est le payeur ton compte = depense - calculertotal;; si tu es dans d'autrs groupe ton compte =,calculertotal
		if (comptes_.size() != utilisateurs_.size()) {
			for (unsigned int k = 0; k < utilisateurs_.size(); k++)
					comptes_.push_back(0);

		}
		
		for (unsigned int i = 0; i < utilisateurs_.size(); i++)
		{
			if (payePar->getNom() == utilisateurs_[i]->getNom()) 
			{
			//	comptes_[i] +=( depense->getMontant() - payePar->getTotalDepenses());
				comptes_[i] += (depense->getMontant() - depense->getMontant()/(1+payePour.size()));
				cout << "le compte " << i << "a pour valeur " << comptes_[i] <<" et c'est celui de "<<payePar<< endl;
			}
			else {
				for (unsigned int j = 0; j < payePour.size(); j++)
			{
				if (payePour[j]->getNom() == utilisateurs_[i]->getNom())
				{
					comptes_[i] = comptes_[i] - (depense->getMontant() / (1 + payePour.size()));//comptes_.push_back();//mettre au bon index;;;;
					cout << "le compte " << i << "a pour valeur " << comptes_[i] << " et c'est celui de " << payePour[j] << endl;
					
				}
				
			}
				

			}
		
		}

	}
	//Sinon affiche une erreur
	else
		cout << "Erreur.impossible d'ajouter depense " << endl;
		
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	//if((utilisateur->getType()==Premium)
	utilisateurs_.push_back(utilisateur);
	
	//if( (utilisateur->getType() == Regulier)&&(utilisateur.))
	return *this;
}

void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;

		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;


		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}

}

void Groupe::calculerTotalDepense() 
{
	totalDepenses_ = 0;
	for (unsigned int i = 0; i <depenses_.size(); i++) {
		totalDepenses_ += depenses_[i]->getMontant();
		cout << "le montant de la depense est" << depenses_[i]->getMontant()<<endl;

	}
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	for (unsigned int i = 0; i < groupe.utilisateurs_.size(); i++)
	{

		//os << (groupe.utilisateurs_[i])<<endl;//cc'est un pointeur sur un type utilisateur
		if (groupe.utilisateurs_[i]->getType() == Premium)
		{
			UtilisateurPremium* p = (static_cast<UtilisateurPremium*>(groupe.utilisateurs_[i]));
			//p->getDepenses() [i].//il met la dwepense par defaut a 0
			//p->getDepenses()[i].
		//une fois le type verifie on converti le type utilisateir,on et on li ajoute le qualificatif premium
				//acces a la valeur de ses méthodes
			//pour le forcer a manipuler un utilisateur premium
			os << p << endl;
			/*delete p;
			p = nullptr;*/  //ne pas delete


		}
		else
		{

			UtilisateurRegulier* regulier = (static_cast<UtilisateurRegulier*>(groupe.utilisateurs_[i]));//attention regarder ici
			//je crois il est mieux d'utiliser le pointeur pour faciliteer l'utilisation de static cast;
			os << regulier << endl;
			
		}

	}
	for (unsigned int i = 0; i < groupe.transferts_.size(); i++)
		os << *groupe.transferts_[i] << endl;


	for (unsigned int i = 0; i < groupe.comptes_.size(); i++)
	{ 
		if (groupe.comptes_[i] !=0)
		os <<"le compte"<<i<<"a pour valeur"<< groupe.comptes_[i] << endl;
	}


	return os;
}
