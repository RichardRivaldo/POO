#include "SkillItem.hpp"

SkillItem::SkillItem()
{
    Skill defSkill;
    this->skillItem.first = defSkill;
    this->skillItem.second = 1;
}

SkillItem::SkillItem(Skill skill, int amount)
{
    this->skillItem.first = skill;
    this->skillItem.second = amount;
}

void SkillItem::addItemAmount(int amount) { this->skillItem.second += amount; }

void SkillItem::decItemAmount(int amount) { this->skillItem.second -= amount; }

const void SkillItem::skillItemInfo()
{
    cout << "Item of Skill   : " << this->skillItem.first.getSkillName() << endl;
    cout << "Amount of Items : " << this->skillItem.second << endl;
}

const Skill SkillItem::getSkill()
{
    return this->skillItem.first;
}
const int SkillItem::getAmount()
{
    return this->skillItem.second;
}