
#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>

#include <stdio.h>

class Transfert {
    public :
    
    // Constructeurs
    Transfert();
    Transfert(double montant, Utilisateur* de, Utilisateur* pour);
    
    // Méthodes d'accès
    
    Utilisateur* getDonneur() ;
    Utilisateur* getReceveur() ;
    double getMontant() ;
    
    
    //Méthode d'affichage
    void setDonneur(Utilisateur* donneur);
    void setMontant(double montant);
    void setReceveur(Utilisateur* receveur);
    
    void afficherTransfert() ;
    
    private :
        double montant_;
        Utilisateur* donneur_;
        Utilisateur* receveur_;
    

};
#endif
