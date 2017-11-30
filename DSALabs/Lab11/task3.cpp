#include<string>
#include <iostream>
using namespace std;
void countingSort(int count[], string output[], int key[], string input[], int n);
int main() {
    int count[100], n, tmp;
    cin>>n;
    int *key = new int[n];
    memset(count, 0, sizeof(count));
    string s, *input = new string[n], *output = new string[n];
    for(int i = 0; i < n; i++) {
        cin>>tmp;
        count[tmp]++; // Count the number of times each key appears
        cin>>s;
        if(i < n/2) {
            input[i] = '-';
        } else {
            input[i]= s;
        }
        key[i] = tmp;
    }
    countingSort(count, output, key, input, n);
    return 0;
}
void countingSort(int count[], string output[], int key[], string input[], int n){
    int total = 0;

    for(int i = 0; i < 100; i++) {
        total += count[i];
        count[i] = total;
    }
    for(int i = n-1; i >= 0; i--) {
        output[count[key[i]]-1] = input[i];
        count[key[i]]--;
    }

    for(int i = 0; i < n; i++) {
        cout << output[i] << " ";
    }
}
