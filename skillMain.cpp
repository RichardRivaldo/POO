#include "Skill.hpp"

int main(){
    // Init ELements
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};

    // Construct the object
    Skill s1;
    Skill s2("Autokill", 100000, 1000000, "God", elmt);

    // Print Skill Info
    s1.skillInfo();
    cout << "--------------------" << endl;
    s2.skillInfo();
    cout << "--------------------" << endl;

    // Method Check: isSkillLearnable
    if(!s2.isSkillLearnable("Dirt", "God")){
        cout << "Not Learnable" << endl;
    }
    if(s2.isSkillLearnable("Fire", "God")){
        cout << "Learnable" << endl;
    }
    cout << "--------------------" << endl;

    // Method Check: getSkillName
    cout << s2.getSkillName() << endl;
    cout << "--------------------" << endl;

    // Method Check: masteryLevelUp
    s2.masteryLevelUp(11111);

    // Check modified
    s2.skillInfo();
    cout << "--------------------" << endl;

    // Getters Check
    cout << s2.getSkillName() << endl;
    cout << s2.getSkillMastery() << endl;
    cout << s2.getSkillPower() << endl;
    
    vector<string> elmts = s2.getSuitableElmt();
    if(elmts.size() == 4){
        cout << "Assigned" << endl;
    }

    return 0;
}