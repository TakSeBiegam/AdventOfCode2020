#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void split_string(string &single_line_from_input, vector<int> &number_of_bus){
    string buffor = "";
    int bus_number;
    //cout << single_line_from_input << endl;
    for (size_t i = 0; i < single_line_from_input.length()+1; i++){
        //cout << single_line_from_input[i] << " ";
        switch (single_line_from_input[i])
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
            buffor += single_line_from_input[i];
            break;
        }
    }
    stringstream(buffor) >> bus_number;
    number_of_bus.push_back(bus_number);
}

void read_testcase(int &my_place, vector<int> &number_of_bus){
    fstream file;
    string single_line_from_input = "";
    file.open("testcase.txt", ios::in);
    file >> my_place;
    for (size_t i = 0; i < 2; i++){
        getline(file,single_line_from_input);
    }
    
    file.close();
    split_string(single_line_from_input, number_of_bus);
}

int math_operations(int &my_position, vector<int> &number_of_bus){
    int highest_diff = 0;
    int fastest_bus;
    int math_memory;
    for (size_t i = 0; i < number_of_bus.size(); i++)
    {
        math_memory = my_position%number_of_bus[i]; 
        if(math_memory > highest_diff){
            highest_diff = math_memory;
            fastest_bus = number_of_bus[i];
        }
    }
    math_memory = ((my_position / fastest_bus) + 1) * fastest_bus;
    math_memory -= my_position;
    if(math_memory < 0){
        math_memory *= -1;
    }
    math_memory *= fastest_bus;

    return math_memory;
}


int main(){
    int my_position;
    vector<int> number_of_bus;
    read_testcase(my_position, number_of_bus);
    int solution;
    solution = math_operations(my_position, number_of_bus);
    
    cout << solution << endl;
    
    return 0;
}
