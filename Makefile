# A simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

all: compress uncompress

<<<<<<< HEAD
compress: HCNode.o HCTree.o
=======
compress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o
>>>>>>> 3cf7f44e150cf52eca699a795b3ac2ec4e9bcc26

uncompress: BitInputStream.o BitOutputStream.o HCNode.o HCTree.o

HCTree.o: BitInputStream.hpp BitOutputStream.hpp HCNode.hpp HCTree.hpp

HCNode.o: HCNode.hpp

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp

clean:
	rm -f compress uncompress *.o core*

