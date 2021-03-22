#include <string>
#include <list>
#include <iostream>
#include "Engimon.hpp"

using namespace std;

Engimon::Engimon(string nama, string species, list<Skill> skills, string element)
{
    this->name = nama;
    this->skill = skills;
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
    if (engimon.cumulativeExperience >= 3000)
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

string Engimon::getName() { return this->name; }