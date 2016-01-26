/* 
 * Madeline Hsia
 * Timothy Koh
 * File: HCTree.cpp
 * Implementing functions in HCTree.hpp
 */ 

 #include "HCTree.hpp"
 #include "HCNode.hpp"
 #include <queue>
 #include <string>

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
void HCTree::build(const vector<int>& freqs) {
	//creating the forest 
	for (unsigned int i=0; i < freqs.size(); i++) {
		if (freqs[i] != 0) {
			char data = i;

			HCNode* temp = new HCNode(freqs[i], data);
			leaves[i] = temp;
		}
	}

	//creating priority queue
	typedef priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> pq;
	pq leavesPQ;

	//putting leaves in priority queue
	for (unsigned int i=0; i < leaves.size(); i++) {
		if (leaves[i]) {
			leavesPQ.push(leaves[i]);
		}
	}

	//if there's only one leaf
	if (leavesPQ.size() == 1) {
		//add empty node
		leavesPQ.push(new HCNode(0,0));
	}

	//while there's more than 1 leaves
    while (leavesPQ.size() > 1) {
    	//create the first two nodes to be merged
     	HCNode* node1;
     	HCNode* node2;
     	//get the two smallest nodes, remove from PQ
     	node1 = leavesPQ.top();
     	leavesPQ.pop();
     	node2 = leavesPQ.top();
     	leavesPQ.pop();


     	//sum their count and create new parent that is the sum of count
     	//with children node1,node2
     	int sum = node1->count + node2->count;
     	HCNode* sumCount = new HCNode(sum, node1->symbol, node1, node2);

     	//set the parent of node1 and node2
     	node1->p = sumCount;
     	node2->p = sumCount;

     	//add parent to PQ
     	leavesPQ.push(sumCount);
<<<<<<< HEAD
     	root = leavesPQ.top();

/*
     	leavesPQ1 = leavesPQ;
		leavesPQ1.pop();

     	int sum = leavesPQ.top()->count + leavesPQ1.top()->count;
     	HCNode* sumCount = new HCNode(sum, leavesPQ.top()->symbol, leavesPQ.top(), leavesPQ1.top());

     	leavesPQ.top()->p = sumCount;
     	leavesPQ1.top()->p = sumCount;

     	leavesPQ.pop();
     	leavesPQ.pop();
     	leavesPQ.push(sumCount); */
     }
    //set root
    //root = leavesPQ.top();
    //leavesPQ.pop();
=======
     	//update root
     	root = leavesPQ.top();
     }
    //set root
	//root = leavesPQ.top();
>>>>>>> cdf6f768fe459dd79c33eaa1f3ec6e5b316a36f0

}

/** Write to the given ofstream
 *  the sequence of bits (as ASCII) coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT 
 *  BE USED IN THE FINAL SUBMISSION.
 */
void HCTree::encode(byte symbol, ofstream& out) const {
	HCNode* n = leaves[symbol];
	cout << n->symbol << "\n";
	string code;

	while (n != root) {
		if (n == n->p->c0) {
			code.append("0");
		}
		else {
			code.append("1");
		}
		n = n->p;
	}
	//reversing the string
	string reverse = "";
	for(int i = 0; i < code.length(); i++) {
		reverse = code[i] + reverse;
	}
	out << reverse;
	cout << reverse << "\n";
}


/** Return the symbol coded in the next sequence of bits (represented as 
 *  ASCII text) from the ifstream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 *  THIS METHOD IS USEFUL FOR THE CHECKPOINT BUT SHOULD NOT BE USED
 *  IN THE FINAL SUBMISSION.
 */
int HCTree::decode(ifstream& in) const {
	HCNode* n = root;
	int data = 0;

	//cout << data;

	//going down the tree to find the symbol
	while (n->c1 != 0 || n->c0 != 0) {
		//converting the ascii value to decimal
		data = in.get() - '0';
		if (in.eof()) break;
		cout << data << "\n";
		if (data == 0) {
			n = n->c0;
		}
		//else if (data == 1) {
		else {
			n = n->c1;
		}
	} 
	//return the current leaf's symbol
	return (int)n->symbol;
}

