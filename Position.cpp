#include <iostream>
#include <list>
#include "Position.hpp"

using namespace std;

Position::Position(){
    x = 0;
    y = 0;
    isPlayer = false;
    isActiveEngimon = false;
    isOccupied = false;
}

Position::Position(int coordinate_x, int coordinate_y){
    x = coordinate_x;
    y = coordinate_y;
    isPlayer = false;
    isActiveEngimon = false;
    isOccupied = false;
}

Position::Position(const Position& pos){
    x = pos.x;
    y = pos.y;
    engimon = pos.engimon;
    isPlayer = pos.isPlayer;
    isActiveEngimon = pos.isPlayer;
    isOccupied = pos.isOccupied;
}

Position& Position::operator=(const Position& pos){
    x = pos.x;
    y = pos.y;
    engimon = pos.engimon;
    isPlayer = pos.isPlayer;
    isActiveEngimon = pos.isPlayer;
    isOccupied = pos.isOccupied;
    return *this;
}

Position::~Position(){
    //
}

bool Position::getisPlayer(){
    return this->isPlayer;
}

bool Position::getisActiveEngimon(){
    return this->isActiveEngimon;
}

Engimon Position::getEngimon(){
    return this->engimon.front();
}

int Position::getXCoordinate(){
    return this->x;
}

int Position::getYCoordinate(){
    return this->y;
}