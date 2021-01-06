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

void find_extreme_numbers(vector<long long int> &p, int &i_pos, int &j_pos){
    long long int max = p[i_pos], min = p[i_pos];
    for(size_t i = i_pos; i < j_pos; i++){
        if(max < p[i]){
            max = p[i];
        }
        if(min > p[i]){
            min = p[i];
        }
    }
    cout << "min/max = " << min+max << endl;
}

int work_on_vector(vector<long long int> &p){
    int save_i;
    int save_j;
    long long int local_accumulator = 0;
    const long long int must_equal = 105950735;
    for(size_t i = 0; i < p.size();i++){ //check every case
    local_accumulator = 0;
       for(size_t j = i; j < p.size();j++){
           if(p[j] == must_equal){
               break;
           }
           local_accumulator += p[j];
           if(local_accumulator == must_equal){
               save_i = i;
               save_j = j;
               break;
           }
       }
    }
    find_extreme_numbers(p, save_i, save_j);
    return 0;
}

int main(){
    vector<long long int> preamble;
    read_testcast(preamble);
    work_on_vector(preamble);

    return 0;
}