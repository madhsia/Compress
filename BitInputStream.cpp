/* 
 * Madeline Hsia
 * Timothy Koh
 * File: BitInputStream.cpp
 */

 #ifndef BITINPUTSTREAM_HPP
 #define BITINPUTSTREAM_HPP
 
 #include "BitInputStream.hpp"

 using namespace std;

 int BitInputStream::readBit() {
 	//If all bits in the buffer are read, fill buffer first
 	if(nbits == 8) {
 		fill();
 	}

 	//Get the bit at the appropriate location in the bit
 	//buffer, and return the appropriate int
 	(buf >> nbits) & 1; 

 	//Increment how many bits read
 	nbits++;

 }

 void BitInputStream::fill() {
	buf = in.get(); 
	nbits = 0;
}

 #endif // BITINPUTSTREAM_HPP