CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g  #-D means to define a macro name
COVERAGE = --coverage 


all: catchdebug catchdebug2


ReallyLongInt.o: ReallyLongInt.cpp ReallyLongInt.hpp
	$(CC) -c ReallyLongInt.cpp

numberTheory.o: numberTheory.cpp numberTheory.hpp
	$(CC) -c numberTheory.cpp

main.o: main_ref.cpp
	$(CC) -c main_ref.cpp

main: main.o ReallyLongInt.o
	$(CC) $(CFLAGS) -o main main_ref.o ReallyLongInt.o

debug: ReallyLongInt.cpp
	$(CC) $(DEBUG) $(CFLAGS)  -o ReallyLongIntDebug ReallyLongInt.cpp

catchdebug: ReallyLongInt_TEST.cpp ReallyLongInt.o catch.hpp
	$(CC) $(CFLAGS) $(CATCHINC) -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.o

catchdebug2: numberTheory.o ReallyLongInt.o numberTheory_TEST.cpp
	$(CC) $(CFLAGS) $(DEBUG) -o numberTheory_TEST numberTheory.o ReallyLongInt.o numberTheory_TEST.cpp

keygen: ReallyLongInt.o numberTheory.o keygen.cpp
	$(CC) -o keygen ReallyLongInt.o numberTheory.o keygen.cpp

encrypt: ReallyLongInt.o encrypt.cpp
	$(CC) -o encrypt ReallyLongInt.o encrypt.cpp

decrypt: ReallyLongInt.o decrypt.cpp
	$(CC) -o decrypt ReallyLongInt.o decrypt.cpp

coverage: ReallyLongInt_TEST.cpp ReallyLongInt.cpp ReallyLongInt.hpp catch.hpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) ReallyLongInt_TEST.cpp ReallyLongInt.cpp

ntcoverage: numberTheory_TEST.cpp numberTheory.cpp numberTheory.hpp ReallyLongInt.hpp  catch.hpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) numberTheory_TEST.cpp numberTheory.cpp

clean:
	rm *.o; rm main; VectorDebug
