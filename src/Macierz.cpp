#include "Macierz.hh"
#include "rozmiar.h"
using namespace std;

Macierz::Macierz() { mac = new Wektor[ROZMIAR]; }
Macierz::Macierz(Wektor *data) {
  mac = new Wektor[ROZMIAR];
  for (int i = 0; i < ROZMIAR; i++) {
    mac[i] = data[i];
  }
}
Macierz::~Macierz() { delete[] mac; }
std::ostream &operator<<(std::ostream &Strm, const Macierz &Mac) {
  for (int i = 0; i < ROZMIAR; i++) {
    Strm << Mac.mac[i] << endl;
  }
  return Strm;
}

std::istream &operator>>(std::istream &Strm, Macierz &Mac) {
  for (int i = 0; i < ROZMIAR; i++) {
    Strm >> Mac.mac[i];
  }
  return Strm;
}
