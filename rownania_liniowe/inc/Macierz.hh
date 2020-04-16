#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class macierzkw{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  wektor tab_m[ROZMIAR];
  
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  macierzkw();
  macierzkw(wektor W,wektor V, wektor U);
  macierzkw(int jednostkowa);

  //wektory - wiersze
  const wektor  & operator[] (int index) const;
  wektor & operator[] (int index);
  //wektory kolumny
  const double  & operator() (int ind1, int ind2) const;
  double & operator() (int ind1, int ind2);

  double wyznacznikLaplace();
  //double wyznacznikGauss(); //napisać
  double wyznacznikSarrus();

  wektor operator *(const wektor & W);
  macierzkw operator +(const macierzkw & B);
  macierzkw operator -(const macierzkw & B);
  macierzkw operator *(const macierzkw & B);
  macierzkw operator *(double l2);

  bool operator== (const macierzkw & M2) const;
  bool operator!= (const macierzkw & M2) const;

  const macierzkw & transponuj() const;
  void transponuj();

  const macierzkw & odwroc() const;
  void odwroc();
  const macierzkw & odwroc_sar() const;
  void odwroc_sar();
};

macierzkw operator *(double l2, const macierzkw M);
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream & operator<< (std::ostream & strm, const macierzkw & M);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream & operator>> (std::istream & strm, macierzkw & M);


#endif
