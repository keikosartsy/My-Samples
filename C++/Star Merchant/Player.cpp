//
// Created by Carina dePillis-Shintaku on 5/4/2021.
//
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include "Player.h"
using namespace std;

int Player::get_loc_x() {
    return loc_x;
}

int Player::get_loc_y() {
    return loc_y;
}

double Player::get_years_passed() {
    return yearsPassed;
}

vector<Cargo> &Player::getCargo() {
    return cargo;
}

double Player::get_curr() {
    return curr;
}

void Player::timePass(double amount)
{
    {yearsPassed += amount;} //Each trade is 0.003 years, each travel is 0.02 years
}

void Player::set_loc_y(int yloc)
{
    loc_y = yloc;
}

void Player::set_loc_x(int xloc)
{
    loc_x = xloc;
}

void Player::set_curr(double c)
{
    curr = c;
}

Player::Player()
{
    loc_x = 0;
    loc_y = 0;
    curr = 1000000;
    yearsPassed = 0;
    for(int i = 0; i < 6; i++)
    {
        cargo.push_back({"Agriculture", 100, 1});
        cargo.push_back({"Machinery", 100, 1});
        cargo.push_back({"Technology", 100, 1});
        cargo.push_back({"Rations", 100, 1});
        cargo.push_back({"Clothing", 100, 1});
        cargo.push_back({"Jewels", 100, 1});
    }
}

void Player :: teleport(string location, Planet planetList[], int &currentPlanet)
{
    timePass(0.02);
    bool canTeleport = false;

    while(!canTeleport)
    {
        for (int k = 0; k < 6; k++)
        {
            if(location == planetList[k].planetName)
            {
                currentPlanet = k;
                set_loc_x(planetList[k].planetXLoc);
                set_loc_y(planetList[k].planetYLoc);
                canTeleport = true;
            }

        }
    }

    cout << "Teleporting to " << location << "..." << endl;

}
string Player:: priorityTrade()
{
    // Randomly generate what the priority trade class is for the specified planet
    int classSelect;
    string className;

    classSelect = (rand()%6) + 1;
    switch(classSelect)
    {
        case 1:
            className = "Agriculture";
            break;
        case 2:
            className = "Machinery";
            break;
        case 3:
            className = "Technology";
            break;
        case 4:
            className = "Rations";
            break;
        case 5:
            className = "Clothing";
            break;
        case 6:
            className = "Jewels";
            break;

    }
    return className;
}

void Player :: trade(Planet &planet)
{
    timePass(0.003);
    // Propose a deal (buy or sell)
    // prices affected by planet's priority class (Selling price increased by 50%, buying decreased by 20%)
    string command;
    cout << "Do you want to buy or sell?" << endl;
    cin >> command;

    if (command[0] == 'b' || command[0] == 'B')
    {
        buy(planet);
    }
    else if (command[0] == 's' || command[0] == 'S')
    {
        sell(planet);
    }

}
void Player :: buy(Planet &planet)
{
    // Buy: trade currency for cargo (x currency for y amount of [type] cargo, type is random
    // need to be able to add cargo to player cargo vector
    int cargoAmt;
    int userBuy;
    cargoAmt =(rand()%10)+1;
    Cargo c;
    c.cargoType = priorityTrade();
    c.cargoValue = (rand()%7000)+1000;
    c.cargoWeight = (rand()%10)+1;

    // Primary Cargo //
    if (c.cargoType == planet.priorityClass)
    {
        c.cargoValue -= c.cargoValue*0.35;
    }

    if (cargoAmt == 1)
    {
        cout << "A merchant is offering " << cargoAmt << " " << c.cargoType << " piece of cargo for " << c.cargoValue << " oobicks apiece.  The piece weighs " << c.cargoWeight << " pounds. " << endl;

    }
    else
    {
        cout << "A merchant is offering " << cargoAmt << " " << c.cargoType << " pieces of cargo for " << c.cargoValue << " oobicks apiece.  Each piece weighs " << c.cargoWeight << " pounds. " << endl;
        cout << "How many would you like to buy?" << endl;
    }
    cin >> userBuy;
    int totalCost = userBuy * c.cargoValue;
    if (c.cargoType == planet.priorityClass)
    {
        cout << "This is a priority-class cargo type! Purchases are 20% off!" << endl;
        totalCost -= totalCost*0.20;
    }
    if (userBuy > cargoAmt)
    {
        cout << "You can't buy more than what the trader has!" << endl;
        cin >> userBuy;
    }
    else if (userBuy < 1)
    {
        cout << "You bought nothing." << endl;
    }
    else if (totalCost > get_curr())
    {
        cout << "You can't afford that many right now." << endl;
        cin >> userBuy;
    }
    else
    {
        for(int i = 0; i < userBuy; i++)
        {
            addCargo(c);
            set_curr(get_curr()-totalCost);
        }
    }
    cout << "This transaction cost " << totalCost << " oobicks." << endl;

}

void Player:: sell(Planet &planet)
{
    // Sell: trade cargo for currency (x amount of [type] cargo for y currency)
    cout << "You have " << getCargo().size() << " units total." << endl;
    int cargoAmt=0;
    int userSell;
    int cargoTypeChoice;
    int sellCount;
    vector<Cargo> c;
    string sellType;
    cout << "What type of cargo would you like to sell?" << endl;
    cout << "1. Agriculture" << "\n2. Machinery" <<"\n3. Technology" << "\n4. Rations" << "\n5. Clothing" << "\n6. Jewels" << endl;
    cin >> cargoTypeChoice;
    switch(cargoTypeChoice)
    {
        case 1:
            sellType = "Agriculture";
            break;
        case 2:
            sellType = "Machinery";
            break;
        case 3:
            sellType = "Technology";
            break;
        case 4:
            sellType = "Rations";
            break;
        case 5:
            sellType = "Clothing";
            break;
        case 6:
            sellType = "Jewels";
            break;
    }
    for (int i = 0; i < getCargo().size(); i++)
    {
        if(getCargo()[i].cargoType == sellType)
        {
            cargoAmt++;
        }
    }
    if (cargoAmt == 0)
    {
        cout << "You don't have any units of this type to sell!" << endl;
    }
    else
    {
        cout << "You have " << cargoAmt << " units available to sell." << endl;
        cout << "How many would you like to sell?" << endl;
        cin >> sellCount;
        double totalCost=0;

        int sellIter = 0;
        vector <Cargo> :: iterator iter;
        for(iter = getCargo().begin(); iter != getCargo().end(); iter++)
        {
            if (sellIter < sellCount && iter->cargoType == sellType)
            {
                totalCost = totalCost+iter->cargoValue;
                getCargo().erase(iter);
                sellIter++;
            }
        }
        if(sellType == planet.priorityClass)
        {
            cout << "This is a priority-class cargo type! Selling price boosted by 20%!" << endl;
            totalCost += totalCost * 0.20;
        }
        set_curr(get_curr()+totalCost);
        cout << "You earned " << totalCost << " oobicks from this trade!" << endl;
        cout << "You now have " << getCargo().size() << " units total." << endl;
    }
}

void Player :: viewInv()
{
    for(int i = 0; i < getCargo().size(); i++)
    {
        cout << "Cargo Type: " << getCargo()[i].cargoType << endl;
        cout << "Value: " << getCargo()[i].cargoValue << endl;
        cout << "Weight: " << getCargo()[i].cargoWeight << endl;
        cout << "***" << endl;
    }
}

void Player :: addCargo(const Cargo& c)
{
    cargo.push_back(c);
}
void Player :: payCrew()
{
    cout << "It's time to pay your crew." << endl;
    set_curr(get_curr()-500000);
}
void Player :: payShipLease()
{
    cout << "It's time to pay off your ship's lease." << endl;
    set_curr(get_curr()-2000000);
}
void Player :: payForFlight()
{
    set_curr(get_curr()-1000);
}
void Player :: showBalance()
{
    if(get_curr() < 1000000)
    {
        cout << "Account balance: " << get_curr() << endl;
    }
    else if (get_curr() >= 1000000)
    {
        cout << "Account balance: " << get_curr()/1000000 << "M" << endl;
    }
}


