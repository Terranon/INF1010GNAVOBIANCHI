#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <algorithm>
#include <vector>

//aurait ton pu mettre template avant de mettre gestionnairegénérique?
class GestionnaireDepenses: public GestionnaireGenerique<Depense*,vector<Depense*>,Depense*, AjouterDepense> {
public:
	//constructeur

	
	double getTotalDepenses() const;



};
