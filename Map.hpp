#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Map{
    private :
        int xmax;
        int ymax;
        int setCapital; /* X >= setCapital (Huruf Besar), X < setCapital (Huruf Kecil)*/
        int dimensiWater;
        //Position player_position;
    public:
        void printMap();
        Map();
};
#endif