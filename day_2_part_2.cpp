    #include <iostream>
    #include <string>
    #include <sstream>
    #include <fstream>
    #include <vector>
    #include <algorithm> 

    using namespace std;

    int main()
    {
        fstream file;
        string temp;
        file.open("data.txt", ios::in);
        int counter =0;
        int letter_counter;
        while(getline(file, temp)){
            letter_counter = 0;
            vector<int> num_line_space;
            int num_line_minus;
            vector<char> first_helper;
            vector<char> second_helper;
            for(int i=0;i<temp.length();i++){
                if(temp[i] == ' '){
                    num_line_space.push_back(i);
                }
                if(temp[i] == '-'){
                    num_line_minus = i;
                }
            }
            int first = 0;
            int second = 0;
            for(int i=0;i<num_line_minus;i++){
                first_helper.push_back(temp[i]);
            }

            for(int i=(num_line_minus+1);i<num_line_space[0];i++){
                second_helper.push_back(temp[i]);
            }
            int c = 1;
            for(unsigned i =1;i<first_helper.size();i++){
                c *=10;
            }
            for(unsigned i=0;i < first_helper.size();i++){
                int let = first_helper[i]  - '0';
                let *= c;
                first += let;
                c = c/10;
            }
            c = 1;
            for(unsigned i =1;i<second_helper.size();i++){
                c *=10;
            }

            for(unsigned i=0;i < second_helper.size();i++){
                int let = second_helper[i]  - '0';
                let *= c;
                second += let;
                c = c/10;
            }
 
            //cout << "first: " << first << " second: " << second << endl;
            char letter_to_find = temp[(num_line_space[0]+1)];
            //cout << "temp[first]: " << temp[num_line_space[1]+first] << " temp[second]: " << temp[num_line_space[1]+second] << endl;
            if(temp[num_line_space[1]+first] == letter_to_find && temp[num_line_space[1]+second] == letter_to_find || temp[num_line_space[1]+first] != letter_to_find && temp[num_line_space[1]+second] != letter_to_find){
                continue;
            }
            else{
                counter++;
            }
        }
        cout << counter << endl;
        return 0;
    }
