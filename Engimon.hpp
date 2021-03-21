#include <string>
#include <list>
#include <iostream>
#include "Skill.hpp"

using namespace std;

class Engimon{
    protected:
        string name;
        string species;
        list<Skill> skill;
        string element;
        int level;
        int experience;
        int cumulativeExperience;

    public :
        Engimon(string nama, list<Skill> skills, string element);
        ~Engimon();

        bool CheckLevelUp(Engimon engimon);
        bool CheckDead(Engimon engimon);
};