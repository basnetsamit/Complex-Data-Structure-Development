#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"



using namespace std;

int main(int argc, char *argv[])
{
  if(argc!=5) //need 4 command line arguments
    {
      cout<<"Please enter two prime numbers and two filenames as command line arguments"<<endl;
      return 1;
    }

  ReallyLongInt p(stoll(argv[1]));
  ReallyLongInt q(stoll(argv[2]));

  cout<<p.toString()<<endl;
  cout<<q.toString()<<endl;

  if(!p.isPrime() || !p.isPrime())
    {
      cout<<"The numbers aren't prime"<<endl;
      return 1;
    }

  ReallyLongInt n=p*q;
  ReallyLongInt t=(p-1)*(q-1);

  cout<<"n: "<<n.toString()<<endl;
  cout<<"t: "<<t.toString()<<endl;

  ReallyLongInt e=2; //need an e relatively prime to t
  cout<<"Value of e before while loop: "<<e.toString()<<endl;

  ReallyLongInt gcd=0;

  ReallyLongInt x;
  ReallyLongInt y;
      
  while(!gcd.equal(1)) //relatively prime when gcd=1
    {
      numberTheory nt;
      gcd=nt.extendedEuclid(e,t,x,y);

      e=e+1;
    }

  cout<<"Value of e after while loop: "<<e.toString()<<endl;

  cout<<"Value of x: "<<x.toString()<<endl;
  cout<<"Value of y: "<<y.toString()<<endl;
				      

  //find a d such that (ed)%t=1

  ReallyLongInt d;

  cout<<"Is x Neg?: "<<x.isNeg<<endl;
  
  if(x.isNeg==false)
    {
      cout<<"Up here"<<endl;
      d=x;
    }
  else
    {
      cout<<"Down here"<<endl;

      d=t+x;
      cout<<"Value of d: "<<d.toString()<<endl;

      /*
      while(!(((e*x)%t).equal(1)))
	{
	  cout<<"---------------"<<endl;;
	    cout<<"e: "<<e.toString()<<endl;
	  cout<<"x: "<<x.toString()<<endl;
	  cout<<"t: "<<t.toString()<<endl;
	  cout<<"Value for (e*x)%t:  "<<((e*x)%t).toString()<<endl;
      
	  x=x+1;
	  //cout<<"Value: "<<((e*x)%t).toString()<<endl;
	  cout<<"Working"<<endl;
	}
      **/
    }

				      
  //d=t-x;

  /***writing to file***/

  //Public(encryption)
  ofstream myfile;
  myfile.open(argv[3]);
  myfile<<e.toString()<<" "<<n.toString()<<endl;
  myfile.close();

  //Private(decryption)
  ofstream myf;
  myf.open(argv[4]);
  myf<<d.toString()<<" "<<n.toString()<<endl;
  myf.close();

  
}
