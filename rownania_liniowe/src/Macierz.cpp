#include "Macierz.hh"
#include <cmath>

using std::cout;
using std::endl;
using std::cerr;
using std::ostream;
using std::istream;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

macierzkw::macierzkw()
{
  wektor w;
  for(int i=0;i<ROZMIAR;i++)
    tab_m[i]=w;
}
macierzkw::macierzkw(wektor W,wektor V, wektor U)
{
  tab_m[0]=W;
  tab_m[1]=V;
  tab_m[2]=U;
}
macierzkw::macierzkw(int jednostkowa)
{
  if(jednostkowa != 1)
    {
      cerr << "To nie jest wartosc macierzy jednostkowej" << endl;
      exit(1);
    }
  wektor W(1,0,0),V(0,1,0),U(0,0,1);
  tab_m[0]=W;
  tab_m[1]=V;
  tab_m[2]=U;
}

//wektory - wiersze
const wektor & macierzkw::operator[] (int index) const
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab_m[index];
}
wektor & macierzkw::operator[] (int index)
{
  if (index < 0 || index >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab_m[index];
}
//wektory kolumny
const double  & macierzkw::operator() (int ind1, int ind2) const
{
  macierzkw M;
  if (ind1 < 0 || ind2 < 0 || ind1 >= ROZMIAR || ind2 >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab_m[ind2][ind1];
}
double & macierzkw::operator() (int ind1, int ind2)
{
  macierzkw M;
  if (ind1 < 0 || ind2 < 0 || ind1 >= ROZMIAR || ind2 >= ROZMIAR)
    {
      cerr << "poza zakresem" << endl;
      exit(1);
    }
  return tab_m[ind2][ind1];
}


double macierzkw::wyznacznikLaplace()
{
  double wyznacznik=0;
  wyznacznik+=tab_m[0][0]*(tab_m[1][1]*tab_m[2][2]-tab_m[1][2]*tab_m[2][1]);
  wyznacznik-=tab_m[0][1]*(tab_m[1][0]*tab_m[2][2]-tab_m[1][2]*tab_m[2][0]);
  wyznacznik+=tab_m[0][2]*(tab_m[1][0]*tab_m[2][1]-tab_m[1][1]*tab_m[2][0]);
  return wyznacznik;
}
double macierzkw::wyznacznikGauss()
{

}
double macierzkw::wyznacznikSarrus()
{
  //00*11*22+01*12*20+02*10*21
  //-02*11*20-01*10*22-00*12*21
  double wyznacznik=0;
  wyznacznik+=tab_m[0][0]*tab_m[1][1]*tab_m[2][2];
  wyznacznik+=tab_m[0][1]*tab_m[1][2]*tab_m[2][0];
  wyznacznik+=tab_m[0][2]*tab_m[1][0]*tab_m[2][1];
  wyznacznik-=tab_m[0][2]*tab_m[1][1]*tab_m[2][0];
  wyznacznik-=tab_m[0][1]*tab_m[1][0]*tab_m[2][2];
  wyznacznik-=tab_m[0][0]*tab_m[1][2]*tab_m[2][1];
  return wyznacznik;
}


const wektor & macierzkw::operator *(const wektor & W)
{
  wektor temp;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      temp[i]=temp[i]+tab_m[i][j]*W[j];
  const wektor & wynik=temp;
  return wynik;
}

const macierzkw & macierzkw::operator +(const macierzkw & B)
{
  macierzkw A;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      A[i][j]=tab_m[i][j]+B[i][j];
  const macierzkw & wynik=A;
  return wynik;
}
const macierzkw & macierzkw::operator -(const macierzkw & B)
{
  macierzkw A;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      A[i][j]=tab_m[i][j]-B[i][j];
  const macierzkw & wynik=A;
  return wynik;
}
const macierzkw & macierzkw::operator *(const macierzkw & B)
{
  macierzkw A;

  for(int i=0;i<ROZMIAR;i++)
    {
      for(int j=0;j<ROZMIAR;j++)  
	{
	  wektor w(B(j,0),B(j,1),B(j,2));
	  A[i][j]=tab_m[i]*w;
	}
    }
  
  const macierzkw & wynik=A;
  return wynik;
}
const macierzkw & macierzkw::operator *(double l2)
{
  macierzkw A;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      A[i][j]=tab_m[i][j]*l2;
  const macierzkw & wynik=A;
  return wynik;
}

bool macierzkw::operator== (const macierzkw & M2) const
{
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      if(tab_m[i][j]!=M2[i][j]) return false;
  return true;
}
bool macierzkw::operator!= (const macierzkw & M2) const
{
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      if(tab_m[i][j]!=M2[i][j]) return true;
  return false;
}

const macierzkw & macierzkw::transponuj() const
{
  macierzkw M;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      M[i][j]=tab_m[j][i];
  const macierzkw & wynik=M;
  return wynik;
}
void macierzkw::transponuj()
{
  macierzkw M;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      M[i][j]=tab_m[j][i];
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      tab_m[i][j]=M[i][j];
}

const macierzkw & macierzkw::odwroc() const
{
  macierzkw dopelnien,M;
  double wyznacznik;
  int w1,w2;
  int k1,k2;

  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      M[i][j]=tab_m[i][j];
  wyznacznik=M.wyznacznikLaplace();
  
  if(wyznacznik==0)
    {
      cerr<<"nie mozna odwrocic";
      exit(1);
    }
  
  for(int i=0;i<ROZMIAR;i++)
    {
      k1=i+1;
      if(k1==3) k1=0;
      k2=k1+1;
      if(k2==3) k2=0;
      
      for(int j=0;j<ROZMIAR;j++)
	{
	  w1=j+1;
	  if(w1==3) w1=0;
	  w2=w1+1;
	  if(w2==3) w2=0;
	  
	  dopelnien[i][j]=(tab_m[k1][w1]*tab_m[k2][w2]-tab_m[k1][w2]*tab_m[k2][w1]);
	}
    }
  dopelnien.transponuj();
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      {
	M[i][j]=dopelnien[i][j]*(1/wyznacznik);
      }
  
  const macierzkw & wynik=M;
  return wynik;
}
void macierzkw::odwroc()
{
  macierzkw dopelnien;
  double wyznacznik;
  int w1,w2;
  int k1,k2;

  wyznacznik=wyznacznikLaplace();
  
  if(wyznacznik==0)
    {
      cerr<<"nie mozna odwrocic";
      exit(1);
    }
  
  for(int i=0;i<ROZMIAR;i++)
    {
      k1=i+1;
      if(k1==3) k1=0;
      k2=k1+1;
      if(k2==3) k2=0;
      
      for(int j=0;j<ROZMIAR;j++)
	{
	  w1=j+1;
	  if(w1==3) w1=0;
	  w2=w1+1;
	  if(w2==3) w2=0;
	  
	  dopelnien[i][j]=(tab_m[k1][w1]*tab_m[k2][w2]-tab_m[k1][w2]*tab_m[k2][w1]);
	}
    }
  dopelnien.transponuj();
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      {
	tab_m[i][j]=dopelnien[i][j]*(1/wyznacznik);
      }
}


const macierzkw & operator *(double l2, const macierzkw M)
{
  macierzkw A;
  for(int i=0;i<ROZMIAR;i++)
    for(int j=0;j<ROZMIAR;j++)
      A[i][j]=M[i][j]*l2;
  const macierzkw & wynik=A;
  return wynik;
}

ostream & operator<< (ostream & strm, const macierzkw & M)
{
  for(int i=0;i<ROZMIAR;i++)
    {
      cout<<'[';
      for(int j=0;j<ROZMIAR;j++)
	{
	  cout<<M[i][j];
	  if(j<ROZMIAR-1) cout<<',';
	}
      cout<<']'<<endl;
    }
  return strm;
}
		       
istream & operator>> (istream & strm, macierzkw & M)
{
  char znak;
  int i,j;
  for(i=0;i<ROZMIAR;i++)
    {
      strm>>znak;
      if (znak != '[')
	strm.setstate(std::ios::failbit);
      for(j=0;j<ROZMIAR;j++)
	{
	  strm>>M(i,j)>>znak;
	  if(j<ROZMIAR-1)
	    if(znak != ',')
	      strm.setstate(std::ios::failbit);
	    else;
	  else if (znak != ']')
	    strm.setstate(std::ios::failbit);
	}
    }
  return strm;
}
