    #include <iostream>
    #include <fstream>
    #include <map>

    using namespace std;

    int main()
    {
        fstream file;
        string temp;
        map<int, string> m;
        file.open("testcase.txt", ios::in);
        long int counter[5] = {0,0,0,0,0};
        int right[5] = {1,3,5,7,1};
        int down[5] = {1,1,1,1,2};
        int pos = 0; //max 31
        long int solution = 1;
        int c = 0;
        while(getline(file, temp)){
            m.insert(make_pair(c, temp));
            c++;
        }
        file.close();
        for(int head = 0; head < 5; head++){
            pos = 0;
            int buff = 31 - right[head]; //31
            for(int i = 1; i < m.size(); i += down[head]){
                if(head == 4 && i < 2){
                    i = 2;
                }
                if(pos >= buff){
                    int t = 31%pos;
                    pos = right[head]-t;
                }
                else{
                    pos += right[head];
                }
                if(m[i][pos] == '#'){
                    counter[head]++;
                }  
            }
        }
        
        for(int i=0;i<5;i++){
            solution *= counter[i];
        }
        cout << solution << endl;
        return 0;
    }
