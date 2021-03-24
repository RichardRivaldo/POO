#include "SkillCat.hpp"

// Unique Skill Definitions
UniqueSkill::UniqueSkill(): Skill(), Species("Species"){}

UniqueSkill::UniqueSkill(string name, int basePower, int mastery, vector<string> elmts, string species): Skill(name, basePower, mastery, elmts),
                                                                                                         Species(species){}

const bool UniqueSkill::isSkillLearnable(string engimonElmt, string species){
    return(Skill::isSkillLearnable(engimonElmt) && species == this->Species);
}

const void UniqueSkill::skillInfo(){
    Skill::skillInfo();
    cout << "Unique to Species  : " << this->Species << endl;
}

const string UniqueSkill::getSkillSpecies(){
    return this->Species;
}

// Special Skill Definitions
SpecialSkill::SpecialSkill(): Skill(), additionalPower(0){}

SpecialSkill::SpecialSkill(string name, int basePower, int mastery, vector<string> elmts, int addPower): Skill(name, basePower, mastery, elmts),
                                                                                                         additionalPower(addPower){}

const int SpecialSkill::totalDamage(){
    return(this->basePower + this->additionalPower);
}

const void SpecialSkill::skillInfo(){
    Skill::skillInfo();
    cout << "Additional Power   : " << this->additionalPower << endl;
}

const int SpecialSkill::getAddPower(){
    return this->additionalPower;
}