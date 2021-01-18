#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void split_string(string &testcase, vector<int> &number_of_bus, vector<int> &timestamp_each_bus){
    string buffor = "";
    int bus_number = 0; //counting 'x' bus
    int bus_station_remember;
    for (size_t i = 0; i < testcase.length()+1; i++){
        switch (testcase[i])
        {
        case ',':
            stringstream(buffor) >> bus_station_remember;
            buffor.clear();
            timestamp_each_bus.push_back(bus_station_remember);
            number_of_bus.push_back(bus_number);
            bus_number++;
            break;
        case 'x':
            buffor.clear();
            i++;
            bus_number++;
            break;
        default:
            buffor += testcase[i];
            break;
        }
    }
    stringstream(buffor) >> bus_station_remember;
    timestamp_each_bus.push_back(bus_station_remember);
    number_of_bus.push_back(bus_number);
}

void read_testcase(vector<int> &number_of_bus, vector<int> &timestamp_each_bus){
    string testcase = "";
    fstream file;
    file.open("testcase.txt", ios::in);
    for (size_t i = 0; i < 2; i++){
        getline(file,testcase);
    }
    split_string(testcase, number_of_bus, timestamp_each_bus);
    file.close();
}

bool solution(vector<int> &number_of_bus, vector<int> &timestamp_each_bus){ 
    std::vector<int>::iterator it;
    long long int timestamp = 0;
    while(true){
        int counter_divided_numbers = 0;
        it = find(number_of_bus.begin(), number_of_bus.end(), timestamp);
        if(it != number_of_bus.end()){
            for (size_t i = 0; i < number_of_bus.size(); i++){
                int math_mem = timestamp % number_of_bus[i];
                if(math_mem == 0){
                    counter_divided_numbers++;
                }
            }
            int place = it - number_of_bus.begin();
            number_of_bus[place] += timestamp_each_bus[place];
        }
        if(counter_divided_numbers >= 2){
            cout << timestamp << endl;
            return true;
        }
        timestamp++;
    }
    return false;
}

int main(){
    vector<int> number_of_bus;
    vector<int> timestamp_each_bus;
    read_testcase(number_of_bus, timestamp_each_bus); 
    /*for (size_t i = 0; i < number_of_bus.size(); i++)
    {
        cout << "Bus Number: " << number_of_bus[i] << " - " << timestamp_each_bus[i] << endl;
    }*/
    
    bool isgood = false;
    isgood = solution(number_of_bus, timestamp_each_bus);
    if(isgood == false){
        cout << "Something goes wrong !" << endl;
    }
    return 0;
}