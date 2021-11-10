#include <iostream>

class SelectionSort {
public:
	static void Selection_Sort(int arr[]) {
		for (int i = 0; i < 4; i++) {
			int min = i;
			for (int j = i + 1; j < 5; i++) {
				if (arr[j] < arr[min]) {
					min = j;
				}
			}
		
			if (min != i) {
				int temp = arr[min];
				arr[i] = temp;
			}
		}
	}
	static int maine() {
		int myarr[5];
		std::cout << "Enter 5 integers in random order: " << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cin >> myarr[i];
		}

		std::cout << "Unsorted Array: " << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << myarr[i] << " "; 
		}
		Selection_Sort(myarr);
		std::cout << "sorted Array: " << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << myarr[i] << " ";
		}
	}
};