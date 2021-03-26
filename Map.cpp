#include "Map.hpp"
#include "Position.hpp"
#include "Engimon.hpp"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <new>
using namespace std;

Map::Map()
{
    xmax = 10;
    ymax = 10;
    setCapital = 5;
    dimensiWater = 5;
    maxEngimonLiar = 5;
    engimonLiar = vector<pair<Position, Engimon>>();
    for (int i = 0; i < xmax; i++)
    {
        peta.push_back(vector<char>());
        for (int j = 0; j < ymax; j++)
        {
            if (i >= xmax - dimensiWater || j < ymax - dimensiWater)
            {
                peta.at(i).push_back('-');
            }
            else
            {
                peta.at(i).push_back('0');
            }
        }
    }
}

Map::~Map()
{
    //
}
void Map::printMap()
{
    for (int i = 0; i < xmax; i++)
    {
        for (int j = 0; j < ymax; j++)
        {
            cout << peta[i][j] << " ";
        }
        cout << endl;
    }
}

vector<pair<Position, Engimon>> Map::getengimonLiar()
{
    return this->engimonLiar;
}
void Map::addEngimonLiar()
{
    if (engimonLiar.size() < maxEngimonLiar)
    {
        int coorX;
        int coorY;
        bool foundx = false;
        bool foundy = false;
        while (!foundx)
        {
            coorX = rand() % (xmax - 1);
            if (coorX != getplayerPositionX() && coorX != getactiveEngimonPositionX())
            {
                foundx = true;
            }
        }
        while (!foundy)
        {
            coorY = rand() % (ymax - 1);
            if (coorY != getplayerPositionY() && coorY != getactiveEngimonPositionY())
            {
                foundy = true;
            }
        }
        Position engimonLiarpos = Position(coorX, coorY);
        //coorX dan coorY ketemu
        //random nama
        enum Name
        {
            Omnimon,
            Skull,
            Greymon,
            Piedmon,
            War_Greymon,
            MagnaAngemon,
            Garurumon,
            Devimon,
            Apocalypmon,
            Etemon,
            Agumon
        };
        static const char *enum_str_name[] = {"Omnimon", "Skull", "Greymon", "Piedmon", "War_Greymon", "MagnaAngemon", "Garurumon", "Devimon", "Apocalypmon", "Etemon", "Agumon"};
        Name name = Name(rand() % 10);
        string nama(enum_str_name[name]);
        //nama ketemu
        //random species
        enum Species
        {
            Firemon,
            Watermon,
            Electromon,
            Groundmon,
            Icemon
        };
        static const char *enum_str_species[] = {"Firemon", "Watermon", "Electromon", "Groundmon", "Icemon"};
        Species species = Species(rand() % 4);
        string spesies(enum_str_species[species]);
        //spesies ketemu
        //random element (susah nih wkwk)
        vector<string> elemennya = vector<string>();
        if (coorX >= xmax - dimensiWater || coorY < ymax - dimensiWater)
        { //grassland
            enum Element
            {
                F,
                G,
                E,
                L,
                N
            };
            static const char *enum_str_element[] = {"Fire", "Ground", "Electric", "Fire/Electric", "Water/Ground"};
            Element element = Element(rand() % 4);
            string elemen(enum_str_element[element]);
            if (elemen == "Fire/Electric")
            {
                elemennya.push_back("Fire");
                elemennya.push_back("Electric");
            }
            else if (elemen == "Water/Ground")
            {
                elemennya.push_back("Water");
                elemennya.push_back("Ground");
            }
            else
            {
                elemennya.push_back(elemen);
                elemennya.push_back(elemen);
            }
        }
        else
        {
            enum Element
            {
                W,
                I,
                S,
                N
            };
            static const char *enum_str_element[] = {"Water", "Ice", "Water/Ice", "Water/Ground"};
            Element element = Element(rand() % 3);
            string elemen(enum_str_element[element]);
            if (elemen == "Water/Ice")
            {
                elemennya.push_back("Water");
                elemennya.push_back("Ice");
            }
            else if (elemen == "Water/Ground")
            {
                elemennya.push_back("Water");
                elemennya.push_back("Ground");
            }
            else
            {
                elemennya.push_back(elemen);
                elemennya.push_back(elemen);
            }
        }
        Engimon engimonbaru = Engimon(nama, spesies, elemennya);
        pair<Position, Engimon> engimonnya;
        engimonnya.first = engimonLiarpos;
        engimonnya.second = engimonbaru;
        engimonLiar.push_back(engimonnya);
        if (engimonbaru.getElement().at(0) == "Fire" && engimonbaru.getElement().at(1) == "Fire")
        {
            peta[coorX][coorY] = 'f';
        }
        else if (engimonbaru.getElement().at(0) == "Water" && engimonbaru.getElement().at(1) == "Water")
        {
            peta[coorX][coorY] = 'w';
        }
        else if (engimonbaru.getElement().at(0) == "Ice" && engimonbaru.getElement().at(1) == "Ice")
        {
            peta[coorX][coorY] = 'i';
        }
        else if (engimonbaru.getElement().at(0) == "Ground" && engimonbaru.getElement().at(1) == "Ground")
        {
            peta[coorX][coorY] = 'g';
        }
        else if (engimonbaru.getElement().at(0) == "Electric" && engimonbaru.getElement().at(1) == "Electric")
        {
            peta[coorX][coorY] = 'e';
        }
        else if (engimonbaru.getElement().at(0) == "Fire" && engimonbaru.getElement().at(1) == "Electric")
        {
            peta[coorX][coorY] = 'l';
        }
        else if (engimonbaru.getElement().at(0) == "Water" && engimonbaru.getElement().at(1) == "Ice")
        {
            peta[coorX][coorY] = 's';
        }
        else if (engimonbaru.getElement().at(0) == "Water" && engimonbaru.getElement().at(1) == "Ground")
        {
            peta[coorX][coorY] = 'n';
        }
    }
}

/*void Map::moveAllEngimonLiar()
{
    //cleaning dulu
    for (int i = 0; i < xmax; i++)
    {
        for (int j = 0; j < ymax; j++)
        {
            if (peta[i][j] != 'P' && peta[i][j] != 'X')
            {
                if (i >= xmax - dimensiWater || j < ymax - dimensiWater)
                {
                    peta.at(i).at(j) = '-';
                }
                else
                {
                    peta.at(i).at(j) = '0';
                }
            }
        }
    }
    for (int a = 0; a < engimonLiar.size(); a++)
    {
        if (engimonLiar.at(a).second.getElement().at(i) ==)
    }
}

void Map::moveEngimonLiar(Position pos, Engimon engimon){
    enum Direction
    {
        N,
        E,
        S,
        W,
    };
    static const char *enum_str_direction[] = {"North", "East", "South", "West"};
    Direction direction = Direction(rand() % 3);
    string arah(enum_str_direction[direction]);
    if (arah == "North" && )

    //BRB
    if(pos.getXCoordinate())
    if (engimon.getElement().at(0) == "Fire" && engimongetElement().at(1) == "Fire")
        {
            
            peta[coorX][coorY] = 'f';
        }
        else if (engimon.getElement().at(0) == "Water" && engimon.getElement().at(1) == "Water")
        {
            peta[coorX][coorY] = 'w';
        }
        else if (engimon.getElement().at(0) == "Ice" && engimon.getElement().at(1) == "Ice")
        {
            peta[coorX][coorY] = 'i';
        }
        else if (engimon.getElement().at(0) == "Ground" && engimon.getElement().at(1) == "Ground")
        {
            peta[coorX][coorY] = 'g';
        }
        else if (engimon.getElement().at(0) == "Electric" && engimon.getElement().at(1) == "Electric")
        {
            peta[coorX][coorY] = 'e';
        }
        else if (engimon.getElement().at(0) == "Fire" && engimon.getElement().at(1) == "Electric")
        {
            peta[coorX][coorY] = 'l';
        }
        else if (engimon.getElement().at(0) == "Water" && engimon.getElement().at(1) == "Ice")
        {
            peta[coorX][coorY] = 's';
        }
        else if (engimon.getElement().at(0) == "Water" && engimon.getElement().at(1) == "Ground")
        {
            peta[coorX][coorY] = 'n';
        }
}
*/
//getter
int Map::getmaxEngimonLiar() { return this->maxEngimonLiar; }
int Map::getxmax() { return this->xmax; }
int Map::getymax() { return this->ymax; }
Position Map::getplayerPosition() { return this->playerPosition; }
Position Map::getactiveEngimonPosition() { return this->activeEngimonPositon; }
int Map::getplayerPositionX() { return this->playerPosition.getXCoordinate(); }
int Map::getplayerPositionY() { return this->playerPosition.getYCoordinate(); }
int Map::getactiveEngimonPositionX() { return this->activeEngimonPositon.getXCoordinate(); }
int Map::getactiveEngimonPositionY() { return this->activeEngimonPositon.getYCoordinate(); }

//setter
void Map::setplayerPosition(int _x, int _y)
{
    playerPosition.setXCoordinate(_x);
    playerPosition.setXCoordinate(_y);
    for (int i = 0; i < xmax; i++)
    {
        for (int j = 0; j < ymax; j++)
        {
            if (peta[i][j] == 'P')
            {
                peta[i][j] = '-';
            }
        }
    }
    peta[_x][_y] = 'P';
}
void Map::setactiveEngimonPosition(int _x, int _y)
{
    activeEngimonPositon.setXCoordinate(_x);
    activeEngimonPositon.setXCoordinate(_y);
    for (int i = 0; i < xmax; i++)
    {
        for (int j = 0; j < ymax; j++)
        {
            if (peta[i][j] == 'X')
            {
                peta[i][j] = '-';
            }
        }
    }
    peta[_x][_y] = 'X';
}

/*int main(int argc, char const *argv[])
{
    Map m = Map();
    m.printMap();
    return 0;
}*/
