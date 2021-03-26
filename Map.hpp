#ifndef MAP_HPP
#define MAP_HPP
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Engimon.hpp"
#include "Position.hpp"
#include "Player.hpp"

using namespace std;

class Map{
    private :
        int xmax;
        int ymax;
        vector<vector<char>> peta;
        map<Position, Engimon> engimonLiar;
        //vector<Engimon> engimon;
        int setCapital; /* X >= setCapital (Huruf Besar), X < setCapital (Huruf Kecil)*/
        int dimensiWater;
        Position playerPosition;
        Position activeEngimonPositon;
    public:
        Map();
        ~Map();
        void printMap();
        Position getplayerPosition();
        int getplayerPositionX();
        int getplayerPositionY();
        int getxmax();
        int getymax();
        void setplayerPosition(int _x, int _y);
        Position getactiveEngimonPosition();
        int getactiveEngimonPositionX();
        int getactiveEngimonPositionY();
        void setactiveEngimonPosition(int _x, int _y);
        vector<Engimon> getEngimon();
        //vector<string> getCurrElement(Position k);
        bool isAboveLevel(Position k);
        
};
#endif