#include <string>
#include <iostream>
#include <list>
#include "Position.hpp"

using namespace std;

class Map : public Position {
    private :
        int xmax;
        int ymax;
        int setCapital; /* X >= setCapital (Huruf Besar), X < setCapital (Huruf Kecil)*/
        int dimensiWater;
        Position player_position;
    public:
        void printMap();
        Map();
};