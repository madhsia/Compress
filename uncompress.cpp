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
	
	//create io files
	ifstream inFile;
	ofstream outFile;

	vector<int> freqs(256,0);
	int sum;

	//read header, count frequency
	inFile.open(argv[1],ifstream::binary);
	if (inFile.good()) {
		for (int i=0; i < freqs.size(); i++) {
			getline(inFile, frequency);
			freqs[i] = atoi(frequency.c_str());
			sum += freqs[i];
		}
	}

	//build tree 
	HCTree huffmanTree;
	//cout << freqs[98];
	huffmanTree.build(freqs);

	//call decode on each encoded symbol
	outFile.open(argv[2], ofstream::binary); //changed to binary
	BitInputStream bitIn = BitInputStream(inFile);

	//decode each binary input 
	 for (int i=0; i<sum; i++) {
	 	outFile << (char)huffmanTree.decode(bitIn);
	 }
}