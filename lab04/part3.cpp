#include "mylist.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
	MyList<int> intList;
	
	for(int i = 0; i < 12; i++) {
		intList.push_back(i);
		i++;
	}
	
	intList[0] = 5;
	
	cout << intList[0] << endl;
	
	return 0;
}
