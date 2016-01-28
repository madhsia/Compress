/* 
 * Madeline Hsia
 * Timothy Koh
 * File: BitInputStream.cpp
 */

 #include "BitInputStream.hpp"

 using namespace std;

 int readbit() {
 	//If all bits in the buffer are read, fill buffer first
 	if(nbits == 8) {
 		fill();
 	}

 	//Get the bit at the appropriate location in the bit
 	//buffer, and return the appropriate int
 	(buff >> nbits) & 1; 

 	//Increment how many bits read
 	nbits++;
 }