#include "SkillItem.hpp"

SkillItem::SkillItem(){
    Skill defSkill;
    skillItem.first = defSkill;
    skillItem.second = 1;
}

SkillItem::SkillItem(Skill skill, int amount){
    skillItem.first = skill;
    skillItem.second = amount;
}

void SkillItem::addItemAmount(int amount){this->skillItem.second += amount;}

void SkillItem::decItemAmount(int amount){this->skillItem.second -= amount;}

void SkillItem::skillItemInfo(){
    cout << "Item of Skill   : " << this->skillItem.first.getSkillName() << endl;
    cout << "Amount of Items : " << this->skillItem.second << endl;
}