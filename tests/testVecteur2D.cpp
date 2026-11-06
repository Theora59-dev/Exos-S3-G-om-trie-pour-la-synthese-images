/**
 * Test les fonctionnalitées de la classe Vecteur2D
 */
#include "vecteur_2d.h"
#include <cstdio>

int main() {
	Vecteur2D v(5, 8);
	printf("v = (%lf, %lf)\n", v.x, v.y);
	return 0;
}
