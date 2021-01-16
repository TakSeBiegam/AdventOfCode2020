#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void split_string(string &testcase, vector<int> &number_of_bus){
    string buffor = "";
    int bus_number;
    for (size_t i = 0; i < testcase.length()+1; i++){
        switch (testcase[i])
        {
        case ',':
            stringstream(buffor) >> bus_number;
            buffor = "";
            number_of_bus.push_back(bus_number);
            break;
        case 'x':
            buffor = "";
            i++;
            break;
        default:
            buffor += testcase[i];
            break;
        }
    }
    stringstream(buffor) >> bus_number;
    number_of_bus.push_back(bus_number);
}

void read_testcase(vector<int> &number_of_bus){
    string testcase = "";
    fstream file;
    file.open("testcase.txt", ios::in);
    for (size_t i = 0; i < 2; i++){
        getline(file,testcase);
    }
    split_string(testcase, number_of_bus);
    file.close();
}

bool solution(vector<int> &number_of_bus){
    long double counter = 1;
    double counter_divided_numbers;
    while(true){
        counter_divided_numbers = 0;
        for(size_t i = 0; i < number_of_bus.size(); i++){
            float math_mem = counter / number_of_bus[i];
            cout << math_mem << endl;
            if(math_mem == 0){
                counter_divided_numbers++;
            }
        }
        if(counter_divided_numbers >= 2){
            cout << counter << endl;
            return true;
        }
        counter++;
    }
    return false;
}

int main(){
    vector<int> number_of_bus;
    read_testcase(number_of_bus);
    bool isgood = false;
    isgood = solution(number_of_bus);
    if(isgood == false){
        cout << "Something goes wrong !" << endl;
    }
    
    return 0;
}