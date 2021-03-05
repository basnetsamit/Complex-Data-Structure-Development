#ifndef REALLYLONGINT_HPP
#define REALLYLONGINT_HPP
#include <string>

using namespace std;

class ReallyLongInt
{
  
  
public:
  
  ReallyLongInt();
  ReallyLongInt(long long num);
  ReallyLongInt(const string& numStr);
  ReallyLongInt(const ReallyLongInt& other);
  
  ~ReallyLongInt();
  
  string toString() const;
  string toStringBinary() const;
  
  bool equal (const ReallyLongInt& other) const;
  bool greater(const ReallyLongInt& other) const;
  void removeLeadingZeros(void);

  ReallyLongInt& operator=(const ReallyLongInt& other);

  ReallyLongInt absAdd(const ReallyLongInt& other) const;
  ReallyLongInt absSub(const ReallyLongInt& other) const;

  ReallyLongInt add(const ReallyLongInt& other) const;
  ReallyLongInt sub(const ReallyLongInt& other) const;

  ReallyLongInt operator-() const;

  ReallyLongInt mult(const ReallyLongInt& other) const;
  void div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;

  ReallyLongInt exp(ReallyLongInt e) const;

  bool isPrime();

  

  //private:
  bool isNeg;
  unsigned int size;
  vector<bool> *digits;

  bool absGreater(const ReallyLongInt& other) const;

  void swap(ReallyLongInt other);
  ReallyLongInt absMult(const ReallyLongInt& other) const;
  

  void flipSign();

  void absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;

 
    
};

#endif

ReallyLongInt operator+(const ReallyLongInt& x,const ReallyLongInt& y);
ReallyLongInt operator-(const ReallyLongInt& x,const ReallyLongInt& y);
ReallyLongInt operator*(const ReallyLongInt& x,const ReallyLongInt& y);
ReallyLongInt operator/(const ReallyLongInt& x,const ReallyLongInt& y);
ReallyLongInt operator%(const ReallyLongInt& x,const ReallyLongInt& y);
