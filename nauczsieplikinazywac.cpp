#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

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

void solution(vector<int> &number_of_bus, vector<int> &timestamp_each_bus){ 
    vector<int>::iterator it;
    int timestamp = 0;
    int is_inn_vector = 0;
    int counter_of_divined_numbers = 0;
    int place_of_equal_number_to_timestamp = 0;
    while(counter_of_divined_numbers < 2){
        cout << "START" << endl;
        counter_of_divined_numbers = 0;
        place_of_equal_number_to_timestamp = 0;
        is_inn_vector = 0;
        int pos_in_vector;
        it = find(number_of_bus.begin(), number_of_bus.end(), timestamp);
        if(it != number_of_bus.end()){
            cout << "FINDED" << *it << endl;
            is_inn_vector = 1;
            pos_in_vector = it - number_of_bus.begin();
        }
        for (size_t place = 0; place < number_of_bus.size(); place++){
            cout << "Bus Number: " << number_of_bus[place] << " - " << timestamp_each_bus[place] << endl;
        }
        if(is_inn_vector == 1){
            cout << "HELLO";
            for(size_t i = 0; i < number_of_bus.size(); i++){
                cout << endl << "MODULO: " << timestamp << " % " << number_of_bus[i] << " = " << timestamp % number_of_bus[i] << endl;
                if(timestamp % number_of_bus[i] == 0){
                    counter_of_divined_numbers++;
                }
            }
            cout << " FOR LOOP DONE" << endl;
            number_of_bus[pos_in_vector] += timestamp_each_bus[pos_in_vector];
        }
        cout << "Add timestamp " << endl;
        timestamp++;
    }
    cout << timestamp << endl;
}

int main(){
    vector<int> number_of_bus;
    vector<int> timestamp_each_bus;
    read_testcase(number_of_bus, timestamp_each_bus); 
    
    
    solution(number_of_bus, timestamp_each_bus);
    return 0;
}
