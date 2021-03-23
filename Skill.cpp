#include "Skill.hpp"

using namespace std;

Skill::Skill(): skillName("Skill"), basePower(0), masteryLevel(0){
    vector<string> Elements;
}

Skill::Skill(string name, int power, int mastery, vector<string> Elmts):skillName(name), 
                                                                        basePower(power), 
                                                                        masteryLevel(mastery),
                                                                        Elements(Elmts){}

// Skill::~Skill(){
//     // Output Message
//     cout << this->skillName << " is deleted successfully." << endl;
// }

const bool Skill::isSkillLearnable(string engimonElmt){
    // STD::find
    return (find(this->Elements.begin(), this->Elements.end(), engimonElmt) != Elements.end());
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

const int Skill::getSkillMaster(){
    return this->masteryLevel;
}

const vector<string> Skill::getSuitableElmt(){
    return this->Elements;
}