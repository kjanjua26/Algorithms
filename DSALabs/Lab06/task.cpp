// Solve expression. 
#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <numeric>
using namespace std;

int solveInFix(vector<string> stringVector, vector<int> numVec);
void clearEquation(vector<string> eqVec);
void numberStack(vector<char> eqVec);
void checkNumbers(string equation);
bool hasPrecedence(string op1, string op2);
bool IsOperator(char C);
int eval(int op1, int op2, char operate);
int main(){
	string equation;
	cout << "Enter equation: " << endl;
	cin >> equation;
	checkNumbers(equation);
	return 0;
}
int solveInFix(vector<string> stringVector, vector<int> numVec){
	stack<int> s;
	int i = 0;
	int val;
	char ch;
	string expression;
	expression = accumulate(begin(stringVector), end(stringVector), expression);
	char *cstr = &expression[0u];
	int size = sizeof(expression);
	while (i < size) {
      ch = *(cstr+i);
      if (isdigit(ch)) {
         s.push(ch-'0');
      }
      else {
         int op1 = s.top();
         s.pop();
         int op2 = s.top();
         s.pop();
         val = eval(op1, op2, ch);
         s.push(val);
      }
      i++;
   }
   	cout << "The result is: " << val;		
	return 0;	
}
void clearEquation(vector<string> eqVec){
	vector<string>stringVector;
	for (string& istr : eqVec){
		istr.erase(remove(istr.begin(), istr.end(), '('), istr.end());
		istr.erase(remove(istr.begin(), istr.end(), ')'), istr.end());
		stringstream vector(istr); //Removing brackets from the equation.
		string vec;
		if (vector >> vec){
			stringVector.push_back(vec);
		}
	}
}
void numberStack(vector<string> eqVec){
	vector<int>numVec;
	for (auto& i : eqVec){
		stringstream num(i);  //Check if input is number
		int no;
		if (num >> no){
			numVec.push_back(no); //Push numbers to number vector.
		}
	}
	solveInFix(eqVec, numVec);
}
void checkNumbers(string equation){
	string temp;
	vector<string> eqVec;
	stringstream ss(equation);
	while (getline(ss, temp, ',')){
		eqVec.push_back(temp);
	}
	numberStack(eqVec);
}
bool hasPrecedence(string op1, string op2){
	if (op2 == "(" || op2 == ")")
		return false;
	if ((op1 == "*" || op1 == "/") && (op2 == "+" || op2 == "-"))
		return false;
	else
		return true;
}
bool IsOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}
int eval(int op1, int op2, char operate) {
   switch (operate) {
      case '*': return op2 * op1;
      case '/': return op2 / op1;
      case '+': return op2 + op1;
      case '-': return op2 - op1;
      default : return 0;
   }
}
