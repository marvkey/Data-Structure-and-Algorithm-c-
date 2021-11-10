#pragma once
#include <iostream>

class BubbleSort {
	
	static void M_BubbleSort(int a[],int Size) { // ascending order
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
public:
	static int Main() {
		int myarray[5];
		int Size = 5;
		std::cout << "enter 5 integer in any order : " << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cin >> myarray[i];
		}
		std::cout << "Before sorting" << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << myarray[i];
		}

		M_BubbleSort(myarray,5);
		std::cout << "After sorting" << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << myarray[i];
		}
	}
};