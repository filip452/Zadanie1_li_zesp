#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona sprzezenie(LZespolona  Skl1);

double modul(LZespolona  Skl1);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona operator - (LZespolona Skl1, LZespolona Skl2);

LZespolona operator * (LZespolona Skl1, LZespolona Skl2);

LZespolona operator / (LZespolona Skl, double Lr);

LZespolona operator / (LZespolona Skl1, LZespolona Skl2);

bool operator == (LZespolona Skl1, LZespolona Skl2);

bool operator != (LZespolona Skl1, LZespolona Skl2);




LZespolona utworz(double re, double im);




std::istream & operator >> (std::istream & strm, LZespolona & Skl1);

std::ostream & operator << (std::ostream & strm, LZespolona Skl1);

#endif
