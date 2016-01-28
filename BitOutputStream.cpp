/* 
 * Madeline Hsia
 * Timothy Koh
 * File: BitOutputStream.cpp
 */

#include <iostream>
#include "BitOutputStream.hpp"

using namespace std;


/** Write the least significant bit of the argument to
 * the bit buffer, and increment the bit buffer index.
 * But flush the buffer first, if it is full.
 */

void BitOutputStream::writeBit(int i) {
	//Is the bit full? Then flush it.
	if(nbit == 8) {
		flush();
	}

	// Write the least significant bit of i onto the butter
	// at the current index

	// Increment the index
	nbits++;
}