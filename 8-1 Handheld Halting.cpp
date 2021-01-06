#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int do_split(string &slff){
    vector<string> v;
    int n = slff.length();
    char str[n];
    char *chest;
    strcpy(str, slff.c_str());
    chest = strtok(str, " ");
    while(chest !=NULL){
        v.push_back(chest);
        chest = strtok(NULL, " ");
    }

    stringstream ss(v[1]); //change "+1" | "-5" into int
    int solution = 0;
    ss >> solution;

    v.clear();
    return solution;
}

void read_line(vector<string> &lff){
    fstream file("testcase.txt", ios::in);
    string single_line_from_file = "";
    while(getline(file, single_line_from_file)){
        lff.push_back(single_line_from_file);
    }
    file.close();
}

int operations_on_vector(vector<string> &lff){
    vector<int> saver_line_num;
    int line_num = 0;
    int counter_from_acc = 0;
    string single_line_from_vector = "";
    bool breaker_loop = true;
    while(breaker_loop){
        saver_line_num.push_back(line_num);
        single_line_from_vector = lff[line_num];
        switch (single_line_from_vector[0])
        {
        case 'n':
            line_num++;
            //cout << "NOP" << endl;
            break;
        case 'a':
            counter_from_acc += do_split(single_line_from_vector);
            line_num++;
            break;
        case 'j':
            line_num += do_split(single_line_from_vector);
            break;
        }
        std::vector<int>::iterator it;
        it = find(saver_line_num.begin(), saver_line_num.end(), line_num);
        if(it != saver_line_num.end()){
            breaker_loop = false;
        }
    }
    return counter_from_acc;
}

int main(){
    int solve = 0;
    vector<string> lines_from_file;
    read_line(lines_from_file);
    solve = operations_on_vector(lines_from_file);
    cout << solve << endl; 
    
    return 0;
}