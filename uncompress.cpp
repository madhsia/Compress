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

	string frequency;

	ifstream inFile;
	ofstream outFile;

	vector<int> freqs(256,0);
	int sum;

	//read header, count frequency
	inFile.open(argv[1],ifstream::binary);
	if (inFile.good()) {
		getline(inFile, frequency);
		freqs[48] = atoi(frequency.c_str());
		getline(inFile, frequency);
		freqs[49] = atoi(frequency.c_str());
		sum = freqs[48] + freqs[49];
	}

	//build tree 
	HCTree huffmanTree;
	//cout << freqs[98];
	huffmanTree.build(freqs);

	//call decode on each encoded symbol
	outFile.open(argv[2], ofstream::binary); //changed to binary
	BitOutputStream bitOut = BitOutputStream(outFile);
	BitInputStream bitIn = BitInputStream(inFile);

	 for (int i=0; i<(sum*8); i++) {
	 	//outFile << (char)huffmanTree.decode(bitIn);
	 	bitOut.writeBit((huffmanTree.decode(bitIn)-48));
	 }
}