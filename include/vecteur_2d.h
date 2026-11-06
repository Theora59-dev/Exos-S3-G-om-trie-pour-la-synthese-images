/**
 * Représente un vecteur (x, y) du plan
 * La classe est munie de toutes les opérationspour réaliser des constructions
 * géométrie
 */

#include <SFML/Window.hpp>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Vecteur2D {
  public:
	double x, y = 0;

	Vecteur2D(const double &x, const double &y) : x(x), y(y) { /* Nothing else */ }
	operator string() const {
		std::ostringstream oss;
		oss << "Vecteur2D(x=" << x << ", y=" << y << ")";
		return oss.str();
	}
};
