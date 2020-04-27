#include <cmath>
#include <iostream>

struct lz
{
  double re;
  double im;

  lz(): re(0), im(0) {}
  lz(double x,double y): re(x), im(y) {}
   explicit lz(double liczba): re(liczba), im(0) {}
  
  lz operator=(double liczba) {re=liczba; im=0;return *this;}
  lz operator+=(const lz & z2) {re=re+z2.re; im=im+z2.im;return *this;}

  lz sprzezenie();
  double modul() {return sqrt(pow(re,2)+pow(im,2));}

  lz operator + (lz z2) const;
  lz operator - (lz z2) const;
  lz operator * (lz z2) const;
  lz operator / (double lr) const;
  
  bool operator == (lz z2) const;
  bool operator != (lz z2) const;
};

lz operator / (lz z1,lz z2);

std::istream & operator >> (std::istream & strm, lz & z2);
std::ostream & operator << (std::ostream & strm, lz z1);
