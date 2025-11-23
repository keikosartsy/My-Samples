//
// Created by barin on 3/3/2021.
//

#ifndef PROJ02_CHARACTER_H
#define PROJ02_CHARACTER_H
#include <iostream>
#include <string>
using namespace std;

class Character
{
private:
    int x; // x location
    int y; // y location
    int floor;
    string name; // character name
    int inventory_size;


public:
    int get_x() {return x;} // <-- inline function
    int get_y() {return y;}
    int get_floor() {return floor;}
    string get_name() {return name;}
    int get_inventory_size() {return inventory_size;}
    void get_item(const char* itemName);
    string* inventory = new string[inventory_size];

    // Mutators //
    void set_x(int xloc) {x = xloc;}
    void set_y(int yloc) {y = yloc;}
    void set_name(string n) {name = n;}
    void set_floor(int f) {floor = f;}
    void inspect();
    void talk();
    void takeItem();
    bool itemCheck(const string& itemName);
    // Constructors //
    Character(); // default constructor
    Character(int xloc, int yloc, string n); // overloaded constructor
    // Other //

};
#endif //PROJ02_CHARACTER_H
