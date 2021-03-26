#include "Player.hpp"
#include "Engimon.hpp"
#include "Inventory.hpp"
#include "Skill.hpp"
#include "SkillCat.hpp"
#include "SkillItem.hpp"
#include "Map.hpp"
#include "Battle.hpp"
#include "SkillandElementsInit.cpp"
#include <string>

using namespace std;

Engimon initializeStarterEngimon(int pilihan, Skill Skill1, Skill Skill2, Skill Skill3, Skill Skill4, Skill Skill5) { 
    string nama;
    while (true) {
        if (pilihan == 1) {
            cout << "Masukkan nama Firemon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Firemon", vector<string>{FIRE, FIRE});    
            starterEngimon.AddSkill(Skill1);
            return starterEngimon;
        } 
        else if (pilihan == 2) {
            cout << "Masukkan nama Watermon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Watermon", {WATER, WATER});
            starterEngimon.AddSkill(Skill2);
            return starterEngimon;
        } else if (pilihan == 3) {
            cout << "Masukkan nama Electricmon mu : ";
            cin >> nama; 
            cout << endl;
            Engimon starterEngimon(nama, "Electromon", {ELECTRIC, ELECTRIC});
            starterEngimon.AddSkill(Skill3); 
            return starterEngimon;
        } else if (pilihan == 4) {
            cout << "Masukkan nama Groundmon mu : ";
            cin >> nama;  
            cout << endl;
            Engimon starterEngimon(nama, "Groundmon", {GROUND, GROUND});
            starterEngimon.AddSkill(Skill4);
            return starterEngimon;
        } else if (pilihan == 5) {
            cout << "Masukkan nama Icemon mu : ";
            cin >> nama;  
            cout << endl;
            Engimon starterEngimon(nama, "Icemon", {ICE, ICE});
            starterEngimon.AddSkill(Skill5);
            return starterEngimon;
        } else {
            cout << "Masukan tidak valid, coba lagi" << endl;
        }
    }
}

int main(){
    // Init Skills
    vector<Skill> fireSkills = createFireSkills();
    vector<Skill> waterSkills = createWaterSkills();
    vector<Skill> electricSkills = createElectricSkills();
    vector<Skill> groundSkills = createGroundSkills();
    vector<Skill> iceSkills = createIceSkills();

    // Init Skill Items
    vector <SkillItem> fireItems = createSkillItem(fireSkills);
    vector <SkillItem> waterItems = createSkillItem(waterSkills);
    vector <SkillItem> electricItems = createSkillItem(electricSkills);
    vector <SkillItem> groundItems = createSkillItem(groundSkills);
    vector <SkillItem> iceItems = createSkillItem(iceSkills);

    // Init Map Items
    Map map = Map();
    
    int pilihan;
    cin >> pilihan;
    
    Engimon firstEngimon = initializeStarterEngimon(pilihan, Fireball, Watercut, Thunderslash, Earthquake, Blizzard);
    
    //Tambahin firstEngimon ke inventory player

    return 0;
}