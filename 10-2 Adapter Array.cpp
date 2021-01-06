#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void read_testcase(vector<int> &adapters){
    fstream file;
    int single_adapter;
    file.open("testcase.txt", ios::in);
    adapters.push_back(0);
    while(file >> single_adapter){
        adapters.push_back(single_adapter);
    }
    file.close();
}

int solution(vector<int> &adapters){
    int element_number = 0;
    int one_jolts = 0;
    int three_jolts = 1; // +1 --- source
    while(element_number+1 != adapters.size()){
        int difference = adapters[element_number+1] - adapters[element_number];
        switch (difference)
        {
        case 1:
            one_jolts++;
            break;
        case 3:
            three_jolts++;
            break;
        case 2:
            break;  
        default:
            cout << "Anti infinity Loop - activated" << endl;
            return 3; //anti infinity loop
        }
        element_number++;
    }
    cout << one_jolts << " " << three_jolts << endl;
    return 1;
}


int main(){
    vector<int> adapters;
    read_testcase(adapters);
    sort(adapters.begin(), adapters.end()); //sorting vector <min --- max>

    int solution_code = 0;
    solution_code = solution(adapters);
    adapters.clear(); //clear vector

    return solution_code;
}