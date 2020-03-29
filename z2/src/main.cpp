#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using std::cin;
using std::cout;
using std::endl;


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


  Statystyki statystyka;

  inicjuj(statystyka);
  
  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona wynik;
  int proba;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe))
    {
      cout << WyrZ_PytanieTestowe << endl;
      proba = 0;
      while(proba<3)
	{
	  cout << "Prosze podac odpowiedz: ";
	  if(cin >> wynik)
	    {
	      proba = 3;
	      if(wynik == Oblicz(WyrZ_PytanieTestowe)) poprawna(statystyka);
	      else niepoprawna(statystyka);
	    }
	  else
	    {
	      if(proba == 2) niepoprawna(statystyka);
	      cin.clear();
	      cin.ignore(1000,'\n');
	      cout << "Odpowiedz nie jest liczba zespolona" << endl;
	      proba++;
	    }
	}
    }

  cout << endl;
  cout << statystyka << endl;
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}

