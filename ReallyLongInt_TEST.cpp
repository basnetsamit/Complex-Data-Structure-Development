#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "ReallyLongInt.hpp"
#include <iostream>

TEST_CASE("TESTING ReallyLongInt Class")
{
  ReallyLongInt *test_ReallyLongInt;
  
  SECTION("Default Constructor")
    {
      test_ReallyLongInt=new ReallyLongInt();
      REQUIRE((test_ReallyLongInt->toString())=="0");
      delete test_ReallyLongInt;
    }
  
  SECTION("Long Long Constructor")
    {
      test_ReallyLongInt=new ReallyLongInt();
      REQUIRE((test_ReallyLongInt->toString())=="0");
      delete test_ReallyLongInt;
    }
  
  SECTION("Long Long Constructor")
    {
      test_ReallyLongInt=new ReallyLongInt(2);
      REQUIRE((test_ReallyLongInt->toString())=="2");
      REQUIRE((test_ReallyLongInt->toStringBinary())=="10");
      delete test_ReallyLongInt;
    }
  
  SECTION("Long Long Constructor")
    {
      test_ReallyLongInt=new ReallyLongInt(267968);
      REQUIRE((test_ReallyLongInt->toString())=="267968");
      REQUIRE((test_ReallyLongInt->toStringBinary())=="1000001011011000000");
      delete test_ReallyLongInt;
    }
    
  SECTION("String Constructor")
    {
      test_ReallyLongInt=new ReallyLongInt("2");
      REQUIRE((test_ReallyLongInt->toString())=="2");
      delete test_ReallyLongInt;
    }

  SECTION("Negative Numbers")
    {
      test_ReallyLongInt=new ReallyLongInt(-2);
      REQUIRE((test_ReallyLongInt->toString())=="-2");
      REQUIRE((test_ReallyLongInt->toStringBinary())=="-10");
      delete test_ReallyLongInt;
    }
  
  SECTION("Copy Constructor")
    {
      test_ReallyLongInt=new ReallyLongInt("267968");
      ReallyLongInt test(*test_ReallyLongInt);
      REQUIRE(test.toString()=="267968");
      delete test_ReallyLongInt;
    }
  
   SECTION("Equal Constructor")
    {
      test_ReallyLongInt=new ReallyLongInt(465);
      REQUIRE((test_ReallyLongInt->equal(465))==true);
      REQUIRE((test_ReallyLongInt->equal(466))==false);

      ReallyLongInt a(100);
      ReallyLongInt b(100);
      ReallyLongInt c(-100);
      ReallyLongInt d(-102);
      REQUIRE(a.equal(b)==true);
      REQUIRE(c.equal(d)==false);
      REQUIRE(c.equal(-100)==true); 
    }

   SECTION("Comparison Operators")
     {
       test_ReallyLongInt=new ReallyLongInt(10);
       REQUIRE((test_ReallyLongInt->toString())=="10");
       REQUIRE((test_ReallyLongInt->toStringBinary())=="1010");
       REQUIRE((test_ReallyLongInt->greater(2))==true);
       REQUIRE((test_ReallyLongInt->greater(11))==false);
       REQUIRE((test_ReallyLongInt->greater(-64342311))==true); 
       delete test_ReallyLongInt;
     }

   SECTION("Greater Operator Check")
     {
       ReallyLongInt a(100);
       ReallyLongInt b(500);
       ReallyLongInt c(-100);
       ReallyLongInt d(-500);
       
       REQUIRE(a.greater(b)==false);
       REQUIRE(b.greater(a)==true);
       REQUIRE(a.greater(c)==true);
       REQUIRE(d.greater(b)==false);
       REQUIRE(c.greater(d)==true);
       REQUIRE(d.greater(c)==false);
       REQUIRE(c.greater(c)==false);
       REQUIRE(a.greater(a)==false);
     }
   
   SECTION("Comparison Operators for Negative number as this")
     {
       test_ReallyLongInt=new ReallyLongInt(-2679684960);
       REQUIRE((test_ReallyLongInt->greater(-9999999999))==true);
       REQUIRE((test_ReallyLongInt->greater(-45641))==false);
       REQUIRE((test_ReallyLongInt->greater(1456141))==false);
     }

  

  SECTION("Leading zeros check")
    {
      test_ReallyLongInt=new ReallyLongInt(0001); //input is long long
      test_ReallyLongInt->removeLeadingZeros();
      REQUIRE((test_ReallyLongInt->toStringBinary())=="1");
      
      test_ReallyLongInt=new ReallyLongInt(1); //input is long long
      test_ReallyLongInt->removeLeadingZeros();
      REQUIRE((test_ReallyLongInt->toStringBinary())=="1");

      test_ReallyLongInt=new ReallyLongInt(00000); //input is long long
      test_ReallyLongInt->removeLeadingZeros();
      REQUIRE((test_ReallyLongInt->toStringBinary())=="0");
    }
    
  SECTION("Unsigned add")
    {  
      //same size && a>b
      ReallyLongInt a1(26796);
      ReallyLongInt b1(26790);
      ReallyLongInt res1=a1.absAdd(b1);
      REQUIRE((res1.toString())=="53586");
      REQUIRE((res1.toStringBinary())=="1101000101010010");

      //same size && b>a
      ReallyLongInt a2(26790);
      ReallyLongInt b2(26796);
      ReallyLongInt res2=a2.absAdd(b2);
      REQUIRE((res2.toString())=="53586");
      REQUIRE((res2.toStringBinary())=="1101000101010010");
       
      //size a>b
      ReallyLongInt a3(2671);
      ReallyLongInt b3(11);
      ReallyLongInt res3=a3.absAdd(b3);
      REQUIRE((res3.toString())=="2682");
      REQUIRE((res3.toStringBinary())=="101001111010"); 
      
      //size b>a
      ReallyLongInt a4(25);
      ReallyLongInt b4(1000);
      ReallyLongInt res4=a4.absAdd(b4);
      REQUIRE((res4.toString())=="1025");
      REQUIRE((res4.toStringBinary())=="10000000001");
      
      //a=b
      ReallyLongInt a5(25);
      ReallyLongInt b5(25);
      ReallyLongInt res5=a5.absAdd(b5);
      REQUIRE((res5.toString())=="50");
      REQUIRE((res5.toStringBinary())=="110010");       
    }
   
  SECTION("Unsigned subtract")
    {
      //same size && a>b
      ReallyLongInt a1(40);
      ReallyLongInt b1(5);
      ReallyLongInt res1=a1.absSub(b1);
      REQUIRE((res1.toString())=="35"); 
      REQUIRE((res1.toStringBinary())=="100011"); 
      
      //same size && b>a
      ReallyLongInt a2(26790);
      ReallyLongInt b2(26796);
      ReallyLongInt res2=a2.absSub(b2);
      REQUIRE((res2.toString())=="-6");
      REQUIRE((res2.toStringBinary())=="-110");
      
      //size a>b
      ReallyLongInt a3(2671);
      ReallyLongInt b3(11);
      ReallyLongInt res3=a3.absSub(b3);
      REQUIRE((res3.toString())=="2660"); 
      REQUIRE((res3.toStringBinary())=="101001100100");
      
      //size b>a
      ReallyLongInt a4(25);
      ReallyLongInt b4(1000);
      ReallyLongInt res4=a4.absSub(b4);
      REQUIRE((res4.toString())=="-975"); 
      REQUIRE((res4.toStringBinary())=="-1111001111"); 
           
      //a=b
      ReallyLongInt a5(25);
      ReallyLongInt b5(25);
      ReallyLongInt res5=a5.absSub(b5);
      REQUIRE((res5.toString())=="0");
      REQUIRE((res5.toStringBinary())=="0");
    }
  
  SECTION("Add cases")
    {
      //both +ve
      ReallyLongInt a1(100);
      ReallyLongInt b1(25);
      ReallyLongInt res1=a1.add(b1);
      REQUIRE((res1.toString())=="125");
      REQUIRE((res1.toStringBinary())=="1111101");
      
      // a + (-b) and |b|<a
      ReallyLongInt a2(100);
      ReallyLongInt b2(-25);
      ReallyLongInt res2=a2.add(b2);
      REQUIRE((res2.toString())=="75");
      REQUIRE((res2.toStringBinary())=="1001011");
      
      // a + (-b)  and  |b|>a
      ReallyLongInt a3(25);
      ReallyLongInt b3(-100);
      ReallyLongInt res3=a3.add(b3);
      REQUIRE((res3.toString())=="-75");
      REQUIRE((res3.toStringBinary())=="-1001011");
      
      
      // (-a) + b  and  |a|>b
      ReallyLongInt a4(-10);
      ReallyLongInt b4(2);
      ReallyLongInt res4=a4.add(b4);
      REQUIRE((res4.toString())=="-8");
      REQUIRE((res4.toStringBinary())=="-1000");
       
      // (-a) + b  and  |a|<b
      ReallyLongInt a5(-10);
      ReallyLongInt b5(12);
      ReallyLongInt res5=a5.add(b5);
      REQUIRE((res5.toString())=="2");
      REQUIRE((res5.toStringBinary())=="10");
      
      // (-a) + (-b) = -(a+b)
      ReallyLongInt a6(-10);
      ReallyLongInt b6(-12);
      ReallyLongInt res6=a6.add(b6);
      REQUIRE((res6.toString())=="-22");
      REQUIRE((res6.toStringBinary())=="-10110");
    }
  
  SECTION("Subtract cases")
    {
      //both +ve a>b
      ReallyLongInt a1(100);
      ReallyLongInt b1(25);
      ReallyLongInt res1=a1.sub(b1);
      REQUIRE((res1.toString())=="75");
      REQUIRE((res1.toStringBinary())=="1001011");
      
      //both +ve b>a
      ReallyLongInt a2(10);
      ReallyLongInt b2(25);
      ReallyLongInt res2=a2.sub(b2);
      REQUIRE((res2.toString())=="-15");
      REQUIRE((res2.toStringBinary())=="-1111");
      
      
      // a-(-b)=a+b
      ReallyLongInt a3(10);
      ReallyLongInt b3(-55);
      ReallyLongInt res3=a3.sub(b3);
      REQUIRE((res3.toString())=="65");
      REQUIRE((res3.toStringBinary())=="1000001");
       
      // (-a)-(+b)=-(a+b)
      ReallyLongInt a4(-10);
      ReallyLongInt b4(50);
      ReallyLongInt res4=a4.sub(b4);
      REQUIRE((res4.toString())=="-60");
      REQUIRE((res4.toStringBinary())=="-111100");
      
      // (-a)-(-b)=-(a-b)
      ReallyLongInt a5(-10);
      ReallyLongInt b5(-50);
      ReallyLongInt res5=a5.sub(b5);
      REQUIRE((res5.toString())=="40");
      REQUIRE((res5.toStringBinary())=="101000");
    }
  
  
   SECTION("mult cases")
     {
       ReallyLongInt a1(100);
       ReallyLongInt b1(500);
       ReallyLongInt res1=a1.mult(b1);
       REQUIRE((res1.toString())=="50000");
       REQUIRE((res1.toStringBinary())=="1100001101010000");
       
       ReallyLongInt a2(-100);
       ReallyLongInt b2(-500);
       ReallyLongInt res2=a2.mult(b2);
       REQUIRE((res2.toString())=="50000");
       REQUIRE((res2.toStringBinary())=="1100001101010000");
       
       
       ReallyLongInt a3(-2);
       ReallyLongInt b3(5);
       ReallyLongInt res3=a3.mult(b3);
       REQUIRE((res3.toString())=="-10");
       REQUIRE((res3.toStringBinary())=="-1010");

       ReallyLongInt a4(20);
       ReallyLongInt b4(-5);
       ReallyLongInt res4=a4.mult(b4);
       REQUIRE((res4.toString())=="-100");
       REQUIRE((res4.toStringBinary())=="-1100100");

       ReallyLongInt a5(20);
       ReallyLongInt b5(-5);
       ReallyLongInt c5(0);
       ReallyLongInt res5=a5.mult(c5);
       ReallyLongInt res6=b5.mult(c5);
       ReallyLongInt res7=c5.mult(c5);
       REQUIRE((res5.toString())=="0");
       REQUIRE((res6.toString())=="0");
       REQUIRE((res7.toString())=="0");
     
     }
   
   SECTION("Division cases")
     {
       
       ReallyLongInt a1(10);
       ReallyLongInt a2(2);
       ReallyLongInt q;
       ReallyLongInt r;
       a1.absDiv(a2,q,r);
       REQUIRE(q.toString()=="5");
       REQUIRE(r.toString()=="0");
              
       ReallyLongInt b1(1000);
       ReallyLongInt b2(33);
       ReallyLongInt q1;
       ReallyLongInt r1;
       b1.absDiv(b2,q1,r1);
       REQUIRE(q1.toString()=="30");
       REQUIRE(r1.toString()=="10");

       ReallyLongInt c1(1000);
       ReallyLongInt c2(33);
       ReallyLongInt q2=c1/c2;
       ReallyLongInt r2=c1%c2;
       REQUIRE(q2.toString()=="30");
       REQUIRE(r2.toString()=="10");

       ReallyLongInt x(7);
       ReallyLongInt y(3);
       ReallyLongInt m=x/y;
       ReallyLongInt n=x%y;
       REQUIRE(m.toString()=="2");
       REQUIRE(n.toString()=="1");
       
       //Signed Division
       ReallyLongInt x1(-8);
       ReallyLongInt x2(-2);
       ReallyLongInt q12;
       ReallyLongInt r12;
       x1.div(x2,q12,r12);
       ReallyLongInt m2=x1%x2;
       REQUIRE(q12.toString()=="4");
       REQUIRE(m2.toString()=="0");
       
     }

   SECTION("Signed Division cases")
     {
       ReallyLongInt a(10);
       ReallyLongInt b(-2);
       ReallyLongInt q;
       ReallyLongInt r;
       a.div(b,q,r);
       REQUIRE(q.toString()=="-5");
       REQUIRE(r.toString()=="0");

       ReallyLongInt a1(-10);
       ReallyLongInt b1(-2);
       ReallyLongInt q1;
       ReallyLongInt r1;
       a1.div(b1,q1,r1);
       REQUIRE(q1.toString()=="5");
       REQUIRE(r1.toString()=="0");

       ReallyLongInt a2(10);
       ReallyLongInt b2(-2);
       ReallyLongInt q2;
       ReallyLongInt r2;
       a2.div(b2,q2,r2);
       REQUIRE(q2.toString()=="-5");
       REQUIRE(r2.toString()=="0");

       ReallyLongInt a3(10);
       ReallyLongInt b3(10);
       ReallyLongInt q3;
       ReallyLongInt r3;
       a3.div(b3,q3,r3);
       REQUIRE(q3.toString()=="1");
       REQUIRE(r3.toString()=="0");

       ReallyLongInt a4(-11);
       ReallyLongInt b4(2);
       ReallyLongInt q4;
       ReallyLongInt r4;
       a4.div(b4,q4,r4);
       REQUIRE(q4.toString()=="-5");
       REQUIRE(r4.toString()=="1");
       
       ReallyLongInt a5(-11);
       ReallyLongInt b5(-2);
       ReallyLongInt q5;
       ReallyLongInt r5;
       a5.div(b5,q5,r5);
       REQUIRE(q5.toString()=="5");
       REQUIRE(r5.toString()=="1");

       ReallyLongInt a6(117);
       ReallyLongInt b6(-5);
       ReallyLongInt q6;
       ReallyLongInt r6;
       a6.div(b6,q6,r6);
       REQUIRE(q6.toString()=="-23");
       REQUIRE(r6.toString()=="2");

       ReallyLongInt a7(0);
       ReallyLongInt b7(131);
       ReallyLongInt q7;
       ReallyLongInt r7;
       a7.div(b7,q7,r7);
       REQUIRE(q7.toString()=="0");
       REQUIRE(r7.toString()=="0");

       
     }
  
   SECTION("Exponents cases")
     {
       ReallyLongInt a(6);
       ReallyLongInt e(2);
       ReallyLongInt exp=a.exp(e);
       REQUIRE(exp.toString()=="36");

       ReallyLongInt a1(5);
       ReallyLongInt e1(2);
       ReallyLongInt exp1=a1.exp(e1);
       REQUIRE(exp1.toString()=="25");

       ReallyLongInt a2(5);
       ReallyLongInt e2(1);
       ReallyLongInt exp2=a2.exp(e2);
       REQUIRE(exp2.toString()=="5");

       ReallyLongInt a3(5);
       ReallyLongInt e3(0);
       ReallyLongInt exp3=a3.exp(e3);
       REQUIRE(exp3.toString()=="1");

       ReallyLongInt a4(2);
       ReallyLongInt e4(6);
       ReallyLongInt exp4=a4.exp(e4);
       REQUIRE(exp4.toString()=="64");
     }

   SECTION("isPrime")
     {
      
       ReallyLongInt a(4);
       REQUIRE(a.isPrime()==false);

       ReallyLongInt b(9);
       REQUIRE(b.isPrime()==false);

       ReallyLongInt c(1050);
       REQUIRE(c.isPrime()==false);
       
       ReallyLongInt d(7);
       REQUIRE(d.isPrime()==true);

       ReallyLongInt e(1223);
       REQUIRE(e.isPrime()==true);

       ReallyLongInt f(11587);
       REQUIRE(f.isPrime()==true);

       ReallyLongInt g(9163);
       REQUIRE(g.isPrime()==false);

       ReallyLongInt h(2); //special case
       REQUIRE(h.isPrime()==true);

       ReallyLongInt i(1); //special case
       REQUIRE(i.isPrime()==false);

       
     
     }
   
}
      
      


  
