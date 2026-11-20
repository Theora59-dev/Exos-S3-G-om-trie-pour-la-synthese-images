/**
 * Test les fonctionnalitées de la classe Vecteur2D
 */
#include "vecteur_2d.h"
#include <cstdio>
#include <iostream>
#include <string>

int main() {
	Vecteur2D v(5, 8);
	// printf("%s)\n", (string)v);
	std::cout << (std::string)v << std::endl;
	return 0;
}
