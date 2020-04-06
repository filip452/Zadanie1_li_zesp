#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::endl;
using std::ostream;
using std::istream;

#define ROZMIAR 3


class wektor
{
  double tab_w[ROZMIAR];

public:
  wektor()
  {
    for(int i=0;i<ROZMIAR;i++)
      tab_w[i]=0;
  }
  wektor(double xx,double yy,double zz)
  {
    tab_w[0]=xx;
    tab_w[1]=yy;
    tab_w[2]=zz;
  }
  wektor(double *tab)
  {
    for(int i=0;i<ROZMIAR;i++)
      tab_w[i]=tab[i];
  }

  
  const double & operator[] (int index) const
  {
    if (index < 0 || index >= ROZMIAR)
      {
	cerr << "poza zakresem" << endl;
	exit(1);
      }
    return tab_w[index];
  }  
  double & operator[] (int index)
  {
    if (index < 0 || index >= ROZMIAR)
      {
	cerr << "poza zakresem" << endl;
	exit(1);
      }
    return tab_w[index];
  }


  const wektor & operator +(const wektor & W2) const
  {
    wektor w;
    for(int i=0;i<ROZMIAR;i++)
      w[i]=tab_w[i]+W2[i];
    const wektor & wynik=w; 
    return wynik;
  }
  const wektor & operator -(const wektor & W2) const
  {
    wektor w;
    for(int i=0;i<ROZMIAR;i++)
      w[i]=tab_w[i]-W2[i];
    const wektor & wynik=w; 
    return wynik;
  }
  double operator *(const wektor & W2) const
  {
    double w=0;
    for(int i=0;i<ROZMIAR;i++)
      w+=tab_w[i]*W2[i];
    const double & wynik=w; 
    return wynik;
  } 
  const wektor & operator *(double l2) const
  {
    wektor w;
    for(int i=0;i<ROZMIAR;i++)
      w[i]=tab_w[i]*l2;
    const wektor & wynik=w; 
    return wynik;
  }


  double dlugosc() const
  {
    return sqrt(pow(tab_w[0],2)+pow(tab_w[1],2)+pow(tab_w[2],2));
  }

  bool operator== (const wektor & W2) const
  {
    if(tab_w[0]==W2[0] && tab_w[1]==W2[1] && tab_w[2]==W2[2]) return true;
    else return false;
  }
  bool operator!= (const wektor & W2) const
  {
    if(tab_w[0]==W2[0] && tab_w[1]==W2[1] && tab_w[2]==W2[2]) return false;
    else return true;
  }
};

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




class macierzkw
{
  wektor tab_m[ROZMIAR];

public:
  macierzkw()
  {
    wektor w;
    for(int i=0;i<ROZMIAR;i++)
      tab_m[i]=w;
  }
  macierzkw(wektor W,wektor V, wektor U)
  {
    tab_m[0]=W;
    tab_m[1]=V;
    tab_m[2]=U;
  }
  macierzkw(int jednostkowa)
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
  const wektor  & operator[] (int index) const
  {
    if (index < 0 || index >= ROZMIAR)
      {
	cerr << "poza zakresem" << endl;
	exit(1);
      }
    return tab_m[index];
  }
  wektor & operator[] (int index)
  {
    if (index < 0 || index >= ROZMIAR)
      {
	cerr << "poza zakresem" << endl;
	exit(1);
      }
    return tab_m[index];
  }
  //wektory kolumny
  const double  & operator() (int ind1, int ind2) const
  {
    macierzkw M;
    if (ind1 < 0 || ind2 < 0 || ind1 >= ROZMIAR || ind2 >= ROZMIAR)
      {
	cerr << "poza zakresem" << endl;
	exit(1);
      }
    return tab_m[ind2][ind1];
  }
  double & operator() (int ind1, int ind2)
  {
    macierzkw M;
    if (ind1 < 0 || ind2 < 0 || ind1 >= ROZMIAR || ind2 >= ROZMIAR)
      {
	cerr << "poza zakresem" << endl;
	exit(1);
      }
    return tab_m[ind2][ind1];
  }


  double wyznacznikLaplace()
  {
    double wyznacznik=0;
    wyznacznik+=tab_m[0][0]*(tab_m[1][1]*tab_m[2][2]-tab_m[1][2]*tab_m[2][1]);
    wyznacznik-=tab_m[0][1]*(tab_m[1][0]*tab_m[2][2]-tab_m[1][2]*tab_m[2][0]);
    wyznacznik+=tab_m[0][2]*(tab_m[1][0]*tab_m[2][1]-tab_m[1][1]*tab_m[2][0]);
    return wyznacznik;
  }
  double wyznacznikGauss();
  double wyznacznikSarrus()
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

  
  const wektor & operator *(const wektor & W)
  {
    wektor temp;
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	temp[i]=temp[i]+tab_m[i][j]*W[j];
    const wektor & wynik=temp;
    return wynik;
  }

  const macierzkw & operator +(const macierzkw & B)
  {
    macierzkw A;
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	A[i][j]=tab_m[i][j]+B[i][j];
    const macierzkw & wynik=A;
    return wynik;
  }
  const macierzkw & operator -(const macierzkw & B)
  {
    macierzkw A;
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	A[i][j]=tab_m[i][j]-B[i][j];
    const macierzkw & wynik=A;
    return wynik;
  }
  /*const macierzkw & operator *(const macierzkw & B)
    {
    macierzkw A;
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	A[i][j]=
    const macierzkw & wynik=A;
    return wynik;
    }*/
  const macierzkw & operator *(double l2)
  {
    macierzkw A;
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	A[i][j]=tab_m[i][j]*l2;
    const macierzkw & wynik=A;
    return wynik;
  }

  bool operator== (const macierzkw & M2) const
  {
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	if(tab_m[i][j]!=M2[i][j]) return false;
    return true;
  }
  bool operator!= (const macierzkw & M2) const
  {
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	if(tab_m[i][j]!=M2[i][j]) return true;
    return false;
  }

  const macierzkw & transponuj() const
  {
    macierzkw M;
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	M[i][j]=tab_m[j][i];
    const macierzkw & wynik=M;
    return wynik;
  }
  void transponuj()
  {
    macierzkw M;
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	M[i][j]=tab_m[j][i];
    for(int i=0;i<ROZMIAR;i++)
      for(int j=0;j<ROZMIAR;j++)
	tab_m[i][j]=M[i][j];
  }
  
  const macierzkw & odwroc() const;
  void odwroc();
};

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
	  cout<<M(i,j);
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
	  strm>>M[i][j]>>znak;
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




class ukladrownan
{
  macierzkw A;
  wektor w;
public:
  ukladrownan()
  {
    macierzkw A;
    wektor w;
  }
  ukladrownan(const macierzkw & M, const wektor & W)
  {
    A=M;
    w=W;
  }
};

ostream & operator << (ostream & strm, const ukladrownan & X);

istream & operator >> (istream & strm, const ukladrownan & X);



  
int main()
{
  wektor u(1,3,2),v(-2,1,5),w(3,4,1);
  macierzkw M(u,v,w);
  cout<<M<<endl;

  return 0;
}
