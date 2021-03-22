#include "Map.hpp"
#include <iostream>
using namespace std;

Map::Map(){
    xmax = 12;
    ymax = 12;
    setCapital = 5;
    dimensiWater = 6;
    player_position = Position(8,8);
}
void Map::printMap(){
    for (int i = 0; i < xmax; i++){
        for (int j = 0; j < ymax; j++){
            if(i > xmax-dimensiWater || j > ymax-dimensiWater){
                cout << "0 ";
            }else{
                cout << "- ";
            }
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    printMap();
    return 0;
}
