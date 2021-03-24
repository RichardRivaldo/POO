#ifndef POSITION_HPP_
#define POSITION_HPP_
#include "Engimon.hpp"
class Position{
    protected :
        int x;
        int y;
        list<Engimon> engimon;
        bool isPlayer;
        bool isActiveEngimon;
        bool isOccupied;

    public:
        Position();
        Position(int coordinate_x, int coordinate_y);
        Position(const Position&);
        ~Position();
        Position& operator=(const Position& pos);
        bool getisPlayer();
        bool getisActiveEngimon();
        Engimon getEngimon();
        int getXCoordinate();
        int getYCoordinate();
};
#endif