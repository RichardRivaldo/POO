#include <string>
#include <iostream>
#include "Player.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"

using namespace std;

Player::Player(Position pos)
{
    this->pos = pos;
}

// Inventory
void Player::addSkill(SkillItem newSkillItem)
{
    try
    {
        int i = 0;
        while (i < this->inventorySkillItem.getInventorySize())
        {
            if (this->inventorySkillItem.getInventoryVector()[i].getSkill().getSkillName() == newSkillItem.getSkill().getSkillName())
            {
                cout << "Berhasil menambahkan add skill ke " << newSkillItem.getSkill().getSkillName() << endl;
                this->inventorySkillItem.getInventoryVector()[i].addItemAmount();
                return;
            }
            i++;
        }

        cout << "Berhasil menambahkan skill baru" << endl;
        this->inventorySkillItem << newSkillItem;
    }
    catch (string err)
    {
        cout << err << endl;
    }
}

void Player::addEngimon(Engimon newEngimon)
{
    try
    {
        this->inventoryEngimon << newEngimon;
        cout << "Berhasil menambahkan engimon baru" << endl;
    }
    catch (string err)
    {
        cout << err << endl;
    }
}

//Move Command
void Player::moveUp()
{
}

void Player::moveDown()
{
}

void Player::moveLeft()
{
}

void Player::moveRight()
{
}

//Engimon Command
void Player::showOwnedEngimon()
{
}

void Player::showStatsEngimon(Engimon a)
{
}

void Player::showActiveEngimon()
{
}

void Player::swapActiveEngimon(Engimon b)
{
}

//Skill Command
void Player::showOwnedSkill()
{
}

void Player::useOwnedSkill(Skill x, Engimon y)
{
}

//Breed
void Player::doBreed(Engimon a, Engimon b)
{
}

//Battle
void Player::doBattle()
{
}