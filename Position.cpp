s #include<iostream>
#include "Position.hpp"

    using namespace std;

Position::Position()
{
    x = 0;
    y = 0;
}

Position::Position(int coordinate_x, int coordinate_y)
{
    x = coordinate_xf;
    y = coordinate_y;
}

Position::Position(const Position &pos)
{
    x = pos.x;
    y = pos.y;
}

Position &Position::operator=(const Position &pos)
{
    x = pos.x;
    y = pos.y;
    return *this;
}

Position::~Position()
{
    //
}

int Position::getXCoordinate()
{
    return this->x;
}

int Position::getYCoordinate()
{
    return this->y;
}

int Position::setXCoordinate(int _x)
{
    this->x = _x;
}

int Position::setYCoordinate(int _y)
{
    this->y = _y;
}