#ifndef NUMBERTHEORY_HPP
#define NUMBERTHEORY_HPP
#include <string>
#include "ReallyLongInt.hpp"

using namespace std;

class numberTheory
{

public:

  ReallyLongInt extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b, ReallyLongInt& x, ReallyLongInt& y);

  
};

#endif
