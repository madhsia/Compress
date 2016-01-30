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
	inFile.open(argv[1],ifstream::in);
	vector<int> freqs(256,0);
	int unique;

	//computing frequency
	while (1) {
		//get the new symbol from file
		byte theSymbol = inFile.get();
		if (inFile.eof()) break;
		//count the number of unique symbols there are
		if (freqs[int(theSymbol)] == 0) {
			unique++;
		}
		//increment freqs when there is such symbol
		freqs[theSymbol]++;
	}

	inFile.close();

	//build huffman tree
	HCTree huffmanTree;
	huffmanTree.build(freqs);

	//create new file to write
	ofstream outFile;
	BitOutputStream bitOutFile = BitOutputStream(outFile);
	outFile.open(argv[2],ofstream::binary);

	//print # of unique symbols
	bitOutFile.writeByte(unique);
	
	//for each element, print its frequency
	for (int i=0; i<freqs.size(); i++) {
		if (freqs[i] !=0 ){
			bitOutFile.writeByte(i);
			bitOutFile.writeInt(freqs[i]);
		}
	}

	inFile.open(argv[1],ifstream::binary); //change to binary
	
	//encode each symbol from file
	while(1) {
		int symbol = inFile.get();
		if (inFile.eof()) break;
		//and put it in bitOutfile
		huffmanTree.encode(symbol, bitOutFile);
	}

	//flush the remaining bits from bitOutFile
	 bitOutFile.flush();

	 //close files
	 inFile.close();
	 outFile.close();

	 return 0;
}