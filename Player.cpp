#include <string>
#include <iostream>
#include "Player.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"

using namespace std;

Player::Player(Position pos, Engimon activeEngi, Inventory<Engimon> inventoryEngimon, Inventory<SkillItem> inventorySkillItem)
{
    this->pos = pos;
    this->ActiveEngimon = activeEngi;
    this->inventoryEngimon = inventoryEngimon;
    this->inventorySkillItem = inventorySkillItem;
    this->map = Map();
}

// Inventory
void Player::addSkillItem(SkillItem newSkillItem)
{
    try
    {
        int i = 0;
        while (i < this->inventorySkillItem.getInventorySize())
        {
            if (this->inventorySkillItem.getInventoryVector()[i].getSkill().getSkillName() == newSkillItem.getSkill().getSkillName())
            {
                cout << "Menambahkan Skill Item untuk " << newSkillItem.getSkill().getSkillName() << endl;
                this->inventorySkillItem.getInventoryVector()[i].addItemAmount();
                return;
            }
            i++;
        }

        cout << "Berhasil menambahkan skill item baru!" << endl;
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
    if(this->map.getplayerPositionY()-1>=0){
        Position prevpos = Position(map.getplayerPosition());
        this->map.setplayerPosition(this->map.getplayerPositionX(), this->map.getplayerPositionY()-1);
        this->map.setactiveEngimonPosition(prevpos.getXCoordinate(), prevpos.getYCoordinate());
    }
    else{
        throw "Invalid move Player Up (Mentok)";
    }
}

void Player::moveDown()
{
    if(this->map.getplayerPositionY()+1 <= map.getymax()){
        Position prevpos = Position(map.getplayerPosition());
        this->map.setplayerPosition(this->map.getplayerPositionX(), this->map.getplayerPositionY()+1);
        this->map.setactiveEngimonPosition(prevpos.getXCoordinate(), prevpos.getYCoordinate());
    }else{
        throw "Invalid move Player Down (Mentok)";
    }
}

void Player::moveLeft()
{
    if(this->map.getplayerPositionX()-1 >= 0){
        Position prevpos = Position(map.getplayerPosition()); 
        this->map.setplayerPosition(this->map.getplayerPositionX()-1, this->map.getplayerPositionY());
        this->map.setactiveEngimonPosition(prevpos.getXCoordinate(), prevpos.getYCoordinate());
    }else{
        throw "Invalid move Player Left (Mentok)";
    }
}

void Player::moveRight()
{
    if(this->map.getplayerPositionX()+1 <= map.getxmax()){
        Position prevpos = Position(map.getplayerPosition());
        this->map.setplayerPosition(this->map.getplayerPositionX()+1, this->map.getplayerPositionY());
        this->map.setactiveEngimonPosition(prevpos.getXCoordinate(), prevpos.getYCoordinate());
    }else{
        throw "Invalid move Player Right (Mentok)";
    }
}

//Engimon Command
void Player::showOwnedEngimon()
{
    if (this->inventoryEngimon.getInventorySize() == 0)
        cout << "Tidak ada engimon di inventory" << endl;
    else
    {
        cout << "Daftar engimon yang dimiliki" << endl;
        for (Engimon engimon : this->inventoryEngimon.getInventoryVector())
        {
            engimon.showStats();
            cout << endl;
        }
    }
}

void Player::showStatsEngimon(Engimon engimon)
{
    cout << "Engimon stats: " << endl;
    engimon.showStats();
}

void Player::showActiveEngimon()
{
    cout << "Engimon yang sedang aktif berpetualang: " << endl;
    this->ActiveEngimon.showStats();
}

void Player::swapActiveEngimon(string newEngimonName)
{
    for (int i = 0; i < this->inventoryEngimon.getInventorySize(); i++)
        if (this->inventoryEngimon.getInventoryVector()[i].getName() == newEngimonName)
        {
            Engimon temp = this->ActiveEngimon;
            this->ActiveEngimon = this->inventoryEngimon.getInventoryVector()[i];
            this->inventoryEngimon.getInventoryVector()[i] = temp;
            cout << "Success change active engimon" << endl;
            break;
        }
}

//Skill Command
void Player::showOwnedItems()
{
    if (this->inventorySkillItem.getInventorySize() == 0)
    {
        cout << "Tidak ada Skill Items di Inventory!";
    }
    else
    {
        cout << "Daftar Skill Items yang dimiliki: " << endl;

        for (SkillItem items : this->inventorySkillItem.getInventoryVector())
        {
            items.skillItemInfo();
        }
    }
}

//Breed
void Player::doBreed(string firstEngimonName, string secondEngimonName)
{
    int firstEngimonIdx = -1, secondEngimonIdx = -1;
    for (int i = 0; i < this->inventoryEngimon.getInventorySize(); i++)
    {
        if (this->inventoryEngimon.getInventoryVector()[i].getName() == firstEngimonName && firstEngimonIdx == -1)
            firstEngimonIdx = i;
        else if (this->inventoryEngimon.getInventoryVector()[i].getName() == secondEngimonName && secondEngimonIdx == -1)
            secondEngimonIdx = i;
    }

    cout << "Breeding...." << endl;
    if (firstEngimonIdx != -1 && secondEngimonIdx != -1)
    {
        Engimon engimonParent1 = this->inventoryEngimon.getInventoryVector()[firstEngimonIdx];
        Engimon engimonParent2 = this->inventoryEngimon.getInventoryVector()[secondEngimonIdx];
        Engimon engimonChild = engimonParent1.breed(engimonParent2);

        this->addEngimon(engimonChild);
    }
    else
    {
        cout << "No corresponding Engimons in your Inventory!" << endl;
        cout << "Breeding failed" << endl;
    }
}

//Battle
void Player::doBattle()
{
}