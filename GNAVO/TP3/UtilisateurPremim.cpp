#include "pch.h"
#include "utilisateurPremium.h"

//constructeurs 
UtilisateurPremium::UtilisateurPremium (const string& nom ):Utilisateur(nom),joursRestants_(30),taux_(0.05)
{
}//n'oublie pas le type
UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur):Utilisateur(utilisateur){}


//getters
unsigned int UtilisateurPremium::getJoursRestants() const
{

	return joursRestants_;
}
double UtilisateurPremium::getTaux() const
{
	return taux_;
}

//setters 
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants)
{

	joursRestants_ = joursRestants;
}

//methode de calcul 
void UtilisateurPremium::calculerTaux()
{
	taux_-= taux_ - (0, 01)*(getNombreDepenses()) % 2;//mod 2 pour toutes les deux depenses 

}

//operateurs
UtilisateurPremium& UtilisateurPremium::operator= (Utilisateur* utilisateur)
{
	
		if (this != utilisateur)
		{
			for (int i = 0; i < this->getNombreDepenses(); i++)
			{
				delete this->getDepenses()[i];
				this->getDepenses().pop_back();//reduire la taille et les élements

				this->setNom(utilisateur->getNom());
				for (int j = 0; j < this->getNombreDepenses(); j++)
					this->getDepenses().push_back(utilisateur->getDepenses()[i]);
			}
	    }
	return *this;
}

ostream& operator << (ostream& os, const UtilisateurPremium& utilisateur)
{
	
	os << static_cast<UtilisateurPremium>(utilisateur) << "le taux est " << utilisateur.getTaux() <<"et le nombre de jours restants est :"<< utilisateur.joursRestants_<< endl;
	return os;
}

//redefinir la methode calcul intret