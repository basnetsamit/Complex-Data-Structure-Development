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

  //ReallyLongInt x; //to store ASCII value

  //string in1;
  //string in2;
  //inFile[0]>>in1;
  //inFile[1]>>in2;
  
  ReallyLongInt e; //(stoll(in1)); 
  ReallyLongInt n;  //(stoll(in2));

  string z;
  int idx=0;
  
  while(inFile>>z)
    {
      if(idx==0)
	e=stoll(z);
      else if(idx==1)
	n=stoll(z);
      //n=stoll(inFile[2]);
      idx++;
    }

  inFile.close();

  //loop over characters in message
  inFile.open(argv[2]);

  if (!inFile) {
    cerr << "Unable to open file"<<endl;
    exit(1);   // call system to stop
  }

  int ascii; //ASCII value
  ReallyLongInt y; 
  char ch;
  
  while(inFile>>ch)
    {
      cout<<"Character is: "<<ch<<endl;
      cout<<"Value of e: "<<e.toString()<<endl;
      cout<<"Value of n: "<<n.toString()<<endl;			       
     
      ascii=(int)ch; //character to ASCII value
      cout<<"ascii value of char is: "<<ascii<<endl;
      ReallyLongInt x(ascii);
      y=(x.exp(e))%n;

      cout<<"checking exp: "<<(x.exp(e)).toString()<<endl;
     
      //cout<<"value of y: "<<y.toString()<<endl;
					  
					  

      long long character=stoll(y.toString(),nullptr,10); //converting string->ll

						     
      cout<<"character long long: "<<character<<endl;
      
      char c=(char)character;

      cout<<"char c is: "<<c<<endl;
      //char c=static_cast<char>(y); 

      outFile<<c;
	       cout<<"------------------------"<<endl;       
      
    }
  inFile.close();
  outFile.close();


  
}
