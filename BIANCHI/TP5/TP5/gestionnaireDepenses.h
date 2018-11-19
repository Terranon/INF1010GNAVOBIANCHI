#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <algorithm>
#include <vector>

class GestionnaireDepenses : public GestionnaireGenerique<Depense*, vector<Depense*>,
	Depense*, AjouterDepense> {
public:
	// Methodes d'access
	
	double getTotalDepenses() const;
};
