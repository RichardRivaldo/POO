#include "Skill.cpp"

int main(){
    // Init ELements
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};

    // Construct the object
    Skill s1;
    Skill s2("Autokill", 100000, 1000000, elmt);

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

    return 0;
}