// Tp1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>


#include "groupe.h"

using namespace std;

int main(int argc, const char * argv[]) 
{
	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
	// Creer un evenement pour  6 depenses et 4 utilisateurs.
	/*
	string& nom;unsigned int tailleTabDepenses
	Depense** listeDepenses_ = new Depense*[6];*/
	//a=new type[taille] reprendreiciUtilisateur** listeUtilisateurs_ = new Utilisateur*[4];unsigned int tailleTabUtilisateurs
	  string name ;
	cout << "entrez un nom pour le groupe"<<endl ; 
	cin >> name;unsigned int tailleTabDepenses = 6;unsigned int tailleTabUtilisateurs = 4;
	/*cout << "entrez un nombre de depense";
	cin >> nombreDepense_;*/
	Groupe evenement (name, tailleTabDepenses, tailleTabUtilisateurs);
// Creer 5 utlisateurs.
	
 	//declaration des depenses
	/*int a = 5;
	*/// declaration des utilisateurs
		string nom;
	///////////////////////////////////////////////////////////////////////////////////////////
		/*Utilisateur* e1=new Utilisateur(nom);
		cout << "Entrez le nom de l'utilisateur" << endl;
		cin >> nom;
		e1->setNom(nom);
		Utilisateur* e2 = new Utilisateur(nom);
		cout << "Entrez le nom de l'utilisateur" << endl;
		cin >> nom;
		e2->setNom(nom);
		Utilisateur* e3 = new Utilisateur(nom);
		cout << "Entrez le nom de l'utilisateur" << endl;
		cin >> nom;
		e3->setNom(nom);
		Utilisateur* e4 = new Utilisateur(nom);
		cout << "Entrez le nom de l'utilisateur" << endl;
		cin >> nom;
		e4->setNom(nom);
		Utilisateur* e5 = new Utilisateur(nom);
		cout << "Entrez le nom de l'utilisateur" << endl;
		cin >> nom;
		e5->setNom(nom);*/
	/*	cout << "Entrez le nom de l'utilisateur1" << endl;
		cin >> nom;
		/////////////////////////////////////////////////////////////////////////
		Utilisateur e1(nom);
		cout << "Entrez le nom de l'utilisateur 2" << endl;
		cin >> nom;
		Utilisateur e2(nom);
		cout << "Entrez le nom de l'utilisateur 3" << endl;
		cin >> nom;
		Utilisateur e3(nom);
		cout << "Entrez le nom de l'utilisateur 4" << endl;
		cin >> nom;
		Utilisateur e4(nom);
		cout << "Entrez le nom de l'utilisateur 5" << endl;
		cin >> nom;
		Utilisateur e5(nom);*/
///////////////////////////////////////////////////////////////////////////////////
	//string nom;
	Utilisateur** listUtilisateurs= new Utilisateur*[5];

	for (int i = 0; i < 5; i++) {
		cout << "Entrez le nom de l'utilisateur" << i << endl;
		cin >> nom ;
		listUtilisateurs[i] = new Utilisateur();///il faut initialiser listutilsateur pour savoir qu'il existe un truc dedans
		listUtilisateurs[i]->setNom(nom);
	}
	////Creer 7 dépenses.
	////////////////////////////////////////////////////////////
	Depense** listeDepenses = new Depense*[7];
	string titre;
	double val;
	unsigned int ordreDeDepense[7];
	for (int i = 0; i < 7; i++)
	{
		listeDepenses[i] = new Depense();
		
		cout << "Entrez le nom de la depense" <<i<< endl;
		cin >> titre;
		listeDepenses[i]->setTitre(titre);
		
		cout << "Entrez la valeur de la depense" <<i<< endl;
		cin >> val;
		listeDepenses[i]->setMontant(val);
		unsigned int rangUtilisateur;
		cout << "Qui a fait la depense?" << endl;
		cout << "pour " << listUtilisateurs[0]->getNom() << " entrer 0" << endl;
		cout << "pour " << listUtilisateurs[1]->getNom() << " entrer 1" << endl;
		cout << "pour " << listUtilisateurs[2]->getNom() << " entrer 2" << endl;
		cout << "pour " << listUtilisateurs[3]->getNom() << " entrer 3" << endl;
		cout << "pour " << listUtilisateurs[4]->getNom() << " entrer 4" << endl;
		cin >> rangUtilisateur;
		/*listUtilisateurs[rangUtilisateur]->ajouterDepense(listeDepenses[i])*///il faut necessairement ajouetr les choses a tout les utilisateurs
		ordreDeDepense[i] = rangUtilisateur;
	}
		////////////////////////////////////////////////////////////////
		/*double montant=1;
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

		d7->setMontant(montant);*/
		
	//}*/
		////////////////////////////////////////////////////////////////////////////
		/*double montant;string nomDepense;
		cout << "entrer le nom de la depense1 puis le montant de la depenses;"<<endl;
		
		
		cin >> nomDepense >> montant;
		Depense D1(nomDepense, montant);
		cout << " entrer le nom de la depense2 puis le montant de la depenses";
		cin >> nomDepense >> montant;
		Depense D2(nomDepense, montant);	
		cout << " entrer le nom de la depense3 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		Depense D3(nomDepense, montant);	cout << " entrer le nom de la depense4 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		Depense D4(nomDepense, montant);
		cout << " entrer le nom de la depense5 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		
		Depense D5(nomDepense, montant);
		cout << " entrer le nom de la depense6 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		Depense D6(nomDepense, montant);
		cout << " entrer le nom de la depense7 puis le montant de la depenses;" << endl;
		cin >> nomDepense >> montant;
		Depense D7(nomDepense, montant);
*/   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 	//ajouter les utilisateurs a l'evenement
	
	
	//	evenement.ajouterUtilisateur(listeUtilisateurs[i]);
	/*	evenement.ajouterUtilisateur(e1);
		evenement.ajouterUtilisateur(e2);
		evenement.ajouterUtilisateur(e3);
		evenement.ajouterUtilisateur(e4);
		evenement.ajouterUtilisateur(e5);*/
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		for (unsigned int i = 0; i < 5; i++) 		{									evenement.ajouterUtilisateur(listUtilisateurs[i]);					}
	///////////////////////////////////////////////////////////////////////////////////////	
	//Depense* uneDepense; Utilisateur* payePar;
	//ajouter les depenses a l'evenement
	for (unsigned int j = 0; j < 7; j++)//le nombre d'utilisateurs
	{//ajouter les depenses de tout les utilisateurs

		cout << listeDepenses[j]->getTitre() <<endl;
 		evenement.ajouterDepense(listeDepenses[j],listUtilisateurs[ordreDeDepense[j]]);	//	une adresse des depense faites par l'utilisateurs//comment savoir c'est lui qui a paye la bonne depense
	}
		
	//////////////////////////////////////////////////////////////////////////////////////////

		/*
		evenement.ajouterDepense(& D1, e1);
		evenement.ajouterDepense(& D2, e1);
		evenement.ajouterDepense(& D3, e1);
		evenement.ajouterDepense(& D4, e2);
		evenement.ajouterDepense(& D5, e3);
		evenement.ajouterDepense(& D6, e4);
		evenement.ajouterDepense(& D7, e5);
		*/
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
		
	//calculer le total de l'evenement et de chaque utilisateur
		 
	//////////////////////////////////////////////////////////////////
	for (int i = 0; i < 5; i++) 	{		listUtilisateurs[i]->calculerTotal();		cout << listUtilisateurs[i]->getTotal();	}
	evenement.calculerTotalDepenses();
	//for (unsigned int i = 0; i < 5; i++)//nombreutilisateur = 5;
	//	listeUtilisateurs[i]->calculerTotal();
	/**e1.calculerTotal();*/
	/*
	e1->calculerTotal();
	e2->calculerTotal();
	e3->calculerTotal();
	e4->calculerTotal();
	e5->calculerTotal();
	evenement.calculerTotalDepenses();*/

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//for (unsigned int i=0;i<tailleTabUtilisateurs;i++)
	//listeUtilisateurs[i]->afficherUtilisateur();
	
	//Equilibrer les comptes
	evenement.equilibrerComptes();
	//Afficher l'évenement
	for (int i = 0; i < 5; i++) {		listUtilisateurs[i]->afficherUtilisateur();	}
	evenement.afficherGroupe();
	//pour pauser le programme
	




for (unsigned int i = 0; i < 5; i++)
{
	delete listUtilisateurs[i];
}
delete [] listUtilisateurs;



for (unsigned int i = 0; i < 7; i++)
{
	delete listeDepenses[i];
}
delete [] listeDepenses;


};

	//terminer le programme correctement
		/*~evenement;
	
		

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
*/