#pragma once
#include<iostream>
// we are setting the last element as the pivot
class QuickSort{
public:
	// s is strting index and e is last index
	static void QuickSortAlgorithm(int* arr, int s, int e){
		if(s<e){
			int p = Partition(arr,s,e);
			QuickSortAlgorithm(arr,s,(p-1));// recursive quicksort call left partion
			QuickSortAlgorithm(arr,(p+1),e);// recursive quicksort call right partion
		}
	}

	static int Partition(int arr[],int s, int e){
		int pivot = arr[e];
		int pIndex = s;
		
		for(int i=s; i<e;i++){
			if(arr[i]<pivot){
				
				int temp = arr[i];
				arr[i] =arr[pIndex];
				arr[pIndex] =temp;
				pIndex++;
			}
		}
		int temp  =arr[e];
		arr[e] =arr[pIndex];
		arr[pIndex] =temp;
		return pIndex;
	}
	static int Main(){
		const int Size=5;
		/*
		std::cout<<"Enter array size: "<<std::endl;
		std::cin >>Size;
		*/
		int myarray[Size];
		std::cout << "Enter number for array: " << std::endl;
		for (int i = 0; i < Size; i++) {
			std::cin>>myarray[i];
		}
		std::cout << "Before swapping: " << std::endl;
		for(int i=0; i<Size;i++){
			std::cout<<myarray[i];
		}
		std::cout<<"\n";

		QuickSortAlgorithm(myarray,0,(Size-1));
		std::cout << "After: " << std::endl;
		for (int i = 0; i < Size; i++) {
			std::cout << myarray[i];
		}
		std::cout << "\n";
	}
}