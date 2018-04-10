#include "LZespolona.hh"

using namespace std;

void Wyswietl(LZespolona Skl) {
  cout << '(' << Skl.re;
  if (Skl.im >= 0)
    cout << "+";
  cout << Skl.im << "i)";
}

void Czytaj(LZespolona &Skl) {
  char tmp;
  int flaga_1 = 0;
  string re = "", im = "";

  cin >> tmp;
  if (tmp != '(') {
    cout << "BLAD";
    return;
  }

  cin >> tmp;
  if (tmp == '0')
    re = re + "0";
  if (tmp == '1')
    re = re + "1";
  if (tmp == '2')
    re = re + "2";
  if (tmp == '3')
    re = re + "3";
  if (tmp == '4')
    re = re + "4";
  if (tmp == '5')
    re = re + "5";
  if (tmp == '6')
    re = re + "6";
  if (tmp == '7')
    re = re + "7";
  if (tmp == '8')
    re = re + "8";
  if (tmp == '9')
    re = re + "9";
  if (tmp == '-')
    re = re + "-";

  while (1) {
    cin >> tmp;
    if (tmp == '0')
      re = re + "0";
    if (tmp == '1')
      re = re + "1";
    if (tmp == '2')
      re = re + "2";
    if (tmp == '3')
      re = re + "3";
    if (tmp == '4')
      re = re + "4";
    if (tmp == '5')
      re = re + "5";
    if (tmp == '6')
      re = re + "6";
    if (tmp == '7')
      re = re + "7";
    if (tmp == '8')
      re = re + "8";
    if (tmp == '9')
      re = re + "9";
    if (tmp == '.')
      re = re + ".";
    if (tmp == '+')
      break;
    if (tmp == '-') {
      flaga_1 = 1;
      break;
    }
  }

  if (flaga_1 == 1)
    im = im + "-";

  while (1) {
    cin >> tmp;
    if (tmp == '0')
      im = im + "0";
    if (tmp == '1')
      im = im + "1";
    if (tmp == '2')
      im = im + "2";
    if (tmp == '3')
      im = im + "3";
    if (tmp == '4')
      im = im + "4";
    if (tmp == '5')
      im = im + "5";
    if (tmp == '6')
      im = im + "6";
    if (tmp == '7')
      im = im + "7";
    if (tmp == '8')
      im = im + "8";
    if (tmp == '9')
      im = im + "9";
    if (tmp == '.')
      im = im + ".";
    if (tmp == 'i')
      break;
  }
  cin >> tmp; // czytamy )

  Skl.re = stod(re, NULL);
  Skl.im = stod(im, NULL);
  // cout << "RE: " << Skl.re+1.0 << " IM: " << Skl.im+2.0 << endl;
}

/*void Czytaj3razy(LZespolona &Skl) {
  char tmp;
  int flaga_1 = 0;
  string re = "", im = "";
  int licznik = 0;
  bool przerwa;
  while (1) {
    std::cin.clear();
    std::cin.sync();
    przerwa = false;
    if (licznik > 2) {
      re = "-99999";
      im = "-99999";
      break;
    }
    cin >> tmp;
    cout << tmp;
    if (tmp != "(") {
      cout << "\n BLAD WPISYWANIA NAWIAS1" << endl;
      licznik++;
      przerwa=true;
    }
    if (przerwa == true) continue;
    cin >> tmp;
    if (tmp == '0')
      re = re + "0";
    if (tmp == '1')
      re = re + "1";
    if (tmp == '2')
      re = re + "2";
    if (tmp == '3')
      re = re + "3";
    if (tmp == '4')
      re = re + "4";
    if (tmp == '5')
      re = re + "5";
    if (tmp == '6')
      re = re + "6";
    if (tmp == '7')
      re = re + "7";
    if (tmp == '8')
      re = re + "8";
    if (tmp == '9')
      re = re + "9";
    if (tmp == '-')
      re = re + "-";
    if (!(tmp == '0' || tmp == '1' || tmp == '2' || tmp == '3' || tmp == '4' ||
          tmp == '5' || tmp == '6' || tmp == '7' || tmp == '8' || tmp == '9' ||
          tmp == '-')) {
      cout << "\n BLAD WPISYWANIA LICZBA1" << endl;
      licznik++;
      re = "", im = "";
      continue;
    }
    while (1) {
      cin >> tmp;
      if (tmp == '0')
        re = re + "0";
      if (tmp == '1')
        re = re + "1";
      if (tmp == '2')
        re = re + "2";
      if (tmp == '3')
        re = re + "3";
      if (tmp == '4')
        re = re + "4";
      if (tmp == '5')
        re = re + "5";
      if (tmp == '6')
        re = re + "6";
      if (tmp == '7')
        re = re + "7";
      if (tmp == '8')
        re = re + "8";
      if (tmp == '9')
        re = re + "9";
      if (tmp == '.')
        re = re + ".";
      if (tmp == '+')
        break;
      if (tmp == '-') {
        flaga_1 = 1;
        break;
      }
      if (tmp == '+' || tmp == '.' || tmp== '-' || tmp == '0' || tmp == '1' || tmp == '2' || tmp == '3' ||
                tmp == '4' || tmp == '5' || tmp == '6' || tmp == '7' ||
                tmp == '8' || tmp == '9') {  //tu usunieta kropka i plus
        cout << "\n BLAD WPISYWANIA PIERWSZA PETLA" << endl;
        licznik++;
        re = "", im = "";
        przerwa = true;
        break;
      }
    }
    if (przerwa == true) continue;
    if (flaga_1 == 1)
      im = im + "-";

    while (1) {
      cin >> tmp;
      if (tmp == '0')
        im = im + "0";
      if (tmp == '1')
        im = im + "1";
      if (tmp == '2')
        im = im + "2";
      if (tmp == '3')
        im = im + "3";
      if (tmp == '4')
        im = im + "4";
      if (tmp == '5')
        im = im + "5";
      if (tmp == '6')
        im = im + "6";
      if (tmp == '7')
        im = im + "7";
      if (tmp == '8')
        im = im + "8";
      if (tmp == '9')
        im = im + "9";
      if (tmp == '.')
        im = im + ".";
      if (tmp == 'i')
        break;
      if (!(tmp == '0' || tmp == '1' || tmp == '2' || tmp == '3' ||
            tmp == '4' || tmp == '5' || tmp == '6' || tmp == '7' ||
            tmp == '8' || tmp == '9' || tmp == '.' || tmp == 'i')) {
        cout << "\n BLAD WPISYWANIA DRUGA PETLA" << endl;
        licznik++;
        re = "", im = "";
        przerwa = true;
        break;
      }
    }
    if (przerwa == true)
      continue;
    }

    Skl.re = stod(re, NULL);
    Skl.im = stod(im, NULL);

  // cout << "RE: " << Skl.re+1.0 << " IM: " << Skl.im+2.0 << endl;
}*/
/*
ostream& operator << (ostream & wyjscie, LZespolona Skl){
  wyjscie << Wyswietl(Skl);
  return &wyjscie;
}*/
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator+(LZespolona Skl1, LZespolona Skl2) {
  LZespolona Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
LZespolona operator-(LZespolona Skl1, LZespolona Skl2) {
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
LZespolona operator*(LZespolona Skl1, LZespolona Skl2) {
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;

  return Wynik;
}

LZespolona Sprzezenie(LZespolona Skl) {
  LZespolona Wynik;

  Wynik.re = Skl.re;
  Wynik.im = -Skl.im;
  return Wynik;
}

double Modul2(LZespolona Skl) {
  LZespolona tmp;
  double wynik;
  tmp = Skl * Sprzezenie(Skl);
  wynik = tmp.re;
  return wynik;
}
LZespolona operator/(LZespolona Skl, double numb) {
  LZespolona Wynik;
  Wynik.re = Skl.re / numb;
  Wynik.im = Skl.im / numb;
  return Wynik;
}
LZespolona operator/(LZespolona Skl1, LZespolona Skl2) {
  LZespolona Wynik;
  Wynik = (Skl1 * Sprzezenie(Skl2)) / (Modul2(Skl2) * Modul2(Skl2));
  return Wynik;
}

bool Compare(LZespolona Skl1, LZespolona Skl2) {
  if (Skl1.re == Skl2.re) {
    if (Skl1.im == Skl2.im)
      return true;
    else
      return false;
  } else
    return false;
}
