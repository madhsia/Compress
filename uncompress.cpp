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

	//read header, count frequency
	inFile.open(argv[1],ifstream::binary);
	getline(inFile, tempString);
	int unique = atoi(tempString.c_str());
	
	if (inFile.good()) {
		for (int i=0; i < unique; i++) {
			getline(inFile, tempString);
			int index = atoi(tempString.c_str());
			getline(inFile, tempString);
			int freq = atoi(tempString.c_str());

			freqs[index] = freq;
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

	int i = (unique*2)+1;
	//decode each binary input 
	 for (i; i<sum; i++) {
	 	inFile.get();
	 	outFile << (char)huffmanTree.decode(bitIn);
	 }

	 return 0;
}