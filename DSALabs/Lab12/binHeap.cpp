#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include <math.h>
using namespace std;

class heap{
	vector<int>heapVec; 
	int *pArr; // pointer to array
	int capacity;
	int heapSize;
public:
	heap(int capacity); // constructor
	int parent(int i) { return (i - 1) / 2; };
	int left(int i) { return 2*i + 1; };
	int right(int i) { return 2 * i + 2; };
	int top() { return pArr[0]; }; //returns the element at the top
	int pop();
	void adjustHeap(int);
	void push(int k); // insert k
	bool isEmpty();
	int size();
	int height();
	void printHeap();
	void buildHeap(int arr[], int);
};
heap::heap(int cap){
	heapSize = 0;
	capacity = cap;
	pArr = new int[cap]; // build heap of capacity.
}
void heap::push(int k){
	if (heapSize == capacity){
		cout << "Heap Full." << endl;
		return;
	}
	heapSize++;
	int i = heapSize - 1;
	pArr[i] = k;
	while (i != 0 && pArr[parent(i)] > pArr[i]){ // keeps heap property intact
		swap(pArr[i], pArr[parent(i)]);
		i = parent(i);
	}
}
 int heap::pop(){
	if (heapSize <= 0) return INT_MAX;
	if (heapSize == 1){
		heapSize--;
		return pArr[0];
	}
	int root = pArr[0];
	pArr[0] = pArr[heapSize - 1];
	heapSize--;
	adjustHeap(0);
	return root;
}
 void heap::adjustHeap(int i){ //heapifies the array.
	 int lchild = left(i);
	 int rchild = right(i);
	 int smallest = i;
	 if (lchild < heapSize && pArr[lchild] < pArr[i])
		 smallest = lchild;
	 if (rchild < heapSize && pArr[rchild] < pArr[smallest])
		 smallest = rchild;
	 if (smallest != i){
		 swap(pArr[i], pArr[smallest]);
		 adjustHeap(smallest);
	 }
 }
 void heap::buildHeap(int arr[], int size){
	 for (int i = 0; i < size; i++)
		 push(arr[i]);
 }
 bool heap::isEmpty(){
	 return size() == 1;
 }
 int heap::size(){
	 return heapSize;
 }
 void heap::printHeap(){
	 for (int i = 0; i < heapSize; i++)
		 cout << pArr[i] << " ";
 }
 int heap::height(){
	 return floor((log2(size())));
 }
 int main(){
	 heap h(20);
	 h.push(6);
	 h.push(7);
	 h.push(12);
	 h.push(17);
	 h.push(15);
	 h.push(8);
	 h.push(10);
	 h.push(5);
	 cout << "Top: " << h.top() << endl;
	 cout << "The heap is: ";
	 h.printHeap();
	 cout << "\nThe size of heap is: " << h.size() << endl;
	 cout << "Is the heap empty? " << h.isEmpty() << endl; // 0 means false and 1 means true
	 cout << "The height of heap is: " << h.height() << endl;
	 int arr[6] = {2,9,22,54,13,1};
	 h.buildHeap(arr,6);
	 cout << "After heapifying the array, the heap is: ";
	 h.printHeap();
	 cout << "\nThe size of heap now is: " << h.size() << endl;
	 cout << "Popping element." << endl;
	 h.pop();
	 cout << "After popping, the heap is: ";
	 h.printHeap();
	 cout << endl;
 } 
