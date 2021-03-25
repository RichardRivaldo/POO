#include "Engimon.hpp"

using namespace std;

const string FIRE = "Fire";
const string WATER = "Water";
const string ELECTRIC = "Electric";
const string GROUND = "Ground";
const string ICE = "Ice";

int main() {
    Engimon* engimon1 = new Engimon("Engimon A", "Firemon", {FIRE, FIRE});
    Engimon* engimon2 = new Engimon("Engimon B", "Firemon", {ICE, ICE});

    engimon1->showStats();
    cout << endl;
    engimon2->showStats();
    cout << endl;

    cout << engimon1->getName() << endl;
    cout << engimon1->getSpecies() << endl;
    cout << engimon1->getLevel() << endl;
    cout << engimon1->getExperience() << endl;
    cout << engimon1->getCumulativeExperience() << endl;

    cout << engimon1->CheckDead(engimon1) << endl;
    cout << engimon2->CheckDead(engimon2) << endl;

    cout << engimon1->CheckLevelUp(engimon1) << endl;
    cout << engimon2->CheckLevelUp(engimon2) << endl;

    engimon1->~Engimon();
    engimon2->~Engimon();

}