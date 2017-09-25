/*
 * HackerRank Challenge: Grading Students
 */
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int testCase, in;
    vector<int> input;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        cin >> in;
        input.push_back(in);
    }
    for (int i : input) {
        if (i < 38) {
            cout << i << endl;
        }
        else if ((i % 5) == 0) {
                cout << i << endl;
            } else if (((i + 1) % 5) == 0) {
                cout << i + 1 << endl;
            } else if (((i + 2) % 5) == 0) {
                cout << i + 2 << endl;
            } else {
                cout << i << endl;
            }
        }
    return 0;
}
