#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    fstream file;
    file.open("data.txt", ios::in);
    string line;
    vector<int> check;

    int highest = 0;
    while(getline(file,line)){
        int max = 127;
        int min = 0;
        for(int i=0;i<7;i++){
            if(line[i] == 'B'){ //up
                min = (((max-min)/2)+min)+1;
            }
            else{ //F - low
                max = (((max-min)/2)+min);
            }
        }
        int row = min;

        min = 0;
        max = 7;
        for(int i=0;i<3;i++){
            if(line[i+7] == 'R'){
                min = (((max-min)/2)+min)+1;
            }
            else{
                max = (((max-min)/2)+min);
            }
        }
        int checker = (row*8)+max;
        check.push_back(checker);
    }
    file.close();
    sort(check.begin(), check.end()); 
    for(unsigned i = 1;i < check.size();i++){
        cout << check[i] << endl;
        if(check[i] != check[i-1]+1){
            return i;
        }
    }
    return 0;
}
