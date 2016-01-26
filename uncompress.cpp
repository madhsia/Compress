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

	//read header, count frequency
	inFile.open(argv[1],ifstream::in);
	if (inFile.good()) {
		for (int i=0; i < freqs.size(); i++) {
			getline(inFile, frequency);
			freqs[i] = atoi(frequency.c_str());
		}
	}

	//cout << freqs[97];

	//build tree 
	HCTree huffmanTree;
	huffmanTree.build(freqs);

	//call decode on each encoded symbol
	outFile.open(argv[2], ofstream::out);

	while (1) {
		//int symbol = inFile.get();
	 	outFile << (char)huffmanTree.decode(inFile);
	 	if (inFile.eof()) break;
	 }

}