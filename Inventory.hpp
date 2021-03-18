#include <iostream>
#include <list>
#include "SkillItem.hpp"
#include "Engimon.hpp"

using namespace std;

class Inventory {
    protected :
        list<Engimon> list_engimon;
        list<SkillItem> list_skillItem;
        int max_capacity;
        int indexEngimonAktif;
};