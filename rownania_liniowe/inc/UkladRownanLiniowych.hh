#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include "Wektor.hh"
#include "Macierz.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanL{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  macierzkw A; 
  wektor b;
  
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
const wektor & rozwiaz() const;
UkladRownanL();
UkladRownanL(const macierzkw & M, const wektor & W);
const wektor & zwroc_wektor_wolny() const;
void zmien_wektor_wolny(const wektor & W);
const macierzkw & zwroc_macierz() const;
void zmien_macierz(const macierzkw & M);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &strm, UkladRownanL &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &strm, const UkladRownanL &UklRown);


#endif
