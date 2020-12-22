#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    fstream file;
    file.open("data.txt", ios::in);
    string arrangement;
    vector<int> seat_ids;

    int highest = 0;
    while(getline(file,arrangement)){
        int max = 127;
        int min = 0;
        for(int i=0;i<7;i++){
            if(arrangement[i] == 'B'){ //up
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
            if(arrangement[i+7] == 'R'){
                min = (((max-min)/2)+min)+1;
            }
            else{
                max = (((max-min)/2)+min);
            }
        }
        int one_seat_id = (row*8)+max; //seat_id
        seat_ids.push_back(one_seat_id);
    }
    file.close();
    sort(seat_ids.begin(), seat_ids.end()); 
    for(unsigned i = 1;i < seat_ids.size();i++){
        cout << seat_ids[i] << endl;
        if(seat_ids[i] != seat_ids[i-1]+1){
            return i;
        }
    }
    return 0;
}
