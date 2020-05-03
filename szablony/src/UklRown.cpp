#include "UklRown.hh"
#include <iostream>
#define EPSILON 0.1

using std::endl;
using std::cerr;

template<class TYP, int ROZMIAR>
uklad<TYP,ROZMIAR>::uklad()
{
  macierz<TYP,ROZMIAR> A;
  wektor<TYP,ROZMIAR> b;
}
template<class TYP, int ROZMIAR>
uklad<TYP,ROZMIAR>::uklad(const macierz<TYP,ROZMIAR> & M,const wektor<TYP,ROZMIAR> & w)
{
  for(int i=0;i<ROZMIAR;i++)
    A[i]=M[i];
  b=w;
}

template<class TYP, int ROZMIAR>
wektor<TYP,ROZMIAR> uklad<TYP,ROZMIAR>::rozwiaz() const
{
  wektor<TYP,ROZMIAR> wynik,w,temp;
  macierz<TYP,ROZMIAR> M;
  w=b;
  for(int i=0;i<ROZMIAR;i++)
    M[i]=A[i];
  for(int i=0;i<ROZMIAR;i++)
    {
      int j=i;
      while(M[j][i]==0 && j<ROZMIAR)
	  j++;
      temp=M[i];
      M[i]=M[j];
      M[j]=temp;
      if(M[i][i]==0)
	{
	  cerr<<"Nie mozna rozwiazac ukladu rownan."<<endl;
	  exit(1);
	}
      for(int k=i+1;k<ROZMIAR;k++)
	{
	  M[k]=M[k]-M[i]*(M[k][i]/M[i][i]);
	  w[k]=w[k]-w[i]*(M[k][i]/M[i][i]);
	}
    }
  TYP poprzedni;
  for(int i=ROZMIAR-1;i>=0;i--)
    {
      for(int j=ROZMIAR-1;j>i;j--)
	poprzedni=poprzedni+M[i][j]*wynik[j];
      wynik[i]=(w[i]-poprzedni)*(1/M[i][i]);
      poprzedni=0;
    }
  return wynik;
}

template<class TYP, int ROZMIAR>
const wektor<TYP,ROZMIAR> & uklad<TYP,ROZMIAR>::get_wek() const
{
  return b;
}
template<class TYP, int ROZMIAR>
void uklad<TYP,ROZMIAR>::set_wek(const wektor<TYP,ROZMIAR> & w)
{
  b=w;
}
template<class TYP, int ROZMIAR>
const macierz<TYP,ROZMIAR> & uklad<TYP,ROZMIAR>::get_mac() const
{
  return A;
}
template<class TYP, int ROZMIAR>
void uklad<TYP,ROZMIAR>::set_mac(const macierz<TYP,ROZMIAR> & M)
{
  A=M;
}


template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &strm, uklad<TYP,ROZMIAR> &U)
{
  macierz<TYP,ROZMIAR> M;
  wektor<TYP,ROZMIAR> w;
  strm>>M>>w;
  U.set_mac(M);
  U.set_wek(w);
  return strm;
}
template<class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream &strm, const uklad<TYP,ROZMIAR> &U)
{
  strm<<U.get_mac()<<endl<<U.get_wek();
  return strm;
}
