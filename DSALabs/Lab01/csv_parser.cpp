#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class CSVRow{
    vector<string> m_data;
public:
    size_t size() const{
        return m_data.size();
    }
    void readNextRow(istream& str){
        string line;
        getline(str, line);
        stringstream lineStream(line);
        string cell;
        m_data.clear();
        while(getline(lineStream, cell, ',')){
            m_data.push_back(cell);
        }
    }

    vector <string> retVec(){
        return m_data;
    }
};
int main(int argc, char* argv[]){
    float page = 0.0;
    if(argc != 2){
        cout << "Usage: " << argc[0];
    }
    else{
    ifstream file(argv[1]);
    if (file.good()){
        vector<vector <string> > vecline;
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
        for (int i = 0; i < vecline.size(); i++){
            for (int j = 0; j < vecline[i].size(); j++){
                //cout << vecline[i][j] << " ";
            }
        }
        ifstream data(argv[1]); //Re-read to get columns.
        vector <string> zero_name;
        vector <string> percent; //large_Schools
        vector <int> large_SchoolIndice;
        vector <int> xvec;

        for (int i = 0; i < vecline.size(); i++){
            while (getline(data, line)){
                stringstream  lineStream(line);
                string cell, name, Enrol, dropout;
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
                    for (int i = 0; i < vecline.size(); i++){
                        int temp;
                        stringstream lschool(vecline[i][6]);
                        lschool >> temp;
                        if (temp > 50){
                            large_SchoolIndice.push_back(i); //Pushing the indices of large school to vector.
                        }
                    }
                }
            }
        }
        cout << "\n\nTask B!!" << endl;
        cout << "\n\nThe schools for which the number of students passed in 10th Class Exam." << endl;
        for (int i = 0; i < zero_name.size(); i++){
            cout << zero_name[i] << endl;
        }
        cout << "\n\nTask C!!" << endl;
        cout << "\nThe large school percentage: ";
        for (int i = 0; i < xvec.size(); i++){
            page = ((xvec.size()) / (percent.size())-1) * 100;
        }
        float xvec_size = float(xvec.size());
        float t_size = float(percent.size() - 1);
        page = xvec_size / t_size * 100;
        cout << page << endl;
        
        float maximum = 0.0;
        float curr;
        int hindice; //Highest Indice
        for (int i = 0; i < large_SchoolIndice.size(); i++){
            stringstream dropout(vecline[large_SchoolIndice[i]][12]);
            dropout >> curr;
            if (curr > maximum){
                hindice = large_SchoolIndice[i];
                maximum = curr;
            }
        }
        cout << "\n\nTask D!!" << endl;
        cout << "\nThe dropout: ";
        cout << vecline[hindice][1];

    }
    else{
        cout << "File is not read.\n";
    }
}
    return 0;
}