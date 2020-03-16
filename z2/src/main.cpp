#include <iostream>
#include "BazaTestu.hh"

using std::cout;
using std::endl;


int main()
{
  LZespolona x,y;
  WyrazenieZesp z;

  x=utworz(2,8);
  y=utworz(-2,0);

  z.Arg1=x;
  z.Arg2=y;
  z.Op=Op_Dziel;
  
  Wyswietl(z);
  cout << endl;
  wyswietl(Oblicz(z));
  
  return 0;
}
/*
int main(int argc, char **argv)
{

  if (argc < 2) {                                               
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {                      
    std::cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {          
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
*/
