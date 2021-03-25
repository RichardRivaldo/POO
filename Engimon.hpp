#ifndef ENGIMON_HPP
#define ENGIMON_HPP
#include <string>
#include <list>
#include <iostream>
#include "Skill.hpp"

using namespace std;

class Engimon
{
protected:
    string name;
    string species;
    list<Skill> skill;
    vector<string> element;
    int level;
    int experience;
    int cumulativeExperience;

public:
    Engimon();
    Engimon(string nama, string species, vector<string> element);
    Engimon(const Engimon& engimon);
    ~Engimon();
    Engimon& operator=(const Engimon&);

    bool CheckLevelUp(Engimon engimon);
    bool CheckDead(Engimon engimon);
    const Skill getHighestMastery();
    void showStats();
    void AddSkill(Skill skill);
    void RemoveSkillByIdx(int skillIdx);
    void RemoveSkill(Skill skill);
    bool containsSkill(list<Skill> listSkill, string skillName);

    Engimon breed(Engimon engimon1, Engimon engimon2);
    bool isSkillSizeValid(Engimon engimon);

    //Getters
    string getName();
    string getSpecies();
    vector<string> getElement();
    int getLevel();
    int getExperience();
    int getCumulativeExperience();
    list<Skill> getSkill();

    //Setters
    void setLevel(int level); // Used for debugging purposes
};
#endif