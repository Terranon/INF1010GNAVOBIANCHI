#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <algorithm>
#include <vector>

//aurait ton pu mettre template avant de mettre gestionnaireg�n�rique?
class GestionnaireDepenses: public GestionnaireGenerique<Depense*,vector<Depense*>,Depense*> {
public:
	//constructeur

	
	double getTotalDepenses() const;



};
