#include "LZ.hh"
#include "macierz.cpp"

template class macierz<double,5>;
template std::istream & operator>>(std::istream & strm,macierz<double,5> & M);
template std::ostream & operator<<(std::ostream & strm, const macierz<double,5> & M);
template macierz<double,5> operator*(double l2,const macierz<double,5> & M);

template class macierz<lz,5>;
template std::istream & operator>>(std::istream & strm,macierz<lz,5> & M);
template std::ostream & operator<<(std::ostream & strm, const macierz<lz,5> & M);
template macierz<lz,5> operator*(lz l2,const macierz<lz,5> & M);
