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
        // Elements
        vector<string> Elements;

    public:
        // Default Constructor, fill with default of each attribute
        Skill();
        // User-Defined Constructor
        Skill(string name, int power, int mastery, vector<string> Elmts);
        // Destructor - Not really needed, just to ensure the object is destructed correctly
        ~Skill();

        // Methods
        bool isSkillLearnable(string engimonElmt);
        void masteryLevelUp(int bpIncrease);
        void skillInfo();

        // Getter
        string getSkillName();
};