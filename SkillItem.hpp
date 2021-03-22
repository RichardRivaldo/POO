#include <iostream>
#include <list>
#include "Skill.hpp"

using namespace std;

class SkillItem : public Skill
{
private:
    int jumlah;

public:
    void inc_jumlah() { this->jumlah++; }
};