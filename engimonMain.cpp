#include "Engimon.hpp"

using namespace std;

const string FIRE = "Fire";
const string WATER = "Water";
const string ELECTRIC = "Electric";
const string GROUND = "Ground";
const string ICE = "Ice";

int main() {
    Engimon engimon1 = Engimon("Engimon A", "Firemon", {FIRE, FIRE});
    Engimon engimon2 = Engimon("Engimon B", "Firemon", {ICE, ICE});

    engimon1.showStats();
    engimon2.showStats();

    cout << engimon1.CheckDead(engimon1) << endl;
    cout << engimon2.CheckDead(engimon2) << endl;

    cout << engimon1.CheckLevelUp(engimon1) << endl;
    cout << engimon2.CheckLevelUp(engimon2) << endl;
}