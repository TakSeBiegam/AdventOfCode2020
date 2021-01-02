#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void read_testcast(vector<long long int> &p){
    fstream file;
    file.open("testcase.txt", ios::in);
    int is_good;
    long long int single_line;
    while(file >> single_line){
        p.push_back(single_line);
    }
    file.close();
}

int work_on_vector(vector<long long int> &p){
    bool is_good;
    for(size_t i = 0; i < p.size()-25;i++){ //check every case
        is_good = true;
        for(size_t j = i; j < i+25; j++){
            for(size_t k = j+1; k <= 25+i; k++){
                if(p[k] + p[j] == p[25+i]){ 
                    is_good = false;
                }
            }
        }
        if(is_good == true){
            cout << p[25+i];
            return 1;
        }
    }
    return 0;
}

int main(){
    vector<long long int> preamble;
    read_testcast(preamble);
    int solution = work_on_vector(preamble);

    return solution;
}