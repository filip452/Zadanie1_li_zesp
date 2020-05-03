#include "macierz.hh"
#include <iostream>

template<class TYP, int ROZMIAR>
class uklad
{
  macierz<TYP,ROZMIAR> A;
  wektor<TYP,ROZMIAR> b;
public:
  uklad();
  uklad(const macierz<TYP,ROZMIAR> & M,const wektor<TYP,ROZMIAR> & w);
  wektor<TYP,ROZMIAR> rozwiaz() const;

  const wektor<TYP,ROZMIAR> & get_wek() const;
  void set_wek(const wektor<TYP,ROZMIAR> & w);
  const macierz<TYP,ROZMIAR> & get_mac() const;
  void set_mac(const macierz<TYP,ROZMIAR> & M);
};

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &strm, uklad<TYP,ROZMIAR> &U);

template<class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream &strm, const uklad<TYP,ROZMIAR> &U);
