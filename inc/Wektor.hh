#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  double *v;

  public:
    Wektor ();
    Wektor (double *data);
    ~ Wektor();
    void Write();
    Wektor operator = (const Wektor &W);
    double & operator [](int indeks){ return v[indeks];}
    double IloczynSkalarny();
    friend std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);
    friend std::istream& operator >> (std::istream &Strm, Wektor &Wek);
    friend Wektor operator + (const Wektor &w1, const Wektor &w2);
    friend Wektor operator - (const Wektor &w1, const Wektor &w2);
    friend Wektor operator * (const Wektor &w1, const Wektor &w2);
    friend Wektor operator * (const Wektor &w1, const double &l);
    friend Wektor operator / (const Wektor &w1, const double &l);
};

  Wektor operator + (const Wektor &w1, const Wektor &w2);
  Wektor operator - (const Wektor &w1, const Wektor &w2);
  Wektor operator * (const Wektor &w1, const Wektor &w2);
  Wektor operator * (const Wektor &w1, const double &l);
  Wektor operator / (const Wektor &w1, const double &l);


std::istream& operator >> (std::istream &Strm, Wektor &Wek);


std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
