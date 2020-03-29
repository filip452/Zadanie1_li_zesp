#include "LZespolona.hh"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona sprzezenie(LZespolona  Skl1)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re;
  Wynik.im = -Skl1.im;
  return Wynik;
}

double modul(LZespolona  Skl1)
{
  double Wynik;

  Wynik=sqrt(pow(Skl1.re,2)+pow(Skl1.im,2));
  return Wynik;
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re *Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

LZespolona operator / (LZespolona Skl, double Lr)
{
  LZespolona Wynik;
  Wynik.re = Skl.re / Lr;
  Wynik.im = Skl.im / Lr;
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  if(Skl2 == utworz(0,0)) Wynik = utworz(0,0);
    else Wynik = Skl1 * sprzezenie(Skl2) / (pow(Skl2.re,2) + pow(Skl2.im,2));
  return Wynik;
}

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re == Skl2.re && Skl1.im == Skl2.im) return true;
  else return false;
}

bool operator != (LZespolona Skl1, LZespolona Skl2)
{
  return !(Skl1 == Skl2);
}




LZespolona utworz(double re, double im)
{
  LZespolona lz;
  lz.re=re;
  lz.im=im;

  return lz;
}




std::istream & operator >> (std::istream & strm, LZespolona & Skl1)
{
  char znak;
  strm>>znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit);
  strm>>Skl1.re>>Skl1.im>>znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit);
  strm>>znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit);
  
  return strm;
}

std::ostream & operator << (std::ostream & strm, LZespolona Skl1)
{
  strm << '{' << Skl1.re << std::showpos << Skl1.im << std::noshowpos << "i}";
  return strm;
}
