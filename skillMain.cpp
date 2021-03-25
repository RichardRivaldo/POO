#include "SkillCat.hpp"

int main(){
    // Init ELements
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};

    // Construct the object
    Skill s1;
    Skill s2("Autokill", 100000, elmt);

    // Print Skill Info
    s1.skillInfo();
    cout << "--------------------" << endl;
    s2.skillInfo();
    cout << "--------------------" << endl;

    // Method Check: isSkillLearnable
    if(!s2.isSkillLearnable("Dirt")){
        cout << "Not Learnable" << endl;
    }
    if(s2.isSkillLearnable("Fire")){
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

    cout << "--------------------" << endl;

    // Unique Skill
    UniqueSkill unique("Endgame", 100000, elmt, "God");
    unique.skillInfo();
    cout << unique.getSkillSpecies() << endl;

    cout << "--------------------" << endl;

    // Special Skill
    SpecialSkill special("BOOM!", 100000, elmt, 1);
    special.skillInfo();
    cout << special.getAddPower() << endl;
    cout << special.totalDamage() << endl;
    cout << "--------------------" << endl;
    return 0;
}