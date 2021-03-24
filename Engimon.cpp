#include <string>
#include <list>
#include <iostream>
#include "Engimon.hpp"

using namespace std;

Engimon::Engimon(string nama, string species, vector<string> element)
{
    this->name = nama;
    this->element = element;
    this->species = species;
    this->level = 1;
    this->experience = 0;
    this->cumulativeExperience = 0;
}

Engimon::~Engimon()
{
    cout << "Engimon " << this->name << " mati karena usia tua." << endl;
}

bool Engimon::CheckDead(Engimon engimon)
{
    // Engimon akan mati jika jumlah experience kumulatif >= 3000
    if (engimon.cumulativeExperience >= 5000)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Engimon::CheckLevelUp(Engimon engimon)
{
    // Level up akan terjadi setiap experience mencapai lebih dari 100
    if (engimon.experience >= 100)
    {
        this->level += 1;
        this->experience -= 100;
    }
}

const Skill Engimon::getHighestMastery(){
    int highest = -9999;
    Skill highestMasterySkill;
    for(list<Skill>::iterator iter = skill.begin(); iter != skill.end(); iter++){
        if(highest <= (*iter).getSkillMastery()){
            highest = (*iter).getSkillMastery();
            highestMasterySkill = (*iter);
        }
    }
    return highestMasterySkill;
}

void Engimon::showStats() {
    cout << "Nama : " << this->getName() << endl;
    cout << "Spesies : " << this->getSpecies() << endl;

    list<Skill>::iterator it;
    cout << "List Skills : ";
    for (it = this->skill.begin(); it != this->skill.end(); it++) {
        cout << it->getSkillName() << " ";
    }
    cout << endl;

    cout << "Element : " << element[0] << "/" << element[1] << endl;
    cout << "Level : " << this->getLevel() << endl;
    cout << "Experience : " << this->getExperience() << endl;
    cout << "Cumulative experience : " << this->getCumulativeExperience() << endl;
}

string Engimon::getName() { return this->name; }
string Engimon::getSpecies() { return this->species; }
vector<string> Engimon::getElement() { return this->element; }
int Engimon::getLevel() { return this->level; }
int Engimon::getExperience() { return this->experience; }
int Engimon::getCumulativeExperience() { return this->cumulativeExperience; }