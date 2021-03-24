#include <string>
#include <iostream>
#include "Battle.hpp"
using namespace std;

Battle::Battle(Engimon EngimonPlayer, Engimon EngimonWild) {
    this->engimonPlayer = EngimonPlayer;
    this->engimonWild = EngimonWild;
    this->levelEngimonPlayer = EngimonPlayer.getLevel();
    this->levelEngimonWild = EngimonWild.getLevel();
    this->setMultiplierEngimon();
    this->setSkillPower();
    this->setTotalPower();

    cout << "Battle antara " << EngimonPlayer.getName() << " dan " << EngimonWild.getName() << " dimulai" << endl;
}

Battle::~Battle() {
    cout << "Battle selesai" << endl;
    if (this->winner != "") {
        cout << "Battle dimenangkan oleh " << this->winner << endl;
        cout << this->loser << " mati karena kalah melawan " << this->winner << endl;
    }
    else {
        cout << "Tidak ada yang memenangkan battle" << endl;
        cout << this->loser << " keduanya mati dalam battle" << endl;
    }
}

int Battle::getlevelEngimonPlayer() {
    return this->levelEngimonPlayer;
}

int Battle::getlevelEngimonWild() {
    return this->levelEngimonWild;
}

int Battle::getMultiplierEngimonPlayer() {
    return this->multiplierEngimonPlayer;
}

int Battle::getMultiplierEngimonWild() {
    return this->multiplierEngimonWild;
}

int Battle::getskillPowerPlayer() {
    return this->skillPowerPlayer;
}

int Battle::getskillPowerWild() {
    return this->skillPowerWild;
}

float Battle::getTotalPowerPlayer() {
    return this->totalPowerPlayer;
}

float Battle::getTotalPowerWild() {
    return this->totalPowerWild;
}

void Battle::setMultiplierEngimon() {
    int max1 = 0, max2 = 0;
    int mult1, mult2;
    vector<string> elemen1, elemen2;

    elemen1 = this->engimonPlayer.getElement();
    elemen2 = this->engimonWild.getElement();
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if ((elemen1[i] != "") && (elemen2[j] != "")) {
                mult1 = checkMultiplier(elemen1[i], elemen2[j]);
                mult2 = checkMultiplier(elemen2[j], elemen1[i]);

                if (max1 < mult1) {
                    max1 = mult1;
                }

                if (max2 < mult2) {
                    max2 = mult2;
                }
            }
        }
    }

    this->multiplierEngimonPlayer = max1;
    this->multiplierEngimonWild = max2;
}

void Battle::setSkillPower() {
    list<Skill> list1 = this->engimonPlayer.getSkill(), list2 = this->engimonWild.getSkill();
    int PowerPlayer = 0, PowerWild = 0;
    Skill skill1, skill2;

    list<Skill>::iterator it1 = list1.begin();
    list<Skill>::iterator it2 = list2.begin();
    
    for (int i = 0; i < list1.size(); i++){
        skill1 = *it1;
        PowerPlayer += skill1.getSkillPower() * skill1.getSkillMastery();
        advance(it1,1);
    }

    for (int i = 0; i < list2.size(); i++){
        skill2 = *it2;
        PowerPlayer += skill2.getSkillPower() * skill2.getSkillMastery();
        advance(it2,1);
    }

    this->skillPowerPlayer = PowerPlayer;
    this->skillPowerWild = PowerWild;
} 

void Battle::setTotalPower() {
    int total1, total2;
    total1 = this->levelEngimonPlayer * this->multiplierEngimonPlayer + this->skillPowerPlayer;
    total2 = this->levelEngimonWild * this->multiplierEngimonWild + this->skillPowerWild;

    this->totalPowerPlayer = total1;
    this->totalPowerWild = total2;
}

float Battle::checkMultiplier(string elemen1,string elemen2) {
    if (elemen1 == "fire") {
        if (elemen2 == "fire") {
            return 1;
        }
        else if (elemen2 == "water") {
            return 0;
        }
        else if (elemen2 == "electric") {
            return 1;
        }
        else if (elemen2 == "ground") {
            return 0.5;
        }
        else if (elemen2 == "ice") {
            return 2;
        }
        else {
            throw elemen2;
        }
    }
    else if (elemen2 == "water") {
        if (elemen2 == "fire") {
            return 2;
        }
        else if (elemen2 == "water") {
            return 1;
        }
        else if (elemen2 == "electric") {
            return 0;
        }
        else if (elemen2 == "ground") {
            return 1;
        }
        else if (elemen2 == "ice") {
            return 1;
        }
        else {
            throw elemen2;
        }
    }
    else if (elemen2 == "electric") {
        if (elemen2 == "fire") {
            return 1;
        }
        else if (elemen2 == "water") {
            return 2;
        }
        else if (elemen2 == "electric") {
            return 1;
        }
        else if (elemen2 == "ground") {
            return 0;
        }
        else if (elemen2 == "ice") {
            return 1.5;
        }
        else {
            throw elemen2;
        }
    }
    else if (elemen2 == "ground") {
        if (elemen2 == "fire") {
            return 1.5;
        }
        else if (elemen2 == "water") {
            return 1;
        }
        else if (elemen2 == "electric") {
            return 2;
        }
        else if (elemen2 == "ground") {
            return 1;
        }
        else if (elemen2 == "ice") {
            return 0;
        }
        else {
            throw elemen2;
        }
    }
    else if (elemen2 == "ice") {
        if (elemen2 == "fire") {
            return 0;
        }
        else if (elemen2 == "water") {
            return 1;
        }
        else if (elemen2 == "electric") {
            return 0.5;
        }
        else if (elemen2 == "ground") {
            return 2;
        }
        else if (elemen2 == "ice") {
            return 1;
        }
        else {
            throw elemen2;
        }
    }
    else {
        if ((elemen2 == "ice") || (elemen2 =="fire") || (elemen2 == "water") || (elemen2 == "electric") || (elemen2 == "ground")) {
            throw elemen1;
        }
        else {
            throw elemen1, elemen2;
        }
    }
}

void Battle::showTotalPower() {
<<<<<<< Updated upstream
    cout << endl
         << "ENGIMON 1" << endl
         << "Nama           : " << this->engimonPlayer1.getName() << endl
         << "Level          : " << this->levelEngimon1 << endl
         << "Elemen         : " << this->engimonPlayer1.getElement() << endl
         << "Total Power    : " << this->totalPower1 << endl;

    cout << endl
         << "ENGIMON 2" << endl
         << "Nama           : " << this->engimonPlayer2.getName() << endl
         << "Level          : " << this->levelEngimon2 << endl
         << "Elemen         : " << this->engimonPlayer2.getElement() << endl
         << "Total Power    : " << this->totalPower2 << endl;
=======
    cout << endl;
    cout << "ENGIMON PLAYER" << endl; 
    cout << "Nama           : " << this->engimonPlayer.getName() << endl;
    cout << "Level          : " << this->levelEngimonPlayer << endl;
    cout << "Elemen         : " << this->engimonPlayer.getElement() << endl;
    cout << "Total Power    : " << this->totalPowerPlayer << endl;;

    cout << endl;
    cout << "ENGIMON WILD" << endl;
    cout << "Nama           : " << this->engimonWild.getName() << endl;
    cout << "Level          : " << this->levelEngimonWild << endl;
    cout << "Elemen         : " << this->engimonWild.getElement() << endl;
    cout << "Total Power    : " << this->totalPowerWild << endl;;
    cout << endl;
>>>>>>> Stashed changes
}

void Battle::doBattle() {
    this->showTotalPower();

    if (this->totalPowerPlayer > this->totalPowerWild) {
        this->winner = this->engimonPlayer;
        this->loser = this->engimonWild;
    }
    else if (this->totalPowerPlayer < this->totalPowerWild) {
        this->winner = this->engimonWild;
        this->loser = this->engimonPlayer;
    }
    else {
        if (this->levelEngimonPlayer > this->levelEngimonWild) {
            this->winner = this->engimonPlayer;
            this->loser = this->engimonWild;
        }
        else if (this->levelEngimonPlayer < this->levelEngimonWild) {
            this->winner = this->engimonPlayer;
            this->loser = this->engimonWild;
        }
        else {
            if (this->)
        }
    }
}