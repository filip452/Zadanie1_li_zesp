#include "UklRown.cpp"
#include "LZ.hh"

template class uklad<double,5>;
template std::istream & operator>>(std::istream & strm,uklad<double,5> &U);
template std::ostream & operator<<(std::ostream & strm,const uklad<double,5> &U);

template class uklad<lz,5>;
template std::istream & operator>>(std::istream & strm,uklad<lz,5> &U);
template std::ostream & operator<<(std::ostream & strm,const uklad<lz,5> &U);
