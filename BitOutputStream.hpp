/* 
 * Madeline Hsia
 * Timothy Koh
 * File: BitInputStream.hpp
 */ 
 
//#include "HCTree.hpp"
//#include "HCNode.hpp"
#include <iostream> 


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

	}	

	//Send the buffer to the output, and clear
	void BitInputStream::flush() { 
		// one byte buffer of bits
		// how many bits have been written to buf
		// clear buffer and bit counter
		out.put(buf); 
		out.flush();
		buf = nbits = 0;
	}
}