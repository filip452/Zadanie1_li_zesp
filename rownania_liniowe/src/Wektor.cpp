#include "Wektor.hh"
#include <cmath>

using std::endl;
using std::cerr;
using std::ostream;
using std::istream;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

wektor::wektor()
{
  for(int i=0;i<ROZMIAR;i++)
    tab_w[i]=0;
}
wektor::wektor(double xx,double yy,double zz)
{
  tab_w[0]=xx;
  tab_w[1]=yy;
  tab_w[2]=zz;
}
wektor::wektor(double *tab)
{
  for(int i=0;i<ROZMIAR;i++)
    tab_w[i]=tab[i];
}


const double & wektor::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab_w[index];
}  
double & wektor::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab_w[index];
}


const wektor & wektor::operator +(const wektor & W2) const
{
  wektor w;
  for(int i=0;i<ROZMIAR;i++)
    w[i]=tab_w[i]+W2[i];
  const wektor & wynik=w; 
  return wynik;
}
const wektor & wektor::operator -(const wektor & W2) const
{
  wektor w;
  for(int i=0;i<ROZMIAR;i++)
    w[i]=tab_w[i]-W2[i];
  const wektor & wynik=w; 
  return wynik;
}
double wektor::operator *(const wektor & W2) const
{
  double w=0;
  for(int i=0;i<ROZMIAR;i++)
    w+=tab_w[i]*W2[i];
  const double & wynik=w; 
  return wynik;
} 
const wektor & wektor::operator *(double l2) const
{
  wektor w;
  for(int i=0;i<ROZMIAR;i++)
    w[i]=tab_w[i]*l2;
  const wektor & wynik=w; 
  return wynik;
}


double wektor::dlugosc() const
{
  return sqrt(pow(tab_w[0],2)+pow(tab_w[1],2)+pow(tab_w[2],2));
}

bool wektor::operator== (const wektor & W2) const
{
  if(tab_w[0]==W2[0] && tab_w[1]==W2[1] && tab_w[2]==W2[2]) return true;
  else return false;
}
bool wektor::operator!= (const wektor & W2) const
{
  if(tab_w[0]==W2[0] && tab_w[1]==W2[1] && tab_w[2]==W2[2]) return false;
  else return true;
}

  

ostream & operator<< (ostream & strm, const wektor & W)
{
  strm << '(' << W[0] << ',' << W[1] << ',' << W[2] << ')';
  return strm;
}

istream & operator>> (istream & strm, wektor & W)
{
  char znak;
  strm>>znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit);
  strm>>W[0]>>znak;
  if (znak != ',')
    strm.setstate(std::ios::failbit);
  strm>>W[1]>>znak;
  if (znak != ',')
    strm.setstate(std::ios::failbit);
  strm>>W[2]>>znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit);
  return strm;
}


wektor operator*(double l1, const wektor & W2)
{
  wektor w;
  for(int i=0;i<ROZMIAR;i++)
    w[i]=W2[i]*l1;
  const wektor & wynik=w; 
  return wynik;
}

