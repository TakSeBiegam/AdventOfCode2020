#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    fstream file;
    file.open("data.txt", ios::in);
    string line;

    int counter = 0;
    vector<char> v;
    while(getline(file,line)){
        if(line.empty()){
            //found empty line
            counter += v.size();
            //cout << v.size() << endl;
            v.clear();
            //cout << endl;
        }
        else{
            for(unsigned i=0;i<line.length();i++){
                auto pos = find(v.begin(), v.end(), line[i]);
                if(pos == v.end()){
                    char temp = line[i];
                    v.push_back(temp);
                }
            }
        }
        for(int i=0;i<v.size();i++){
            //cout << v[i] << endl;
        }
    }
    counter += v.size();
    cout << counter << endl;
    return 0;
}
