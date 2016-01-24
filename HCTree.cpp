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
void HCNode::build(const vector<int>& freqs) {
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

/** Write to the given ofstream
 *  the sequence of bits (as ASCII) coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT 
 *  BE USED IN THE FINAL SUBMISSION.
 */
void HCNode::encode(byte symbol, ofstream& out) const {
	HCNode* n = leaves[symbol];
	stack<int> s;

	while (n != root) {
		if (n == n->p->c0) {
			out << '0';
		}
		else {
			out << '1';
		}
		n = n->p;
	}
}


/** Return the symbol coded in the next sequence of bits (represented as 
 *  ASCII text) from the ifstream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT BE USED
 *  IN THE FINAL SUBMISSION.
 */
int HCNode::decode(ifstream& in) const {
	HCNode* n = root;
	int num;

	while (n->c1 != 0 || n->c0 != 0) {
		in >> num;
		if (num == 0) {
			n = n->c0;
		}
		else if (num == 1) {
			n = n->c1;
		}
	}
	return (int)n->symbol;
}

