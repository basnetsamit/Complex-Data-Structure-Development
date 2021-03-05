#include <vector>
#include <iostream>
#include "numberTheory.hpp"
#include <cmath>
#include <string>
//#include "ReallyLongInt.cpp"

using namespace std;

ReallyLongInt numberTheory::extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b,ReallyLongInt& x, ReallyLongInt& y) 
{
  if(b.equal(0))
    {
      x=1;
      y=0;
      
      return a;
    }
  else
    {
      ReallyLongInt d;
      
      numberTheory t;
      d=t.extendedEuclid(b,a%b,x,y);
      
      ReallyLongInt x1;
      x1=y;
      
      ReallyLongInt y1;
      y1=x-y*(a/b);
      
      x=x1;
      y=y1;
      
      return d;
    }
  
}
/*
int main(){

  ReallyLongInt a(12);
  ReallyLongInt b(8);

  ReallyLongInt gcd;
  ReallyLongInt x;
  ReallyLongInt y;

  numberTheory t;
  
  gcd=t.extendedEuclid(a,b,x,y);

  cout<<"GCD is: "<<gcd.toString()<<endl;
  cout<<"x value: "<<x.toString()<<endl;
  cout<<"y value: "<<y.toString()<<endl;

  

}
**/

