/**
 * Représente un vecteur (x, y) du plan
 * La classe est munie de toutes les opérations pour réaliser des constructions
 * géométrie
 */

#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Vecteur2D {

  public:
	double x, y = 0;

	// Constructeurs
	Vecteur2D(const double &x = 0, const double &y = 0) : x(x), y(y) { /* Nothing else */ }
	Vecteur2D(Vecteur2D const &v) : x(v.x), y(v.y) { /* Nothing else */ }

	operator string() const {
		ostringstream oss;
		oss << "Vecteur2D(x=" << x << ", y=" << y << ")";
		return oss.str();
	}

	const Vecteur2D operator+(const Vecteur2D &v) const {
		return Vecteur2D(this->x + v.x, this->y + v.y);
	}
	const Vecteur2D operator-() const { return Vecteur2D(-this->x, -this->y); }

	const double scalaire(const Vecteur2D &v) const { return this->x * v.x + this->y * v.y; }
};
const Vecteur2D operator-(const Vecteur2D &v1, const Vecteur2D &v2) { return v1 + -v2; }
