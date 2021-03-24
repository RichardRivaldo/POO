#include <string>
#include <iostream>
#include "Battle.hpp"
using namespace std;

Battle::Battle(Engimon engimon1, Engimon engimon2) {
    this->engimonPlayer1 = engimon1;
    this->engimonPlayer2 = engimon2;
    this->levelEngimon1 = engimon1.getLevel();
    this->levelEngimon2 = engimon2.getLevel();
    this->setMultiplierEngimon();
    this->setSkillPower();
    this->setTotalPower();

    cout << "Battle antara " << engimon1.getName() << " dan " << engimon2.getName() << " dimulai" << endl;
}

Battle::~Battle() {
    cout << "Battle selesai" << endl;
    cout << "Battle dimenangkan oleh " << this->winner << endl;
    cout << this->loser << " mati karena kalah melawan " << this->winner << endl;
}

int Battle::getLevelEngimon1() {
    return this->levelEngimon1;
}

int Battle::getLevelEngimon2() {
    return this->levelEngimon2;
}

int Battle::getMultiplierEngimon1() {
    return this->multiplierEngimon1;
}

int Battle::getMultiplierEngimon2() {
    return this->multiplierEngimon2;
}

int Battle::getskillPower1() {
    return this->skillPower1;
}

int Battle::getskillPower2() {
    return this->skillPower2;
}

void Battle::setMultiplierEngimon() {
    int max1 = 0, max2 = 0;
    int mult1, mult2;
    vector<string> elemen1, elemen2;

    elemen1 = elementSplitter(this->engimonPlayer1.getElement());
    elemen2 = elementSplitter(this->engimonPlayer2.getElement());
    
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

    this->multiplierEngimon1 = max1;
    this->multiplierEngimon2 = max2;
}

void Battle::setSkillPower() {
    list<Skill> list1 = engimonPlayer1.getSkill(), list2 = engimonPlayer2.getSkill();
    int power1 = 0, power2 = 0;
    Skill skill1, skill2;

    list<Skill>::iterator it1 = list1.begin();
    list<Skill>::iterator it2 = list2.begin();
    
    for (int i = 0; i < list1.size(); i++){
        skill1 = *it1;
        power1 += skill1.getSkillPower() * skill1.getSkillMastery();
        advance(it1,1);
    }

    for (int i = 0; i < list2.size(); i++){
        skill2 = *it2;
        power1 += skill2.getSkillPower() * skill2.getSkillMastery();
        advance(it2,1);
    }

    this->skillPower1 = power1;
    this->skillPower2 = power2;
}

void Battle::setTotalPower() {
    int total1, total2;
    total1 = this->levelEngimon1 * this->multiplierEngimon1 + this->skillPower1;
    total2 = this->levelEngimon2 * this->multiplierEngimon2 + this->skillPower2;

    this->totalPower1 = total1;
    this->totalPower2 = total2;
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
    }
}

void Battle::showTotalPower() {
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
}

vector<string> elementSplitter(string element) {
    string elemen1 = "", elemen2 = "";
    vector<string> elemen(2);
    int garing;

    for (int i = 0; i < element.length(); i++) {
        if (element[i] == '/') {
            garing = i;
        }
    }

    for (int i = 0; i < element.length(); i++) {
        if (i < garing) {
            elemen1 += element[i];
        }
        else if (i > garing) {
            elemen2 += element[i];
        }
    }

    elemen[0] = elemen1;
    elemen[1] = elemen2;

    return elemen;
}