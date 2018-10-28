#include "pch.h"
#include "utilisateurPremium.h"

//constructeurs 
UtilisateurPremium::UtilisateurPremium (const string& nom ):
	Utilisateur(nom),
	joursRestants_(30),
	taux_(TAUX_REGULIER)
{
	setType(Premium);
}//n'oublie pas le type
UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur):Utilisateur(utilisateur){
	if (utilisateur.getType() == Premium) {
		setJoursRestants(static_cast<UtilisateurPremium>(utilisateur).getJoursRestants());
		setTaux(static_cast<UtilisateurPremium>(utilisateur).getTaux());
	}
	else {
		setJoursRestants(30);
	    setTaux(TAUX_REGULIER);
	}
		
		

}


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
void UtilisateurPremium::setTaux(double taux) {
	taux_ = taux;
}
//methode de calcul 
void UtilisateurPremium::calculerTaux()
{ 
	if (taux_ != 0)
		taux_ = TAUX_REGULIER;
	unsigned int nombreDepenses=getNombreDepenses();
		
	if (taux_ <= 0)
		taux_ = 0;
	else
		taux_-=  (0.01)*(nombreDepenses /2) ;//la depense doit etre uhe depense de groupe
	
	
}

//operateurs
UtilisateurPremium& UtilisateurPremium::operator= (Utilisateur* utilisateur)
{
	
	if (this != utilisateur){
			*this = utilisateur;
			if (utilisateur->getType() == Premium) {
				setJoursRestants(static_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants());
				setTaux(static_cast<UtilisateurPremium*>(utilisateur)->getTaux());
			}
    }
	return *this;
}

ostream& operator << (ostream& os,  const UtilisateurPremium& utilisateur)
{
	
	os << static_cast<Utilisateur>(utilisateur) << "avec un taux de" << 100*utilisateur.getTaux() <<"% et le nombre de jours restants est :"<< utilisateur.joursRestants_<< endl;
	return os;
}

//redefinir la methode calcul intret