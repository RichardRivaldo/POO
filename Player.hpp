#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <iostream>
#include <list>
#include "Position.hpp"
#include "Inventory.hpp"
#include "Engimon.hpp"
#include "SkillItem.hpp"

using namespace std;

/*  To Do : 
    Gerak (Engimon mengikuti di belakang)
    Show List Engimon
    Show Data Engimon
    Select, Swap Active Engimon
    Menggunakan Skill
    Mengecek dan Mengganti Active Engimon
    Breeding
    Battle (prioritas WASD)
*/

class Player
{
private:
    Position pos;
    Inventory<Engimon> inventoryEngimon;
    Inventory<SkillItem> inventorySkillItem;

public:
    //Ctor
    Player(Position pos);

    // Inventory
    void addSkill(SkillItem newSkillItem);
    void addEngimon(Engimon newEngimon);

    //Move Command
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    //Engimon Command
    void showOwnedEngimon();
    void showStatsEngimon(Engimon a);
    void showActiveEngimon();
    void swapActiveEngimon(Engimon b);

    //Skill Command
    void showOwnedSkill();
    void useOwnedSkill(Skill x, Engimon y);

    //Breed
    void doBreed(Engimon a, Engimon b);

    //Battle
    void doBattle();
};

#endif