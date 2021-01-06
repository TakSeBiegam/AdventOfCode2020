#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

void push_empty_line(vector<vector<char> > &seats){
    vector<char> temp;
    for (size_t i = 0; i < 100; i++)
    {
        temp.push_back('X');
    }
    seats.push_back(temp);
    temp.clear();
}

void read_data(vector<vector<char> > &seats)
{
    fstream file;
    vector<char> full_row;
    int column_number = 0;
    char single_point;
    file.open("testcase.txt", ios::in);
    push_empty_line(seats);
    full_row.push_back('X');
    while (file >> single_point)
    {
        if (column_number == 98)
        {
            full_row.push_back('X');
            seats.push_back(full_row);
            column_number = 0;
            full_row.clear();
            full_row.push_back('X');
        }
        full_row.push_back(single_point);
        column_number++;
    }
    file.close();
    full_row.push_back('X');
    seats.push_back(full_row);
    full_row.clear();
    push_empty_line(seats);
    //close file and don't stress disk
}

void show_vector(vector<vector<char> > s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 0; j < s[i].size(); j++)
        {
            cout << s[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
}
int check_seats_around(vector<vector<char> > &s, char symbol, int i, int j)
{
    // i --- y_diag
    int y_diag = i;
    // j --- x_diag
    int x_diag = j;
    int counter = 0;
    do{
        y_diag--;
        if(s[y_diag][x_diag] == '#'){
            counter++;
            break;
        }
        if(s[y_diag][x_diag] == 'L'){
            break;
        }
    }while(s[y_diag][x_diag] != 'X' && s[y_diag][x_diag] != '#');

    y_diag = i;
    x_diag = j;
    do{
        y_diag--;
        x_diag++;
        if(s[y_diag][x_diag] == '#'){
            counter++;
            break;
        }
        if(s[y_diag][x_diag] == 'L'){
            break;
        }
    }while(s[y_diag][x_diag] != 'X' && s[y_diag][x_diag] != '#');

    y_diag = i;
    x_diag = j;
    do{
        x_diag++;
        if(s[y_diag][x_diag] == '#'){
            counter++;
            break;
        }
        if(s[y_diag][x_diag] == 'L'){
            break;
        }
    }while(s[y_diag][x_diag] != 'X' && s[y_diag][x_diag] != '#');

    y_diag = i;
    x_diag = j;
    do{
        y_diag++;
        x_diag++;
        if(s[y_diag][x_diag] == '#'){
            counter++;
            break;
        }
        if(s[y_diag][x_diag] == 'L'){
            break;
        }
    }while(s[y_diag][x_diag] != 'X' && s[y_diag][x_diag] != '#');

    y_diag = i;
    x_diag = j;
    do{
        y_diag++;
        if(s[y_diag][x_diag] == '#'){
            counter++;
            break;
        }
        if(s[y_diag][x_diag] == 'L'){
            break;
        }
    }while(s[y_diag][x_diag] != 'X' && s[y_diag][x_diag] != '#');
    y_diag = i;
    x_diag = j;
    do{
        y_diag++;
        x_diag--;
        if(s[y_diag][x_diag] == '#'){
            counter++;
            break;
        }
        if(s[y_diag][x_diag] == 'L'){
            break;
        }
    }while(s[y_diag][x_diag] != 'X' && s[y_diag][x_diag] != '#');
    y_diag = i;
    x_diag = j;
    do{
        x_diag--;
        if(s[y_diag][x_diag] == '#'){
            counter++;
            break;
        }
        if(s[y_diag][x_diag] == 'L'){
            break;
        }
    }while(s[y_diag][x_diag] != 'X' && s[y_diag][x_diag] != '#');
    y_diag = i;
    x_diag = j;
    do{
        y_diag--;
        x_diag--;
        if(s[y_diag][x_diag] == '#'){
            counter++;
            break;
        }
        if(s[y_diag][x_diag] == 'L'){
            break;
        }
    }while(s[y_diag][x_diag] != 'X' && s[y_diag][x_diag] != '#');

    return counter;
}

void modify_seats(vector<vector<char> > &seats)
{
    vector<char> single_line_buffor;
    vector<vector<char> > all_line_buffor;
    int counter_of_seats = 0;
    bool breaker_loop = true;
    while (breaker_loop)
    {
        for (size_t i = 0; i < seats.size(); i++)
        {
            for (size_t j = 0; j < seats[i].size(); j++)
            {
                switch (seats[i][j])
                {
                case '.':
                    single_line_buffor.push_back('.');
                    break;
                case 'L':
                    counter_of_seats = check_seats_around(seats, '#', i, j);
                    if(counter_of_seats == 0){
                        single_line_buffor.push_back('#');
                    }
                    else{
                        single_line_buffor.push_back('L');
                    }
                    counter_of_seats = 0;
                    break;
                case '#':
                    counter_of_seats = check_seats_around(seats, '#', i, j);
                    if(counter_of_seats >= 5){
                        single_line_buffor.push_back('L');
                    }
                    else{
                        single_line_buffor.push_back('#');
                    }
                    counter_of_seats = 0;
                    break;

                default:
                    single_line_buffor.push_back(seats[i][j]);
                    break;
                }
            }
            all_line_buffor.push_back(single_line_buffor);
            single_line_buffor.clear();
        }
        if(all_line_buffor != seats){
            seats = all_line_buffor;
            all_line_buffor.clear();
        }
        else{
            breaker_loop = false;
        }
    }
}

void counter_occupied_seats(vector<vector<char> > &seats){
    int counter = 0;
    for (size_t i = 0; i < seats.size(); i++)
    {
        for (size_t j = 0; j < seats[i].size(); j++)
        {
            if(seats[i][j] == '#'){
                counter++;
            }
        }
    }
    cout << "solution: " << counter << endl;
}

int main()
{
    int sol = 0;

    vector<vector<char> > seats;
    read_data(seats);
    //show_vector(seats);
    modify_seats(seats);
    counter_occupied_seats(seats);

    return 0;
}
