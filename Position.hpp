#include "Engimon.hpp"
class Position {
    protected :
        int x;
        int y;
        Engimon * engimon;
        bool isPlayer;
        bool isActiveEngimon;

    public:
        Position();
        Position(int coordinate_x, int coordinate_y);
        Position(const Position&);
        bool getisPlayer();
        bool getisActiveEngimon();
        Engimon * getEngimon();
        int getXCoordinate();
        int getYCoordinate();
};