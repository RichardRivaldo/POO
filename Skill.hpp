#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Skill {
    protected :
        // Skill name
        string skillName;
        // Power
        int basePower;
        // Mastery Level
        int masteryLevel;
        //
        string Species;
        // Elements
        vector<string> Elements;

    public:
        // Default Constructor, fill with default of each attribute
        Skill();
        // User-Defined Constructor
        Skill(string name, int power, int mastery, string species, vector<string> Elmts);
        // Destructor - Not really needed, just to ensure the object is destructed correctly
        // ~Skill();

        // Methods
        const bool isSkillLearnable(string engimonElmt, string species);
        void masteryLevelUp(int bpIncrease);
        const void skillInfo();
        const Skill getHighestMastery();

        // Getter
        const string getSkillName();
        const int getSkillPower();
        const int getSkillMastery();
        const vector<string> getSuitableElmt();
        const string getSkillSpecies();
};