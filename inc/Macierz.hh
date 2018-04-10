#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

class Macierz {
  Wektor *mac;

public:
  Macierz();
  Macierz(Wektor *data);
  ~Macierz();
  Wektor &operator[](int indeks) { return mac[indeks]; }
  friend std::ostream &operator<<(std::ostream &Strm, const Macierz &Mac);
  friend std::istream &operator>>(std::istream &Strm, Macierz &Mac);
};

std::istream &operator>>(std::istream &Strm, Macierz &Mac);

std::ostream &operator<<(std::ostream &Strm, const Macierz &Mac);

#endif
