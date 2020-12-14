#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <unordered_map> 
#include <sstream>
#include <vector>


using namespace std;

bool checker(unordered_map<string, string> ma){
    vector<string> v;
    //ints
    v.push_back("byr");
    v.push_back("iyr");
    v.push_back("eyr");
    //strings
    v.push_back("hcl");
    v.push_back("hgt");
    v.push_back("ecl");
    v.push_back("pid");
    int int_data[3];
    string string_data[4];
    for(int i=0;i<3;i++){
        istringstream(ma[v[i]]) >> int_data[i];
    }
    for(int i=0;i<4;i++){
        string_data[i] = ma[v[i+3]];
    }
    if(int_data[0] < 1920 || int_data[0] > 2002){
        return false;
    }
    if(int_data[1] < 2010 || int_data[1] > 2020){
        return false;
    }
    if(int_data[2] < 2020 || int_data[2] > 2030){
        return false;
    }
    string temp = string_data[0];
    if(string_data[0].size() != 7 || temp[0] != '#'){
        return false;
    }
    temp = string_data[1];
    int temp_size = temp.size();
    if(temp[temp_size-1] == 'n'){
        string second_temp = "";
        int h=0;
        while(temp[h] != 'i'){
            second_temp += temp[h];
            h++;
        }
        int tall_first;
        istringstream(second_temp) >> tall_first;
        if(tall_first < 59 || tall_first > 76){
            return false;
        }
    }
    else{
        int h=0;
        string second_temp = "";
        while(temp[h] != 'c'){
            second_temp += temp[h];
            h++;
        }
        int tall_second;
        istringstream(second_temp) >> tall_second;
        if(tall_second < 150 || tall_second > 193){
            return false;
        }
    }
    if(string_data[2] == "amb" || string_data[2] == "blu" || string_data[2] == "brn" || string_data[2] == "gry" || string_data[2] == "grn" || string_data[2] == "hzl" || string_data[2] == "oth"){
        cout << "";
    }
    else{
        return false;
    }
    if(string_data[3].size() != 9){
        return false;
    }
    return true;
}

int main()
{
    fstream file;
    string line;
    char changer[] = " ";
    char * chest;
    unordered_map<string, string> m;
    int large_counter = 0;
    int small_counter = 0;
    file.open("data.txt", ios::in);
    while(getline(file,line)){
        if(line.empty()){
            if(small_counter > 6){
                if(checker(m) == true){
                    large_counter++;
                }
                m.clear();
                small_counter = 0;
                continue;
            }
            small_counter = 0;
            m.clear();
            continue;
        }
        else{     
            int n = line.length();
            char str[n];
            strcpy(str, line.c_str());
            chest = strtok(str, changer);
            while( chest != NULL )
            {
                if(chest[0] == 'c'){
                    chest = strtok( NULL, changer);
                    continue;
                }
                string letters = "";
                string value = "";
                for(int i=0;i<3;i++){
                    letters += chest[i];
                }
                auto size = strlen(chest);
                for(int i=4;i<size;i++){
                    value += chest[i];
                }
                m.insert(make_pair(letters, value));
                small_counter++;
                chest = strtok( NULL, changer );
            }   
        }
    }
    if(small_counter > 6){
                if(checker(m) == true){
                    large_counter++;
                }
                m.clear();
                small_counter = 0;
                cout << endl;
            }
    cout << large_counter << endl;
    return 0;
}
