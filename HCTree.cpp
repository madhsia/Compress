/* 
 * Madeline Hsia
 * Timothy Koh
 * File: HCTree.cpp
 * Implementing functions in HCTree.hpp
 */ 

 #include "HCTree.hpp"
 #include <queue>

 using namespace std;

 HCTree::~HCTree() {
 	delete root;
 }


/** Use the Huffman algorithm to build a Huffman coding trie.
 *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is 
 *  the frequency of occurrence of byte i in the message.
 *  POSTCONDITION:  root points to the root of the trie,
 *  and leaves[i] points to the leaf node containing byte i.
 */
void build(const vector<int>& freqs) {
	for (unsigned int i=0; i < freqs.size(); i++) {
		if (freqs[i] != 0) {
			char data = i;

			HCNode* temp = new HCNode(freqs[i], data);
			leaves[i] = temp;
		}
	}

	typedef priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> pq;
	pq leavesPQ;

	for (unsigned int i=0; i < leaves.size(); i++) {
		if (leaves[i]) {
			leavesPQ.push(leaves[i]);
			count++;
		}
	}

    while (!leavesPQ.empty()) {
     	if (leavesPQ.size() == 1) {
     		root = leavesQ.top();
     		leavesQ.pop();
     	}

     	HCNode* node1;
     	HCNode* node2;

     	first = leavesPQ.top();
     	leavesPQ.pop();
     	second = leavesPQ.top();
     	leavesPQ.pop();

     	int sum = first.count + second.count;
     	HCNode* sumCount = new HCNode(sum, 0);

     	sumCount->c0 = node1;
     	sumCount->c1 = node2;
     	node1->p = sumCount;
     	node2->p = sumCount;

     	leavesPQ.push(sumCount);
     }
}

/** Write to the given BitOutputStream
 *  the sequence of bits coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 
void encode(byte symbol, BitOutputStream& out) const {
	HCNode* current = leaves[symbol];
	stack<int> s;

	while (current->p != nullptr) {
		HCNode* p = current->p;

		if (p->c0 == current) {
			s.push(0);
		}
		else if (p->c1 == current) {
			s.push(1);
		}
		current = p;
	}
	while (!s.empty()) {
		out.writeBit(s.top());
		s.pop();
	}
}*/

/** Write to the given ofstream
 *  the sequence of bits (as ASCII) coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT 
 *  BE USED IN THE FINAL SUBMISSION.
 */
void encode(byte symbol, ofstream& out) const {
	
	if (n->isZeroChild) {
		out << '0';
	}
	else {
		out << '1';
	}

}


/** Return the symbol coded in the next sequence of bits (represented as 
 *  ASCII text) from the ifstream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT BE USED
 *  IN THE FINAL SUBMISSION.
 */
int decode(ifstream& in) const;

