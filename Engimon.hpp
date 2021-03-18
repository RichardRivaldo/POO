#include <string>
#include <list>
#include <iostream>
#include "Skill.hpp"

using namespace std;

class Engimon{
    private:
        string name;
        list<Skill> skill;
        string* elements;
        int level;
        int experience;
        int cumulative_Experience;
};

