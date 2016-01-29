/* 
 * Madeline Hsia
 * Timothy Koh
 * File: BitInputStream.cpp
 */

 #ifndef BITINPUTSTREAM_HPP
 #define BITINPUTSTREAM_HPP
 
 #include <iostream>
 #include "BitInputStream.hpp"

 using namespace std;

 /* read bit one at a time*/
 int BitInputStream::readBit() {
 	int bit;
 	//If all bits in the buffer are read, fill buffer first
 	if(nbits == 8) {
 		fill();
 	}

 	//Get the bit at the appropriate location in the bit
 	//buffer, and return the appropriate int
 	//bit = (buf << nbits) >> 7;
 	bit = (buf >> nbits) & 1;

 	//Increment how many bits read
 	nbits++;

 	return bit;
}
	
/*fill buffer with zeros*/
 void BitInputStream::fill() {
	buf = in.get(); 
	nbits = 0;
}

/*read a byte at a timee*/
int BitInputStream::readByte() {
	return in.get();
}

/*read ints 1 byte at a time and return an integer*/
int BitInputStream::readInt() {
	int byte1 = in.get();
	int byte2 = in.get();
	int byte3 = in.get();
	int byte4 = in.get();

	int out = byte1;
	out |= (byte2 << 8);
	out |= (byte3 << 16);
    out |= (byte4 << 24);

   return out; 
}


 #endif // BITINPUTSTREAM_HPP}
