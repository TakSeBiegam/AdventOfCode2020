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

void check_turn_value(int &turn_side, int angle, char symbol_of_turn, int vertical_waypoint, int horizontal_waypoint){
    int old_turn_side = turn_side;
    if(symbol_of_turn == 'R'){
        turn_side += angle;
        if(turn_side >= 360){
            turn_side -= 360;
        }
    }
    if(symbol_of_turn == 'L'){
        turn_side += 360-angle;
        if(turn_side >= 360){
            turn_side -= 360;
        }
    }
    int difference = old_turn_side - turn_side;
    if(difference < 0 ){
        difference *= -1;
    }
    int temp;
    switch (difference)
    {
    case 90:
        temp = vertical_waypoint;
        vertical_waypoint = horizontal_waypoint;
        horizontal_waypoint = temp; 
        break;
    case 180: 
        vertical_waypoint *= -1;
        horizontal_waypoint *= -1; 
        break;
    case 270:
        temp = vertical_waypoint;
        vertical_waypoint = horizontal_waypoint;
        horizontal_waypoint = temp; 
        break;
    default:
        cout << "ERROR CHECK TURN VALUE" << endl;
        break;
    }
}

void go_forward(int turn_side, int times_to_multiple_waypoint, int &go_y, int &go_x, int ver_way, int hor_way){
    if(ver_way < 0){
        ver_way *= -1;
    }
    if(hor_way < 0){
        hor_way *= -1;
    }

    switch (turn_side)
    {
    case 0:
        go_y += (ver_way*times_to_multiple_waypoint);
        go_x -= (hor_way*times_to_multiple_waypoint);
        break;
    case 180:
        go_y -= (ver_way*times_to_multiple_waypoint);
        go_x += (hor_way*times_to_multiple_waypoint);
        break;
    case 90:
        go_y += (ver_way*times_to_multiple_waypoint);
        go_x += (hor_way*times_to_multiple_waypoint);
        break;
    case 270:
        go_y -= (ver_way*times_to_multiple_waypoint);
        go_x -= (hor_way*times_to_multiple_waypoint);
        break;
    default:
        break;
    }
    //cout << "Go_y: " << go_y << endl << "Go_x: " << go_x << endl;
}

void move_ship(vector<char> &instruction_action, vector<int> &instruction_value){
    int vertical_waypoint = 1;
    int horizontal_waypoint = 10;
    
    int go_horizontal = 0;
    int go_vertical = 0;
    int turn_side = 90;

    string single_line = "";
    for (size_t i = 0; i < instruction_action.size(); i++){
        switch (instruction_action[i])
        {
        case 'N':
            vertical_waypoint += instruction_value[i];
            break;
        case 'S':
            vertical_waypoint -= instruction_value[i];
            break;
        case 'E':
            horizontal_waypoint += instruction_value[i];
            break;
        case 'W':
            horizontal_waypoint -= instruction_value[i];
            break;
        case 'R':
            check_turn_value(turn_side, instruction_value[i], 'R', vertical_waypoint, horizontal_waypoint);
            break;
        case 'L':
            check_turn_value(turn_side, instruction_value[i], 'L', vertical_waypoint, horizontal_waypoint);
            break;
        case 'F':
            go_forward(turn_side, instruction_value[i], go_vertical, go_horizontal, vertical_waypoint, horizontal_waypoint);
            break;
        default:
            break;
        }
        //cout << "vert: " << go_vertical << endl << "hori: " << go_horizontal << endl ;
        //cout << "v_way: "<< vertical_waypoint << endl << "h_way: " << horizontal_waypoint << endl << endl;
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