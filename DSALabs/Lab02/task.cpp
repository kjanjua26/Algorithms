#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <assert.h>
using namespace std;
/**
@class CSVRow.
*/
class CSVRow{
	vector<string> m_data;
public:
	/// Parameters: None.
	/// Return Type: size
	/// Function: Returns the size of the vector m_data.
	size_t size() const{
		return m_data.size();
	}
	/// Parameters: File. 
	/// Return Type: Void.
	/// Function: Inputs the file and reads the rows and pushes them into vector m_data.
	void readNextRow(istream& str){
		string line;
		getline(str, line);
		stringstream lineStream(line);
		string cell;
		m_data.clear();
		while (getline(lineStream, cell, ',')){
			m_data.push_back(cell);
		}
	}
	/// Parameters: None.
	/// Return Type: Vector.
	/// Function: Returns the vector in which the rows are pushed. 
	vector <string> retVec(){
		return m_data;
	}
};
// Function declarations. 
void task1(vector<string>zero_percent);
void task2(vector<int> xvec, float page, vector <string> percent);
string task3(vector<vector <string>> vecline, vector<int>large_SchoolIndice);
void printVec(vector<vector <string>> vecline);

/// Main Method
int main(int argc, char* argv[]){ //No command line arguments used for lab 3 since the main task was to add doxygen comments. 
	float page = 0.0;
	ifstream file("Tehsil_schools.csv");
	assert(!file.good()); //Asserting that the file is good. 
	if (file.good()){
		vector<vector <string>> vecline;
		vector <string> sample;
		CSVRow row; //Calling the CSVRow function. 
		sample = row.retVec();
		string line;
		vector <string> csv_data;
		while (getline(file, line, ',')){
			row.readNextRow(file);
			vecline.push_back(row.retVec()); //fill the vector. 
		}
		//Print the data stored in the vector. 
		printVec(vecline);

		ifstream data("Tehsil_schools.csv"); //Re-read to get columns.
		vector <string> zero_name; //Vector for task 2.
		vector <string> percent;
		vector <int> large_SchoolIndice; //Vector for task 4. 
		vector <int> xvec; //Vector for task 3.
		for (int i = 0; i < vecline.size(); i++){
			while (getline(data, line)){
				stringstream  lineStream(line);
				string cell, name, Enrol;
				int count = 0;
				while (getline(lineStream, cell, ',')){
					count += 1;
					if (count == 2)
						name = cell;
					if (count == 8){
						if (!cell.compare("0")){
							zero_name.push_back(name);
						}
					}
					if (count == 7){
						percent.push_back(cell);
						int x;
						stringstream temp(cell); //Convert to int.
						temp >> x;
						if (x > 50){
							xvec.push_back(x);
						}
					}
				}
			}
		}
		// Task B
		cout << "\n\nTask B!!" << endl;
		cout << "\n\nThe schools for which the number of students passed in 10th Class Exam." << endl;
		task1(zero_name);

		// Task C
		cout << "\n\nTask C!!" << endl;
		cout << "\nThe large school percentage: ";
		task2(xvec, page, percent);

		// Task D
		cout << "\n\nTask D!!" << endl;
		cout << "\nThe dropout: ";
		string out = task3(vecline, large_SchoolIndice); //Getting the highest Dropout school. 
		cout << out << endl;
	}
	else{
		cout << "File is not read.\n";
	}
	return 0;
}

// Task B
/***
This function is for task B i.e. print the names of schools for which students passed in 10th.

@param[in]		Vector in which the names of schools are stored.
@param[out]		void.
@return			prints the vector.
*/
void task1(vector<string>zero_name){
	assert(zero_name.empty); //Asserting that vector if empty, the program closes. 
	for (int i = 0; i < zero_name.size(); i++){
		cout << zero_name[i] << endl;
	}
}

/***
This function is for task D i.e. it prints the school with highest dropout.

@param[in] 2D vector which contains the csv file, another vector in which the highest value vector is pushed into.
@param[out] The name of the school with highest Dropout.
@return a string i.e. name of school.

*/
string task3(vector<vector <string>> vecline, vector<int>large_SchoolIndice){
	float maximum = 0.0;
	float curr = 0.0;
	int hindice = 0; //Highest Indice
	for (int i = 0; i < large_SchoolIndice.size(); i++){
		stringstream dropout(vecline[large_SchoolIndice[i]][12]);
		dropout >> curr;
		if (curr > maximum){
			hindice = large_SchoolIndice[i];
			maximum = curr;
		}
	}
	return vecline[hindice][1];
	assert(vecline[hindice][1].empty); //Asserting that the string is not empty. 
}
/***
This function prints the vector which contains the csv file pushed into.

@param[in] 2D vector in which the data is pushed into.
@param[out] none.
@return prints the vector.
*/
void printVec(vector<vector <string>> vecline){
	assert(vecline.empty); //Asserting that the vector is not empty and that csv file is pushed into it. 
	for (int i = 0; i < vecline.size(); i++){
		for (int j = 0; j < vecline[i].size(); j++){
			cout << vecline[i][j] << " ";
		}
	}
}
/***
This function is for the task C i.e. it prints the percentage.

@param[in]		2 1D vectors, one for large schools and other for total schools.
@param[out]		void.
@return			prints the percentage of large schools.
*/
void task2(vector<int> xvec, float page, vector <string> percent){
	for (int i = 0; i < xvec.size(); i++){
		page = ((xvec.size()) / (percent.size()) - 1) * 100;
	}
	float xvec_size = float(xvec.size());
	float t_size = float(percent.size() - 1);
	page = xvec_size / t_size * 100;
	assert(page != 0); //Asserting that the value of page, percentage, is not 0.
	cout << page << endl;
}
