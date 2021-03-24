#ifndef __SKILLITEM__HPP__
#define __SKILLITEM__HPP__
#include <iostream>
#include <utility>
#include "Skill.hpp"

using namespace std;

class SkillItem
{
protected:
    // Map to contain skill item and number of the items
    pair<Skill, int> skillItem;

public:
    // Default Constructor, fill with default value
    SkillItem();
    // User-Defined Constructor
    SkillItem(Skill skill, int amount);

    // Methods
    void addItemAmount(int amount = 1);
    void decItemAmount(int amount = 1);
    const void skillItemInfo();

    // Getter
    const Skill getSkill();
    const int getAmount();
};

#endif