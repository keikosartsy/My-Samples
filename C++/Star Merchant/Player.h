//
// Created by barin on 5/4/2021.
//

#ifndef PROG4_PLAYER_H
#define PROG4_PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include<algorithm>
#include <cmath>
using namespace std;

struct Cargo
{
    string cargoType; // Agriculture, Machinery, Technology, Rations, Clothing, Jewels
    double cargoValue;
    int cargoWeight;
};

struct Planet
{
    string planetName;
    string priorityClass;
    int planetXLoc{};
    int planetYLoc{};

};

class Player
{
public:
    int get_loc_x();
    int get_loc_y();
    double get_years_passed();
    vector<Cargo>& getCargo();
    double get_curr();

    static string priorityTrade();

    void timePass(double amount);
    void set_loc_y(int yloc);
    void set_loc_x(int xloc);
    void set_curr(double c);
    void addCargo(const Cargo& c);


    Player();

    void trade(Planet &planet);
    void buy(Planet &planet);
    void sell(Planet &planet);
    void teleport(string location, Planet planetList[], int &currentPlanet);
    void viewInv();

    void payCrew();
    void payShipLease();
    void payForFlight();
    void showBalance();

private:
    int loc_x;
    int loc_y;
    double curr;
    double yearsPassed;
    vector<Cargo> cargo;

};
#endif //PROG4_PLAYER_H
