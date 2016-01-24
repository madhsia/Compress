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


using namespace std;

int main(int argc, const char* argv[]) {

	int frequency;
	int symCount =0;
	int bytes =0;

	ifstream inFile;
	ofstream outFile;

	vector<int> freqs(256);

	//read header, count frequency
	inFile.open(argv[1],ifstream::in);
	if (inFile.good()) {
		for (int i=0; i < freqs.size(); i++) {
			//??????
			}
		}
	}

	//build tree 
	HCTree huffmanTree;
	huffmanTree.build(freqs);

	//call decode on each encoded symbol
	outFile.open(argv[2], ofstream::out);

	for (int i=0; i < bytes, i++) {
		//????????
	}

}