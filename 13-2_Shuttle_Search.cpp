#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void read_file(vector<int> &bus, vector<int> &offset)
{
    fstream file;
    file.open("test.txt", ios::in);
    string tempomary;
    string converter = "";
    short int timestamp = 0;

    file >> tempomary;
    for (size_t i = 0; i < tempomary.length(); i++)
    {
        if (tempomary[i] == ',')
        {
            if (tempomary[i - 1] == 'x')
            {
                converter = "";
                continue;
            }
            offset.push_back(timestamp);
            bus.push_back(stoi(converter));
            converter = "";
            timestamp++;
            continue;
        }
        converter += tempomary[i];
    }
    offset.push_back(timestamp);
    bus.push_back(stoi(converter));
    file.close();
}

void solution(vector<int> &bus, vector<int> &offset)
{
    long long int time = 100000000000000;
    int loop_breaker = 0;

    while (loop_breaker != bus.size())
    {
        loop_breaker = 0;
        for (long long int i = 0; i < bus.size(); i++)
        {
            if ((time+offset[i]) % bus[i] == 0)
            {
                loop_breaker++;
            }
        }
        time++;
    }
    cout << time-1 << endl;
}

int main()
{
    vector<int> bus_offset;
    vector<int> bus;
    read_file(bus, bus_offset);
    cout << "read" << endl;
    solution(bus, bus_offset);
    return 0;
}
