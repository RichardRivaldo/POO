#include "Skill.hpp"

using namespace std;

Skill::Skill(): skillName("Skill"), basePower(0), masteryLevel(1), Species("Species"){
    vector<string> Elements;
}

Skill::Skill(string name, int power, int mastery, string species, vector<string> Elmts):skillName(name), 
                                                                                        basePower(power), 
                                                                                        masteryLevel(mastery),
                                                                                        Elements(Elmts),
                                                                                        Species(species){}

// Skill::~Skill(){
//     // Output Message
//     cout << this->skillName << " is deleted successfully." << endl;
// }

const bool Skill::isSkillLearnable(string engimonElmt, string species){
    // STD::find and check if the species of the engimon can learn the skill
    return (find(this->Elements.begin(), this->Elements.end(), engimonElmt) != Elements.end() && species == this->Species);
}

void Skill::masteryLevelUp(int bpIncrease){
    // Increase mastery level and add BP
    this->masteryLevel++;
    this->basePower += bpIncrease;
}

const void Skill::skillInfo(){
    // Output attributes info
    cout << "Skill Name         : " << this->skillName << endl;
    cout << "Base Power         : " << this->basePower << endl;
    cout << "Master Level       : " << this->masteryLevel << endl;
    cout << "Skill of Species   : " << this->Species << endl;
    cout << "Available Elements : [";

    // Iterate through vector with iterator
    for(vector<string>::iterator iter = Elements.begin(); iter != Elements.end(); iter++){
        cout << *iter;

        if(next(iter) != Elements.end()){
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

const string Skill::getSkillName(){
    return this->skillName;
}

const int Skill::getSkillPower(){
    return this->basePower;
}

const int Skill::getSkillMastery(){
    return this->masteryLevel;
}

const vector<string> Skill::getSuitableElmt(){
    return this->Elements;
}

const string Skill::getSkillSpecies(){
    return this->Species;
}