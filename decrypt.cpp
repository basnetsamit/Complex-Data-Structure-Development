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
  if(argc!=4)
    {
      cout<<"Please enter the key file, input file and output file as command line arguments"<<endl;
      return 1;
    }

  ifstream inFile;
  ofstream outFile;
  
  inFile.open(argv[1]);
  outFile.open(argv[3]);

  if (!inFile) {
    cerr << "Unable to open file"<<endl;
    exit(1);   // call system to stop
  }
 
  //ReallyLongInt y; //to store ASCII value

  ReallyLongInt d;
  ReallyLongInt n;

  string z;
  int idx=0;
  
  while(inFile>>z)
    {
      if(idx==0)
	d=stoll(z);
      else if(idx==1)
	n=stoll(z);
      idx++;
    }

  cout<<"value of d: "<<d.toString()<<endl;
  cout<<"value of n: "<<n.toString()<<endl;
  
  inFile.close();

  //loop over characters in message
  inFile.open(argv[2]);
  if (!inFile) {
    cerr << "Unable to open file"<<endl;
    exit(1);   // call system to stop
  }

  int ascii; //ASCII value
  ReallyLongInt x;
  char ch;
  
  while(inFile>>ch)
    {
      cout<<"character is: "<<ch<<endl;
      
      ascii=(int)ch; //character to ASCII value
      cout<<"ascii value is: "<<ascii<<endl;
      
      ReallyLongInt y(ascii);
      cout<<"ascii value rlt is: "<<y.toString()<<endl;
      
      x=(y.exp(d))%n;

      cout<<"new ascii value: "<<x.toString()<<endl;;

      long long character=stoll(x.toString(),nullptr,10);

      char c=(char)character;
      cout<<"character after conversion: "<<c<<endl;

      outFile<<c;
      cout<<"------------------------------"<<endl;
    }
  inFile.close();
  outFile.close();
  
}
  

