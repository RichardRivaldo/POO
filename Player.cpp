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

void Player::learnSkill(string SkillName)
{
    int i = 0;
    bool found = false;
    SkillItem newSkillItem;
    Skill newSkill;

    while (i < this->inventorySkillItem.getInventorySize() && !found)
    {
        if (this->inventorySkillItem.getInventoryVector()[i].getSkill().getSkillName() == SkillName)
        {
            found = true;
            newSkillItem = this->inventorySkillItem.getInventoryVector()[i];
            newSkill = this->inventorySkillItem.getInventoryVector()[i].getSkill();
        }
    }

    if (found != true)
    {
        cout << "Tidak ada Skill Item untuk Skill ini di dalam Inventory!" << endl;
        return;
    }
    else
    {
        int skillIdx;
        string choice;
        if (this->ActiveEngimon.getSkill().size() == 4)
        {
            cout << "Engimon kamu sudah memiliki 4 buah Skill." << endl;
            cout << "Apakah kamu ingin mengganti salah satu Skill tersebut? (Y/N)";
            cin >> choice;

            if (choice == "Y")
            {
                cout << "Pilih nomor Skill yang ingin kamu ganti: ";
                cin >> skillIdx;
                this->replaceSkillItem(skillIdx, newSkill);
                cout << "Skill berhasil ditambahkan!" << endl;

                // Remove or Decrease Item from Inventory here
                if (newSkillItem.getAmount() > 1)
                    this->inventorySkillItem.getInventoryVector()[i].decItemAmount(); // ini ngurangin di skill item
                else
                    this->inventorySkillItem.removeItem(i);          // ini buang skill dari invent
                this->inventorySkillItem.decrementCurrentCapacity(); // ini ngurangin di invent
            }
            else
            {
                cout << "Penggunaan Skill Item Dibatalkan!" << endl;
                return;
            }
        }
    }
}

void Player::replaceSkillItem(int replacedSkillIdx, Skill newSkill)
{
    if (replacedSkillIdx - 1 > this->ActiveEngimon.getSkill().size() - 1)
    {
        cout << "Indeks Invalid! Pergantian Gagal" << endl;
        return;
    }
    else
    {
        this->ActiveEngimon.RemoveSkillByIdx(replacedSkillIdx);
        this->ActiveEngimon.AddSkill(newSkill);
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