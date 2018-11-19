#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>

double GestionnaireDepenses::getTotalDepenses() const {
	double totalDepenses = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		totalDepenses += depenses_[i]->getMontant();
	}
	return totalDepenses;
}
