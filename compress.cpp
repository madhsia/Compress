/* 
 * Madeline Hsia
 * Timothy Koh
 * File: HCTree.cpp
 * Implementing functions in HCTree.hpp
 */ 

#include "HCTree.hpp"
using namespace std;

int main(int argc, char** argv) {

	/* scan textfile to compute frequencies
	 * build huffman tree
	 * find code for every symbol
	 * create new compressed file by saving entire code at top of file
	 * followed by code for each symbol
	 */ 

	 ifstream inFile;
	 inFile.open(argv[1]);

	 vector<int> freqs(256,0);

	 //computing frequency
	 while (1) {
	 	int theSymbol= inFile.get();
	 	if (inFile.eof()) break;
	 	freqs[theSymbol]++;
	 }

	 in.close();

	 HCTree huffmanTree;
	 huffmanTree.build(freqs);

	 ofstream outFile;
	 outFile.open(argv[2]);

	 for (int i=0; i<freqs.size(); i++) {
	 	outFile << freqs[i];
	 }

	 in.open(argv[1]);

	 




}