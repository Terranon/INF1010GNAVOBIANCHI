/********************************************
* Titre: Travail pratique #4 - transfert.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfert.h"
#include "utilisateurRegulier.h"//inclusion de cette bibliotheque
// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) :
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {


}


// Methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}
//voir le type de l"utilisateur par defaut je suppose que l'utilisateur qui 
//effectue le transfert est premium et n'as pas de frais de transfert

void Transfert::effectuerTransfert() {
	//ici je ne travaille qu'avec len receveur vu que j'ai deja donner des valeurs a 
	//l'expediteur dans le constructeur
	//on ajoute a la balance de l'expediteur le montant--le montant qu'il doit envoyer
	expediteur_->modifierBalanceTranferts(getMontant());
	//--pour l'expediteur je me demande comment mettre a jour ses frais
	//if(expediteur_->estRegulier()==true)//utilisateur regulier
	if (dynamic_cast<UtilisateurRegulier*>(expediteur_))
		expediteur_->modifierBalanceFrais(getFraisTransfert());
	else //utilisateur non regulier --on utilise le montant du transfert
		expediteur_->modifierBalanceFrais(-getMontant()*TAUX_EPARGNE);
	//on retire au receveurcar c'est un montant qu'ON Lui doit
	receveur_->modifierBalanceTranferts(-getMontant());

}

// Methodes de modifications
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}

//Methode affichage
ostream& operator<<(ostream& os, const Transfert& transfert) {
	//faire la mise en page
	return os << transfert.getExpediteur()->getNom() << "->" << transfert.getReceveur()->getNom() << ":" << transfert.getMontant() << "$" << endl;
}
