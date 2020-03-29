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

int ile_wszystkich(const Statystyki & st)
{
  return st.wszystkie;
}

int procent_dobrych(const Statystyki & st)
{
  return (st.dobre*100)/st.wszystkie;
}

std::ostream & operator << (std::ostream & strm, const Statystyki & st)
{
  strm << "Procent poprawnych odpowiedzi: " << procent_dobrych(st) << "%";
  strm << endl;
  strm << "wszystkie odpowiedzi: " << ile_wszystkich(st);
  return strm;
}
