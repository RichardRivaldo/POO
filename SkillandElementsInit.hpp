#ifndef SKILLS_AND_ELEMENTS_HPP
#define SKILLS_AND_ELEMENTS_HPP
#include "Skill.hpp"
#include "SkillCat.hpp"
#include "SkillItem.hpp"

using namespace std;

//Define elements
const string FIRE = "Fire";
const string WATER = "Water";
const string ELECTRIC = "Electric";
const string GROUND = "Ground";
const string ICE = "Ice";
// enum Elements {Fire, Water, Electric, Ground, Ice};

// Create Skills based on Elements
vector<Skill> createFireSkills()
{
    UniqueSkill Fireball("Fireball", 20, vector<string>{FIRE}, "Firemon");
    Skill CrimsonFire("Crimson Fire", 10, vector<string>{FIRE});
    Skill Flamethrower("Flame Thrower", 12, vector<string>{FIRE, ELECTRIC});
    Skill HeatWave("Heat Wave", 14, vector<string>{FIRE});
    Skill ScorchingSands("ScorchingSands", 12, vector<string>{GROUND, FIRE});
    SpecialSkill Hellfire("Hellfire", 65, vector<string>{FIRE}, 10);
    SpecialSkill ChasmTrample("Chasm Trample", 70, vector<string>{FIRE}, 10);

    return vector<Skill>{Fireball, CrimsonFire, Flamethrower, HeatWave, Hellfire, ChasmTrample, ScorchingSands};
}

vector<Skill> createWaterSkills()
{
    UniqueSkill Watercut("Watercut", 20, vector<string>{WATER}, "Watermon");
    Skill LittleWanderers("Little Wanderers", 10, vector<string>{WATER});
    Skill DancingRain("Dancing Rain", 12, vector<string>{WATER, ICE});
    Skill Tsunami("Tsunami", 14, vector<string>{WATER});
    Skill SubzeroSlammer("Subzero Slammer", 10, vector<string>{ICE, WATER});
    SpecialSkill BubbleBeam("Bubble Beam", 60, vector<string>{WATER}, 10);
    SpecialSkill PoseidonWrath("Poseidon's Wrath", 75, vector<string>{WATER}, 10);

    return vector<Skill>{Watercut, LittleWanderers, DancingRain, Tsunami, BubbleBeam, PoseidonWrath, SubzeroSlammer};
}

vector<Skill> createElectricSkills()
{
    UniqueSkill Thunderslash("Thunderslash", 20, vector<string>{ELECTRIC}, "Electromon");
    Skill PlasmaFist("PlasmaFist", 10, vector<string>{ELECTRIC});
    Skill PikaPapow("Pika Papow", 12, vector<string>{ELECTRIC});
    Skill Flamethrower("Flame Thrower", 12, vector<string>{FIRE, ELECTRIC});
    Skill StokedSparksurfer("Stoked Sparksurfer", 14, vector<string>{ELECTRIC, GROUND});
    SpecialSkill BOLT("10,000,000 Volt Thunderbolt", 75, vector<string>{ELECTRIC}, 10);
    SpecialSkill ForkedLightning("Forked Lightning", 60, vector<string>{ELECTRIC}, 10);

    return vector<Skill>{Thunderslash, PlasmaFist, PikaPapow, StokedSparksurfer, BOLT, ForkedLightning, Flamethrower};
}

vector<Skill> createGroundSkills()
{
    UniqueSkill Earthquake("Earthquake", 20, vector<string>{GROUND}, "Groundmon");
    Skill SpikesOfDeath("Spikes of Death", 10, vector<string>{GROUND});
    Skill ScorchingSands("ScorchingSands", 12, vector<string>{GROUND, FIRE});
    Skill TempestOfBlades("Tempest of Blades", 14, vector<string>{GROUND});
    Skill StokedSparksurfer("Stoked Sparksurfer", 14, vector<string>{ELECTRIC, GROUND});
    SpecialSkill Void("Void", 70, vector<string>{GROUND}, 10);
    SpecialSkill ThornedRose("Thorned Rose", 75, vector<string>{GROUND}, 10);

    return vector<Skill>{Earthquake, SpikesOfDeath, ScorchingSands, TempestOfBlades, Void, ThornedRose, StokedSparksurfer};
}

vector<Skill> createIceSkills()
{
    UniqueSkill Blizzard("Blizzard", 20, vector<string>{ICE}, "Icemon");
    Skill SubzeroSlammer("Subzero Slammer", 10, vector<string>{ICE, WATER});
    Skill IceSpearhead("Ice Spearhead", 12, vector<string>{ICE});
    Skill Avalanche("Avalanche", 14, vector<string>{ICE});
    Skill DancingRain("Dancing Rain", 12, vector<string>{WATER, ICE});
    SpecialSkill CastleOfIce("Castle of Ice", 55, vector<string>{ICE}, 10);
    SpecialSkill Avalon("Avalon", 80, vector<string>{ICE}, 10);

    return vector<Skill>{Blizzard, SubzeroSlammer, IceSpearhead, Avalanche, CastleOfIce, Avalon, DancingRain};
}

// Create Skill Items Based on Elements
vector<SkillItem> createSkillItem(vector<Skill> Skills)
{
    vector<SkillItem> skillItems;
    for (int i = 0; i < Skills.size(); i++)
    {
        SkillItem temp(Skills[i]);
        skillItems.push_back(temp);
    }

    return skillItems;
}

// Testing

// int main(){
//     vector<Skill> fireSkills = createFireSkills();
//     for(int i = 0; i < fireSkills.size(); i++){
//         cout << fireSkills[i].getSkillName() << endl;
//     }

//     vector<SkillItem> fireSkillItems = createSkillItem(fireSkills);
//     for(int i = 0; i < fireSkillItems.size(); i++){
//         cout << fireSkillItems[i].getSkill().getSkillName() << endl;
//     }
// }
#endif