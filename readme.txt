README FILE_PROJECT 1: Samit Basnet
CPS222: Computer Science III
===================================

Project 1: Our own data type - RSA
----------------------------------------------------------------------
This project aims at overcoming the size limit on in-built C++ data types by creating our very own data type called ReallyLongInt that can handle integers with unlimited number of digits. We use this data type to implement the RSA algorithm. First, we developed a program for encrypting and decrypting messages with provided keys followed by a program to generate keys. We can use this program to encrypt and decrypt our own text files.
----------------------------------------------------------------------


Files included in the project:
***********************************************************************
ReallyLongInt.cpp/.hpp
ReallyLongInt_TEST.cpp

-This is the backbone of the program that builds ReallyLongInt data type for encryption/decryption purpose. This also introduces basic binary arithmetic for our ReallyLongInt data type: addition, subtraction, multiplication, division, exponents, prime and gcd. 

Compile: make
Run: ./ReallyLongIntTEST
***********************************************************************
numberTheory.cpp/.hpp
numberTheory_TEST.cpp

-This program implements the extendedEuclid function for ReallyLongInt which calculates the Greatest Common Divisor(GCD) for two ReallyLongInt a and b along with x and y values such that ax+by=gcd(a,b). These values are essential for the encryption/decryption algorithm.

Compile: make
Run: ./numberTheory_TEST
***********************************************************************
keygen.cpp

-This program generates a matched pair of RSA keys to encrypt and decrypt messages. It requires 4 command line arguments: two prime numbers and two file names. The file names are used to store the keys for encryption(public) and decryption(private).

Compile: make keygen
Run: ./keygen 7(prime 1) 11(prime 2) ecode.txt dcode.txt 
***********************************************************************
encrypt.cpp

-This program takes 3 command line arguments: the name of the file containing the key,  name of input file, name of output file. The output file will give us the encrypted message after execution.

Compile: make encrypt
Run: ./encrypt <ecode.txt> <message.txt> <encryptedmsg.txt>
***********************************************************************
decrypt.cpp

-This program takes 3 command line arguments: the name of the file containing the key,  name of input file, name of output file. The output file will give us the original message after execution of decryption.

Compile: make decrypt
Run: ./decrypt <dcode.txt> <encryptedmsg.txt> <decryptedmsg.txt> 
***********************************************************************
Makefile: This facilitates compilation of all the abovementioned files including finding out their coverage using make coverage. 
***********************************************************************

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Issues
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
1. It takes a while to compile.
2. The algorithm used for some methods are certainly not the most efficient ones.
3. Although best efforts were made, some of the edge cases might have gone unnoticed in some functions.
4. decrypt.cpp doesn't give us the original text. While debugging, I realized that when using the formula x=(y^d)%d (from project description) in decrypt, it doesn't give me the same ASCII value generated in encrypt.cpp. For example, it used it with my name: samit 

ASCII values:  Conversion in encrypt  
s-115               37
a-97                36
m-109               23 
i-105               70
t-116               37

So when I convert the encrypted text into ASCII in decrypt.cpp I get the values on the second column which is good. But when I apply the formula in the algorithm it doesn't give me the corresponding ASCII values.

Update: % and exp were checked for edge cases but couldn't find any abnormal behavior.

I guess the problem could be with my keygen algorithm when x is negative.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Coverage for Unit Tests:

ReallyLongInt.cpp: 96.8% Line Coverage    96.9% Function Coverage 
keygen.cpp: 93%



