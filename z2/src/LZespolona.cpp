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

  Wynik = Skl1 * sprzezenie(Skl2) / (pow(Skl2.re,2) + pow(Skl2.im,2));
  return Wynik;
}




LZespolona utworz(double re, double im)
{
  LZespolona lz;
  lz.re=re;
  lz.im=im;

  return lz;
}

bool wyswietl(LZespolona Skl1)
{
  if(cout << '(' << Skl1.re << std::showpos << Skl1.im << std::noshowpos << ");")
    return true;
  return false;
}

bool wczytaj(LZespolona &Skl1)
{
  char znak;

  cin >> znak;
  if(znak!='(')
    return false;
  cin >> Skl1.re >> Skl1.im;
  return true;
}


bool wczytaj(std::istream & strm, LZespolona &Skl1)
{
  char znak;

  strm >> znak;
  if(znak!='(')
    return false;
  cin >> Skl1.re >> Skl1.im;
  strm >> znak;
  if(znak!='i')
    return false;
  strm >> znak;
  if(znak!=')')
    return false;
  
  return true;
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
}
