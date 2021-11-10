#pragma once
#include<iostream>
// to make dynamic we have to go to video and wathc it at the end there is some things we need ot ad
// everything static
class MergSort{
	static void MergeSort(int arr[],int l, int r){
		if(l<r){
			int m = (l+r)/2;
			MergeSort(arr,l,m);
			MergeSort(arr,m+1,r);
			Merge(arr,l,m,r);
		}
	}

	static void Merge(int arr[], int l,int m, int r){
		int i=l; // starting index left subarray
		int j=m+1; // starting index right subarray
		int k =l; // starting index for temporary array

		int temp[5];
		while(i<=m && j<=r){ // makes sure does not go over invalid index
			if(arr[i] <arr[j]){
				temp[k] = arr[i]; // arr[i] is smaller thatn arr[j]
				i++;
				k++;
			}
			else{
				temp[k] = arr[j]; // arr[j] is smaller thatn arr[i]
				j++;
				k++;
			}
		}

		while(i<=m){ 
			temp[k] =arr[i]; // copying all element from left subarray to temp as it is
			i++;
			k++;
		}

		while (j <= r) {
			temp[k] = arr[i];// copying all element from right subarray to temp as it is
			i++;
			k++;
		}

		for (int s = l; s <=r; i++) {
			arr[s] = temp[s]; // copying temp into arr
		}
	}
public:
	static int Main(){
		int arr[5];
		std::cout << "Enter 5 element for the array: " << std::endl;
		for(int i=0; i<5; i++){
			std::cin>>arr[i];
		}
		std::cout << "\n";

		std::cout<<"Before Merge sort: "<<std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << arr[i];
		}
		std::cout<<"\n";
		MergeSort(arr,0,4);
		std::cout << "After Merge sort: " << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << arr[i];
		}
	}
};