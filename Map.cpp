#include "Map.hpp"
#include "Position.cpp"
#include "Engimon.cpp"
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

Map::Map(){
    xmax = 10;
    ymax = 10;
    setCapital = 5;
    dimensiWater = 5;
    maxEngimonLiar = 5;
    map<Position, Engimon> engimonLiar = map<Position, Engimon>();
    for (int i = 0; i < xmax; i++){
        peta.push_back(vector<char>());
        for(int j = 0; j < ymax; j++){
            if(i >= xmax-dimensiWater || j < ymax-dimensiWater){
                peta.at(i).push_back('-');
            }else{
                peta.at(i).push_back('0');
            }
        }
    }
}

Map::~Map(){
    //
}
void Map::printMap(){
    for (int i = 0; i < xmax; i++){
        for(int j = 0; j < ymax; j++){
            cout << peta[i][j] << " ";
        }
        cout << endl;
    }
}

void Map::addEngimonLiar(){
    if(engimonLiar.size() < maxEngimonLiar){
        int coorX;
        int coorY;
        bool foundx = false;
        bool foundy = false;
        while(!foundx){
            coorX = rand() % (xmax-1);
            if (coorX != getplayerPositionX() && coorX != getactiveEngimonPositionX()){
                foundx = true;
            }
        }
        while(!foundy){
            coorY = rand() % (ymax-1);
            if (coorY != getplayerPositionY() && coorY != getactiveEngimonPositionY()){
                foundy = true;
            }
        }
        Position engimonLiarpos = Position(coorX,coorY);
        //coorX dan coorY ketemu
        //random nama
        enum Name {Omnimon, Skull, Greymon, Piedmon, War_Greymon, MagnaAngemon, Garurumon, Devimon, Apocalypmon, Etemon, Agumon};
        static const char *enum_str_name[] = {"Omnimon", "Skull", "Greymon", "Piedmon", "War_Greymon", "MagnaAngemon", "Garurumon", "Devimon", "Apocalypmon", "Etemon", "Agumon"};
        Name name = Name(rand()%10);
        string nama(enum_str_name[name]);
        //nama ketemu
        //random species
        enum Species {Firemon, Watermon, Electromon, Groundmon, Icemon};
        static const char *enum_str_species[] = { "Firemon", "Watermon", "Electromon", "Groundmon", "Icemon" };
        Species species = Species(rand()%4);
        string spesies(enum_str_species[species]);
        //spesies ketemu
        //random element (susah nih wkwk)
        vector<string> elemennya = vector<string>();
        if(coorX >= xmax-dimensiWater || coorY < ymax-dimensiWater){ //grassland
            enum Element {F, G, E, L, N};
            static const char *enum_str_element[] = { "Fire", "Ground", "Electric", "Fire/Electric", "Water/Ground" };
            Element element = Element(rand()%4);
            string elemen(enum_str_element[element]);
            vector<string> elemennya = vector<string>();
            if (elemen == "Fire/Electric"){
                elemennya = {"Fire", "Electric"};
            }else if (elemen == "Water/Ground"){
                elemennya = {"Water","Ground"};
            }else{
                elemennya = {elemen,elemen};
            }
        }else{
            enum Element {W, I, S, N};
            static const char *enum_str_element[] = { "Water", "Ice", "Water/Ice", "Water/Ground" };
            Element element = Element(rand()%3);
            string elemen(enum_str_element[element]);           
            if (elemen == "Water/Ice"){
                elemennya = {"Water","Ice"};
            }else{
                elemennya = {elemen,elemen};
            }
        }
        Engimon engimonbaru = Engimon(nama, spesies, elemennya);
        engimonLiar.insert({engimonLiarpos, engimonbaru});
        //peta[coorX][coorY] = 
    }
}

//getter
int Map::getmaxEngimonLiar(){ return this->maxEngimonLiar; }
int Map::getxmax(){ return this->xmax; }
int Map::getymax(){ return this->ymax; }
Position Map::getplayerPosition(){ return this->playerPosition; }
Position Map::getactiveEngimonPosition(){ return this->activeEngimonPositon; }
int Map::getplayerPositionX(){ return this->playerPosition.getXCoordinate(); }
int Map::getplayerPositionY(){ return this->playerPosition.getYCoordinate(); }
int Map::getactiveEngimonPositionX(){ return this->activeEngimonPositon.getXCoordinate(); }
int Map::getactiveEngimonPositionY(){ return this->activeEngimonPositon.getYCoordinate(); }

//setter
void Map::setplayerPosition(int _x, int _y){
    playerPosition.setXCoordinate(_x);
    playerPosition.setXCoordinate(_y);
    for (int i = 0; i < xmax; i++){
        for (int j = 0; j < ymax; j++){
            if (peta[i][j] == 'P'){
                peta[i][j] = '-';
            }
        }
    }
    peta[_x][_y] = 'P';
}
void Map::setactiveEngimonPosition(int _x, int _y){
    activeEngimonPositon.setXCoordinate(_x);
    activeEngimonPositon.setXCoordinate(_y);
    for (int i = 0; i < xmax; i++){
        for (int j = 0; j < ymax; j++){
            if (peta[i][j] == 'X'){
                peta[i][j] = '-';
            }
        }
    }
    peta[_x][_y] = 'X';
}

/*
void Map::printMap(){
    for (int i = 0; i < xmax; i++){
        for(int j = 0; j < ymax; j++){
            if(i > xmax-dimensiWater || j < ymax-dimensiWater){
                cout << "- ";
            }else if (i == player_position.getXCoordinate() && j == player_position.getYCoordinate()){
                cout << "P ";
            }else if (i == ActiveEngimon_positon.getXCoordinate() && j == ActiveEngimon_positon.getYCoordinate()){
                cout << "X ";
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Fire"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "F ";
                }else{
                    cout << "f ";
                }
            }
            else if (getCurrElement(peta.at(i).at(j)).at(0)=="Water"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "W ";
                }else{
                    cout << "w ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Ice"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "I ";
                }else{
                    cout << "i ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Ground"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "G ";
                }else{
                    cout << "g ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Electric"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "E ";
                }else{
                    cout << "e ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Fire" 
                && getCurrElement(peta.at(i).at(j)).at(0)=="Electric"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "L ";
                }else{
                    cout << "l ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Water" 
                && getCurrElement(peta.at(i).at(j)).at(0)=="Ice"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "S ";
                }else{
                    cout << "s ";
                }
            }else if (getCurrElement(peta.at(i).at(j)).at(0)=="Water" 
                && getCurrElement(peta.at(i).at(j)).at(0)=="Ground"){
                if (isAboveLevel(peta.at(i).at(j))){
                    cout << "N ";
                }else{
                    cout << "n ";
                }
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

vector<string> Map::getCurrElement(Position k){
    return k.getEngimon().getElement();
}

bool Map::isAboveLevel(Position k){
    return (k.getEngimon().getLevel() >= setCapital);
}
*/

int main(int argc, char const *argv[])
{
    Map m = Map();
    m.printMap();
    return 0;
}
