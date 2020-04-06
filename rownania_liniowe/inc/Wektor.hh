#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  double tab_w[ROZMIAR];
  
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
  wektor();
  wektor(double xx,double yy,double zz);
  wektor(double *tab);

  const double & operator[] (int index) const;
  double & operator[] (int index);

  const wektor & operator +(const wektor & W2) const;
  const wektor & operator -(const wektor & W2) const;
  double operator *(const wektor & W2) const;
  const wektor & operator *(double l2) const;

  double dlugosc() const;
  bool operator== (const wektor & W2) const;
  bool operator!= (const wektor & W2) const;
};


wektor operator*(double l1, const wektor & W2);
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream & operator>> (std::istream & strm, wektor & W);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &strm, const wektor & W);

#endif
