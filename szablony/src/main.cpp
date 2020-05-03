#include <iostream>
#include "LZ.hh"
#include "UklRown.hh"


using std::cout;
using std::endl;
using std::cerr;
using std::cin;


int main()
{
  uklad<double,5> Ur;
  uklad<lz,5> Uz;
  char wariant;
  
  cin>>wariant;
  if(wariant!='r' && wariant!='z')
    {
      cerr<<"Nalezy wybrac wariant obliczen."<<endl;
      exit(1);
    }
  if(wariant=='r') cin>>Ur;
  else cin>>Uz;
  if(wariant=='r') cout<<Ur.rozwiaz()<<endl;
  else cout<<Uz.rozwiaz()<<endl;
  
  return 0;
}
