#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T> class MyList{
	public:
		MyList();
		~MyList();
		int getSize();
		void push_back(T item);
		T& at(int loc);
		bool remove(T val);
		T pop(int loc);
		T& operator[](int loc);
	
	private:
		T* data_;
		int size;
		int capacity;
};

template <typename T> MyList<T>::MyList() {
	size = 0;
	capacity = 2;
	data_ = new T[2];
};

template <typename T> MyList<T>::~MyList() {
	delete [] data_;
}

template <typename T> int MyList<T>::getSize() {
	return size;
}

template <typename T> void MyList<T>::push_back(T item) {
	if(size == capacity) {
		T* newData = new T[size*2];
		
		for(int i = 0; i < size; i++) {
			newData[i] = data_[i];
		}
		
		delete [] data_;
		
		data_ = newData;
		
		capacity *= 2;
		
		data_[size] = item;
		
		size++;
		
		return;
	}
	
	data_[size] = item;
	size++;
}

template <typename T> T& MyList<T>::at(int loc) {

	if(loc < 0 || loc >= size) {
		throw invalid_argument("Trying to perform at() at invalid location");
	}

	return data_[loc];
}

template <typename T> bool MyList<T>::remove(T val) {
	for(int i = 0; i < size; i++) {
		if(data_[i] == val) {
			for(int j = i; j < size; j++) {
				data_[j] = data_[j+1];
			}
			size--;
			return 1;
		}
	}
	return 0;
}

template <typename T> T MyList<T>::pop(int loc) {
	
	if(loc < 0 || loc >= size) {
		throw invalid_argument("Trying to perform pop() at invalid location");
	}
	
	T temp = data_[loc];
	for(int i = loc; i < size; i++) {
		data_[i] = data_[i+1];
	}
	size--;
	return temp;
}

template <typename T> T& MyList<T>::operator[](int loc) {
	if(loc < 0 || loc >= size) {
		throw invalid_argument("Trying to perform [] at invalid location");
	}

	return data_[loc];
}
#endif
