#include <iostream>
#include <time.h>

using namespace std;
int rollDice(int numRoll);

int main(){
	srand(time(0));
	int numRoll = 10;
	
	cout << "The random numbers are: " << endl;
	while (numRoll){
		int diceRoll = rollDice(numRoll);
		cout << diceRoll << " ";
		numRoll--;
	}
	cout << endl;
}
int rollDice(int numRoll){
	return rand() % 6 + 1;
}
