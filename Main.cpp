#include "Player.hpp"
#include "Engimon.hpp"
#include "Inventory.hpp"
#include "Skill.hpp"
#include "SkillCat.hpp"
#include "SkillItem.hpp"
#include "Map.hpp"
#include <string>

using namespace std;

//Define elements
const string FIRE = "Fire";
const string WATER = "Water";
const string ELECTRIC = "Electric";
const string GROUND = "Ground";
const string ICE = "Ice";
// enum Elements {Fire, Water, Electric, Ground, Ice};

void createSkillsandSkillItems(){   
    // Unique Skill
    UniqueSkill Fireball("Fireball", 20, 1, vector<string> {FIRE}, ada spesies dsni);
    UniqueSkill Watercut("Watercut", 20, 1, vector<string> {WATER});
    UniqueSkill Thunderslash("Thunderslash", 20, 1, vector<string> {ELECTRIC});
    UniqueSkill Earthquake("Earthquake", 20, 1, vector<string> {GROUND});
    UniqueSkill Blizzard("Blizzard", 20, 1, vector<string> {ICE});

    // Regular Skill
    Skill CrimsonFire("Crimson Fire", 10, 1, vector<string> {FIRE});
    Skill Flamethrower("Flame Thrower", 12, 1, vector<string> {FIRE, ELECTRIC});
    Skill HeatWave("Heat Wave", 14, 1, vector<string> {FIRE});
    Skill LittleWanderers("Little Wanderers", 10, 1, vector<string> {WATER});
    Skill DancingRain("Dancing Rain", 12, 1, vector<string> {WATER, ICE});
    Skill Tsunami("Tsunami", 14, 1, vector<string> {WATER});
    Skill PlasmaFist("PlasmaFist", 10, 1, vector<string> {ELECTRIC});
    Skill PikaPapow("Pika Papow", 12, 1, vector<string> {ELECTRIC});
    Skill StokedSparksurfer("Stoked Sparksurfer", 14, 1, vector<string> {ELECTRIC, GROUND});
    Skill SpikesOfDeath("Spikes of Death", 10, 1, vector<string> {GROUND});
    Skill ScorchingSands("ScorchingSands", 12, 1, vector<string> {GROUND, FIRE});
    Skill TempestOfBlades("Tempest of Blades", 14, 1, vector<string> {GROUND});
    Skill SubzeroSlammer("Subzero Slammer", 10, 1, vector<string>{ICE, WATER});
    Skill IceSpearhead("Ice Spearhead", 12, 1, vector<string>{ICE});
    Skill Avalanche("Avalanche", 14, 1, vector<string>{ICE});

    // Special Skill
    SpecialSkill Hellfire("Hellfire", 65, 1, vector<string>{FIRE}, 10);
    SpecialSkill ChasmTrample("Chasm Trample", 70, 1, vector<string>{FIRE}, 10);
    SpecialSkill BubbleBeam("Bubble Beam", 60, 1, vector<string>{WATER}, 10);
    SpecialSkill PoseidonWrath("Poseidon's Wrath", 75, 1, vector<string>{WATER}, 10);
    SpecialSkill BOLT("10,000,000 Volt Thunderbolt", 75, 1, vector<string>{ELECTRIC}, 10);
    SpecialSkill ForkedLightning("Forked Lightning", 60, 1, vector<string>{ELECTRIC}, 10);
    SpecialSkill Void("Void", 70, 1, vector<string> {GROUND}, 10);
    SpecialSkill ThornedRose("Thorned Rose", 75, 1, vector<string>{GROUND}, 10);
    SpecialSkill CastleOfIce("Castle of Ice", 55, 1, vector<string>{ICE}, 10);
    SpecialSkill Avalon("Avalon", 80, 1, vector<string>{ICE}, 10);

    // Skill Items
    SkillItem 
}

Engimon initializeStarterEngimon(int pilihan) {
    string nama;
    while (true) {
        if (pilihan == 1) {
            cout << "Masukkan nama Firemon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Firemon", vector<string>{FIRE, FIRE});    
            return starterEngimon;
        } 
        else if (pilihan == 2) {
            cout << "Masukkan nama Watermon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Watermon", {WATER, WATER});
            return starterEngimon;
        } else if (pilihan == 3) {
            cout << "Masukkan nama Electricmon mu : ";
            cin >> nama; 
            cout << endl;
            Engimon starterEngimon(nama, "Electromon", {ELECTRIC, ELECTRIC}); 
            return starterEngimon;
        } else if (pilihan == 4) {
            cout << "Masukkan nama Groundmon mu : ";
            cin >> nama;  
            cout << endl;
            Engimon starterEngimon(nama, "Groundmon", {GROUND, GROUND});
            return starterEngimon;
        } else if (pilihan == 5) {
            cout << "Masukkan nama Icemon mu : ";
            cin >> nama;  
            cout << endl;
            Engimon starterEngimon(nama, "Icemon", {ICE, ICE});
            return starterEngimon;
        } else {
            cout << "Masukan tidak valid, coba lagi" << endl;
        }
    }
}

int main(){
    int pilihan;
    cin >> pilihan;
    
    createSkillsandSkillItems();
    Engimon firstEngimon = initializeStarterEngimon(pilihan);
    
}