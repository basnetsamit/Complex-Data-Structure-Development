#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "numberTheory.hpp"
#include <iostream>
#include "ReallyLongInt.hpp"

TEST_CASE("TESTING numberTheory Class")
{
  SECTION("extended Euclid")
    {
      ReallyLongInt a(12);
      ReallyLongInt b(8);
      ReallyLongInt gcd;
      ReallyLongInt x;
      ReallyLongInt y;
      numberTheory t;
      gcd=t.extendedEuclid(a,b,x,y);
      REQUIRE(gcd.toString()=="4");
      REQUIRE(x.toString()=="1");
      REQUIRE(y.toString()=="-1");

      ReallyLongInt a1(13);
      ReallyLongInt b1(8);
      ReallyLongInt gcd1;
      ReallyLongInt x1;
      ReallyLongInt y1;
      numberTheory t1;
      gcd1=t1.extendedEuclid(a1,b1,x1,y1);
      REQUIRE(gcd1.toString()=="1");
      REQUIRE(x1.toString()=="-3");
      REQUIRE(y1.toString()=="5");

      ReallyLongInt a2(-20);
      ReallyLongInt b2(-10);
      ReallyLongInt gcd2;
      ReallyLongInt x2;
      ReallyLongInt y2;
      numberTheory t2;
      gcd2=t2.extendedEuclid(a2,b2,x2,y2);
      REQUIRE(gcd2.toString()=="-10");
      REQUIRE(x2.toString()=="0");
      REQUIRE(y2.toString()=="1");

      ReallyLongInt a3(20);
      ReallyLongInt b3(-10);
      ReallyLongInt gcd3;
      ReallyLongInt x3;
      ReallyLongInt y3;
      numberTheory t3;
      gcd3=t3.extendedEuclid(a3,b3,x3,y3);
      REQUIRE(gcd3.toString()=="-10");
      REQUIRE(x3.toString()=="0");
      REQUIRE(y3.toString()=="1");

      ReallyLongInt a4(-20);
      ReallyLongInt b4(10);
      ReallyLongInt gcd4;
      ReallyLongInt x4;
      ReallyLongInt y4;
      numberTheory t4;
      gcd4=t4.extendedEuclid(a4,b4,x4,y4);
      REQUIRE(gcd4.toString()=="10");
      REQUIRE(x4.toString()=="0");
      REQUIRE(y4.toString()=="1");



      
	
    }
}
  
