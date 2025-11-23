//
// Created by Carina dePillis-Shintaku on 3/3/2021.
//
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

Character::Character() // what our character starts out with
{
    x=0;
    y=1;
    floor = 1;
    name = "Bob";
    inventory_size = 0;
    inventory = NULL;
}
void Character::inspect()
{
    switch(get_floor())
    {
        case 1:
            if(get_x() == 0)
            {
                if (get_y() == 0)
                {
                    cout << "A few flowerpots have been knocked over." << endl;
                    cout << "A trail of pawprints and powdered glass leads away from the scene of the crime." << endl;
                }
                else if (get_y() == 1)
                {
                    cout << "The front entrance to the house." << endl;
                    cout << "Mrs. Wright stands at the door, weeping softly into a lace handkerchief." << endl;
                }
                else if (get_y() == 2)
                {
                    cout << "This bedroom hasn't been occupied in a while." << endl;
                }
            }
            else if (get_x() == 1)
            {
                if (get_y() == 0)
                {
                    cout << "The tablecloth is absolutely pristine." << endl;
                    cout << "...except for the knife sitting at the head of the table." << endl;
                    cout << "A maid stands right beside a painting of the now-deceased master of the house, standing as still as a marble statue." << endl;
                }
                else if (get_y() == 1)
                {
                    cout << "A couple of policemen are sweeping the living room for evidence." << endl;
                    cout << "The manor's butler stands watch with a nervous look in his eye." << endl;
                }
                else if (get_y() == 2)
                {
                    cout << "Beth Aberdeen's room." << endl;
                    cout << "Mrs. Wright's niece and Autumn Falls' most recent rehab release." << endl;
                    cout << "Beth sits at the end of the bed with her arms crossed." << endl;
                }
            }
            else if (get_x() == 2)
            {
                if (get_y() == 0)
                {
                    cout << "Most of the kitchen staff has been interviewed and sent home." << endl;
                    cout << "For some reason, the head chef has decided to stay." << endl;
                }
                else if (get_y() == 1)
                {
                    cout << "Stairs that lead up to the second floor." << endl;
                }
                else if (get_y() == 2)
                {
                    cout << "There's a headless gnome standing watch beside a bed of flowers." << endl;
                    cout << "The manor's resplendent greenhouse is full of colorful, exotic plants." << endl;
                    cout << "The gardener is pouring water into a flowerpot that's already beginning to overflow." << endl;
                }
            }
            break;

        case 2:
            if(get_x() == 0)
            {
                if (get_y() == 0)
                {
                    cout << "The dark, dank room of a moody teenager." << endl;
                    cout << "Johnathan Wright, the oldest son of Mr. and Mrs. Wright" << endl;
                }
                else if (get_y() == 1)
                {
                    cout << "Mr. and Mrs. Wright's...or, Mrs. Wright's bedroom." << endl;
                    cout << "With Mr. Wright gone, Mrs. Wright is set to inherit the entire estate." << endl;
                    cout << "There's a wedding ring, two glasses, and a bottle of wine on the nightstand." << endl;
                }
                else if (get_y() == 2)
                {
                    if (!itemCheck("rusty key"))
                    {
                        cout << "A door eaten away by time and termites." << endl;
                        cout << "The lock is only half-attached to the door, but it doesn't give way when you pull on it." << endl;
                        cout << "If only you had a key..." << endl;
                    }
                    else
                    {
                        cout << "A dusty bedroom that belongs to a little girl." << endl;
                        cout << "The sign on the door reads 'Suzy', and a little girl with big brown eyes plays with a porcelain doll on the floor." << endl;
                        cout << "That must be Suzy." << endl;
                    }
                }
            }
            else if (get_x() == 1)
            {
                if (get_y() == 0)
                {
                    cout << "The waiting staff have all been sent home, except for two butlers who were present at the time of the murder." << endl;
                    cout << "A mousy-looking man fiddles with his tie in the mirror." << endl;
                }
                else if (get_y() == 1)
                {
                    cout << "The room's walls are entirely dedicated to large, colorful canvases with no focal point or meaning." << endl;
                    cout << "At the center of it all is a tall, lanky man in an artist's smock and a bucket of oxblood-red paint." << endl;
                }
                else if (get_y() == 2)
                {
                    cout << "A room filled to the top with musical instruments." << endl;
                    cout << "Violins, flutes, trumpets, a mahogany grand piano, instruments that probably aren't available to the public..." << endl;
                    cout << "Who would need this many instruments?" << endl;
                }
            }
            else if (get_x() == 2)
            {
                if (get_y() == 0)
                {
                    cout << "A standard bathroom." << endl;
                    cout << "There's a fresh razor by the sink, not even out of the package." << endl;
                }
                else if (get_y() == 1)
                {
                    cout << "Stairs that lead up to the third floor, or down to the first floor." << endl;
                }
                else if (get_y() == 2)
                {
                    cout << "Mr. Wright's study and the scene of the crime." << endl;
                    cout << "Officer Harrison has already started bagging evidence with a pair of tongs." << endl;
                    cout << "It seems like he's left aside a blue stuffed rabbit and a manila folder--you recognize it as the preliminary autopsy report." << endl;
                }
            }
            break;
        case 3:
            if(get_x() == 0)
            {
                if (get_y() == 0)
                {
                    cout << "This room seems to be under renovation." << endl;
                }
                else if (get_y() == 1)
                {
                    cout << "A concrete balcony with a cast-iron railing." << endl;
                    cout << "There's a small glass bottle sitting on the railing..." << endl;
                    cout << "Whatever used to be inside it is long gone, but it stained the bottle brown." << endl;
                    if (!itemCheck("rusty key"))
                    {
                        cout << "There's also a little key here." << endl;
                    }
                }
                else if (get_y() == 2)
                {
                    cout << "This room seems to be under renovation." << endl;
                }
            }
            else if (get_x() == 1)
            {
                if (get_y() == 0)
                {
                    cout << "A young girl's playroom." << endl;
                    cout << "There's a blue stuffed rabbit sitting on a child-sized table." << endl;
                }
                else if (get_y() == 1)
                {
                    cout << "A young boy's playroom." << endl;
                    cout << "It's surprisingly neat.  Every toy is organized by size and color." << endl;
                }
                else if (get_y() == 2)
                {
                    cout << "A standard bathroom." << endl;
                }
            }
            else if (get_x() == 2)
            {
                if (get_y() == 0)
                {
                    cout << "The bedroom of a little girl." << endl;
                    cout << "Alice Wright combs the hair of a porcelain doll with a bright grin on her face." << endl;
                }
                else if (get_y() == 1)
                {
                    cout << "Stairs that lead down to the second floor." << endl;
                }
                else if (get_y() == 2)
                {
                    cout << "The bedroom of a little boy." << endl;
                    cout << "Adam Wright is obsessively picking at his fingernails and mumbling something under his breath." << endl;
                }
            }
            break;
    }
}

void Character::talk()
{
    int answer;
    if(get_floor() == 1)
    {
        if(get_x() == 0 && get_y() == 1)  // Mrs. Wright Dialogue
        {
            cout << "Mrs. Wright sobs loudly as you approach." << endl;
            cout << "1. \"Mrs. Wright?\"" << endl;
            if (itemCheck("wedding ring"))
            {
                cout << "2. \"About this wedding ring...\"" << endl;
            }
            if (itemCheck("wine bottle"))
            {
                cout << "3. \"About this wine bottle...\"" << endl;
            }
            cin >> answer;
            while (answer != 1 && answer != 2 && answer != 3)
            {
                cout << "Invalid answer.  Please try again." << endl;
                cin >> answer;
            }

            if (answer == 1)
            {
                cout << R"("That's me," Mrs. Wright sobs.  "The widow of Alastair Wright.")" << endl;
                cout << R"("Are you all right?")" << endl;
                cout << R"("Am I ALL RIGHT?! My husband is dead, you massive, useless oaf!")" << endl;
                cout << "Maybe you should come back later." << endl;
            }
            else if (answer == 2 && itemCheck("wedding ring"))
            {
                wife_sus = true;
                cout << "Mrs. Wright pauses and stares at you." << endl;
                cout << R"("My ring," she says quietly.  "Yes, it was our anniversary today.  Our 20th anniversary...")" << endl;
                cout << "She breaks down into another fit of tears." << endl;
            }
            else if (answer == 3 && itemCheck("wine bottle"))
            {
                cout << "Mrs. Wright sighs." << endl;
                cout << R"("I loved Alastair, but the man never knew when to stop drinking," she says wistfully.")" << endl;
                cout << R"("Isn't your niece a recovering alcoholic?")" << endl;
                cout << R"("Well, yes, but she's been very good.  I don't think she knew about the wine anyways.")" << endl;
                cout << R"("Are you absolutely certain?")" << endl;
                cout << R"("I know my cousin, Detective )" << get_name() << R"(.")"<< endl;
            }

        }
        else if (get_x() == 1 && get_y() == 0) //Anne Dialogue
        {
            cout << "The maid lifts her head as you approach." << endl;
            cout << R"(1. "Who are you?")" << endl;
            if (itemCheck("knife"))
            {
                cout << R"(2. "Why is there a knife here?")" << endl;
            }
            cin >> answer;
            while (answer != 1 && answer != 2)
            {
                cout << "Invalid answer.  Please try again." << endl;
                cin >> answer;
            }

            if(answer == 1)
            {
                cout << R"("Anne," the woman says with a little bow.  "At your service, sir.")" << endl;
            }
            else if(answer == 2 && itemCheck("knife"))
            {
                staff_sus = true;
                cout << "Anne goes a bit pale and clears her throat." << endl;
                cout << R"("An error on my part," she says stiffly.  "Please forgive my impudence.")" << endl;
                cout << R"("This knife is incredibly clean.  Why bother cleaning it and leaving it out?")" << endl;
                cout << "...it doesn't seem like Anne's taking any more questions." << endl;
            }
        }
        else if (get_x() == 1 && get_y() == 1) //Butler dialogue
        {
            cout << "The butler straightens his back and tailcoat as you get close." << endl;
            cout << R"("I saw nothing," he says quickly.  "I invoke the fifth amendment.")" << endl;
            cout << "Another officer will probably deal with him later..." << endl;
        }

        else if (get_x() == 1 && get_y() == 2) //Beth dialogue
        {
            cout << R"("What?" Beth snaps as you approach.)" << endl;
            cout << R"(1. "Where were you last night?")" << endl;
            if (itemCheck("wine bottle"))
            {
                cout << R"(2. "Did you know about this?")" << endl;
            }
            cin >> answer;
            while (answer != 1 && answer != 2)
            {
                cout << "Invalid answer.  Please try again." << endl;
                cin >> answer;
            }

            if(answer == 1)
            {
                cout << R"("I was here," Beth says.  "Aunt Meredith never lets me go anywhere else.")" << endl;
                cout << R"("Never?")" << endl;
                cout << R"("She's too worried I'll break into her secret stash or something.  She doesn't really think I'm clean, for...whatever reason.")" << endl;
                cout << "Beth's widely-televised rehab escapes are probably why, but you don't tell her that." << endl;
            }
            else if (answer == 2 && itemCheck("wine bottle"))
            {
                beth_sus = true;
                cout << "Beth's eyes go wide at the sight of the bottle." << endl;
                cout << R"("I knew it! I KNEW she was drinking behind my back! When I see Aunt Meredith again, I'll--")" << endl;
                cout << "You politely remind her that she is in the company of a police officer and should probably mind what she says." << endl;
            }
        }
        else if (get_x() == 2 && get_y() == 0)
        {
            cout << "The chef glares at the shiny badge on your chest." << endl;
            cout << R"(1. "Who are you?")" << endl;
            if (itemCheck("knife"))
            {
                cout << R"(2. "Explain the knife on the table.")" << endl;
            }
            cin >> answer;
            while (answer != 1 && answer != 2)
            {
                cout << "Invalid answer.  Please try again." << endl;
                cin >> answer;
            }
            if (answer == 1)
            {
                cout << R"("Chef Milton," the chef says.)" << endl;
                cout << R"("Do you have a last name?")" << endl;
                cout << R"("Milton.")" << endl;
                cout << R"("...your name is Milton Milton?")" << endl;
                cout << R"("Maybe.  I'm not tellin' you, cop.")" << endl;
                cout << "He seems like a really nice guy." << endl;
            }
            else if (answer == 2 && itemCheck("knife"))
            {
                cout << R"(Chef Milton shrugs and tucks something--probably tobacco--under his tongue.)" << endl;
                cout << R"("Must've been one of the waitstaff got careless after dinner," he says.  "They work long shifts.  Sometimes it happens.")" << endl;
                cout << R"("Having it happen the night your boss gets stabbed to death is a little...coincidental, isn't it?")" << endl;
                cout << R"("It sure is.")" << endl;
            }
        }
        else if (get_x() == 2 && get_y() == 2)
        {
            cout << "The gardener gets startled by your presence, but rightens herself quickly." << endl;
            cout << R"(1. "You're the one who called the police?")" << endl;
            cout << R"(2. "Did you hear anything unusual?")" << endl;
            if(itemCheck("gnome"))
            {
                cout << R"(3. "Tell me a bit about this...strange gnome.")" << endl;
            }
            cin >> answer;
            while (answer != 1 && answer != 2 && answer!= 3)
            {
                cout << "Invalid answer.  Please try again." << endl;
                cin >> answer;
            }

            if (answer == 1)
            {
                cout << R"("That I am," the gardener says in a thick British accent.  "Miss Marjorie Thornwood.  Oh, it's right dreadful what they did to Mr. Wright...")" << endl;
                cout << R"("So you're the one that found the body?")" << endl;
                cout << R"("If only.  Poor Miss Alice found him in the study upstairs.  Came wailing to me like a banshee.")" << endl;
                cout << R"("And Alice is...?")" << endl;
                cout << R"("Mr. Wright's youngest.  Her and her twin brother Adam have been sent to their rooms on the third floor for the time being.  Don't want them seeing all this mess, you see.")" << endl;
            }
            else if (answer == 2)
            {
                cout << R"("Unusual?")" << endl;
                cout << R"("Thumping, yelling, anything like that.")" << endl;
                cout << R"(Marjorie shakes her head.)" << endl;
                cout << R"("I was fast asleep until Alice woke me up.  Could hardly hear a peep from outside the room, let alone a room across the way,")" << endl;
                cout << "So Marjorie probably didn't hear the murder take place..." << endl;
            }
            else if (answer == 3 && itemCheck("gnome"))
            {
                cout << R"(Marjorie furrows her brow as she inspects the headless gnome.)" << endl;
                cout << R"("Oh, this little fellow," she mutters.  "That loon Ralph, Ronnie, whatever his name is--he tried to give Gustav here a 'makeover' with that fancy new paint of his.")" << endl;
                cout << R"("New paint?")" << endl;
                cout << R"("That...red paint he flaunts everywhere.  He's had it since last week.  Says its made of crushed opals or whatnot, but it really just smells like a pile of salt and metal.  Nothing opal-ly to it!")" << endl;
                cout << "You may not be a master painter, but last you checked, paint isn't supposed to smell like salt and metal." << endl;
            }
        }
        else
        {
            cout << "There's no one to talk to in here." << endl;
        }
    }
    if (get_floor() == 2)
    {
        if (get_x() == 0)
        {
            if (get_y() == 0)
            {
                cout << "Johnathan doesn't look at you." << endl;
                cout << "...it doesn't seem like he'll talk to you, either." << endl;
            }
            if (get_y() == 2)
            {
                cout << "The little girl beams as you approach." << endl;
                cout << R"(1. "Who are you?")" << endl;
                cin >> answer;
                while (answer != 1 && answer != 2)
                {
                    cout << "Invalid answer.  Please try again." << endl;
                    cin >> answer;
                }

                if (answer == 1)
                {
                    cout << R"("Suzy," says the girl.)" << endl;
                    cout << R"("Hi, Suzy.  What are you up to?")" << endl;
                    cout << R"("Waiting for Mr. Alastair to show up.")" << endl;
                    cout << R"("I'm...not sure he will.")" << endl;
                    cout << R"("He will." Suzy glares up at you.  "I know he will.")" << endl;
                    cout << "A cold chill runs down your spine." << endl;
                }
            }
        }
        else if (get_x() == 1)
        {
            if (get_y() == 1)
            {
                cout << R"("Ah, hello!" the painter announces as you come closer.)" << endl;
                cout << R"(1. "Who are you?")" << endl;
                if (itemCheck("bucket"))
                {
                    cout << R"(2. "Care to explain the bucket?")" << endl;
                }
                cin >> answer;
                while (answer != 1 && answer != 2)
                {
                    cout << "Invalid answer.  Please try again." << endl;
                    cin >> answer;
                }

                if (answer == 1)
                {
                    cout << R"("I!" The painter waves his hands dramatically.  "Am the legendary artist Raphael deMarco.")" << endl;
                    cout << R"("Legendary? How come I've never heard of you before?")" << endl;
                    cout << R"(Raphael does not appreciate that remark.  "I am the Wright's private artist," he sniffs.)" << endl;
                }
                else if (answer == 2 && itemCheck("bucket"))
                {
                    artist_sus = true;
                    cout << R"(Raphael glances down at the bucket by his feet.)" << endl;
                    cout << R"("Ah, my new Rich Crimson.  Made from ground beetle shells and stirred with the essence of opals to give it a sheer finish.")" << endl;
                    cout << R"("It looks like blood to me.")" << endl;
                    cout << R"("Blood?!" Raphael sputters.  "Don't be ridiculous.  Blood is much more of a mauve tone.  This is pure crimson! Pure!! Can't you tell the difference?!")" << endl;
                    cout << "You cannot, in fact, tell the difference." << endl;
                    cout << "You've offended Raphael with your lack of knowledge." << endl;
                }
            }
        }
        else if (get_x() == 2)
        {
            if (get_y() == 2)
            {
                cout << "Officer Harrison tips his hat to you." << endl;
                cout << R"("Detective )" << get_name() << R"(.")" << endl;
                cout << R"("Officer Harrison.")" << endl;
                cout << R"("Got any clue who the murderer could be?")" << endl;

                cout << R"(1. "Still working on it...")" << endl;
                if (artist_sus)
                {
                    cout << R"(2. "Raphael")" << endl;
                }
                if (beth_sus)
                {
                    cout << R"(3. "Beth")" << endl;
                }
                if (staff_sus)
                {
                    cout << R"(4. "The staff")" << endl;
                }
                if (alice_sus)
                {
                    cout << R"(5. "Alice")" << endl;
                }
                if (wife_sus)
                {
                    cout << R"(6. "Mrs. Wright")" << endl;
                }
                cin >> answer;
                while (answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5 && answer != 6)
                {
                    cout << "Invalid answer.  Please try again." << endl;
                    cin >> answer;
                }

                switch(answer)
                {
                    case 1:
                        cout << R"("Well, get on it quick, detective.")" << endl;
                        break;

                    case 2:
                        murderer_pick = true;
                        artist_murder = true;
                        cout << R"("Look into the painter a few rooms away.  He's got a suspicious bucket of...something.")" << endl;
                        cout << R"(Officer Harrison frowns.  "You think he's the type to kill for authenticity?)" << endl;
                        cout << R"("Well, if it got him the right color of paint...")" << endl;
                        cout << R"("Fair point, I guess.  All right, I'll put in a background check for him.")" << endl;
                        break;

                    case 3:
                        murderer_pick = true;
                        beth_murder = true;
                        cout << R"("They have a recovering alcoholic living with them.")" << endl;
                        cout << R"("Maybe Beth found out they were having drinks without her and the withdrawls got to her.")" << endl;
                        cout << R"("She's done pretty crazy stuff," Officer Harrison admits.  "Remember that story about her drinking actual paint for a high?")" << endl;
                        cout << R"("Don't have to do a background check right now.  Just figure out if anyone can corroborate where she was at the time of the murder.")" << endl;
                        cout << R"("Yes, Detective.")" << endl;
                        break;

                    case 4:
                        murderer_pick = true;
                        staff_murder = true;
                        cout << R"("All of them?" Officer Harrison lifts a brow.  "At once?")" << endl;
                        cout << R"("Well, maybe not all at once...but they were collaborating, I'm sure.")" << endl;
                        cout << R"("Okay...how?")" << endl;
                        cout << R"("Well, think about it.  The servants have seen pretty shut up about this whole affair, right?")" << endl;
                        cout << R"("Yeah, their boss was murdered.  They might be in shock.")" << endl;
                        cout << R"("Maybe, or they're staying silent to cover for each other.  Either way, I want you to check it out.")" << endl;
                        cout << R"("Yes, Detective.")" << endl;
                        break;

                    case 5:
                        murderer_pick = true;
                        alice_murder = true;
                        cout << R"("That kid was WAY too eager about her dad dying.")" << endl;
                        cout << R"("Still..." Officer Harrison shrugs.  "I dunno how I feel about accusing a kid.")" << endl;
                        cout << R"("Potential murderer, Harrison.  Small, but a potential murderer nonetheless.")" << endl;
                        cout << R"("She's 8.")" << endl;
                        cout << R"("She's a suspect.  Look into it.")" << endl;
                        cout << R"("...yes, Detective.")" << endl;
                        break;

                    case 6:
                        murderer_pick = true;
                        wife_murder = true;
                        cout << R"("Mrs. Wright seems to be grieving pretty hard.")" << endl;
                        cout << R"(Harrison's words are punctuated by a wail from downstairs.)" << endl;
                        cout << R"("True...but that's the reason why no one's asked for her alibi yet, isn't it? Try and wrangle one out of the staff.")" << endl;
                        cout << R"("Yes, Detective.")" << endl;
                        break;
                }
            }
        }

    }
    if (get_floor() == 3)
    {
        if (get_x() == 2)
        {
            if (get_y() == 0)
            {
                cout << "Alice looks up at you with a smile." << endl;
                cout << R"(1. "Who are you?")" << endl;
                if (itemCheck("rabbit"))
                {
                    cout << R"(2. "Is this yours?")" << endl;
                }
                cin >> answer;
                while (answer != 1)
                {
                    cout << "Invalid answer.  Please try again." << endl;
                    cin >> answer;
                }

                if (answer == 1)
                {
                    cout << R"(The girl holds her hand out as if expecting you to shake it.)" << endl;
                    cout << R"("Alice Wright," she says cheerfully, "hairy parrot to the Wright estate!")" << endl;
                    cout << R"("...sorry, the what?")" << endl;
                    cout << R"("The hairy parrot! With Dad dead and Johnathan being pathetic, I'm next in line for the inheritance!")" << endl;
                    cout << R"("Wouldn't that be your mother?")" << endl;
                    cout << R"("No.  Dad never loved her as much as he loved me.")" << endl;
                    cout << "Jeez.  Conniving kid.  She doesn't even know how to say heir apparent yet." << endl;
                }
                else if (answer == 2 && itemCheck("rabbit"))
                {
                    alice_sus = true;
                    cout << R"(Alice's eyes go cold when you show her the stuffed rabbit.)" << endl;
                    cout << R"("Where did you get that," she snaps.)" << endl;
                    cout << R"("Your dad's study.  Any idea what it was doing there?")" << endl;
                    cout << R"("Not a clue.  Why don't you figure it out? That's your job.")" << endl;
                }
            }
        }
    }
}
void Character::get_item(const char* itemName)
{

    if (inventory == NULL)
    {
        delete inventory; //delete NULL inventory
        inventory_size++; // increase size by one, giving us one inventory space
        inventory = new string[inventory_size]; // reallocates memory to an array of length inventory_size
        inventory[0] = itemName;
    }
    else
    {

        string* temp;
        temp = new string[inventory_size];
        for (int i = 0; i < inventory_size; i++)
        {
            temp[i] = inventory[i]; // copy inventory values to temp array
        }
        delete[]inventory;
        inventory_size++;
        inventory = new string[inventory_size];
        for(int i = 0; i < inventory_size-1; i++)
        {
            inventory[i+1] = temp[i]; // copy inventory values FROM temp array (since we have an additional space, need to scoot inventory[i] over by 1
        }
        inventory[0] = itemName; // assign first member of the array
        delete[]temp; //free up temp memory

    }
}
void Character::takeItem()
{
    if (get_floor() == 1)
    {
        if (get_x() == 1)
        {
            if (get_y() == 0)
            {
                get_item("knife");
                cout << "You got a stainless steel knife." << endl;
            }
        }
        else if (get_x() == 2)
        {
            if (get_y() == 2)
            {
                cout << "You got a stained, headless gnome." << endl;
                get_item("gnome");
            }
        }
        else
        {
            cout << "There's nothing to take here!" << endl;
        }
    }
    else if (get_floor() == 2)
    {
        if (get_x() == 0)
        {
            if (get_y() == 1)
            {
                get_item("wine bottle");
                get_item("wedding ring");
                cout << "You picked up the wine bottle and wedding ring." << endl;
            }
        }
        else if (get_x() == 1)
        {
            if (get_y() == 1)
            {
                get_item("bucket");
                cout << "You take note of the artist's bucket of 'red paint'.  It smells like metal." << endl;
            }
        }
        else if (get_x() == 2)
        {
            if (get_y() == 2)
            {
                get_item("rabbit");
                get_item("autopsy report");
                cout << "You got a stuffed rabbit and an autopsy report." << endl;
            }
        }
        else
        {
            cout << "There's nothing to take here!" << endl;
        }
    }
    else if (get_floor() == 3)
    {
        if (get_x() == 0)
        {
            if (get_y() == 1)
            {
                get_item("rusty key");
                cout << "You got the key, but what does it unlock?" << endl;
            }
        }
        else
        {
            cout << "There's nothing to take here!" << endl;
        }
    }
}

bool Character::itemCheck(const string& itemName) {
    bool haveItem = false;

    for (int i = 0; i < inventory_size; i++) {
        if (inventory[i] == itemName) {
            haveItem = true;
        }
    }
    if (haveItem) {
        return true;
    } else {
        return false;
    }

}