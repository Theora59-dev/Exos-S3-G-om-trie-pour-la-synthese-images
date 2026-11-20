#include "vecteur_2d.h"

#include <sstream>

// Constructeurs : les arguments par défaut restent dans le header uniquement
Vecteur2D::Vecteur2D(double x, double y) : x(x), y(y) {}
Vecteur2D::Vecteur2D(const Vecteur2D &v) : x(v.x), y(v.y) {}

Vecteur2D::operator std::string() const {
	std::ostringstream oss;
	oss << "Vecteur2D(x=" << x << ", y=" << y << ")";
	return oss.str();
}

// Fonction libre déclarée friend dans le header -> pas de "Vecteur2D::"
std::ostream &operator<<(std::ostream &o, const Vecteur2D &v) {
	return o << static_cast<std::string>(v);
}

Vecteur2D Vecteur2D::operator+(const Vecteur2D &v) const {
	return Vecteur2D(this->x + v.x, this->y + v.y);
}
Vecteur2D Vecteur2D::operator-() const { return Vecteur2D(-this->x, -this->y); }

Vecteur2D operator*(double a, const Vecteur2D &v) { return v * a; }
Vecteur2D Vecteur2D::operator*(double a) const { return Vecteur2D(this->x * a, this->y * a); }
Vecteur2D operator-(const Vecteur2D &v1, const Vecteur2D &v2) { return v1 + -v2; }

Vecteur2D &Vecteur2D::operator+=(const Vecteur2D &v) {
	this->x += v.x;
	this->y += v.y;
	return *this;
}
Vecteur2D &Vecteur2D::operator-=(const Vecteur2D &v) {
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}
Vecteur2D &Vecteur2D::operator*=(const Vecteur2D &v) {
	this->x *= v.x;
	this->y *= v.y;
	return *this;
}

double Vecteur2D::scalaire(const Vecteur2D &v) const { return this->x * v.x + this->y * v.y; }
