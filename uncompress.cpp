/* 
 * Madeline Hsia
 * Timothy Koh
 * File: uncompress.cpp
 * main for decoding
 */ 

#include "HCTree.hpp"
#include "HCNode.hpp"
#include <iostream>
#include <queue>
#include <stdlib.h> //for atoi function

using namespace std;

int main(int argc, char** argv) {

	string tempString;
	
	//create io files
	ifstream inFile;
	ofstream outFile;

	vector<int> freqs(256,0);
	int sum = 0;
	int nextChar;

	//read header, count frequency
	inFile.open(argv[1],ifstream::binary);
	BitInputStream bitInFile = BitInputStream(inFile);
	int unique = bitInFile.readByte();

	if (inFile.good()) {
		for (int i=0; i < unique; i++) {
			int index = bitInFile.readByte();
			nextChar = bitInFile.readInt();
			freqs[index] = nextChar;

			sum += nextChar;
		}
	}

	//build tree /
	HCTree huffmanTree;
	huffmanTree.build(freqs);

	//call decode on each encoded symbol
	outFile.open(argv[2], ofstream::binary); //changed to binary

	//decode each binary input 
	for (int i=0; i<sum; i++) {
		outFile << (char)huffmanTree.decode(bitInFile);
	} 

	inFile.close();
	outFile.close();

	return 0;
}