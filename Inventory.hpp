#include <vector>
#include "SkillItem.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"
using namespace std;

template<class T>
class Inventory
{
protected:
    static const int max_capacity = 100;
    static int current_capacity = 0;
    vector<T> vector_inventory;

public:
    // Constructor
    Inventory() { cout << "make inventory" << endl; }

    // Operator
    Inventory &operator<<(const T &inventory_item)
    {
        if(Inventory::current_capacity + 1 > Inventory::max_capacity) {
            throw "full capacity";
        }
        else
        {
            this->vector_inventory.push_back(inventory_item);
            Inventory::current_capacity++;
        }

        return *this;
    }
};