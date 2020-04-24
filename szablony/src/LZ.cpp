#include <iostream>
#include <cmath>
#include "LZ.hh"

#define EPSILON 0.00001

lz lz::sprzezenie()
{
  lz wynik;
  wynik.re=re;
  wynik.im=-im;
  return wynik;

}

lz lz::operator + (lz z2) const
{
  lz wynik;
  wynik.re=re+z2.re;
  wynik.im=im+z2.im;
  return wynik;
}
lz lz::operator - (lz z2) const
{
  lz wynik;
  wynik.re=re-z2.re;
  wynik.im=im-z2.im;
  return wynik;
}
lz lz::operator * (lz z2) const
{
  lz wynik;
  wynik.re=re*z2.re-im*z2.im;
  wynik.im=re*z2.im+im*z2.re;
  return wynik;
}
lz lz::operator / (double lr) const
{
  if(lr==0)
    {
      std::cout<<"Nie mozna dzielic przez zero.\n";
      exit(1);
    }
  lz wynik;
  wynik.re=re/lr;
  wynik.im=im/lr;
  return wynik;
}

bool lz::operator == (lz z2) const
{
  if(abs(re-z2.re)<EPSILON && abs(im-z2.im)<EPSILON) return true;
  else return false;
} 
bool lz::operator != (lz z2) const
{
  if(abs(re-z2.re)>EPSILON || abs(im-z2.im)>EPSILON) return true;
  else return false;
}


lz operator / (lz z1,lz z2)
{
  if(z2.re==0 && z2.im==0)
    {
      std::cout<<"Nie mozna dzielic przez zero.\n";
      exit(1);
    }
  lz wynik;
  wynik=z1*z2.sprzezenie()/(pow(z2.re,2)+pow(z2.im,2));
  return wynik;
}

std::istream & operator >> (std::istream & strm, lz & z1)
{
  char znak;
  strm>>znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit);
  strm>>z1.re>>z1.im>>znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit);
  strm>>znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit);
  
  return strm;
}
std::ostream & operator << (std::ostream & strm, lz z1)
{
  strm << '{' << z1.re << std::showpos << z1.im << std::noshowpos << "i}";
  return strm;
}
