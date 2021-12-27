#pragma once
#include<iostream>
#include<math.h>
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
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

	int Parent(int index) {
		return (index - 1) / 2;
	}
	int Left(int index) {
		return (2 * index + 1);
	}

	int Right(int index) {
		return (2 * index + 2);
	}
	void InsertKey(int k) {
		if (HeapSize == Capicity) {
			std::cout << "\nOverflow: Could not insert Key\n";
			return;
		}

		// First insert the new key at the end
		HeapSize++;
		int i = HeapSize - 1;
		Harr[i] = k;

		// Fix the min heap property if it is violated
		while (i != 0 && Harr[Parent(i)] > Harr[i]) {
			swap(Harr[i], Harr[Parent(i)]);
			i = Parent(i);
		}
	}

	// Method to remove minimum element (or root) from min heap
	int ExtractMin() {
		if (HeapSize<= 0)
			return INT_MAX;
		if (HeapSize == 1) {
			HeapSize--;
			return Harr[0];
		}

		// Store the minimum value, and remove it from heap
		int root = Harr[0];
		Harr[0] = Harr[HeapSize- 1];
		HeapSize--;
		MinHeapify(0);

		return root;
	}
	// A recursive method to heapify a subtree with the root at given index
 // This method assumes that the subtrees are already heapified
	void MinHeapify(int i) {
		int l = Left(i);
		int r = Right(i);
		int smallest = i;
		if (l < HeapSize && Harr[l] < Harr[i])
			smallest = l;
		if (r < HeapSize && Harr[r] < Harr[smallest])
			smallest = r;
		if (smallest != i) {
			swap(Harr[i], Harr[smallest]);
			MinHeapify(smallest);
		}
	}

	void decreaseKey(int i, int new_val) {
		harr[i] = new_val;
		while (i != 0 && harr[parent(i)] > harr[i]) {
			swap( & harr[i], & harr[parent(i)]);
			i = parent(i);
		}
  	}
  	// This function deletes key at index i. It first reduced value to minus
  	// infinite, then calls extractMin()
  	void deleteKey(int i) {
    	decreaseKey(i, INT_MIN);
    	extractMin();
  	}
};