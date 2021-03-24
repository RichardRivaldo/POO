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
    Engimon(string nama, string species, vector<string> element);
    Engimon(const Engimon& engimon);
    ~Engimon();
    Engimon& operator=(const Engimon&);

    bool CheckLevelUp(Engimon engimon);
    bool CheckDead(Engimon engimon);
    const Skill getHighestMastery();
    void showStats();
    void AddSkill(Skill skill);

    //Getters
    string getName();
    string getSpecies();
    vector<string> getElement();
    int getLevel();
    int getExperience();
    int getCumulativeExperience();
    list<Skill> getSkill();
};