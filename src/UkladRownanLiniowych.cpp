#include "UkladRownanLiniowych.hh"

using namespace std;

UkladRownanLiniowych::UkladRownanLiniowych(Macierz m, Wektor wek) {
  wspolczynniki = m;
  x = wek;
}
UkladRownanLiniowych::UkladRownanLiniowych() {
  Macierz wspolczynniki;
  Wektor x;
}
std::ostream &operator<<(std::ostream &Strm,
                         const UkladRownanLiniowych &UklRown) {
  Strm << "Macierz A^T: \n"
       << UklRown.wspolczynniki << "\n Wektor wyrazow wolnych b: \n"
       << UklRown.x << "\n";
  return Strm;
}
std::istream &operator>>(std::istream &Strm, UkladRownanLiniowych &UklRown) {
  Strm >> UklRown.wspolczynniki >> UklRown.x;
  return Strm;
}
/*Wektor UkladRownanLiniowych::Wyznacznik() {
  Wektor wtmp1;
  double tmp2, y;
  Macierz wynik;
  Wektor wynikiii;
  wynik[0] = wspolczynniki[0];
  wynikiii[0]=x[0];
  wtmp1 = wspolczynniki[0];
  tmp2 = wspolczynniki[1][0];
  y = tmp2 / wtmp1[0];
  wynik[1][0] = wspolczynniki[1][0] - y * wtmp1[0];
  wynik[1][1] = wspolczynniki[1][1] - y * wtmp1[1];
  wynik[1][2] = wspolczynniki[1][2] - y * wtmp1[2];
  wynikiii[1] = x[1] - y * x[0];
  tmp2 = wspolczynniki[2][0];
  y = tmp2 / wtmp1[0];
  wynik[2][0] = wspolczynniki[2][0] - y * wtmp1[0];
  wynik[2][1] = wspolczynniki[2][1] - y * wtmp1[1];
  wynik[2][2] = wspolczynniki[2][2] - y * wtmp1[2];
  wynikiii[2] = x[2] - y * x[0];
  wtmp1 = wynik[1];
  tmp2 = wynik[2][1];
  y = tmp2 / wtmp1[1];
  wynik[2][0] = wynik[2][0] - y * wtmp1[0];
  wynik[2][1] = wynik[2][1] - y * wtmp1[1];
  wynik[2][2] = wynik[2][2] - y * wtmp1[2];
  wynikiii[2] = wynikiii[2] - y * wynikiii[1];
  Wektor rozwiazanie;
  rozwiazanie[0] = wynikiii[0] / wynik[0][0];
  rozwiazanie[1] = (wynikiii[1] - wynikiii[0] * wynik[0][1]) / wynik[1][1];
  rozwiazanie[2] =
      (x[2] - wynikiii[0] * wynik[0][2] - wynikiii[1] * wynik[1][2]) /
wynik[2][2]; return rozwiazanie;
}*/
const Wektor UkladRownanLiniowych::Wyznacznik() {
  Macierz wynik;
  Wektor d;
  Wektor rozwiazanie;
  float tmp;
  /*
  for (int i = 0; i < ROZMIAR; i++) {
    for (int j = 0; i < ROZMIAR; j++) {
      wynik[i][j] = wspolczynniki[i][j];
    }
  }*/ //wywala blad pchrony pamieci. kiedy petla
  wynik[0][0] = wspolczynniki[0][0];
  wynik[0][1] = wspolczynniki[0][1];
  wynik[0][2] = wspolczynniki[0][2];
  wynik[1][0] = wspolczynniki[1][0];
  wynik[1][1] = wspolczynniki[1][1];
  wynik[1][2] = wspolczynniki[1][2];
  wynik[2][0] = wspolczynniki[2][0];
  wynik[2][1] = wspolczynniki[2][1];
  wynik[2][2] = wspolczynniki[2][2];
  for (int i = 0; i < ROZMIAR; i++) {
    d[i] = x[i];
  }
  tmp = wynik[0][1] / wynik[0][0];
  for (int i = 0; i < ROZMIAR; i++) {
    wynik[i][1] = wynik[i][1] - tmp * wynik[i][0];
  }
  d[1] = d[1] - tmp * d[0];
  // wyzerowany drugi wiersz/k0olumna zalezy jak patrzymy do tego momentu ok
  tmp = wynik[0][2] / wynik[0][0];
  for (int i = 0; i < ROZMIAR; i++) {
    wynik[i][2] = wynik[i][2] - tmp * wynik[i][0];
  }
  d[2] = d[2] - tmp * d[0];
  // trzeci wiersz czesciowo wyzerowany -> tak samo jak drugi >> tu tez dziala
  tmp = wynik[1][2] / wynik[1][1];
  // Na razie recznie, bo ja nie wiem, co tu sie dzieje. Wartosci z kosmosu, ale
  // to moze moja wyobraznia przestrzenna a raczej jej brak
  wynik[1][2] = wynik[1][2] - tmp * wynik[1][1];
  wynik[2][2] = wynik[2][2] - tmp * wynik[2][1];
  d[2] = d[2] - tmp * d[1]; // i niech mi ktos powie dlaczego to nie dziala
  rozwiazanie[2] = d[2] / wynik[2][2];
  rozwiazanie[1] = (d[1] - rozwiazanie[2] * wynik[2][1]) / wynik[1][1];
  rozwiazanie[0] =
      (d[0] - rozwiazanie[2] * wynik[2][0] - rozwiazanie[1] * wynik[1][0]) /
      wynik[0][0];

  return rozwiazanie;
}
const void UkladRownanLiniowych::Blad(Wektor wynik) {
  Wektor blad;
  float dlug = 0;
  // Sprawdzic bo moja wyobraznia przestrzenna i kot chodzacy po klawiaturze"
  blad[0] = wspolczynniki[0][0] * wynik[0] + wspolczynniki[1][0] * wynik[1] +
            wspolczynniki[2][0] * wynik[2] - x[0];
  blad[1] = wspolczynniki[0][1] * wynik[0] + wspolczynniki[1][1] * wynik[1] +
            wspolczynniki[2][1] * wynik[2] - x[1];
  blad[2] = wspolczynniki[0][2] * wynik[0] + wspolczynniki[1][2] * wynik[1] +
            wspolczynniki[2][2] * wynik[2] - x[2];
  for (int i = 0; i < ROZMIAR; i++) {
    dlug += blad[i]*blad[i];
  }
  cout<<"Wektor bledu to: "<<endl<<blad<<endl;
  cout <<"Dlugosc wektora bledu to: "<<endl<<dlug<<endl;
}
