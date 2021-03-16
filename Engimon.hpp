#include <string>
#include <list>
#include "Skill.hpp"

using namespace std;

class Engimon{
    private:
    string Name;
    list<Skill> Skill;
    string* Elements;
    int Level;
    int Experience;
    int Cumulative_Experience;
};

