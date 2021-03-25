#include <vector>
#include "SkillItem.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"
using namespace std;

template <class T>
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
        if (Inventory::current_capacity + 1 > Inventory::max_capacity)
        {
            throw "full capacity";
        }
        else
        {
            this->vector_inventory.push_back(inventory_item);
            Inventory::current_capacity++;
        }

        return *this;
    }

    void decrementCurrentCapacity() { Inventory::current_capacity--; }

    void removeItem(int index)
    {
        if (index > this->vector_inventory.size() - 1)
            throw "index out of bound";
        else
            this->vector_inventory.erase(this->vector_inventory.begin() + index);
    }

    vector<T> getInventoryVector() { return this->vector_inventory; }

    int getInventorySize() { return this->vector_inventory.size(); }
};