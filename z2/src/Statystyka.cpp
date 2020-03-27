#include "Statystyka.hh"
#include <iostream>

using std::endl;

void inicjuj(Statystyki & st)
{
  st.dobre = 0;
  st.wszystkie = 0;
}

void poprawna(Statystyki & st)
{
  st.dobre++;
  st.wszystkie++;
}

void niepoprawna(Statystyki & st)
{
  st.wszystkie++;
}

int ile_dobrych(Statystyki & st)
{
  return st.dobre;
}

int ile_wszystkich(Statystyki & st)
{
  return st.wszystkie;
}

int procent_dobrych(Statystyki & st)
{
  return (st.dobre*100)/st.wszystkie;
}

std::ostream & operator << (std::ostream & strm, const Statystyki & st)
{
  strm << "Poprawne odpowiedzi: " << st.dobre << endl << "Niepoprawne odpowiedzi: " << st.wszystkie-st.dobre << endl << "wszystkie odpowiedzi: " << st.wszystkie;
  return strm;
}
