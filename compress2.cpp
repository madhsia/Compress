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
		byte theSymbol = inFile.get();
		if (freqs[int(theSymbol)] == 0) {
			unique++;
		}
		if (inFile.eof()) break;
		freqs[theSymbol]++;
	}

	inFile.clear();
	inFile.seekg(0,ios::end);
	int fileSize = inFile.tellg();

	inFile.close();

	//build huffman tree
	HCTree huffmanTree;
	huffmanTree.build(freqs);

	//create new file to write
	ofstream outFile;
	BitOutputStream bitOutFile = BitOutputStream(outFile);
	outFile.open(argv[2],ofstream::binary);

	//print # of unique symbols
	bitOutFile.writeInt(unique);
	//for each element, print its frequency
	for (int i=0; i<freqs.size(); i++) {
		if (freqs[i] !=0 ){
			bitOutFile.writeByte(i);
			bitOutFile.writeInt(freqs[i]);
		}
		//outFile << freqs[i] << "\n";
		//outFile.write((char*)&freqs[i], sizeof(int));
	}

	inFile.open(argv[1],ifstream::binary); //change to binary
	while(1) {
		int symbol = inFile.get();
		if (inFile.eof()) break;
		huffmanTree.encode(symbol, bitOutFile);
	}

	 bitOutFile.flush();

	 inFile.close();
	 outFile.close();

	 return 0;
}