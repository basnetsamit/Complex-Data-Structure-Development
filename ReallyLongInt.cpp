#include <vector>
#include <iostream>
#include "ReallyLongInt.hpp"
#include <cmath>
#include <string>

using namespace std;

ReallyLongInt::ReallyLongInt()
{
  size=1;
  isNeg=false;
  digits=new vector<bool>(1,0);
}

ReallyLongInt::ReallyLongInt(long long num)
{
  if(num<0)
      {
	isNeg=true;
	num = num * (-1);
      }
    else
      {
	isNeg=false;
      }

  if(num==0) //log base doesn't work for zero
    size=1;
  else
    size=(log2(num))+1; //exactly the required number of spaces

  digits=new vector<bool>(size,0);
  
  unsigned int i=0;
  while(num>0)
    {
      (*digits)[i]=num%2;
      num=num/2;
      i++;
    } 
}

ReallyLongInt::ReallyLongInt(const string& numStr)
{
  long long num =  stoll(numStr); //string to long long

   if(num<0)
      {
	isNeg=true;
	num = num * (-1);
      }
    else
      {
	isNeg=false;
      }
    
   if(num==0) //log base doesn't work for zero
     size=1;
   else
     size=(log2(num))+1; //exactly the required number of spaces
  
   digits=new vector<bool>(size,0);
   
   unsigned int i=0;
   while(num>0)
     {
       (*digits)[i]=num%2;
       num=num/2;
       i++;
     }
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt& other)
{
  isNeg=other.isNeg;
  size=other.size;

  digits=new vector<bool>(size,0);

  for(unsigned int i=0;i<size;i++)
    (*digits)[i]=(*other.digits)[i];
    
}

ReallyLongInt::~ReallyLongInt()
{
  delete digits;
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const
{
  if(this->equal(other))
    return false;
  
  else if(size>other.size)
    return true;

  else if(other.size>size)
    return false;

  else
    {
      for(unsigned int i=size-1;i>=0;i--) //loop from the last index cause digit stores binary in reverse
      {
	if((*digits)[i]!=(*(other.digits))[i])
	  {
	    if((*digits)[i]>(*(other.digits))[i])
	      return true;
	    else
	      return false;
	  }
      }
      //return false; //equal case
    }
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const
{
  if(other.isNeg==true&&this->isNeg==false)
    return true;

  else if(other.isNeg==false&&this->isNeg==true)
    return false;

  else if(other.isNeg==true&&this->isNeg==true)
    {
      if(absGreater(other)==true)
	return false;
      else if(absGreater(other)==false)
	{
	  //cout<<"We Here"<<endl;
	  if(equal(other)==true) //equal case
	    return false;
	  else
	    return true;
	}
      /*
      else //equal case
	{
	  //cout<<"We Here"<<endl;
	  return false;
	}
      **/
    }

  else if(other.isNeg==false&&this->isNeg==false)
    {
      if(absGreater(other)==true)
	return true;
      else if(absGreater(other)==false)
	return false;
      else //equal case
	return false;
    }
}

string ReallyLongInt::toString() const
{
 long long result=0;

  for(int i=size-1;i>=0;i--)
    {
      result=result+((*digits)[i])*pow(2,i);
      
    }
  
  string out="";
  
  if(this->isNeg==true)
    {
      out="-"+to_string(result);
      return out;
    }
       
  return to_string(result);
}

string ReallyLongInt::toStringBinary() const
{
  string Bin="";
  
  for(unsigned int i=0;i<=size-1;i++)
    {
      if((*this->digits)[i]==true)
	Bin="1"+Bin;
      else
	Bin="0"+Bin;
    }

  string outp="";

  if(this->isNeg==true)
    {
      outp="-"+Bin;
      return outp;
    }

  return Bin;
}

bool ReallyLongInt::equal (const ReallyLongInt& other) const
{
  if(this->isNeg!=other.isNeg)
    return false;

  else if(size!=other.size)
    return false;
  
  else 
    {
    for(unsigned int i=0;i<size;i++)
      {
	if((*digits)[i]!=(*(other.digits))[i])
	  return false;
      }
    return true;
    }
}

void ReallyLongInt::removeLeadingZeros(void)
{
  if(size==1)
    return;
  else if((*digits)[size-1]==1)
    return;
  else if(this->toString()=="0")
    *this=0;
  else 
    {
      int i=1; //size is 1 more than idx 

      while((*digits)[size-i]!=1)
	{
	  //cout<<"index: "<<size-i<<"  Number: "<<(*digits)[size-i]<<endl;
	  i=i+1;
	}
      int newsize=(size-i)+1; //size starts from 1 but i from 0
          
      vector<bool> *dig=new vector<bool>(newsize,0);
			   
      for(int j=0;j<newsize;j++)
	{
	  (*dig)[j]=(*digits)[j]; //i is where the first 1 is found
	}
      
      //delete digits;
      this->digits=dig;
      this->size=newsize;
    }
}

void ReallyLongInt::swap(ReallyLongInt other)
{
  std::swap(this->digits, other.digits);
  std::swap(this->size, other.size);
  std::swap(this->isNeg, other.isNeg);
}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other)
{
  swap(other);
  return *this;
}
  
ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const
{
  unsigned int smallsize=0;
  unsigned int bigsize=0;
  int carry=0;
  
  if(size<other.size)
    {
      smallsize=size;
      bigsize=other.size;
    }
  else
    {
      smallsize=other.size;
      bigsize=size;
    }
  
  vector<bool> *temp=new vector<bool>(bigsize+1,0);

  unsigned int i=0;

  for(i=0;i<smallsize;i++)
    {
      if(((*digits)[i]+(*other.digits)[i]+carry)==0)
	{
	  (*temp)[i]=0;
	  carry=0;
	}
      else if(((*digits)[i]+(*other.digits)[i]+carry)==1)
	{
	  (*temp)[i]=1;
	  carry=0;
	}
      else if(((*digits)[i]+(*other.digits)[i]+carry)==2)
	{
	  (*temp)[i]=0;
	  carry=1;
	}
      else if(((*digits)[i]+(*other.digits)[i]+carry)>2)
	{
	  (*temp)[i]=1;
	  carry=1;
	}
    }

  unsigned int j;
  for(j=smallsize; j<bigsize; j++)
    {
      if(size>other.size)
	{
	  if((*digits)[j]+carry==2)
	    {
	      (*temp)[j]=0;
	      carry=1;
	    }
	  
	  if((*digits)[j]+carry==1)
	    {
	      (*temp)[j]=1;
	      carry=0;
	    }
	}
      else
	{
	  if((*other.digits)[j]+carry==2)
	    {
	      (*temp)[j]=0;
	      carry=1;
	    }
	  
	  if((*other.digits)[j]+carry==1)
	    {
	      (*temp)[j]=1;
	      carry=0;
	    }
	}
      
      
    }
  
  if(carry==1)
    (*temp)[j]=1;
  
  ReallyLongInt a;
  *a.digits=*temp;
  a.size=bigsize+1;
  a.isNeg=false;
  a.removeLeadingZeros();
  return a;  
}


ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const
{
  unsigned int nsize=0;
  unsigned int bigsize=0;

  if(size<other.size) //size of new vector is smaller RLI
    {
      nsize=size;
      bigsize=other.size;
    }
  else
    {
      nsize=other.size;
      bigsize=size;
    }

  vector<bool> *temp=new vector<bool>(bigsize,0);

  ReallyLongInt a;
  
  if(this->absGreater(other)==true)
    a.isNeg=false;
  else if(this->equal(other)==true)
    a.isNeg=false;
  else 
    a.isNeg=true;

  if((this->absGreater(other))==true)    //|a|>|b|
    {
      for(unsigned int i=0; i<nsize;i++) //here
	{
	  //cout<<"We here"<<endl;
	  if((*digits)[i]==(*other.digits)[i])
	    (*temp)[i]=0;
	  
	  else if((*digits)[i]==1&&(*other.digits)[i]==0)
	    (*temp)[i]=1;
	  	  
	  else if((*digits)[i]==0&&(*other.digits)[i]==1)
	    {
	      unsigned int j=i;
	      while((*digits)[j]!=1)
		{
		  j=j+1;
		}
	      
	      (*digits)[j]=0;
	      j=j-1;
	      
	      while(j!=i)
		{
		  (*digits)[j]=1;
		  j--;
		}
	      (*digits)[i]=1;
	      (*temp)[i]=1;
	    }
	  //cout<<"i: "<<i<<"temp: "<<(*temp)[i]<<endl;
	}
      for(unsigned int r=nsize;r<bigsize;r++)
	{
	  //cout<<"Yeta hai aba"<<endl;
	  (*temp)[r]=(*digits)[r];
	  //cout<<"r: "<<r<<"temp: "<<(*temp)[r]<<endl;
	}
    }
  
  else if((this->absGreater(other))==false)
    {
      for(unsigned int i=0; i<nsize;i++)
	{
	  if((*digits)[i]==(*other.digits)[i])
	    (*temp)[i]=0;
	  
	  else if((*other.digits)[i]==1&&(*digits)[i]==0)
	    (*temp)[i]=1;
	  
	  else if((*other.digits)[i]==0&&(*digits)[i]==1)
	    {
	      unsigned int j=i;
	      while((*other.digits)[j]!=1)
		{
		  j=j+1;
		}
	      
	      (*other.digits)[j]=0;
	      j=j-1;
	      
	      while(j!=i)
		{
		  (*other.digits)[j]=1;
		    j--;
		}
	      (*other.digits)[i]=1;
	      (*temp)[i]=1;
	    }
	}
      for(unsigned int s=nsize;s<bigsize;s++)
	(*temp)[s]=(*other.digits)[s];
    }
  
  
  *a.digits=*temp;
  a.size=bigsize;
  a.removeLeadingZeros();
  return a;  
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const
{
  if(this->isNeg==false && other.isNeg==false)
    return this->absAdd(other);

  if(this->isNeg==false && other.isNeg==true)  //considers both |b|>a and |b|<a
    return this->absSub(other);
  
  if(this->isNeg==true && other.isNeg==false) //flipsign using operator-
    return -this->absSub(other);
  
  if(this->isNeg==true && other.isNeg==true) //add and use operator-
    return -this->absAdd(other);
    
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const
{
  if(this->isNeg==false && other.isNeg==false) //considers both b>a and b<a
    return this->absSub(other);
  
  if(this->isNeg==false && other.isNeg==true)  // a-(-b)=a+b
    return this->absAdd(other);
  
  if(this->isNeg==true && other.isNeg==false) //need to flipsign for result   
    return -this->absAdd(other);
  
  if(this->isNeg==true && other.isNeg==true) //need to add a -ve
    return -this->absSub(other);
    
}

void ReallyLongInt::flipSign()
{
  if(toString()=="0")
    isNeg=false;
  else if(isNeg==false)
    isNeg=true;
  else if(isNeg==true)
    isNeg=false;
}

ReallyLongInt ReallyLongInt::operator-() const
{
  ReallyLongInt a=*this;
  a.flipSign();
  return a;
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const
{
  unsigned int nsize=size+other.size;

  //Nested loops
  unsigned int i=0;
  unsigned int j=0;
  unsigned int res=0;
  unsigned int tmp=0;
  unsigned int pointer=0;

  //cout<<"size of other: "<<other.size<<endl;
  //cout<<"size of this: "<<size<<endl;
  
  
  vector<bool> *temp=new vector<bool>(nsize,0);

  
  while(i<other.size) //outer loop for bottom
    {
      //cout<<"value of i or other: "<<i<<endl;
      j=0;
      
      while(j<size) //inner loop for top
	{
	  //cout<<"value of j or this: "<<j<<endl;
	   
	  res=(*other.digits)[i] * (*digits)[j];
	  
	  if(res==0)
	    {
	      if((*temp)[tmp]==0)
		{
		  (*temp)[tmp]=0;
		  tmp++;
		}

	      else if((*temp)[tmp]==1)
		{
		  (*temp)[tmp]=1;
		  tmp++;
		}
	    }
	  
	  else if(res==1)
	    {
	      if((*temp)[tmp]==0)
		{
		  (*temp)[tmp]=1;
		  tmp++;
		}

	      else if((*temp)[tmp]==1)
		{
		  pointer=tmp;
		  
		  (*temp)[pointer]=0; //make 1 on that index to 0
		  
		  pointer++; //look to the left
		  
		  while((*temp)[pointer]!=0) //look until you find a zero
		    {
		      (*temp)[pointer]=0; //change every 1 you encounter to a 0
		      pointer++; //move left
		      
		    }
		  		  
		  (*temp)[pointer]=1; //when you find a 0 make it 1

		  tmp++;
		}
	    }
	  //cout<<"value in temp: "<<(*temp)[tmp]<<endl;
	  j++;
       	} //end of inner loop
      i++;
      tmp=i;
    } //end of outer loop
  
  ReallyLongInt a;
  *a.digits=*temp;
  a.size=nsize;
  a.isNeg=false;
  a.removeLeadingZeros();
  return a;  
  
}

ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other) const
{
  if(this->isNeg==false && other.isNeg==false) 
    return this->absMult(other);

  if(this->isNeg==true && other.isNeg==true) 
    return this->absMult(other);

  if(this->isNeg==false && other.isNeg==true) 
    return -this->absMult(other);

  if(this->isNeg==true && other.isNeg==false) 
     return -this->absMult(other);

  
}

void ReallyLongInt::absDiv(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
  ReallyLongInt r(0);
  ReallyLongInt d(0);
  ReallyLongInt q(0);

  for(int i=size-1;i>=0;i--)
    {
      //cout<< "this: "<<this->toStringBinary()<<endl;
      //cout << "other: " << other.toStringBinary() << endl;
      //cout << "i: "<<i << endl;
      //cout <<"Starting r is: "<<r.toStringBinary()<< endl;
      r=2*r;
      //cout <<"After 2*r, r is: "<<r.toStringBinary()<< endl;
      
      if((*digits)[i]==1)
	r=r+1;
      

     
      //cout <<"Before the while loop,r is: "<<r.toStringBinary()<< endl;
      //cout << "other: " << other.toStringBinary() << endl;
      
      d=0;
      
      //cout<<"while r>=other (works when 0) "<<other.absGreater(r)<<endl;

      while(other.absGreater(r)==false)
	{
	  r=r.absSub(other);
	  //cout <<"Inside the loop: "<<r.toString()<< endl;
	  d=d+1;
	  //cout <<"Value of d: "<<d.toString()<< endl;
	}
      
      d= d* pow(2,i);
      q=q+d;

      //cout<<"----------------------------"<<endl;
    }
  
  quotient=q;
  remainder=r;
 
}

void ReallyLongInt::div(const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const
{
  if((*this).toString()=="0")
    return;
  else if(other.toString()=="0")
    return;
  else if((*this).toString()=="0"&&other.toString()=="0")
    return;
    
  else if(isNeg==true&&other.isNeg==true)
    {
      ReallyLongInt a(*this);
      ReallyLongInt b(other);
      a.flipSign();
      b.flipSign();
      a.absDiv(b,quotient,remainder);
    }
  else if(isNeg==false&&other.isNeg==true) 
    {
      ReallyLongInt a(*this);
      ReallyLongInt b(other);
      b.flipSign();
      a.absDiv(b,quotient,remainder);
      quotient.flipSign();
    }
  else if(isNeg==true&&other.isNeg==false)
    {
      ReallyLongInt a(*this);
      ReallyLongInt b(other);
      a.flipSign();
      a.absDiv(b,quotient,remainder);
      quotient.flipSign();
    }
  else if(isNeg==false&&other.isNeg==false)
    (*this).absDiv(other,quotient,remainder);

      
  
  
}

bool ReallyLongInt::isPrime()
{
  ReallyLongInt rem;

  if((*this).toString()=="2")
    return true;
  else if((*this).toString()=="1")
    return false;
  else if((*digits)[0]==0) //even numbers
    return false;
  else
    {
      ReallyLongInt i=3;
      //for(ReallyLongInt i=3;(*this).absGreater(i);i+2)
      while((*this).absGreater(i))
	{
	  //cout<<"============"<<endl;
	  //cout<<"our number is: "<<(*this).toString()<<endl;
	  //cout<<"value of i: "<<i.toString()<<endl;
	  rem=(*this)%i;
	  //cout<<"value of rem: "<<rem.toString()<<endl;
	  
	  if(rem.equal(0))
	    return false;

	  i=i+2;
	}
      return true;
    }
}

ReallyLongInt ReallyLongInt::exp(ReallyLongInt e) const
{
  int lastindex=0;
  bool idx=(*e.digits)[lastindex];
   
  if(idx==1) //odd
    {
      if(e.equal(0))
	return 1;
      else
	return (*this)*(this->exp(e/2))*(this->exp(e/2));
    }
  else //even
    {
      if(e.equal(0))
	return 1;
      else
	return (this->exp(e/2))*(this->exp(e/2));
    }
}


ReallyLongInt operator+(const ReallyLongInt& x,const ReallyLongInt& y)
{
  return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x,const ReallyLongInt& y)
{
  return x.sub(y);
}

ReallyLongInt operator*(const ReallyLongInt& x,const ReallyLongInt& y)
{
  return x.mult(y);
}

ReallyLongInt operator/(const ReallyLongInt& x,const ReallyLongInt& y)
{
  ReallyLongInt q;
  ReallyLongInt r;
  x.div(y,q,r);
  return q;
}

ReallyLongInt operator%(const ReallyLongInt& x,const ReallyLongInt& y)
{
  ReallyLongInt q;
  ReallyLongInt r;
  x.div(y,q,r);
  return r;
}

/*
int main(){
  long long x;
  long long y;
  cout << "x: " ;
  cin >> x;
  cout <<"y:";
  cin >> y;
  ReallyLongInt a(x);
  ReallyLongInt b(y);
  //cout << a.absSub(b).toString();
  
  ReallyLongInt q;
  ReallyLongInt r;
  cout << a.toString() << " " << a.toStringBinary() << endl;

  cout<<"Entering absDiv"<<endl;
  cout<<"====================="<<endl;
  a.absDiv(b,q,r);
   //c.removeLeadingZeros();
  cout << "Quotient: "<<(q.toString()) << " " << (q).toStringBinary() << endl;
  cout << "Remainder: "<<(r.toString()) << " " << (r).toStringBinary() << endl;
  
}
**/




  







  
