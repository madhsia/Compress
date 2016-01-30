/* 
 * Madeline Hsia
 * Timothy Koh
 * File: BitOutputStream.cpp
 * Implement functions in BitOutputStream.hpp to write bits to file
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

//flush the buffer to the output stream
void BitOutputStream::flush() {
	
	//to print out 8 bits for testing
	//bitset<8> x(buf);
	//cout << x << "\n";
	out.put(buf);
	out.flush();
	buf = nbits = 0;
}

//read a byte at a time
void BitOutputStream::writeByte(int b) {
	out.put(b);
}

//write an int to output a char at a time
void BitOutputStream::writeInt(int i) {
	//shift the separate 4 bytes in the int i paseed in
	char a = (i & 255);
	char b = ((i >> 8) & (255));
    char c = ((i >> 16) & (255));
    char d = ((i >> 24) & (255));
 
 	//put char in file
    out.put(a);
    out.put(b);
    out.put(c);
    out.put(d);
}



