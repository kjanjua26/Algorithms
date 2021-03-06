#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

bool moveMin(vector<int>&in, vector<int>&out);
int ranGen(int numElements);
bool testMoveMin(int numElements);
void swap(int *xp, int *yp);
int main(){
	clock_t t;
	float avg = 0.0;
	vector<float>time;
	int numElements;
	for (int i = 10; i <= 10000; i *= 10){
		t = clock();
		assert(testMoveMin(i));
		cout << "Passed for " << i << endl;
		time.push_back(((float)(clock() - t)) / CLOCKS_PER_SEC);
	}
	sort(time.begin(), time.end());
	for (int i : time){
		avg += i;
	}
	cout << "\nBest Time: " << time[0] << endl;
	cout << "Average Time: " << avg / time.size() << endl;
	cout << "Worst Time: " << time[time.size() - 1] << endl;

	return 0;
}

bool testMoveMin(int numElements){
	srand(unsigned(time(0)));
	vector<int> out;
	vector<int> in;
	while (numElements){
		in.push_back(ranGen(numElements));
		numElements--;
	}

	sort(in.begin(), in.end());
	int max = in[numElements]; 
	in.push_back(rand() % max + 1);
	for (int i : in){
		out.push_back(i); //Pushing the unsorted vector to another vector.
	}
	sort(in.begin(), in.end());
	return moveMin(in, out);
}

int ranGen(int numElements){
	return rand() % 100 + 1;
}
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
bool moveMin(vector<int>&in, vector<int>&out){
	//Selection sort
	int i, j, min_idx;
	for (i = 0; i < out.size() - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < out.size(); j++)
		if (out[j] < out[min_idx])
			min_idx = j;
		swap(&out[min_idx], &out[i]);
	}
	return in == out;
}
