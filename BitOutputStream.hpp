/* 
 * Madeline Hsia
 * Timothy Koh
 * File: BitOutputStream.hpp
 */ 

#ifndef BITOUTPUTSTREAM_HPP
#define BITOUTPUTSTREAM_HPP

//#include "HCTree.hpp"
//#include "HCNode.hpp"
#include <iostream> 

/** A ostream class for bits
 */
class BitOutputStream {
private:
	char buf;
	int nbits;
	std::ostream & out; // reference to the output stream to use

public:
	/** Initialize a BitOutputStream that will use
	* the given ostream for output.
	*/
	BitOutputStream(std::ostream & os) : out(os), buf(0), nbits(0) {
		//clear buffer and bit counter
	}	

	//Send the buffer to the output, and clear
	void flush();

	void writeBit(int i);
	void writeInt(int i);
	void writeByte(int b);
};

#endif // BITOUTPUTSTREAM_HPP