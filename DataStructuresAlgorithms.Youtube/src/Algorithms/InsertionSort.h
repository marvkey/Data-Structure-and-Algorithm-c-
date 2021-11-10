#pragma once

#include<iostream>

class InsertionSort {
public:
	static void _InsertionSort(int arr[]) {
		int j = 0;
		int Key = 0;

		for (int i = 1; i < 5; i++) {
			Key = arr[i]; // pickign element;
			j = i - 1;
			while (j >= 0 && arr[j] > Key) // we are using j as arr access and array cannot have -1 as value
			{
				arr[j + 1] == arr[j];
				j -= 1;
			}
			arr[j + 1] = Key;
		}
	};

	static void Main() {
		int myarray[5];
		std::cout << "enter 5 integers in any order" << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cin >> myarray[i];
		}
		std::cout << "before sorting :" << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << myarray[i] << " ";
		}
		_InsertionSort(myarray);
		std::cout << "after sorting :" << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << myarray[i] << " ";
		}
	}
};