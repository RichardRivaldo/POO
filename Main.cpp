#include "Player.hpp"
#include "Engimon.hpp"
#include "Inventory.hpp"
#include "Skill.hpp"
#include "SkillCat.hpp"
#include "SkillItem.hpp"
#include "Map.hpp"
#include "Battle.hpp"
#include <string>

using namespace std;

//Define elements
const string FIRE = "Fire";
const string WATER = "Water";
const string ELECTRIC = "Electric";
const string GROUND = "Ground";
const string ICE = "Ice";
// enum Elements {Fire, Water, Electric, Ground, Ice};

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
    // Unique Skill
    UniqueSkill Fireball("Fireball", 20, vector<string> {FIRE}, "Firemon");
    UniqueSkill Watercut("Watercut", 20, vector<string> {WATER}, "Watermon");
    UniqueSkill Thunderslash("Thunderslash", 20, vector<string> {ELECTRIC}, "Electromon");
    UniqueSkill Earthquake("Earthquake", 20, vector<string> {GROUND}, "Groundmon");
    UniqueSkill Blizzard("Blizzard", 20, vector<string> {ICE}, "Icemon");

    // Regular Skill
    Skill CrimsonFire("Crimson Fire", 10, vector<string> {FIRE});
    Skill Flamethrower("Flame Thrower", 12, vector<string> {FIRE, ELECTRIC});
    Skill HeatWave("Heat Wave", 14, vector<string> {FIRE});
    Skill LittleWanderers("Little Wanderers", 10, vector<string> {WATER});
    Skill DancingRain("Dancing Rain", 12, vector<string> {WATER, ICE});
    Skill Tsunami("Tsunami", 14, vector<string> {WATER});
    Skill PlasmaFist("PlasmaFist", 10, vector<string> {ELECTRIC});
    Skill PikaPapow("Pika Papow", 12, vector<string> {ELECTRIC});
    Skill StokedSparksurfer("Stoked Sparksurfer", 14, vector<string> {ELECTRIC, GROUND});
    Skill SpikesOfDeath("Spikes of Death", 10, vector<string> {GROUND});
    Skill ScorchingSands("ScorchingSands", 12, vector<string> {GROUND, FIRE});
    Skill TempestOfBlades("Tempest of Blades", 14, vector<string> {GROUND});
    Skill SubzeroSlammer("Subzero Slammer", 10, vector<string>{ICE, WATER});
    Skill IceSpearhead("Ice Spearhead", 12, vector<string>{ICE});
    Skill Avalanche("Avalanche", 14, vector<string>{ICE});

    // Special Skill
    SpecialSkill Hellfire("Hellfire", 65, vector<string>{FIRE}, 10);
    SpecialSkill ChasmTrample("Chasm Trample", 70, vector<string>{FIRE}, 10);
    SpecialSkill BubbleBeam("Bubble Beam", 60, vector<string>{WATER}, 10);
    SpecialSkill PoseidonWrath("Poseidon's Wrath", 75, vector<string>{WATER}, 10);
    SpecialSkill BOLT("10,000,000 Volt Thunderbolt", 75, vector<string>{ELECTRIC}, 10);
    SpecialSkill ForkedLightning("Forked Lightning", 60, vector<string>{ELECTRIC}, 10);
    SpecialSkill Void("Void", 70, vector<string> {GROUND}, 10);
    SpecialSkill ThornedRose("Thorned Rose", 75, vector<string>{GROUND}, 10);
    SpecialSkill CastleOfIce("Castle of Ice", 55, vector<string>{ICE}, 10);
    SpecialSkill Avalon("Avalon", 80, vector<string>{ICE}, 10);
    
    // Skill Items
    SkillItem FireballItem(Fireball);
    SkillItem WatercutItem(Watercut);
    SkillItem ThunderslashItem(Thunderslash);
    SkillItem EarthquakeItem(Earthquake);
    SkillItem BlizzardItem(Blizzard);
    SkillItem CrimsonFireItem(CrimsonFire);
    SkillItem FlamethrowerItem(Flamethrower);
    SkillItem HeatWaveItem(HeatWave);
    SkillItem LittleWanderersItem(LittleWanderers);
    SkillItem DancingRainItem(DancingRain);
    SkillItem TsunamiItem(Tsunami);
    SkillItem PlasmaFistItem(PlasmaFist);
    SkillItem PikaPapowItem(PikaPapow);
    SkillItem StokedSparksurferItem(StokedSparksurfer);
    SkillItem SpikesOfDeathItem(SpikesOfDeath);
    SkillItem ScorchingSandsItem(ScorchingSands);
    SkillItem TempestOfBladesItem(TempestOfBlades);
    SkillItem SubzeroSlammerItem(SubzeroSlammer);
    SkillItem IceSpearheadItem(IceSpearhead);
    SkillItem AvalancheItem(Avalanche);
    SkillItem HellfireItem(Hellfire);
    SkillItem ChasmTrampleItem(ChasmTrample);
    SkillItem BubbleBeamItem(BubbleBeam);
    SkillItem PoseidonWrathItem(PoseidonWrath);
    SkillItem BOLTItem(BOLT);
    SkillItem ForkedLightningItem(ForkedLightning);
    SkillItem VoidItem(Void);
    SkillItem ThornedRoseItem(ThornedRose);
    SkillItem CastleOfIceItem(CastleOfIce);
    SkillItem AvalonItem(Avalon);

    int pilihan;
    cin >> pilihan;
    
    Engimon firstEngimon = initializeStarterEngimon(pilihan, Fireball, Watercut, Thunderslash, Earthquake, Blizzard);
    
    //Tambahin firstEngimon ke inventory player

    return 0;
}