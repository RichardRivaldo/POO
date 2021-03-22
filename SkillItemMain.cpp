#include "SkillItem.hpp"

int main(){
    // Init Skill
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};
    Skill autokill("Autokill", 100000, 1000000, elmt);

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

    return 0;
}