#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <vector>
#include <iostream>
#include "Engimon.hpp"
#include "Position.hpp"

using namespace std;

class Map{
    private :
        int xmax;
        int ymax;
        vector<vector<char>> peta;
        //vector<Engimon> engimon;
        int setCapital; /* X >= setCapital (Huruf Besar), X < setCapital (Huruf Kecil)*/
        int dimensiWater;
        Position ActiveEngimon_positon;
    public:
        Map();
        ~Map();
        void printMap();
        void movePlayerUp();
        void movePlayerRight();
        void movePlayerLeft();
        void movePlayerDown();
        vector<Engimon> getEngimon();
        vector<string> getCurrElement(Position k);
        bool isAboveLevel(Position k);
        
};
#endif