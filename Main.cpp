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

Engimon initializeStarterEngimon(int pilihan) { 
    string nama;
    createSkillsandSkillItems();
    while (true) {
        if (pilihan == 1) {
            cout << "Masukkan nama Firemon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Firemon", vector<string>{FIRE, FIRE});    
            starterEngimon.AddSkill(Fireball);
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
    // Unique Skill
    UniqueSkill Fireball("Fireball", 20, 1, vector<string> {FIRE}, "Firemon");
    UniqueSkill Watercut("Watercut", 20, 1, vector<string> {WATER}, "Watermon");
    UniqueSkill Thunderslash("Thunderslash", 20, 1, vector<string> {ELECTRIC}, "Electromon");
    UniqueSkill Earthquake("Earthquake", 20, 1, vector<string> {GROUND}, "Groundmon");
    UniqueSkill Blizzard("Blizzard", 20, 1, vector<string> {ICE}, "Icemon");

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
    SkillItem FireballItem(Fireball, 1);
    SkillItem WatercutItem(Watercut, 1);
    SkillItem ThunderslashItem(Thunderslash, 1);
    SkillItem EarthquakeItem(Earthquake, 1);
    SkillItem BlizzardItem(Blizzard, 1);
    SkillItem CrimsonFireItem(CrimsonFire, 1);
    SkillItem FlamethrowerItem(Flamethrower, 1);
    SkillItem HeatWaveItem(HeatWave, 1);
    SkillItem LittleWanderersItem(LittleWanderers, 1);
    SkillItem DancingRainItem(DancingRain, 1);
    SkillItem TsunamiItem(Tsunami, 1);
    SkillItem PlasmaFistItem(PlasmaFist, 1);
    SkillItem PikaPapowItem(PikaPapow, 1);
    SkillItem StokedSparksurferItem(StokedSparksurfer, 1);
    SkillItem SpikesOfDeathItem(SpikesOfDeath, 1);
    SkillItem ScorchingSandsItem(ScorchingSands, 1);
    SkillItem TempestOfBladesItem(TempestOfBlades, 1);
    SkillItem SubzeroSlammerItem(SubzeroSlammer, 1);
    SkillItem IceSpearheadItem(IceSpearhead, 1);
    SkillItem AvalancheItem(Avalanche, 1);
    SkillItem HellfireItem(Hellfire, 1);
    SkillItem ChasmTrampleItem(ChasmTrample, 1);
    SkillItem BubbleBeamItem(BubbleBeam, 1);
    SkillItem PoseidonWrathItem(PoseidonWrath, 1);
    SkillItem BOLTItem(BOLT, 1);
    SkillItem ForkedLightningItem(ForkedLightning, 1);
    SkillItem VoidItem(Void, 1);
    SkillItem ThornedRoseItem(ThornedRose, 1);
    SkillItem CastleOfIceItem(CastleOfIce, 1);
    SkillItem AvalonItem(Avalon, 1);

    int pilihan;
    cin >> pilihan;
    
    createSkillsandSkillItems();
    Engimon firstEngimon = initializeStarterEngimon(pilihan);
    
}