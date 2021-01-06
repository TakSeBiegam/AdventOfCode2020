#include <iostream>
#include <fstream> //fstream.file
#include <string> //getline(file,line)
#include <cstring>
#include <sstream> 
#include <vector>
#include <map>

using namespace std;

int separate_bags_names(vector<string> &sw, map<string, map<string, string>> &br){
    string head_bag_name = "";
    string first_bag_from_recipt = "";
    string second_bag_from_recipt = "";
    head_bag_name = sw[0] + sw[1];
    if(br.size() == 7){
        br[head_bag_name]["CLOSE"] = "CLOSE";
        return 404;
    }
    first_bag_from_recipt = sw[5] + sw[6];
    if(sw.size() > 7){

        second_bag_from_recipt = sw[9] + sw[10];
        br[head_bag_name][first_bag_from_recipt] = second_bag_from_recipt;
        return 1;
    }
    br[head_bag_name][first_bag_from_recipt] = "EMPTY";
    return 0;
}

void include_bags(fstream &f, map<string, map<string, string>> &bag_recipt){
    f.open("testcase.txt", ios::in);
    vector<string> splited_words;

    map<string, map<string, string> >::iterator acces_full_map_size; 
    map<string, string>::iterator acces_inner_map; 

    char *splited_word;
    string arrangement;

    while(getline(f, arrangement)){
        int n = arrangement.length();
        char str[n];
        strcpy(str, arrangement.c_str());
        splited_word = strtok(str, " ");
        while(splited_word != NULL){
            splited_words.push_back(splited_word);
            splited_word = strtok(NULL, " ");
        }
        separate_bags_names(splited_words, bag_recipt);
        splited_words.clear();
    }
    f.close();
    for (acces_full_map_size = bag_recipt.begin(); acces_full_map_size != bag_recipt.end(); acces_full_map_size++) { 
  
        for (acces_inner_map = acces_full_map_size->second.begin(); acces_inner_map != acces_full_map_size->second.end(); acces_inner_map++) { 
            cout << "First key is " << acces_full_map_size->first 
                 << " And second key is " << acces_inner_map->first 
                 << " And value is " << acces_inner_map->second << endl; 
        } 
    } //downloaded from geeksforgeeks.org
}

void recursion(map<string, map<string, string>> br, int &solution){
    //HELP
}

int main(){
    fstream file;
    map<string, map<string, string>> bag_recipt;
    include_bags(file);
    int solution = 0;
    recursion(bag_recipt, solution);

    return 0;
}
