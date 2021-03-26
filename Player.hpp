#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <iostream>
#include <list>
#include "Position.hpp"
#include "Inventory.hpp"
#include "Engimon.hpp"
#include "SkillItem.hpp"
#include "Map.hpp"

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
    Engimon ActiveEngimon;
    Position pos;
    Inventory<Engimon> inventoryEngimon;
    Inventory<SkillItem> inventorySkillItem;

public:
    //Ctor
    Player(Position pos, Engimon activeEngi, Inventory<Engimon> inventoryEngimon, Inventory<SkillItem> inventorySkillItem);

    // Inventory
    void addSkillItem(SkillItem newSkillItem);
    void addEngimon(Engimon newEngimon);

    //Move Command
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    //Engimon Command
    void showOwnedEngimon();
    void showStatsEngimon(Engimon engimon);
    void showActiveEngimon();
    void swapActiveEngimon(string newEngimonName); // Swap active engimon with engimon from inventory

    //Skill Items Command
    void showOwnedItems();

    //Breed
    void doBreed(string firstEngimonName, string secondEngimonName);

    //Battle
    void doBattle();

    void learnSkill(string SkillName);
    void replaceSkillItem(int replacedSkillIdx, Skill newSkill)
};

#endif