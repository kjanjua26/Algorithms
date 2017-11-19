#include<iostream>
#include<time.h>
typedef int enc_cfg2_t;
typedef void enc_cfg_t;
using namespace std;

void merge(int arr[], int first, int middle, int last);
void mergeSort(int arr[], int first, int last);
void printArray(int arr[], int size);

enc_cfg2_t main(){
	int arr[] = { 5, 3, 20, 7, 1, 64 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Given array is: ";
	printArray(arr, size);
	mergeSort(arr, 0, size - 1);
	cout << "Sorted array is: ";
	printArray(arr, size);
	return 0;
}

enc_cfg_t mergeSort(int arr[], int first, int last){
	if (first < last){
		int middle = first + (last - first) / 2;
		mergeSort(arr, first, middle);
		mergeSort(arr, middle + 1, last);
		merge(arr, first, middle, last);
	}
}
enc_cfg_t merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1];
	int *R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0, j = 0, k = l; 

	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}
enc_cfg_t printArray(int arr[], int size){
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
