#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("data.txt", ios::in);
    string line;

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
        if(highest < checker){
            highest = checker;
        }
    }
    file.close();

    cout << highest << endl;
    return 0;
}
