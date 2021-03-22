#include <vector>
#include "SkillItem.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"
using namespace std;

class Inventory
{
protected:
    int max_capacity;
    int engimon_active_index; // idx -1 for undefine index
    vector<Engimon> vector_engimon;
    vector<SkillItem> vector_skillItem;

public:
    Inventory(int max_capacity) : max_capacity(max_capacity), engimon_active_index(-1){};

    Inventory &operator<<(const Engimon &engimon)
    {
        if (this->vector_engimon.size() + 1 > this->max_capacity)
            cout << "capacity has been maximum" << endl;
        else
        {
            this->vector_engimon.push_back(engimon);
            this->max_capacity++;
        }

        return *this;
    }
    Inventory &operator<<(SkillItem &skill)
    {
        if (this->vector_skillItem.size() + 1 > this->max_capacity)
            cout << "capacity has been maximum" << endl;
        else
        {
            // Check skill already equipped or not
            int i = 0;
            bool finish = false;
            while (i < this->vector_skillItem.size() && !finish)
            {
                if (this->vector_skillItem[i].getSkillName() == skill.getSkillName())
                {
                    this->vector_skillItem[i].inc_jumlah();
                    finish = true;
                }
                i++;
            }

            // Not found
            if (!finish)
            {
                this->vector_skillItem.push_back(skill);
                this->max_capacity++;
            }
        }
        return *this;
    }

    void changeActiveEngimon(string engimonName)
    {
        int i = 0;
        bool found = false;
        while (i < this->vector_engimon.size() && !found)
        {
            if (this->vector_engimon[i].getName() == engimonName)
                found == true;
            else
                i++;
        }

        if (found)
        {
            this->engimon_active_index = i;
        }
        else
        {
            cout << "Engimon not found!";
        }
    }
};