/* 
 * Madeline Hsia
 * Timothy Koh
 * File: BitInputStream.hpp
 */


#include <iostream>


class BitInputStream  {

private:
	char buf; // one byte buffer of bits
	int nbits; // how many bits have been read from buf
	std::istream & in; // the input stream to use

public:
	/** Initialize a BitInputStream that will use
	* the given istream for input.
	*/
	BitInputStream(std::istream & is) : in(is) { 
		buf = 0; // clear buffer
		nbits = 8; // initialize bit index
	}

	/** Fill the buffer from the input */
	void fill();

	//read one bit
	int readBit();

	//read one int
	int readInt();

	//read one byte
	int readByte();
};