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
	bool condition = false;///verifier que le payeur n'est pas dans le vecteur d'utilisateur en parametre payepour
	
	////Verifie que la dépense soit bien une DepenseGroupe
	unsigned int nombreUtilsateurValides =0;
	//Verifier que tous les utilisateurs concernés soient là.

	
	for (unsigned int i = 0; i < utilisateurs_.size(); i++)
	{
		
		for (unsigned int j = 0; j <payePour.size() ; j++)
		{ 
			if (payePour[j]->getNom() == utilisateurs_[i]->getNom())
				nombreUtilsateurValides++;//compte le nombre d'utilisateurvalides
			
		}
		if (payePar->getNom() == utilisateurs_[i]->getNom())
		{
			condition = true;

		}
		

	}
		
	if (condition == false)
		cout << "ERREUR .L'utilisateur"<<payePar->getNom()<< "n'a pas ete trouve dans le groupe" << endl;
	if (nombreUtilsateurValides != payePour.size()) {
		condition = false;
		cout << "ERREUR.le groupe d'utilisateurs ne correspond pas aux utilisateurs du groupe " <<getNom()<< endl;
	}
		
				
		
	if (depense->getType() != groupe){
		condition = false;
		cout << "ERREUR.La depense n'est pas une depense de groupe" << endl;
	}
		//faire des si imbriquees

//////////////////////etre en mesure d'ignorer louis
   //Si tout est bon
	if (condition == true)
	{
		//ajout de payepar
		payePour.push_back(payePar);
		static_cast<DepenseGroupe*>(depense)->setNombreParticipants (payePour.size());


		//*payePar += static_cast<DepenseGroupe*>(depense);
		for (unsigned int i = 0; i < payePour.size(); i++)
		{
			

			*payePour[i] += static_cast<DepenseGroupe*>(depense);
		


		}	
		//Mets à jour les comptes des utilisateurs concernés
	//dans lordre des paye pour ajoute...
		//payePar->calculerTotalDepenses();
		
		for (unsigned int i = 0; i < payePour.size(); i++) {
			//for (unsigned int i = 0; i < payePour[i]->getDepenses().size(); i++)
			payePour[i]->calculerTotalDepenses();
		}
		/////////////////////////////////////////////////////////////////////////////////////////


		depenses_.push_back(static_cast<DepenseGroupe*>(depense));
		//initialisation du tableau de compte a 0 et reservations de place 
		for (unsigned int k = 0; k < utilisateurs_.size(); k++)
			comptes_.push_back(0);

		//mets a jour les comptes
		//selon le nom mets a jour les comptes...
		//on ajoute a paye par le montant totla et on soustrait a paye pour le montant personnel
		for (unsigned int i = 0; i < utilisateurs_.size(); i++)
		{
			if (payePar->getNom() == utilisateurs_[i]->getNom())
			{

				comptes_[i] += depense->getMontant() ;

			}
			else
			{
				for (unsigned int j = 0; j < (payePour.size()); j++)
				{
					if (payePour[j]->getNom() == utilisateurs_[i]->getNom())
					{
						comptes_[i] -= (depense->getMontant() / (payePour.size()));


					}

				}


			}

		}








	}
	//Sinon affiche une erreur
	else
		cout << "Impossible d'ajouter la depense car a cause de(s) avertissement(s) ERROR!" << endl;
	
	
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	if (utilisateur->getType() == Premium) {
		if (static_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() != 0)
		{
			utilisateurs_.push_back(utilisateur);
		}
		else

		{
			cout << "L'utilisateur doit renouveller son abonnement premium" << endl;
		}
	}
	else {
		
			if (static_cast<UtilisateurRegulier*>(utilisateur)->estGroupe() == false) {
				utilisateurs_.push_back(utilisateur);
				static_cast<UtilisateurRegulier*>(utilisateur)->setEtatGroupe(true);
			}
			else
			{
				cout << "L'utilisateur: "<<utilisateur->getNom()<<"est deja groupe" << endl;
			}
		


	}
		
	
	return *this;
}

void Groupe::equilibrerComptes() {

	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		//ajout de cete ligne de if 
		if (utilisateurs_[i]->getType() == Premium)
			static_cast<UtilisateurPremium*>(utilisateurs_[i])->calculerTaux();
	}
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve

		

		for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
			//ajout de cete ligne de if 
			
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}
		//ajouter interet au sonneur c'est l'utilisateur  avex l'index le pllux petit
		//calculer le taux de l'utilisateur
		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			if (utilisateurs_[indexMin]->getType() == Regulier)
				utilisateurs_[indexMin]->ajouterInteret(-min * TAUX_REGULIER);
			else {
				
				utilisateurs_[indexMin]->ajouterInteret((static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->getTaux())*-min);

			}
				

			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
			
		}
		else if (-min > max  && min != 0 && max != 0) {
			if (utilisateurs_[indexMin]->getType() == Regulier)
				utilisateurs_[indexMin]->ajouterInteret(max * TAUX_REGULIER);
			else {
			
				utilisateurs_[indexMin]->ajouterInteret((static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->getTaux())*max);

			}
				
			
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
			
		
			os << static_cast<UtilisateurPremium*>(groupe.utilisateurs_[i]) << endl;
			
		}
		else
		{

			
		
			os << static_cast<UtilisateurRegulier*>(groupe.utilisateurs_[i]) << endl;
			
		}

	}
	for (unsigned int i = 0; i < groupe.transferts_.size(); i++)
		os << *groupe.transferts_[i] << endl;

	return os;
}
