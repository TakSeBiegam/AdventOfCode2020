#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void check(vector<char> &v, map<int, string> &m, int &c){
    int large_counter = 0;
    int small_counter = 0;
    for(unsigned i=0;i<v.size();i++){
         for(unsigned j=0;j<m.size();j++){
            auto pos = find(m[j].begin(), m[j].end(), v[i]);
            if(pos != m[j].end()){
                small_counter++;
            }
        }
        if(small_counter == m.size()){
            large_counter++;
        }
            small_counter = 0;
    }
    c += large_counter;
    v.clear();
    m.clear();
}

int main()
{
    fstream file;
    file.open("data.txt", ios::in);
    string line;

    int counter = 0;
    int n = 0;
    vector<char> v;
    map<int, string> m;

    while(getline(file,line)){
        if(line.empty()){
            check(v, m, counter);
            n=0;
            continue;
        }
        else{
            m.insert(make_pair(n, line));
            for(unsigned i=0;i<line.length();i++){ 
                auto pos = find(v.begin(), v.end(), line[i]);
                if(pos == v.end()){
                    char temp = line[i];
                    v.push_back(temp);
                }
            }   
        }
        n++;
    }
    check(v, m, counter);
    cout << counter << endl;
    return 0;
}
