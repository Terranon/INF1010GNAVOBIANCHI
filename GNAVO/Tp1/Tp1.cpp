// Tp1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>


#include "groupe.h"

using namespace std;

int main(int argc, const char * argv[]) {
	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
	// Creer un evenement pour  6 depenses et 4 utilisateurs.
	/*
	string& nom;unsigned int tailleTabDepenses
	Depense** listeDepenses_ = new Depense*[6];*/
	//a=new type[taille] reprendreiciUtilisateur** listeUtilisateurs_ = new Utilisateur*[4];unsigned int tailleTabUtilisateurs
	  string name ;
	cout << "entrez un nom"<<endl ; 
	cin >> name;unsigned int tailleTabDepenses = 6;unsigned int tailleTabUtilisateurs = 4;
	/*cout << "entrez un nombre de depense";
	cin >> nombreDepense_;*/
	Groupe evenement (name, tailleTabDepenses, tailleTabUtilisateurs);
// Creer 5 utlisateurs.
	
 	//declaration des depenses
	/*int a = 5;
	*/// declaration des utilisateurs
		string nom;
	
		Utilisateur* e1=new Utilisateur();
		cout << "Entrez le nom de l'utilisateur" << endl;
		cin >> nom;
		e1->setNom(nom);
		Utilisateur* e2 = new Utilisateur();
		cout << "Entrez le nom de l'utilisateur" << endl;
		//cin >> nom;
		e2->setNom(nom);
		Utilisateur* e3 = new Utilisateur();
		cout << "Entrez le nom de l'utilisateur" << endl;
		//cin >> nom;
		e3->setNom(nom);
		Utilisateur* e4 = new Utilisateur();
		cout << "Entrez le nom de l'utilisateur" << endl;
		//cin >> nom;
		e4->setNom(nom);
		Utilisateur* e5 = new Utilisateur();
		cout << "Entrez le nom de l'utilisateur" << endl;
		//cin >> nom;
		e5->setNom(nom);


	//	/*Utilisateur e2(nom);
	//	cout << "Entrez le nom de l'utilisateur" << endl;
	//	cin >> nom;
	//	Utilisateur e3(nom);
	//	cout << "Entrez le nom de l'utilisateur" << endl;
	//	cin >> nom;
	//	Utilisateur e4(nom);
	//	cout << "Entrez le nom de l'utilisateur" << endl;
	//	cin >> nom;
	//	Utilisateur e5(nom);*/

	///*string nom;
	//Utilisateur** listUtilisateurs= new Utilisateur*[5];
	//for (int i = 0; i < 5; i++) {
	//	cout << "Entrez le nom de l'utilisateur";
	//	cin >> nom;
	//	listUtilisateurs[i] = new Utilisateur();///il faut initialiser listutilsateur pour savoir qu'il existe un truc dedans
	//	listUtilisateurs[i]->setNom(nom);
	//}*/
	////Creer 7 dépenses.
	///*Depense** listeDepenses = new Depense*[7]();
	//
	//for (int i = 0; i < 7; i++)
	//{
	//	
	//	string titre;
	//	cin >> titre;
	//	listeDepenses[i]->setTitre(titre);
	//	double val;
	//	cin >> val;
	//	listeDepenses[i]->setMontant(val);
	//	
		
		double montant=1;
		Depense* d1 = new Depense();

		d1->setTitre(nom);
		
		d1->setMontant(montant);
		Depense* d2 = new Depense();

		d2->setTitre(nom);

		d2->setMontant(montant);
		Depense* d3 = new Depense();
	
		d3->setTitre(nom);

		d3->setMontant(montant);
		Depense* d4 = new Depense();
		
		d4->setTitre(nom);

		d4->setMontant(montant);
		Depense* d5 = new Depense();
	
		d5->setTitre(nom);

		d5->setMontant(montant);
		Depense* d6 = new Depense();
		
		d6->setTitre(nom);

		d6->setMontant(montant);
		Depense* d7 = new Depense();
		
		d7->setTitre(nom);

		d7->setMontant(montant);
		
	//}*/
	//	int montant;
	/*	string nomDepense;double montant;
		cout << "entrer le nom de la depense1 puis le montant de la depenses;"<<endl;
		
		
		cin >> nomDepense >> montant;
		Depense D1(nomDepense, montant);
		cout << "entrer le nom de la depense2 puis le montant de la depenses";
		cin >> nomDepense >> montant;
		Depense D2(nomDepense, montant);	
		cout << "entrer le nom de la depense3 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		Depense D3(nomDepense, montant);	cout << "entrer le nom de la depense4 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		Depense D4(nomDepense, montant);
		cout << "entrer le nom de la depense5 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		
		Depense D5(nomDepense, montant);
		cout << "entrer le nom de la depense6 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		Depense D6(nomDepense, montant);
		cout << "entrer le nom de la depense7 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		Depense D7(nomDepense, montant);*/

 	//ajouter les utilisateurs a l'evenement
	
	//for (int i = 0; i < 5; i++)
	//	evenement.ajouterUtilisateur(listeUtilisateurs[i]);
		evenement.ajouterUtilisateur(e1);
		evenement.ajouterUtilisateur(e2);
		evenement.ajouterUtilisateur(e3);
		evenement.ajouterUtilisateur(e4);
		evenement.ajouterUtilisateur(e5);
	//Depense* uneDepense; Utilisateur* payePar;
	//ajouter les depenses a l'evenement
	/*for (int i =0;i<7;i++)
 		evenement.ajouterDepense( listeDepenses[i],  listeUtilisateurs[i]);*///juste changer les variables et l;es declarer		evenement.ajouterDepense(&D1, e1);
		evenement.ajouterDepense(d1, e1);
		evenement.ajouterDepense(d2, e1);
		evenement.ajouterDepense(d3, e1);//chaque utilisateur a sa depense
		evenement.ajouterDepense(d4, e2);
		evenement.ajouterDepense(d5, e3);
		evenement.ajouterDepense(d6, e4);
		evenement.ajouterDepense(d7, e5);
		
		/*evenement.ajouterDepense(&D6, );Quelles parametre donner a utilisateur?
		evenement.ajouterDepense(&D7,);*/
		
	//calculer le total de l'evenement et de chaque utilisateur
		 
	//for (unsigned int i = 0; i < 5; i++)//nombreutilisateur = 5;
	//	listeUtilisateurs[i]->calculerTotal();
	/**e1.calculerTotal();*/
	e1->calculerTotal();
	e2->calculerTotal();
	e3->calculerTotal();
	e4->calculerTotal();
	e5->calculerTotal();
	evenement.calculerTotalDepenses();//on le calcule qpres avoir calculer chaque depense d'utilisateur
	//Afficher event
	cout << " l'evenement: "<< name<<" a couté un total pour le groupe: "<< evenement.getTotal()<<endl;
	

	//for (unsigned int i=0;i<tailleTabUtilisateurs;i++)
	//listeUtilisateurs[i]->afficherUtilisateur();
	
	//Equilibrer les comptes
	evenement.equilibrerComptes();
	//Afficher l'évenement
    e1->afficherUtilisateur();
	e2->afficherUtilisateur();
	e3->afficherUtilisateur();
	e4->afficherUtilisateur();
	e5->afficherUtilisateur();
	evenement.afficherGroupe();
	//pour pauser le programme
	

	//terminer le programme correctement
		/*~evenement;*/
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant 
//pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
