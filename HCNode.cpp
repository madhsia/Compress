/* 
 * Madeline Hsia
 * Timothy Koh
 * File: HCNode.cpp
 * Implementing functions in HCNode.hpp
 */ 

 #include "HCNode.hpp"

/** Less-than comparison, so HCNodes will work in std::priority_queue
*  We want small counts to have high priority.
*  And we want to break ties deterministically.
*/
bool HCNode::operator<(const HCNode& other) {
	if (count != other.count) {
		return count > other.count;
	}
	//compare symbols if they are the same
	return symbol > other.symbol;
}