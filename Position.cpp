#include <iostream>
#include "Position.hpp"

using namespace std;

Position::Position(int coordinate_x, int coordinate_y){
    x = coordinate_x;
    y = coordinate_y;
}

Position::Position(const Position& pos){
    x = pos.x;
    y = pos.y;
}

void Position::setPosition(int a, int b){
    x = a;
    y = b;
}