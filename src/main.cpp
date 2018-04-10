#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
using namespace std;

int main()
{
cout << endl << " Start programu " << endl << endl;
UkladRownanLiniowych ikl;
UkladRownanLiniowych rozw;
Macierz W;
Wektor iksy;
cin>>ikl;
cout<<ikl;
//cout<<ikl.Wyznacznik();
iksy=ikl.Wyznacznik();
cout<<"Rozwiazanie x = (x1, x2, x3):"<<endl;
cout<<iksy<<endl;
cout.setf( ios::scientific );
ikl.Blad(iksy);
return 0;
}
