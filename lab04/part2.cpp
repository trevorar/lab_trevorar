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
	
	MyList<string> stringList;
	
	stringList.push_back("trevor");
	stringList.push_back("dog");
	stringList.push_back("cat");
	stringList.push_back("sun");
	stringList.push_back("moon");
	
	
	stringList.remove("trevor");
	intList.remove(10);
	
	try {
		cout << stringList.pop(1) << endl;
		cout << intList.pop(1) << endl;
	
		for(int i = 0; i < intList.getSize(); i++) {
			cout << intList.at(i) << endl;
		}
		for(int i = 0; i < stringList.getSize(); i++) {
			cout << stringList.at(i) << endl;
		}
	}
	catch(invalid_argument ia) {
		cout << ia.what() << endl;
	}
	
	return 0;
}

