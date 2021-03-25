#include "SkillItem.hpp"
#include "SkillCat.hpp"

int main(){
    // Init Skill
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};
    Skill autokill("Autokill", 100000, elmt, 1000000);

    // Skill Item
    SkillItem defItem;
    SkillItem autokillItem(autokill, 20);

    // Get Skill Item Information
    cout << "---------------------" << endl;
    defItem.skillItemInfo();
    autokillItem.skillItemInfo();
    cout << "---------------------" << endl;

    // Decrease and Increase Amount
    defItem.addItemAmount(100);
    autokillItem.decItemAmount();

    // Get Skill Item Information
    cout << "---------------------" << endl;
    defItem.skillItemInfo();
    autokillItem.skillItemInfo();
    cout << "---------------------" << endl;

    // Unique and Special Skill Item
    SpecialSkill special("BOOM!", 100000, elmt, 1);
    UniqueSkill unique("Endgame", 100000, elmt, "God");

    SkillItem specialItem(special);
    SkillItem uniqueItem(unique);

    // Check
    cout << "---------------------" << endl;
    specialItem.skillItemInfo();
    uniqueItem.skillItemInfo();
    cout << "---------------------" << endl;

    return 0;
}