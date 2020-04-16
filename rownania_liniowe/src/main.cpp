#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using std::cout;
using std::cin;
using std::endl;

int main()
{
  wektor v(2,2,1),w(1,2,1.5),x(1,3,1),y(9,8.5,8);
  macierzkw M(v,w,x);
  UkladRownanL U(M,y);
  cout<<U;
  
  return 0;
}

