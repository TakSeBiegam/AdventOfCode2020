    #include <iostream>
    #include <fstream>
    #include <map>

    using namespace std;

    int main()
    {
        fstream file;
        string temp;
        map<int, string> m;
        file.open("data.txt", ios::in);
        int counter = 0;
        int pos = 0; //max 31
        //right 3 and 1 down
        int c = 0;
        while(getline(file, temp)){
            m.insert(make_pair(c, temp));
            c++;
        }
        file.close();
        for(unsigned i = 1; i < m.size(); i++){
            if(pos >= 28){ //63
                int t = 31%pos; //66%63
                pos = 3-t;
            }
            else{
                pos += 3;
            }
            if(m[i][pos] == '#'){
                counter++;
            }
        }
        
        cout << counter << endl;
        return 0;
    }
