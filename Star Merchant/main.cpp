#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include<algorithm>
#include <cmath>
#include <iomanip>
#include "Player.h"
using namespace std;


void starMap(Planet planetList[]);
string planetNameGen();
void help();
// Map system is an ordered grid (see map.txt)

// Step 1: get the map working
// Step 2: get the trade system set up
// Step 2.5: add cargo, inventory, trade, etc.
// Step 3: implement trade classes
// Step 4: add features that are based on core mechanics like piracy, mutiny, etc.
// Need function that, when trade interactions are called, will randomize what is being sold per loop

int main() {
    srand(time(0));
    Player player;
    int currentPlanet = 0;
    vector<Cargo> cargo(0);
    // PLANET GENERATION //
    Planet planetList[6];
    for (int i = 0; i < 6; i++)
    {
        planetList[i].planetName = planetNameGen();
    }
    // MAP INITIALIZATION //
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                planetList[i].planetName = planetNameGen();
                planetList[i].planetXLoc = j;
                planetList[i].planetYLoc = k;
                planetList[i].priorityClass = player.priorityTrade();
            }
        }
    }

    string playerCommand;
    help();
    bool win = false;
    bool gameOver = false;
    bool mutiny = false;
    bool repossess = false;
    while(!win && !gameOver && !mutiny && !repossess)
    {
        string planetName;

        if (player.get_years_passed() == 10.0)
        {
            win = true;
        }

        if (player.get_curr() <= 0)
        {
            gameOver = true;
        }

        // Can the player pay their crew? If not, mutiny
        if (fmod(player.get_years_passed(), 1) == 0 && player.get_years_passed() > 0)
        {
            if (player.get_curr() >= 500000)
            {
                player.payCrew();
            }
            else
            {
                mutiny = true;
            }
        }

        // Can the player pay for their ship? If not, the ship gets taken back
        if (fmod(player.get_years_passed(), 2) == 0 && player.get_years_passed() > 0)
        {
            if (player.get_curr() >= 2000000)
            {
                player.payShipLease();
            }
            else
            {
                repossess = true;
            }
        }
        cout << "Current location: " << planetList[currentPlanet].planetName << endl;
        player.showBalance();
        cout << "Planet's primary trade: " << planetList[currentPlanet].priorityClass << endl;
        cout << "Years passed: " << player.get_years_passed() << endl;
        cout << "What would you like to do?" << endl;
        cin >> playerCommand;

        if (playerCommand[0] == 't' || playerCommand[0] == 'T')
        {
            if (playerCommand[1] == 'e' || playerCommand[1] == 'E')
            {
                starMap(planetList);
                cout << "Where would you like to go?" << endl;
                cin >> planetName;
                if(planetName == planetList[currentPlanet].planetName)
                {
                    cout << "You can't travel to the same planet you're on!" << endl;
                    cin >> planetName;
                }

                for (int i = 0; i < 6; i++)
                {
                    if(planetName == planetList[i].planetName)
                    {
                        player.teleport(planetName, planetList, currentPlanet);
                        player.payForFlight();

                    }
                }
            }

            else if (playerCommand[1] == 'r' || playerCommand[1] == 'R')
            {
                player.trade(planetList[currentPlanet]);
            }
        }
        else if(playerCommand[0] == 'i' || playerCommand[0] == 'I')
        {
            player.viewInv();
        }
        else
        {
            cout << "Command not recognized.  Please try again: " << endl;
            cin >> playerCommand;
        }
        cout << endl;
        cout << "----------" << endl;
        cout << endl;

    }
    if (win)
    {
        cout << "Congratulations! You are the ultimate star merchant!" << endl;
    }
    else if (gameOver)
    {
        cout << "You went broke and lost the ship.  Better luck next time!" << endl;
    }
    else if (mutiny)
    {
        cout << "Your crew, angered by the fact that you couldn't pay them, staged a mutiny and robbed you clean!" << endl;
        cout << "Game over!" << endl;
    }
    else if (repossess)
    {
        cout << "The Intergalactic Bank repossessed your ship after you failed to pay the 2,000,000 oobick lease." << endl;
        cout << "Game over!" << endl;
    }
    return 0;
}

void starMap(Planet planet[])
{
    for(int i = 0; i < 6; i++)
    {
        cout << "** " << planet[i].planetName << " **" << endl;
    }
}

string planetNameGen()
{
    string planetName;
    for (int i = 0; i < 6 ; i++)
    {
        planetName.push_back('a' + rand()%26);
    }
    planetName[0] = toupper(planetName[0]);

    return planetName;
}

void help()
{
    cout << "Welcome to Star Merchant!" << endl;
    cout << "The goal of this game is to make it through ten years of capitalism in space without going broke." << endl;
    cout << "You will have access to six different planets, each with their own priority trade class." << endl;
    cout << "A priority trade class increases the value of everything within that class; pieces of cargo are cheaper to buy and sell for higher values." << endl;
    cout << "Here in space, everything costs oobicks: traveling between planets costs 1000 oobicks, and you have to pay your crew an annual salary of 500,000 oobicks." << endl;
    cout << "Don't forget about your 2,000,000 oobick ship loan! That's a hefty price to pay every two years.  At least you're starting off with 1,000,000 oobicks." << endl;
    cout << endl;
    cout << "TO PLAY:" << endl;
    cout << "teleport --> allows you to teleport between planets." << endl;
    cout << "trade --> allows you to buy and sell cargo." << endl;
    cout << "inventory --> view your inventory, including any cargo you just obtained." << endl;
    cout << "help --> brings up this dialogue, in case you forget how to play." << endl;
    cout << "Ship and crew payments will be made automatically, but if you don't have enough money to pay up when the time rolls around, it's an instant game over!" << endl;
    cout << "Good luck, Star Merchant!" << endl;
    cout << "------------------------------" << endl;
}