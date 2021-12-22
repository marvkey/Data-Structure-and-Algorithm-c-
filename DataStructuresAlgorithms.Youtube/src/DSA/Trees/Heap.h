#pragma once
#include<iostream>
#include<math.h>
class MinHeap {
public:
	int* Harr; // pointer to elements
	int Capicity;
	int HeapSize;
	MinHeap(int cap) {
		HeapSize = cap;
		Harr = new int[cap];
	};

	void LinearSearch(int val) {
		for (int i = 0; i < HeapSize; i++) {
			if (Harr[i] == val) {
				std::cout << "Value found" << std::endl;
				return;
			}
		}
		std::cout << "value not found" << std::endl;
	}

	void PrintArray() {
		for (int i = 0; i < HeapSize; i++)
			std::cout << Harr[i] << " ";
		std::cout<< std::endl;
	}

	int Height() {
		return ceil(log2(HeapSize + 1) - 1);
		// ciel reuturns the smallest integer that is 
		// greater or equal to x
	}
};