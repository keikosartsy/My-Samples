#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

void initFloorMap(string M[3][3], int size, Character player);

int main() {

    Character player1;
    string Mansion[3][3]; // 3x3 mansion with three floors
    string command;
    string playerName;
    bool win = false; // indicates if the game's been won

    // initialize map //
    cout << "What is your name?" << endl;
    cin >> playerName;
    player1.set_name(playerName);

    while(!win)
    {
        initFloorMap(Mansion, 3, player1);
        // Give current information about the world and character
        // Get a command
        string location = Mansion[player1.get_x()][player1.get_y()];
        cout << "-------------------" << endl;
        cout << "Location: " << location << endl;
        cout << "What would you like to do?" << endl;
        cin >> command;

        // Process command
        switch(command[0])
        {
            case 'h':
            case 'H':
                cout << "You can go NORTH, SOUTH, EAST, or WEST." << endl;
                cout << "You can call for help at any time by asking for HELP." << endl;
                cout << "You can INSPECT the scene and TALK to anyone who may be in the room." << endl;
                cout << "If you notice a suspicious item in the room, you might be able to GRAB it." << endl;
                cout << "You can also QUIT." << endl;
                break;
            case 'e':
            case 'E':
                if (command[1] == 'x')
                {
                    cout << "Goodbye!" << endl;
                    exit(1);
                }
                else if (command[1] == 'a' || command[1] == NULL)
                {
                    if (player1.get_y() == 2)
                    {
                        cout << "You can't go any further east!" << endl;
                    }
                    else
                    {
                        player1.set_y(player1.get_y() + 1);
                    }
                    break;
                }
                break;

            case 'n':
            case 'N':
                if (player1.get_x() == 2)
                {
                    cout << "You can't go any further north!" << endl;
                }
                else
                {
                    player1.set_x(player1.get_x() + 1);
                }
                break;
            case 's':
            case 'S':
                if (player1.get_x() == 0)
                {
                    cout << "You can't go any further south!" << endl;
                }
                else
                {
                    player1.set_x(player1.get_x() - 1);
                }
                break;
            case 'w':
            case 'W':
                if (player1.get_y() == 0)
                {
                    cout << "You can't go any further west!" << endl;
                }
                else
                {
                    player1.set_y(player1.get_y() - 1);
                }
                break;

            case 'u':
            case 'U':
                if(player1.get_x() == 2 && player1.get_y() == 1)
                {
                    if(player1.get_floor() == 3)
                    {
                        cout << "There are no more floors." << endl;
                    }
                    else
                    {
                        player1.set_floor(player1.get_floor()+1);
                    }
                }
                else
                {
                    cout << "You cannot go upstairs without any stairs nearby!" << endl;
                }
                break;
            case 'd':
            case 'D':
                if(player1.get_x() == 2 && player1.get_y() == 1)
                {
                    if(player1.get_floor() == 1)
                    {
                        cout << "This is the ground floor." << endl;
                    }
                    else
                    {
                        player1.set_floor(player1.get_floor()-1);
                    }
                }
                else
                {
                    cout << "You cannot go downstairs without any stairs nearby!" << endl;
                }
                break;

            case 'i':
            case 'I':
                player1.inspect();
                break;

            case 't':
            case 'T':
                if (command[2] == 'k' || command[2] == 'K')
                {
                    player1.takeItem();
                } else
                    {
                    player1.talk();
                }
                break;

            case 'g':
            case 'G':
                player1.takeItem();
                break;

            case 'q':
            case 'Q':
                cout << "See you later!" << endl;
                exit(0);

            default:
                cout << "I don't understand." << endl;
                break;
        }

        // check for win condition
        if (player1.murderer_pick)
        {
            win = true;
        }
    }
    cout << "You left Wright Manor and never looked back." << endl;
    cout << "---------------------" << endl;
    if (player1.alice_murder) {cout << "Alice was admitted to a children's hospital after police found strands of Mr. Wright's hair under her pillow." << endl;}
    else if (player1.artist_murder) {cout << "The paint in Raphael's bucket was ran through lab tests, and although it was mostly paint, about a third was Mr. Wright's blood." << endl;}
    else if (player1.beth_murder) {cout << "Beth confessed to everything the minute a detective offered her a cold beer.  She was checked into rehab instead of prison, thanks to her aunt's influence." << endl;}
    else if (player1.staff_murder) {cout << "Although it took some questioning, several staff members cracked and admitting to plotting Mr. Wright's murder with other staff members." << endl;}
    else if (player1.wife_murder) {cout << "Mrs. Wright's alibi didn't hold up under several conflicting testimonies.  She confessed to slipping roofies in her husband's wine, but not to killing him." << endl;}
    cout << "Another case solved!" << endl;
    return 0;
}


void initFloorMap(string M[][3], int size, Character player)
{
    if (player.get_floor() == 1)
    {
        M[0][0] = "Outdoor Patio";
        M[0][1] = "Front Entrance";
        M[0][2] = "Guest Bedroom";
        M[1][0] = "Dining Room";
        M[1][1] = "Living Room";
        M[1][2] = "Beth's Room";
        M[2][0] = "Kitchen";
        M[2][1] = "Stairs (Floor 1)";
        M[2][2] = "Greenhouse";
    }
    else if (player.get_floor() == 2)
    {
        M[0][0] = "Johnathan's Room";
        M[0][1] = "Mr. and Mrs. Wright's Bedroom";
        M[0][2] = "Abandoned Bedroom";
        M[1][0] = "Servant's Quarters";
        M[1][1] = "Art Display";
        M[1][2] = "Music Room";
        M[2][0] = "Bathroom";
        M[2][1] = "Stairs (Floor 2)";
        M[2][2] = "Mr. Wright's Study";
    }
    else if (player.get_floor() == 3)
    {
        M[0][0] = "Room under Renovation";
        M[0][1] = "Balcony";
        M[0][2] = "Room under Renovation";
        M[1][0] = "Alice's Playroom";
        M[1][1] = "Adam's Playroom";
        M[1][2] = "Bathroom";
        M[2][0] = "Alice's Room";
        M[2][1] = "Stairs (Floor 3)";
        M[2][2] = "Adam's Room";
    }

    return;
}