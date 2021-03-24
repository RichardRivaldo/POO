#include "Player.hpp"
#include "Engimon.hpp"
#include "Inventory.hpp"
#include "Skill.hpp"
#include "SkillCat.hpp"
#include "SkillItem.hpp"
#include "Map.hpp"

using namespace std;

enum Elements {Fire = "Fire", Water = "Water", Electric = "Electric", 
              Ground = "Ground", Ice = "Ice"};

void createSkillsandSkillItems(){
    Skill Fireball("Fireball", 10, 1, Fire);
    Skill Watercut("Watercut", 10, 1, Water);
    Skill Thunderslash("Thunderslash", 10, 1, Electric);
    Skill Earthquake("Earthquake", 10, 1, Ground);
    Skill Blizzard("Blizzard", 10, 1, Ice);

    
}

int main(){

}