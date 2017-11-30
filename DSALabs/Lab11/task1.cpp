#include<iostream>
#include<time.h>
#define range 10
using namespace std;
void countingSort(int[], int);
void printArray(int[], int);
int main(){
	srand(unsigned(time(NULL)));
	int size;
	cout << "Enter size: ";
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++){
		arr[i] = rand() % range;
	}
	printArray(arr, size);
	cout << endl; 
	countingSort(arr, size);
}
void countingSort(int arr[], int n){
	int count[range] = { 0 };
	int i;
	for (i = 0; i < n; i++)
		count[arr[i]]++;
	printArray(count, range);
	cout << endl;
}
void printArray(int arr[], int size){
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}
