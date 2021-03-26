#include "Player.hpp"
#include "Engimon.hpp"
#include "Inventory.hpp"
#include "Skill.hpp"
#include "SkillCat.hpp"
#include "SkillItem.hpp"
#include "Map.hpp"
#include "Battle.hpp"
#include "SkillandElementsInit.cpp"
#include <string>

using namespace std;

void showHelp()
{
    cout << "HELP HERE!" << endl;
    cout << "-------------------------" << endl;
    cout << "w : Move Up" << endl;
    cout << "a : Move Left" << endl;
    cout << "s : Move Down" << endl;
    cout << "d : Move Right" << endl;
    cout << "help : Show Help Menu" << endl;
    cout << "items : Show Skill Items" << endl;
    cout << "engimons : Show Engimons" << endl;
    cout << "breed : Breed Two Engimons" << endl;
    cout << "stats: Show Active Engimons" << endl;
    cout << "engi: Interact With Engimons" << endl;
    cout << "swap: Swap Active Engimons" << endl;
    cout << "learn: Learn New Skills" << endl;
    cout << "battle: Challenge Engimons!" << endl;
    cout << "quit: Exit The Game." << endl;
}

Engimon initializeStarterEngimon(int pilihan, Skill Skill1, Skill Skill2, Skill Skill3, Skill Skill4, Skill Skill5)
{
    string nama;
    while (true)
    {
        if (pilihan == 1)
        {
            cout << "Masukkan nama Firemon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Firemon", vector<string>{FIRE, FIRE});
            starterEngimon.AddSkill(Skill1);
            return starterEngimon;
        }
        else if (pilihan == 2)
        {
            cout << "Masukkan nama Watermon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Watermon", {WATER, WATER});
            starterEngimon.AddSkill(Skill2);
            return starterEngimon;
        }
        else if (pilihan == 3)
        {
            cout << "Masukkan nama Electricmon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Electromon", {ELECTRIC, ELECTRIC});
            starterEngimon.AddSkill(Skill3);
            return starterEngimon;
        }
        else if (pilihan == 4)
        {
            cout << "Masukkan nama Groundmon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Groundmon", {GROUND, GROUND});
            starterEngimon.AddSkill(Skill4);
            return starterEngimon;
        }
        else if (pilihan == 5)
        {
            cout << "Masukkan nama Icemon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Icemon", {ICE, ICE});
            starterEngimon.AddSkill(Skill5);
            return starterEngimon;
        }
        else
        {
            cout << "Masukan tidak valid, coba lagi" << endl;
        }
    }
}

int main()
{
    bool gameEnd = false;

    // Init Skills
    vector<Skill> fireSkills = createFireSkills();
    vector<Skill> waterSkills = createWaterSkills();
    vector<Skill> electricSkills = createElectricSkills();
    vector<Skill> groundSkills = createGroundSkills();
    vector<Skill> iceSkills = createIceSkills();

    // Init Skill Items
    vector<SkillItem> fireItems = createSkillItem(fireSkills);
    vector<SkillItem> waterItems = createSkillItem(waterSkills);
    vector<SkillItem> electricItems = createSkillItem(electricSkills);
    vector<SkillItem> groundItems = createSkillItem(groundSkills);
    vector<SkillItem> iceItems = createSkillItem(iceSkills);

    // Starting game, initialize starter engimon
    int pilihan;
    cin >> pilihan;

    Engimon starterEngimon = initializeStarterEngimon(pilihan, fireSkills[0], waterSkills[0], electricSkills[0], groundSkills[0], iceSkills[0]);

    while (!gameEnd)
    {
        string command;
        cout << "$ ";
        cin >> command;
        cout << endl;

        if (command == "help")
        {
            showHelp();
        }
        else if (command == "w")
        {
        }
        else if (command == "a")
        {
        }
        else if (command == "s")
        {
        }
        else if (command == "d")
        {
        }
        else if (command == "items")
        {
        }
        else if (command == "engimons")
        {
        }
        else if (command == "breed")
        {
        }
        else if (command == "stats")
        {
        }
        else if (command == "engi")
        {
        }
        else if (command == "swap")
        {
        }
        else if (command == "learn")
        {
        }
        else if (command == "battle")
        {
        }
        else if (command == "quit")
        {
        }
        else
        {
            cout << "Invalid Command!" << endl;
        }
    }

    //Tambahin firstEngimon ke inventory player

    return 0;
}