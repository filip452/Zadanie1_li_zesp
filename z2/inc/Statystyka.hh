#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>

struct Statystyki {
  int dobre;
  int wszystkie;
};

void inicjuj(Statystyki & st);

void poprawna(Statystyki & st);

void niepoprawna(Statystyki & st);

int ile_dobrych(Statystyki & st);

int ile_wszystkich(Statystyki & st);

int procent_dobrych(Statystyki & st);

std::ostream & operator << (std::ostream & strm, const Statystyki & st);
  
#endif
