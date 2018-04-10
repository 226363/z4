#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH
#include "Macierz.hh"
#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  Macierz wspolczynniki;
  Wektor x;

public:
  UkladRownanLiniowych(Macierz m, Wektor x);
  UkladRownanLiniowych();
  const Wektor Wyznacznik ();
  const void Blad (Wektor wynik);
  friend std::istream &operator>>(std::istream &Strm,
                                  UkladRownanLiniowych &UklRown);
  friend std::ostream &operator<<(std::ostream &Strm,
                                  const UkladRownanLiniowych &UklRown);
};

std::istream &operator>>(std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream &operator<<(std::ostream &Strm,
                         const UkladRownanLiniowych &UklRown);

#endif
