#include "Wektor.hh"
#include "rozmiar.h"
using namespace std;

Wektor::Wektor() {
  v = new double[ROZMIAR];
}
Wektor::Wektor(double *data) { // Recently I dont't use it
  v = new double[ROZMIAR];
  for (int i = 0; i < ROZMIAR; i++) {
    v[i] = data[i];
  }
}

Wektor::~Wektor() {
  //  delete []v;
  // cout << "Kasuje";
}
//////////////
std::ostream &operator<<(std::ostream &Strm, const Wektor &Wek) {
  for (int i = 0; i < ROZMIAR; i++) {
    Strm << Wek.v[i] << " ";
  }
  return Strm;
}

void Wektor::Write() {
  for (int i = 0; i < ROZMIAR; i++) {
    cout << v[i] << " ";
  }
}
/////////////////////////////

std::istream &operator>>(std::istream &Strm, Wektor &Wek) {
  // cout<<"cos";
  for (int i = 0; i < ROZMIAR; i++) {
    Strm >> Wek.v[i];
  }
  return Strm;
}
///////////////////////
Wektor operator+(const Wektor &w1, const Wektor &w2) {
  Wektor result;
  for (int i = 0; i < ROZMIAR; i++) {

    result.v[i] = w1.v[i] + w2.v[i];
    //  cout << i << " W1: "<< w1.v[i] << " W2: " << w2.v[i] << " W3: " <<
    //  result.v[i]<<endl;
  }

  return result;
}

Wektor Wektor::operator=(const Wektor &W) { // to change, but now result of add is ok
  for (int i = 0; i < ROZMIAR; i++) {
    v[i] = W.v[i];
  }
  return W;
}

Wektor operator-(const Wektor &w1, const Wektor &w2) {
  Wektor result;
  for (int i = 0; i < ROZMIAR; i++) {
    result.v[i] = w1.v[i] - w2.v[i];
  }
  return result;
}
Wektor operator*(const Wektor &w1, const Wektor &w2) {
  Wektor result;
  for (int i = 0; i < ROZMIAR; i++) {
    result.v[i] = w1.v[i] * w2.v[i];
  }
  return result;
}
Wektor operator*(const Wektor &w1, const double &l) {
  Wektor result;
  for (int i = 0; i < ROZMIAR; i++) {
    result.v[i] = w1.v[i] * l;
  }
  return result;
}
Wektor operator/(const Wektor &w1, const double &l) {
  Wektor result;
  for (int i = 0; i < ROZMIAR; i++) {
    result.v[i] = w1.v[i] / l;
  }
  return result;
}
double Wektor::IloczynSkalarny(){
  
}
