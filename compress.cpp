/* 
 * Madeline Hsia
 * Timothy Koh
 * File: compress.cpp
 * main for encoding
 */ 

#include "HCTree.hpp"
#include "HCNode.hpp"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main(int argc, char** argv) {

	/* scan textfile to compute frequencies
	 * build huffman tree
	 * find code for every symbol
	 * create new compressed file by saving entire code at top of file
	 * followed by code for each symbol
	 */
	ifstream inFile;
	inFile.open(argv[1],ifstream::binary);
	BitInputStream bitInFile1 = BitInputStream(inFile);
	BitInputStream bitInFile2 = BitInputStream(inFile);
	vector<int> freqs(256,0);

	//If the input file is non-existent
	if (!inFile) { 
		ofstream ofs(argv[2], std::ios::binary); 
		exit(0);	
	}

	//computing frequency
	while (1) {
		int theSymbol = bitInFile1.readBit();
		theSymbol += 48;
		if (inFile.eof()) break;
		freqs[theSymbol]++;
		//cout << "Reading :"<< theSymbol << endl;
	}
	//cout << freqs[48] << endl;

	inFile.close();

	//build huffman tree
	HCTree huffmanTree;
	huffmanTree.build(freqs);

	//create new file to write
	ofstream outFile;
	BitOutputStream bitOutFile = BitOutputStream(outFile);
	outFile.open(argv[2],ofstream::binary);

	outFile << freqs[48] << endl;
	outFile << freqs[49] << endl;

	inFile.open(argv[1],ifstream::binary); //change to binary
	for(int i = 0; i < (freqs[48] + freqs[49]); i ++) {
	//while(1) {
		int symbol = bitInFile2.readBit();
		symbol += 48;
		
		huffmanTree.encode(symbol, bitOutFile);
	}

	 bitOutFile.flush();

	 inFile.close();
	 outFile.close();

	 return 0;
}