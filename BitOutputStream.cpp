/* 
 * Madeline Hsia
 * Timothy Koh
 * File: BitOutputStream.cpp
 */

#include <iostream>
#include "BitOutputStream.hpp"
#include <bitset> 
using namespace std;


/** Write the least significant bit of the argument to
 * the bit buffer, and increment the bit buffer index.
 * But flush the buffer first, if it is full.
 */

void BitOutputStream::writeBit(int i) {
	
	//Is the bit fill? Then flush it.
	if(nbits == 8) {
		flush();
	}

	// Write the least significant bit of i onto the butter
	// at the current index
	buf = (buf | (i << nbits));

	//cout << "buf is: " << buf << "and the i is: "  << i << " and the nbit is: " << nbits << endl;
	// Increment the index
	nbits++;
}

void BitOutputStream::flush() {
	
	bitset<8> x(buf);
	cout << x << "\n";
	out.put(buf);
	out.flush();
	buf = nbits = 0;
}