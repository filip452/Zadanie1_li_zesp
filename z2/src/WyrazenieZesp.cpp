#include "WyrazenieZesp.hh"
#include <iostream>

using std::cout;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

void Wyswietl(WyrazenieZesp WyrZ)
{
  wyswietl(WyrZ.Arg1);

  switch(WyrZ.Op)
    {
    case Op_Dodaj:
      cout << '+';
      break;
      
    case Op_Odejmij:
      cout << '-';
      break;

    case Op_Mnoz:
      cout << '*';
      break;

    case Op_Dziel:
      cout << '/';
      break;
    }
  
  wyswietl(WyrZ.Arg2);
}

LZespolona Oblicz(WyrazenieZesp WyrZ)
{
  LZespolona Wynik;
  
  switch(WyrZ.Op)
    {
    case Op_Dodaj:
      Wynik = WyrZ.Arg1 + WyrZ.Arg2;
      break;
      
    case Op_Odejmij:
      Wynik = WyrZ.Arg1 - WyrZ.Arg2;
      break;

    case Op_Mnoz:
      Wynik = WyrZ.Arg1 * WyrZ.Arg2;
      break;
      
    case Op_Dziel:
      Wynik = WyrZ.Arg1 / WyrZ.Arg2;
      break;
    }
  
      return Wynik;
}
