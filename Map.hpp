#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <vector>
#include <iostream>
#include "Position.cpp"

using namespace std;

class Map{
    private :
        int xmax;
        int ymax;
        vector<vector<Position>> peta;
        int setCapital; /* X >= setCapital (Huruf Besar), X < setCapital (Huruf Kecil)*/
        int dimensiWater;
        //Position player_position;
    public:
        Map();
        void printMap();
        void movePlayerUp();
        void movePlayerRight();
        void movePlayerLeft();
        void movePlayerDown();
        
};
#endif