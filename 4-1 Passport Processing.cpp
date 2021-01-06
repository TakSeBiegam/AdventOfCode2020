#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    fstream file;
    string line;
    char changer[] = " ";
    char * chest;
    int large_counter = 0;
    int small_counter = 0;
    file.open("testcase.txt", ios::in);
    while(getline(file,line)){
        if(line.empty()){
            if(small_counter > 6){
                large_counter++;
            }
            small_counter = 0;
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
                small_counter++;
                chest = strtok( NULL, changer );
            }
        }
    }
    file.close();
    if(small_counter > 6){
        large_counter++;
    }

    cout << large_counter << endl;

    return 0;
}
