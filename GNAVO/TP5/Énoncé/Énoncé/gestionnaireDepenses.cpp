#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>


double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepenses = 0;
	
	for (unsigned int i= 0; i < getNombreElements();i++) {//on parcourt le tableau 
		totalDepenses+=getElementParIndex(i)->getMontant();//on retourne les elements qu'on additionne a total Depenses
	}
	return totalDepenses;
}