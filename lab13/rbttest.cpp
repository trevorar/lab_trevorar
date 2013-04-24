#include <iostream>
#include <fstream>
#include <sstream>
#include "rbtree.h"

using namespace std;

int main(int argc, char* argv[]) {	

	if(argc < 2 || argc > 2) {
		cout << "Invalid arguments." << endl;
		return 0;
	}
	
	RBTree<int> tree;	
	
	ifstream inputFile(argv[1]);
	
	if(!inputFile.is_open()) {
		cout << "Error: Could not open file." << endl;
		return 0;
	}

	int num;
	
	while(inputFile >> num) {
		tree.insert(num);
		tree.preOrderPrintTraversal();
		cout << "----" << endl;
	}
	
	tree.inOrderPrintTraversal();
	
	
	return 0;
}