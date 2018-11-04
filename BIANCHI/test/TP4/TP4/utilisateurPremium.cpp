/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurPremium.h"


UtilisateurPremium::UtilisateurPremium(const string& nom, MethodePaiement methodePaiement,
	unsigned int joursRestants, const string& courriel, const string& idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), joursRestants_(joursRestants)
{}
UtilisateurPremium::~UtilisateurPremium() {}
unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}
//ajout specifique de cette fonction


void UtilisateurPremium::print(ostream& os) const {

	//il me faut trouver un moyen de mettre la valeur 
	//de get balance a zero
	//IL Y A DANS LA CLASSE groupe UNE METTODE ou on pourra calculer  LES FRAIs DE TRANSFERT adequat//SINON ICI IL PRENDRA JUSTE LEM3/ DU MONTANT TOTAL DU TRANSFERT
	double economie = 0;
	economie = balanceFrais_;
	if (getTotalATransferer() > 0)
		economie = TAUX_EPARGNE * getTotalATransferer();//en fait c'est gale a 0,03 *le montant total du transfert*/
	os << "Utilisateur(premium) " << getNom() << " :" << endl << "Total  a payer: " << getTotalATransferer() <<
		"(" << economie << " economises)" << endl << "Jours restants: " << getJoursRestants() << endl << "-Depenses:" << endl;
	for (size_t i = 0; i < depenses_.size(); i++)
		os << *depenses_[i];





}