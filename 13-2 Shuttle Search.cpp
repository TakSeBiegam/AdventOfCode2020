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

void solution(vector<int> &number_of_bus, vector<int> &timestamp_each_bus){ 
    int timestamp = 0;
    int is_inn_vector = 0;
    int counter_of_divined_numbers = 0;
    int place_of_equal_number_to_timestamp = 0;
    while(counter_of_divined_numbers < 2){
        cout << "START" << endl;
        counter_of_divined_numbers = 0;
        place_of_equal_number_to_timestamp = 0;
        is_inn_vector = 0;

        for(size_t i = 0; i < number_of_bus.size(); i++){
            if(timestamp == number_of_bus[i]){
                place_of_equal_number_to_timestamp = i;
                is_inn_vector = 1;
                break;
            }
        }

        if(is_inn_vector == 1){
            cout << "HELLO";
            for (size_t i = 0; i < number_of_bus.size(); i++){
                cout << endl << "MODULO: " << timestamp << " % " << number_of_bus[i] << " = " << timestamp%number_of_bus[i] << endl;
                if(timestamp % number_of_bus[i] == 0){
                    counter_of_divined_numbers++;
                }
            }
            number_of_bus[place_of_equal_number_to_timestamp] += timestamp_each_bus[place_of_equal_number_to_timestamp];
        }
        timestamp++;
    }
    cout << timestamp << endl;
}

int main(){
    vector<int> number_of_bus;
    vector<int> timestamp_each_bus;
    read_testcase(number_of_bus, timestamp_each_bus); 
    /*for (size_t i = 0; i < number_of_bus.size(); i++){
        cout << "Bus Number: " << number_of_bus[i] << " - " << timestamp_each_bus[i] << endl;
    }*/
    
    solution(number_of_bus, timestamp_each_bus);
    return 0;
}
