#include "LZ.hh"
#include "wek.cpp"


template class wektor<double,3>;
template std::istream & operator>>(std::istream & strm, wektor<double,3> & W);
template std::ostream & operator<<(std::ostream & strm, const wektor<double,3> & W);
template wektor<double,3> operator*(double l1, const wektor<double,3> & W2);


template class wektor<lz,5>;
template std::istream & operator>>(std::istream & strm, wektor<lz,5> & W);
template std::ostream & operator<<(std::ostream & strm, const wektor<lz,5> & W);
template wektor<lz,5> operator*(lz l1, const wektor<lz,5> & W2);

