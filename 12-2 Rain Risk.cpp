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
    switch (difference)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
}

void go_forward(int turn_side, int times_to_multiple_waypoint, int &go_y, int &go_x, int n_way, int s_way, int e_way, int w_way){
    switch (turn_side)
    {
    case 0:
        go_y += (n_way*times_to_multiple_waypoint);
        go_x -= (w_way*times_to_multiple_waypoint);
        break;
    case 180:
        go_y -= (s_way*times_to_multiple_waypoint);
        go_x += (e_way*times_to_multiple_waypoint);
        break;
    case 90:
        go_y += (n_way*times_to_multiple_waypoint);
        go_x += (e_way*times_to_multiple_waypoint);
        break;
    case 270:
        go_y -= (s_way*times_to_multiple_waypoint);
        go_x -= (w_way*times_to_multiple_waypoint);
        break;
    default:
        break;
    }
    cout << "Go_y: " << go_y << endl << "Go_x: " << go_x << endl;
}

void move_ship(vector<char> &instruction_action, vector<int> &instruction_value){
    int direction[4];
    for (size_t i = 0; i < 4; i++){
        direction[i] = 0;
    }
    
    int go_horizontal = 0;
    int go_vertical = 0;
    int turn_side = 90;

    string single_line = "";
    for (size_t i = 0; i < instruction_action.size(); i++){
        switch (instruction_action[i])
        {
        case 'N':
            direction[0] += instruction_value[i];
            break;
        case 'S':
            direction[2] += instruction_value[i];
            break;
        case 'E':
            direction[1] += instruction_value[i];
            break;
        case 'W':
            direction[3] += instruction_value[i];
            break;
        case 'R':
            check_turn_value(turn_side, instruction_value[i], 'R', direction);
            break;
        case 'L':
            check_turn_value(turn_side, instruction_value[i], 'L', direction);
            break;
        case 'F':
            go_forward(turn_side, instruction_value[i], go_vertical, go_horizontal, direction);
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