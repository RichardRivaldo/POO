#include <string>
#include <iostream>
#include <vector>
#include "Engimon.hpp"

using namespace std;

class Battle {
    private :
        Engimon engimonPlayer;
        Engimon engimonWild; 
        int levelEngimon1; // Level Engimon Player 1
        int levelEngimon2; // Level Engimon Player 2
        float multiplierEngimon1; // Element Advantage Engimon Player 1
        float multiplierEngimon2; // Element Advantage Engimon Player 2
        int skillPower1; // Total skill base power Engimon Player 1
        int skillPower2; // Total skill base power Engimon Player 2
        float totalPower1;
        float totalPower2;
        string winner;
        string loser;
    public :
        // Constructor & Destructor
        Battle(Engimon engimonPlayer, Engimon engimonWild);
        ~Battle();

        // Get Class Attribute
        int getLevelEngimon1();
        int getLevelEngimon2();
        int getMultiplierEngimon1();
        int getMultiplierEngimon2();
        int getskillPower1();
        int getskillPower2();
        int getTotalPower1();
        int getTotalPower2();

        // Set Class Attribute
        void setMultiplierEngimon();
        void setSkillPower();
        void setTotalPower();

        // Fungsi dan Prosedur
        float checkMultiplier(string element1, string elemen2);
        void showTotalPower();
        void doBattle();
};