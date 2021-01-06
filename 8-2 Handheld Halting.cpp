#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>
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
    int which_line_to_change = -1;
    string single_line_from_vector = "";
    bool breaker_loop = true;
    bool head_breaker_loop = true;
    while(head_breaker_loop){
        int line_num = 0;
        int counter_from_acc = 0;
        which_line_to_change++;
        int counter_jn = 0;
        saver_line_num.clear();
        breaker_loop = true;
        while(breaker_loop){
            saver_line_num.push_back(line_num);
            single_line_from_vector = lff[line_num];
            //cout << single_line_from_vector << endl;
            //cout << "line num: " << line_num << endl;
            if(counter_jn == which_line_to_change){
                if(single_line_from_vector[0] == 'n'){
                    single_line_from_vector[0] = 'j';
                }
                if(single_line_from_vector[0] == 'j'){
                    single_line_from_vector[0] = 'n';
                }
            }
            switch (single_line_from_vector[0])
            {
            case 'n':
                line_num++;
                counter_jn++;
                //cout << "NOP" << endl;
                break;
            case 'a':
                counter_from_acc += do_split(single_line_from_vector);
                line_num++;
                break;
            case 'j':
                counter_jn++;
                line_num += do_split(single_line_from_vector);
                break;
            }
            std::vector<int>::iterator it;
            it = find(saver_line_num.begin(), saver_line_num.end(), line_num);
            if(it != saver_line_num.end()){
                breaker_loop = false;
            }
            if(line_num >= lff.size()){
                breaker_loop = false;
                head_breaker_loop = false;
            }
        }   
        cout << counter_from_acc << endl;
    }
    return 0;
}

int main(){
    int max = 0;
    int result_from_function = 0;
    vector<string> lines_from_file;
    read_line(lines_from_file);
    result_from_function = operations_on_vector(lines_from_file);
    return result_from_function;
}