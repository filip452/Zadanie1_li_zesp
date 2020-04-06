#include "UkladRownanLiniowych.hh"
#include <iostream>

using std::endl;
using std::ostream;
using std::istream;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

const wektor & UkladRownanL::rozwiaz() const
{
  return 0;
}
UkladRownanL::UkladRownanL()
{
  macierzkw A;
  wektor b;
}
UkladRownanL::UkladRownanL(const macierzkw & M, const wektor & W)
{
  for(int i=0;i<ROZMIAR;i++)
    {
      A[i]=M[i];
      b[i]=W[i];
    }
}
const wektor & UkladRownanL::zwroc_wektor_wolny() const
{
  return b;
}
void UkladRownanL::zmien_wektor_wolny(const wektor & W)
{
  b=W;
}
const macierzkw & UkladRownanL::zwroc_macierz() const
{
  return A;
}
void UkladRownanL::zmien_macierz(const macierzkw & M)
{
  A=M;
}


std::ostream& operator << ( std::ostream &strm, const UkladRownanL &UklRown)
{
  macierzkw M;
  wektor w;

  M=UklRown.zwroc_macierz();
  w=UklRown.zwroc_wektor_wolny();

  for(int i=0;i<ROZMIAR;i++)
    strm<<M[i][0]<<'x'<<std::showpos<<M[i][1]<<'y'<<M[i][2]<<std::noshowpos<<"z="<<w[i]<<endl;
  
  return strm;
}

std::istream& operator >> (std::istream &strm, UkladRownanL &UklRown)
{
  macierzkw M;
  wektor w;
  char znak;
  //cin>>11 x +12 y -13 z = 1
  for(int i=0;i<ROZMIAR;i++)
    {
      strm>>M[i][0];
      strm>>znak;
      if (znak != 'x')
	strm.setstate(std::ios::failbit);
      strm>>M[i][1];
      strm>>znak;
      if (znak != 'y')
	strm.setstate(std::ios::failbit);
      strm>>M[i][2];
      strm>>znak;
      if (znak != 'z')
	strm.setstate(std::ios::failbit);
      strm>>znak;
      if (znak != '=')
	strm.setstate(std::ios::failbit);
      strm>>w[i];
    }
  UklRown.zmien_macierz(M);
  UklRown.zmien_wektor_wolny(w);
  
  return strm;
}
