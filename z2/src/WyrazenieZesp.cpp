#include "WyrazenieZesp.hh"
#include <iostream>

using std::cout;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

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




std::istream & operator >> (std::istream & strm,Operator & Op)
{
  char znak;

  std::cin >> znak;
  switch(znak)
    {
    case '+': Op = Op_Dodaj;
      break;
    case '-': Op = Op_Odejmij;
      break;
    case '*': Op = Op_Mnoz;
      break;
    case '/': Op = Op_Dziel;
      break;
    }
  return strm;
}

std::istream & operator >> (std::istream & strm,WyrazenieZesp & WyrZ)
{
  strm >> WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
  return strm;
}


std::ostream & operator << (std::ostream & strm, Operator Op)
{
  switch(Op)
    {
    case Op_Dodaj: strm << '+';
      break;
    case Op_Odejmij: strm << '-';
      break;
    case Op_Mnoz: strm << '*';
      break;
    case Op_Dziel: strm << '/';
      break;
    }
  
  return strm;
}

std::ostream & operator << (std::ostream & strm, WyrazenieZesp WyrZ)
{
  strm << WyrZ.Arg1 << WyrZ.Op << WyrZ.Arg2;
  return strm;
}
