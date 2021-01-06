#include <iostream>
#include <fstream> //fstream.file
#include <string> //getline(file,line)
#include <cstring>
#include <map>
#include <sstream> //stringstream
#include <vector>


using namespace std;

bool data_checker(map<string, string> &s_map, map<string, int> &i_map){
    if(i_map["byr"] < 1920 || i_map["byr"] > 2002){
        return false;
    }
    if(i_map["iyr"] < 2010 || i_map["iyr"] > 2020){
        return false;
    }
    if(i_map["eyr"] < 2020 || i_map["eyr"] > 2030){
        return false;
    }
    if(s_map["pid"].size() != 9){
        return false;
    }
    if(s_map["hcl"].size() != 7 && s_map["hcl"][0] != '#'){
        return false;
    }
    cout << "s_map: " << s_map["hgt"] << endl;
    int hgt = s_map["hgt"].size();
    cout << "hgt: " << hgt << endl;
    string helper = "";
    int tall = 0;
    if(s_map["hgt"][hgt-1] == 'm'){
        for(int i=0;i<(hgt-2);i++){
            helper += s_map["hgt"][i];
        }
        istringstream(helper) >> tall;
        cout << "tall: " << tall << endl;
        if(tall < 150 || tall > 193){
            return false;
        }
    }
    else{
        for(int i=0;i<(hgt-2);i++){
            helper += s_map["hgt"][i];
        }
        istringstream(helper) >> tall;
        cout << "tall: " << tall << endl;
        if(tall < 59 || tall > 76){
            return false;
        }
    }
    if(s_map["ecl"] == "amb" || s_map["ecl"] == "blu" || s_map["ecl"] == "brn" || s_map["ecl"] == "gry" || s_map["ecl"] == "grn" || s_map["ecl"] == "hzl" || s_map["ecl"] == "oth"){
        return true;
    }

    return false;
}

bool data_distribution(vector<string> &vec){
    int change_string;
    map<string, string> string_map;
    map<string, int> ints_map;
    for(unsigned i=0 ; i < vec.size() ; i += 2){
        if(vec[i] == "byr" || vec[i] == "iyr" || vec[i] == "eyr"){
            stringstream geek(vec[i+1]);
            geek >> change_string;
            ints_map.insert(make_pair(vec[i], change_string));
        }
        else{
            string_map.insert(make_pair(vec[i], vec[(i+1)]));
        }
    }
    bool controller = data_checker(string_map, ints_map);
    

    ints_map.clear();
    string_map.clear();
    vec.clear();
    if(controller == true){
        return true;
    }
    else{
        return false;
    }
}

void separate_pasport(fstream &f){
    char changer[] = " :";
    char * chest;
    string line;
    int large_counter = 0;
    int small_counter = 0;
    vector<string> temp_vec;
    while(getline(f,line)){
        if(line.empty()){
            //cout << small_counter << endl;
            if(small_counter > 6){
                if(data_distribution(temp_vec) == true){
                    large_counter++;
                }
            }
            cout << endl << " NEW LINE " << endl;
            small_counter = 0;
            continue;
        }
        int n = line.length();
        char str[n];
        strcpy(str, line.c_str());
        chest = strtok(str, changer);
        while( chest != NULL ){
            temp_vec.push_back(chest);
            //cout << chest << endl;
            if(chest[0] == 'c'){
                chest = strtok( NULL, changer);
                continue;
            }
            small_counter++;
            chest = strtok( NULL, changer );
        }
    }
    if(small_counter > 6){
        if(data_distribution(temp_vec) == true){
            large_counter++;
        }
    }
    cout << large_counter << endl;
}

int main()
{
    fstream file;
    file.open("testcase.txt", ios::in);
    separate_pasport(file);
    file.close();
    ////////////////////////////////////////////////




    return 0;
}
