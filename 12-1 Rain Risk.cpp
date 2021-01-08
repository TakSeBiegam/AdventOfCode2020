#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void readfile(vector<char> &instruction_action, vector<int> &instruction_value){
    fstream file;
    file.open("testcase.txt", ios::in);
    string single_line = "";
    char single_action;
    string single_value = "";
    int value;
    while(getline(file, single_line)){
        single_action = single_line[0];
        for (size_t i = 1; i < single_line.length(); i++){
            single_value += single_line[i];
        }
        instruction_action.push_back(single_action);
        value = stoi(single_value);
        instruction_value.push_back(value);
        single_value = "";
    }
    file.close();
}

void check_turn_value(int &turn_side, int angle, char symbol_of_turn){
    if(symbol_of_turn == 'R'){
        turn_side += angle;
        if (turn_side >= 360)
        {
            turn_side -= 360;
        }
    }
    else{
        turn_side -= angle;
        if (turn_side < 0)
        {
            turn_side += 360;
        }
    }
}

void go_forward(int turn_side, int length_of_the_road, int &go_y, int &go_x){
    switch (turn_side)
    {
    case 0:
        go_y += length_of_the_road;
        break;
    case 180:
        go_y -= length_of_the_road;
        break;
    case 90:
        go_x += length_of_the_road;
        break;
    case 270:
        go_x -= length_of_the_road;
        break;
    default:
        break;
    }
}

void move_ship(vector<char> &instruction_action, vector<int> &instruction_value){
    int go_vertical = 0; //  north/south
    int go_horizontal = 0; //  east/west
    int turn_side = 90;
    /* 
    turn side = 0/360 --- go North
    turn side = 90 --- go East
    turn side = 180 --- go South
    turn side = 270 --- go West
    */
    string single_line = "";
    for (size_t i = 0; i < instruction_action.size(); i++){
        switch (instruction_action[i])
        {
        case 'N':
            go_vertical += instruction_value[i];
            break;
        case 'S':
            go_vertical -= instruction_value[i];
            break;
        case 'E':
            go_horizontal += instruction_value[i];
            break;
        case 'W':
            go_horizontal -= instruction_value[i];
            break;
        case 'R':
            check_turn_value(turn_side, instruction_value[i], 'R');
            break;
        case 'L':
            check_turn_value(turn_side, instruction_value[i], 'L');
            break;
        case 'F':
            go_forward(turn_side, instruction_value[i], go_vertical, go_horizontal);
            break;
        default:
            break;
        }
    }
    if(go_vertical < 0){
        go_vertical *= -1;
    }
    if(go_horizontal < 0){
        go_horizontal *= -1;
    }
    cout << "vertical: " << go_vertical << endl << "horizontal: " << go_horizontal << endl;
    cout << "sum: " << go_horizontal+go_vertical << endl;
}

int main(){
    vector<char> instruction_action;
    vector<int> instruction_value;
    readfile(instruction_action, instruction_value);
    move_ship(instruction_action, instruction_value);

}