/**
 * Représente un vecteur (x, y) du plan
 * La classe est munie de toutes les opérations pour réaliser des constructions
 * géométrie
 */
#pragma once

#include <ostream>
#include <string>

class Vecteur2D {

  public:
	double x, y;

	// Constructeurs
	Vecteur2D(double x = 0.0, double y = 0.0);
	Vecteur2D(const Vecteur2D &v);
	Vecteur2D &operator=(const Vecteur2D &v) = default; // copie membre par membre par défaut
	static const Vecteur2D creePolaire(const double &theta);

	operator std::string() const;
	friend std::ostream &operator<<(std::ostream &o, const Vecteur2D &v);

	const Vecteur2D operator+(const Vecteur2D &v) const;
	const Vecteur2D operator-() const;
	friend Vecteur2D operator*(double a, const Vecteur2D &v);
	Vecteur2D operator*(double a) const;
	friend Vecteur2D operator-(const Vecteur2D &v1, const Vecteur2D &v2);
	const Vecteur2D operator^(const Vecteur2D &v) const;

	Vecteur2D &operator+=(const Vecteur2D &v);
	Vecteur2D &operator-=(const Vecteur2D &v);
	Vecteur2D &operator*=(const Vecteur2D &v);
	Vecteur2D &operator^=(const Vecteur2D &v);

	double scalaire(const Vecteur2D &v) const;

	double magnitude() const;

	// Méthodes Métiers
	Vecteur2D rotationQuartGauche() const;
	Vecteur2D rotationQuartDroite() const;
	Vecteur2D rotation(double angle_radian) const;
};
