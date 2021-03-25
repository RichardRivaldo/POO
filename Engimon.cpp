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

Engimon::Engimon(const Engimon& engimon)
{
    this->name = engimon.name;
    this->element = engimon.element;
    this->species = engimon.species;
    this->level = engimon.level;
    this->experience = engimon.experience;
    this->cumulativeExperience = engimon.cumulativeExperience;
}


Engimon::~Engimon()
{
    cout << "Engimon " << this->name << " mati karena usia tua." << endl;
}

Engimon& Engimon::operator=(const Engimon& engimon)
{
    this->name = engimon.name;
    this->element = engimon.element;
    this->species = engimon.species;
    this->level = engimon.level;
    this->experience = engimon.experience;
    this->cumulativeExperience = engimon.cumulativeExperience;
    return *this;
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

void Engimon::AddSkill(Skill skill) {
    this->skill.push_back(skill);
}

Engimon Engimon::breed(Engimon engimon1, Engimon engimon2) {
    if (engimon1.getElement() != engimon2.getElement()){
        cout << "Tidak bisa melakukan cross breeding";
    } else if (engimon1.getLevel() < 30 || engimon2.getLevel() < 30) {
        cout << "Engimon parent belum cukup umur";
    } else {
        string nama;
        cout << "Masukkan nama Engimon mu : ";
        cin >> nama;
        cout << endl;
        Engimon engimonAnak = Engimon(nama, engimon1.species, engimon1.element);
        list<Skill> tmpskill = engimon1.getSkill();
        tmpskill.merge(engimon2.getSkill());
    }
}

bool Engimon::isSkillSizeValid(Engimon engimon) {
    return (engimon.skill.size() <= 4);
}

string Engimon::getName() { return this->name; }
string Engimon::getSpecies() { return this->species; }
vector<string> Engimon::getElement() { return this->element; }
int Engimon::getLevel() { return this->level; }
int Engimon::getExperience() { return this->experience; }
int Engimon::getCumulativeExperience() { return this->cumulativeExperience; }
list<Skill> Engimon::getSkill() { return this->skill; }