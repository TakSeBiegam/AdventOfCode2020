#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
    fstream file;
    vector<int> numbs;
    string temp;
    file.open("testcase.txt", ios::in);

    while(getline(file,temp)){
        int temp_var;
        istringstream(temp) >> temp_var;
        numbs.push_back(temp_var);
    }
    file.close();
    
    for(int i=0;i<numbs.size();++i){
        if(numbs[i] >= 2020){
            continue;
        }
        for(int j=i;j<numbs.size();++j){
            if(numbs[i] + numbs[j] == 2020){
                cout << numbs[i]*numbs[j] << endl;
            }
        }
    }

    return 0;
}
