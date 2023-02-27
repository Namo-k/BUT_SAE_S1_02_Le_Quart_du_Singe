/**
 * @file singe.cpp
 * Projet SAE102 - Comparaison d’approches algorithmiques
 * @author Namodacane KALIAMOORTHY et Alexandre CAROUNANITHI
 * @version 15 - 02/01/2023
 * @brief Programme principal du jeu : Le Quart du Singe
 */

#include <iostream>
#include <cstdlib>
#include <locale>

#include "fonctions.h"

int main(int argc, const char* argv[]) {

	setlocale(LC_CTYPE, "fra");
	srand(time(NULL));
	
	Partie p;

	if (!verifNbJoueur(argv)) {
		std::cout << "Nombre insuffisant de joueurs" << std::endl;
		return 2;
	}
	else {
		if (verifJoueur(argv)) {
			std::cout << "Seul les joueurs humains et robots sont acceptés" << std::endl;
			return 2;
		}
		else {
			initialiserPartie(p, argv);
			jouerPartie(p);
			detruirePartie(p);
		}
	}		
	
	return 0;
}
