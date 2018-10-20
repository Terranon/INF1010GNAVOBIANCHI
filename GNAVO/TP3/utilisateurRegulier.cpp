#include "pch.h"
#include "utilisateurRegulier.h"



UtilisateurRegulier::UtilisateurRegulier(const string& nom ):Utilisateur(nom)
{

	estGroupe_ = false;



}
UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur):Utilisateur(utilisateur)
{



}

bool UtilisateurRegulier::estGroupe() const
{
	return estGroupe_;


}
void UtilisateurRegulier::setEtatGroupe(bool etat)
{
	estGroupe_ = etat;


}
void UtilisateurRegulier::ajouterInteret(double montant)
{
	Utilisateur::ajouterInteret( montant);
	

}
UtilisateurRegulier& UtilisateurRegulier::operator=(Utilisateur* utilisateur) 
{

	if (this != utilisateur)
	{
		for (int i = 0; i < this->getNombreDepenses(); i++)
		{
			delete this->getDepenses()[i];
			this->getDepenses().pop_back();//reduire la taille et les élements
			//this->getDepenses.clear();pas necessaire vu qu'on va le reinistialiser plus loin
			this->setNom(utilisateur->getNom());
			for (int j = 0; j < this->getNombreDepenses(); j++)
				this->getDepenses().push_back(utilisateur->getDepenses()[i]);
			
		}

			
		
		//pas de delete car vector de depense
		//le delete s,applique a l'attribut  pointeur de l'objetcourant
		
		//probleme 
		//copier quelque attribut de la sous-class;
		//aproche de solutions utiliser le constructeur par copie
		

		//UtilisateurRegulier use =UtilisateurRegulier(*utilisateur);

		//approche qui fut garde utilisations des methodes pour avoir acces aux attributs des classes derive


			
	}
	return *this;

}

 ostream& operator<< (ostream& os,  UtilisateurRegulier* utilisateur){

	 os << static_cast<Utilisateur*>(utilisateur)<<"etatgroupe est"<<utilisateur->estGroupe()<<endl;
	 return os;

}