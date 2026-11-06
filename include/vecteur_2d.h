/**
 * Représente un vecteur (x, y) du plan
 * La classe est munie de toutes les opérationspour réaliser des constructions
 * géométrie
 */

class Vecteur2D {
public:
  double x, y = 0;
  Vecteur2D(const double &x, const double &y) { this->x = x, this->y = y; }
};
