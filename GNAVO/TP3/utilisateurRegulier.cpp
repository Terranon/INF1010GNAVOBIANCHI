#include "pch.h"
#include "utilisateurRegulier.h"



UtilisateurRegulier::UtilisateurRegulier(const string& nom ):
	Utilisateur(nom),
	estGroupe_(false)
{
	
}
UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur):
	Utilisateur(utilisateur),estGroupe_(false)
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
		*this = utilisateur;
		if (utilisateur->getType() == Regulier)
			setEtatGroupe(static_cast<UtilisateurRegulier*>(utilisateur)->estGroupe());

	}
	return *this;

}

 ostream& operator<< (ostream& os,  UtilisateurRegulier* utilisateur){
	 if (utilisateur->estGroupe()==true)
	 os << static_cast<Utilisateur*>(utilisateur)<<endl;
	 else 
		 os << static_cast<Utilisateur*>(utilisateur) << endl;
	 return os;

}