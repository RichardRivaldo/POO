#include "Map.hpp"
#include <iostream>
using namespace std;

Map::Map() : Position(8,8){
    xmax = 12;
    ymax = 12;
    setCapital = 5;
    dimensiWater = 6;
}
void Map::printMap(){
    for (int i = 0; i < xmax; i++){
        for (int j = 0; j < ymax; j++){
            if(i > xmax-dimensiWater || j < ymax-dimensiWater){
                cout << "- ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    Map m = Map();
    m.printMap();
    return 0;
}
