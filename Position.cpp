#include <iostream>
#include "Position.hpp"

using namespace std;

Position::Position(){
    x = 0;
    y = 0;
    engimon = NULL;
    isPlayer = false;
    isActiveEngimon = false;

}
Position::Position(int coordinate_x, int coordinate_y){
    x = coordinate_x;
    y = coordinate_y;
    engimon = NULL;
    isPlayer = false;
    isActiveEngimon = false;
}

Position::Position(const Position& pos){
    x = pos.x;
    y = pos.y;
    engimon = pos.engimon;
    isPlayer = pos.isPlayer;
    isActiveEngimon = pos.isPlayer;
}

bool Position::getisPlayer(){
    return this->isPlayer;
}

bool Position::getisActiveEngimon(){
    return this->isActiveEngimon;
}

Engimon* Position::getEngimon(){
    return this->engimon;
}

int Position::getXCoordinate(){
    return this->x;
}

int Position::getYCoordinate(){
    return this->y;
}