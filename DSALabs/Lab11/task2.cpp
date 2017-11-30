#include<iostream>
#include<time.h>
#define range 10
using namespace std;
void countingSort(int[], int[], int[], int);
void printArray(int[], int);
int main(){
	srand(unsigned(time(NULL)));
	int size;
	cout << "Enter size: ";
	cin >> size;
	int *arr = new int[size];
	int count[range] = { 0 };
	int *temp = new int[size];
	for (int i = 0; i < size; i++){
		arr[i] = rand() % range;
	}
	cout << "The input array: " << endl;
	printArray(arr, size);
	cout << endl; 
	countingSort(arr, count, temp, size);
	cout << "The sorted array: " << endl;
	printArray(arr, size);
}
void countingSort(int arr[], int count[], int temp[], int n){
	for (int i = 0; i < n; i++)
		++count[arr[i]]; // freq
	cout << "Frequency: " << endl;
	printArray(count, range);
	cout << endl;
	for (int i = 1; i <= range; i++)
		count[i] += count[i - 1]; // cummulative freq.
	for (int i = n-1; i >= 0; i--){
		temp[--count[arr[i]]] = arr[i];
	}
	for (int i = 0; i < n; i++)
		arr[i] = temp[i];
}
void printArray(int arr[], int size){
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}
