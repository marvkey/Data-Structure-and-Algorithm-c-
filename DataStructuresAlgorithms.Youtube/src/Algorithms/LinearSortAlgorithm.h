#pragma once

#include <iostream>
/* does not have to be rapped in class*/

class LinearSearchAlgorithm {
public:
	static void LinearSearch(int a[],int n) {
		for (int i = 0; i < 5; i++) {
			if (a[i] == n) {
				std::cout << "element found at location :" << i << std::endl;
				return;
			}
		}
		std::cout << "no element found" << std::endl;
	}
	static int mainer() {
		int arr[5] = {1,22,34,5,7};
		std::cout << "please enter an element to search" << std::endl;
		int num;
		std::cin >> num;
		LinearSearch(arr,num);
		return 0;
	}
};