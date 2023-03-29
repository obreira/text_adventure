#include <iostream>
#include <string>
#include <cstdlib> // for rand() function
#include <ctime>   // for time() function
using namespace std;

class Elf
{
private:
    int health;
    int strength;
    int agility;
    int defense;
    int maxHealth;
    string name;

public:
    Elf(string n)
    {
        health = 100;
        strength = 50;
        agility = 75;
        defense = 5;
        name = n;
        maxHealth = 150;
    }

    int getHealth() const
    {
        return health;
    }

    int getStrength() const
    {
        return strength;
    }

    int getAgility() const
    {
        return agility;
    }

    int getDefense()
    {
        return defense;
    }
    int getmaxHealth()
    {
        return maxHealth;
    }

    string getName() const
    {
        return name;
    }
    void takeDamage(int damage)
    {
        health -= damage;
    }
    void restoreHealth()
    {
        health = maxHealth;

        cout << name << "have restored to full health points. Your current health is " << health << "." << endl;
    }

    bool dodgeTrap()
    {
        int trapDifficulty = rand() % 100 + 1;  // generate a random number between 1 and 100 for the trap difficulty
        int agilityRoll = rand() % agility + 1; // generate a random number between 1 and the elf's agility for the agility roll
        if (agilityRoll > trapDifficulty)
        {

            return true; // trap successfully dodged
        }
        else
        {
            health -= 10; // decrease Elf's health by 10
            return false; // trap not dodged, Elf takes damage
        }
    }
    int turnCombat() // iniciative roll
    {
        int strenghtRoll = rand() % 20 + 1; // generate a random number between 1 and the elf's agility for the agility roll

        return strenghtRoll;
    }
};
class Goblin
{
private:
    int health;
    int strength;
    int agility;
    int defense;
    string name;

public:
    Goblin(string n)
    {
        health = 25;
        strength = 15;
        agility = 30;
        defense = 2;
        name = n;
    }
    int
    getHealth() const
    {
        return health;
    }

    int getStrength() const
    {
        return strength;
    }

    int getAgility() const
    {
        return agility;
    }

    int getDefense()
    {
        return defense;
    }

    void takeDamage(int damage)
    {
        health -= damage;
    }
    int turnCombat() // iniciative roll
    {
        int strenghtRoll = rand() % 20 + 1; // generate a random number between 1 and the elf's agility for the agility roll
        return strenghtRoll;
    }
};
class Human
{
private:
    int health;
    int strength;
    int agility;
    int defense;
    string name;
    int maxHealth;

public:
    Human(string n)
    {
        health = 150;
        strength = 100;
        agility = 40;
        defense = 5;
        name = n;
        maxHealth = 150;
    }

    int
    getHealth() const
    {
        return health;
    }

    int getStrength() const
    {
        return strength;
    }

    int getAgility() const
    {
        return agility;
    }

    int getDefense()
    {
        return defense;
    }
    string getName() const
    {
        return name;
    }
    int getmaxHealth() const
    {
        return maxHealth;
    }
    void takeDamage(int damage)
    {
        health -= damage;
    }
    void restoreHealth()
    {
        health = maxHealth;

        cout << name << " have restored to full health points. Your current health is " << health << "." << endl;
    }

    bool dodgeTrap()
    {
        int trapDifficulty = rand() % 100 + 1;  // generate a random number between 1 and 100 for the trap difficulty
        int agilityRoll = rand() % agility + 1; // generate a random number between 1 and the elf's agility for the agility roll
        if (agilityRoll > trapDifficulty)
        {
            return true; // trap successfully dodged
        }
        else
        {
            health -= 10;
            return false; // trap not dodged, human takes damage
        }
    }

    int turnCombat() // iniciative roll
    {
        int strenghtRoll = rand() % 20 + 1; // generate a random number between 1 and the elf's agility for the agility roll

        return strenghtRoll;
    }
};
int main()
{
    string nameE;
    string nameH;
    string nameG;

    getline(cin, nameG);
    Goblin myGoblin(nameG);

    cout << "Enter the Elf's name: ";
    getline(cin, nameE);
    Elf myElf(nameE);

    cout << "Enter the Human's name: ";
    getline(cin, nameH);
    Human myHuman(nameH);

    // Print out the attributes for each character using the getter functions
    cout << "\n"
         << myElf.getName() << " attributes:\n";
    cout << "Health: " << myElf.getHealth() << endl;
    cout << "Strength: " << myElf.getStrength() << endl;
    cout << "Agility: " << myElf.getAgility() << endl;
    cout << "Defense " << myElf.getDefense() << "\n"
         << endl;

    cout << "\n"
         << myHuman.getName() << " attributes:\n";
    cout << "Health: " << myHuman.getHealth() << endl;
    cout << "Strength: " << myHuman.getStrength() << endl;
    cout << "Agility: " << myHuman.getAgility() << endl;
    cout << "Defense: " << myHuman.getDefense() << "\n"
         << endl;

    cout << "Once upon a time, in a vast and ancient forest, a human named" << myHuman.getName() << " and an elf named " << myElf.getName() << " set out on a quest to find a long-lost treasure.\n"
                                                                                                                                               "The treasure was said to be hidden deep within the forest, guarded by powerful magic and dangerous creatures.";
    cout << "As they made their way through the dense undergrowth, Jack and Elara encountered all sorts of obstacles, from treacherous ravines to deadly traps.\n";

    cout << "You come across a trap in the road!\n";
    if (myElf.dodgeTrap())
    {
        cout << "You continue on your journey unscathed. \n";
    }
    else
    {
        cout << "You take 10 damage from the trap!\n";
        cout << "Current Health: " << myHuman.getHealth() << "\n";
    }
    cout << "After passing the trap, " << myHuman.getName() << " and " << myElf.getName() << " see a light ahead on the road.\n";
    cout << "Do you: \n";
    cout << "1) Go towards the light and see what it is.\n";
    cout << "2) Go in to the forest, try and sneak in closer to the light.\n";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You cautiously approach the light, and find that it is a campfire with 2 goblins sitting around it.\n";
        break;
    case 2:

        cout << (myElf.getAgility() >= 75 ? "You manage to sneak up on the campfire, and find that it is a goblin campfire with 2 goblins sitting around it.\n" : "You try to sneak up on the campfire, but you are heard and the campers flee.\n");

        break;

    default:
        cout << "Invalid choice. You wander aimlessly through the forest.\n";
    }

    if (choice == 1)
    {

        cout << "The goblins hear you and turn around to atack you\n \n";
        while (myElf.getHealth() > 0 && myGoblin.getHealth() > 0)
        {
            if (myElf.turnCombat() > myGoblin.turnCombat())
            {

                // Display attack options for the player to choose from
                cout << "Choose your attack: " << endl;
                cout << "1) Quick Attack (50% chance to hit for 5-10 damage)" << endl;
                cout << "2) Power Attack (30% chance to hit for 10-20 damage)" << endl;
                cout << "3) Defensive Attack (70% chance to hit for 3-5 damage, reduces Enemy's next attack by 50%)" << endl;
                cin >> choice;

                // Character attacks based on player's choice
                switch (choice)
                {
                case 1: // Quick Attack
                    if (rand() % 2 == 0)
                    { // 50% chance to hit
                        int enemyAttack;
                        enemyAttack = rand() % 6 + 5;
                        int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 5-10
                        myGoblin.takeDamage(damage);
                        cout << "You hit the Goblin for " << damage << " damage.\n \n"
                             << endl;
                    }
                    else
                    {
                        cout << "Your attack missed!" << endl;
                    }
                    break;

                case 2: // Power Attack
                    if (rand() % 10 < 3)
                    {
                        int enemyAttack;
                        enemyAttack = rand() % 11 + 10;
                        int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 10-20
                        myGoblin.takeDamage(damage);
                        cout << "You hit the Goblin for " << damage << " damage.\n \n"
                             << endl;
                    }
                    else
                    {
                        cout << "Your attack missed!\n \n"
                             << endl;
                    }
                    break;

                case 3: // Defensive atack
                    if (rand() % 10 < 7)
                    {
                        int enemyAttack;
                        enemyAttack = rand() % 3 + 3;
                        int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 3-5
                        myGoblin.takeDamage(damage);
                        cout << "You hit the Goblin for " << damage << " damage.\n \n"
                             << endl;
                        myGoblin.takeDamage(damage / 2); // Reduce Enemy's next attack by 50%
                        cout << "Your attack also weakened the enemy's next attack! \n \n"
                             << endl;
                    }
                    else
                    {
                        cout << "Your attack missed!\n \n"
                             << endl;
                    }
                    break;
                    return 0;
                }
            }
            else if (myHuman.turnCombat() > myGoblin.turnCombat())
            {
                // Display attack options for the player to choose from
                cout << "Choose your attack: " << endl;
                cout << "1) Quick Attack (50% chance to hit for 5-10 damage)" << endl;
                cout << "2) Power Attack (30% chance to hit for 10-20 damage)" << endl;
                cout << "3) Defensive Attack (70% chance to hit for 3-5 damage, reduces Enemy's next attack by 50%)" << endl;
                cin >> choice;

                // Character attacks based on player's choice
                switch (choice)
                {
                case 1: // Quick Attack
                    if (rand() % 2 == 0)
                    {
                        int enemyAttack;
                        enemyAttack = rand() % 6 + 5;
                        int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 5-10
                        myGoblin.takeDamage(damage);
                        cout << "You hit the Goblin for " << damage << " damage.\n \n"
                             << endl;
                    }
                    else
                    {
                        cout << "Your attack missed!" << endl;
                    }
                    break;

                case 2: // Power Attack
                    if (rand() % 10 < 3)
                    {
                        int enemyAttack;
                        enemyAttack = rand() % 11 + 10;
                        int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 10-20
                        myGoblin.takeDamage(damage);
                        cout << "You hit the Goblin for " << damage << " damage.\n \n"
                             << endl;
                    }
                    else
                    {
                        cout << "Your attack missed!" << endl;
                    }
                    break;

                case 3: // Defensive atack
                    if (rand() % 10 < 7)
                    {
                        int enemyAttack;
                        enemyAttack = rand() % 3 + 3; // Random damage between 3-5
                        int damage = enemyAttack - myGoblin.getDefense();
                        myGoblin.takeDamage(damage);
                        cout << "You hit the Goblin for " << damage << " damage.\n \n"
                             << endl;
                        myGoblin.takeDamage(damage / 2); // Reduce Enemy's next attack by 50%
                        cout << "Your attack also weakened the enemy's next attack!\n \n"
                             << endl;
                    }
                    else
                    {
                        cout << "Your attack missed!\n \n"
                             << endl;
                    }
                    break;
                    return 0;
                }
            }

            else

            {
                int enemyAttack = rand() % myGoblin.getStrength() + 1; // Random Enemy Attack
                int damage = enemyAttack - myElf.getDefense();         // Calculate damage based on Enemy's Attack and Player's Defense
                if (damage < 0)
                {
                    damage = 0; // If damage is negative, set it to 0
                }
                myElf.takeDamage(damage); // Reduce Player's health by calculated damage
                cout << "The Goblin hit you for " << damage << " damage!\n \n"
                     << endl;
            }
        }
    }
    if (choice == 2)
    {
        cout << "Choose what to do: " << endl;
        cout << "1) Assassinate" << endl;
        cout << "2) Engage" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: // Assassinate
        {
            int enemyAttack;
            enemyAttack = rand() % 999 + 99;
            int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 5-10
            myGoblin.takeDamage(damage);
            cout << "You hit the Goblin for " << damage << " damage.\n";
        }
        break;

        case 2: // Engage

            cout << "You attack the goblins from behind\n";
            {
                while (myElf.getHealth() > 0 && myGoblin.getHealth() > 0)
                {
                    if (myElf.turnCombat() > myGoblin.turnCombat())
                    {

                        // Display attack options for the player to choose from
                        cout << "Choose your attack: " << endl;
                        cout << "1) Quick Attack (50% chance to hit for 5-10 damage)" << endl;
                        cout << "2) Power Attack (30% chance to hit for 10-20 damage)" << endl;
                        cout << "3) Defensive Attack (70% chance to hit for 3-5 damage, reduces Enemy's next attack by 50%)" << endl;
                        cin >> choice;

                        // Character attacks based on player's choice
                        switch (choice)
                        {
                        case 1: // Quick Attack
                            if (rand() % 2 == 0)
                            { // 50% chance to hit
                                int enemyAttack;
                                enemyAttack = rand() % 6 + 5;
                                int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 5-10
                                myGoblin.takeDamage(damage);
                                cout << "You hit the Goblin for " << damage << " damage.\n"
                                     << endl;
                            }
                            else
                            {
                                cout << "Your attack missed!" << endl;
                            }
                            break;

                        case 2: // Power Attack
                            if (rand() % 10 < 3)
                            {
                                int enemyAttack;
                                enemyAttack = rand() % 11 + 10;
                                int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 10-20
                                myGoblin.takeDamage(damage);
                                cout << "You hit the Goblin for " << damage << " damage.\n"
                                     << endl;
                            }
                            else
                            {
                                cout << "Your attack missed!" << endl;
                            }
                            break;

                        case 3: // Defensive atack
                            if (rand() % 10 < 7)
                            {
                                int enemyAttack;
                                enemyAttack = rand() % 3 + 3;
                                int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 3-5
                                myGoblin.takeDamage(damage);
                                cout << "You hit the Goblin for " << damage << " damage.\n"
                                     << endl;
                                myGoblin.takeDamage(damage / 2); // Reduce Enemy's next attack by 50%
                                cout << "Your attack also weakened the enemy's next attack!" << endl;
                            }
                            else
                            {
                                cout << "Your attack missed!" << endl;
                            }
                            break;
                            return 0;
                        }
                    }
                    else if (myHuman.turnCombat() > myGoblin.turnCombat())
                    {
                        // Display attack options for the player to choose from
                        cout << "Choose your attack: " << endl;
                        cout << "1) Quick Attack (50% chance to hit for 5-10 damage)" << endl;
                        cout << "2) Power Attack (30% chance to hit for 10-20 damage)" << endl;
                        cout << "3) Defensive Attack (70% chance to hit for 3-5 damage, reduces Enemy's next attack by 50%)" << endl;
                        cin >> choice;

                        // Character attacks based on player's choice
                        switch (choice)
                        {
                        case 1: // Quick Attack
                            if (rand() % 2 == 0)
                            {
                                int enemyAttack;
                                enemyAttack = rand() % 6 + 5;
                                int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 5-10
                                myGoblin.takeDamage(damage);
                                cout << "You hit the Goblin for " << damage << " damage.\n"
                                     << endl;
                            }
                            else
                            {
                                cout << "Your attack missed!" << endl;
                            }
                            break;

                        case 2: // Power Attack
                            if (rand() % 10 < 3)
                            {
                                int enemyAttack;
                                enemyAttack = rand() % 11 + 10;
                                int damage = enemyAttack - myGoblin.getDefense(); // Random damage between 10-20
                                myGoblin.takeDamage(damage);
                                cout << "You hit the Goblin for " << damage << " damage.\n"
                                     << endl;
                            }
                            else
                            {
                                cout << "Your attack missed!" << endl;
                            }
                            break;

                        case 3: // Defensive atack
                            if (rand() % 10 < 7)
                            {
                                int enemyAttack;
                                enemyAttack = rand() % 3 + 3; // Random damage between 3-5
                                int damage = enemyAttack - myGoblin.getDefense();
                                myGoblin.takeDamage(damage);
                                cout << "You hit the Goblin for " << damage << " damage.\n"
                                     << endl;
                                myGoblin.takeDamage(damage / 2); // Reduce Enemy's next attack by 50%
                                cout << "Your attack also weakened the enemy's next attack!" << endl;
                            }
                            else
                            {
                                cout << "Your attack missed!" << endl;
                            }
                            break;
                            return 0;
                        }
                    }

                    else
                    {
                        int enemyAttack = rand() % myGoblin.getStrength() + 1; // Random Enemy Attack
                        int damage = enemyAttack - myElf.getDefense();         // Calculate damage based on Enemy's Attack and Player's Defense
                        if (damage < 0)
                        {
                            damage = 0; // If damage is negative, set it to 0
                        }
                        myElf.takeDamage(damage); // Reduce Player's health by calculated damage
                        cout << "The Goblin hit you for " << damage << " damage!" << endl;
                    }
                }
            }
            break;

        default:
        {
            cout << "Invalid choice.\n";
            break;
            return 0;
        }
        }
        cout << "After your fight you restored your health after resting for a while near the camp fire.\n";
        myElf.restoreHealth();
        myHuman.restoreHealth();
    }
    // continue the adventure after the fight
    cout << "You defeated the goblin! You have a moment to catch your breath and take stock of your surroundings.\n";
    cout << "To your left, you see a narrow path that leads into the woods. To your right, you see a dirt road that appears to lead to a small village.\n";
    cout << "What do you do?\n";
    cout << "1) Take the path into the woods.\n";
    cout << "2) Follow the dirt road to the village.\n";

    int choice2;
    cin >> choice2;

    switch (choice2)
    {
    case 1:
        cout << "You decide to take the path into the woods. The trees are dense and the undergrowth is thick, making it difficult to see far ahead. You proceed cautiously, keeping your guard up for any signs of danger.\n";
        // more adventure code here
        break;

    case 2:
        cout << "You decide to follow the dirt road to the village. After walking for some time, you come across a small hamlet nestled in a valley. Smoke rises from the chimneys of the thatched-roof cottages, and you can hear the sounds of livestock and people going about their daily business.\n";
        // more adventure code here
        break;

    default:
        cout << "Invalid choice.\n";
        break;
    }
    if (choice2 == 1)
    {
        cout << "You follow the path deeper into the forest.\n";
        cout << "As you continue down the path, you come across a wise old ent standing in your way.\n";
        cout << "The ent challenges you to solve a riddle before he will let you pass.\n";
        cout << "Here is the riddle:\n";
        cout << "I am always hungry, I must always be fed. The finger I touch, Will soon turn red. What am I?\n";

        // Wait for player to input answer to riddle
        string answer;
        cin >> answer;

        // Check if answer is correct
        if (answer == "fire")
        {
            cout << "The ent is pleased with your answer and lets you pass.\n";
            cout << "Further down the path, you find a chest containing a treasure.\n";
            // Add code for player to obtain the treasure
        }
        else
        {
            cout << "The ent shakes his head and says 'Incorrect, you shall not pass!'\n";
            // Add code for player to continue the adventure without obtaining the treasure
        }
    }
    else
    {
        // Follow the road to the village
        cout << "You decide to follow the road and it leads you to a small village.\n";
        cout << "As you enter the village, you are greeted by a group of villagers.\n";
        cout << "They ask you what brings you to their village.\n";

        // Wait for player to input reason for being there
        string reason;
        cin >> reason;

        // Villagers send players on a quest to find the treasure
        cout << "The villagers tell you about a treasure that was lost deep in the forest.\n";
        cout << "They believe that only a brave adventurer like you can retrieve it.\n";
        cout << "They provide you with a map of the forest and wish you luck on your journey.\n";
        // Add code for players to obtain the map and continue the adventure
    }

    cout << "The villagers tell you that they heard about a treasure hidden in the forest. They give you a map and send you on your way.\n";
    cout << "You head into the forest and soon find yourself standing in front of a massive tree. As you approach, you realize that it's an Ent, a tree-like creature that speaks like a human.\n";
    cout << "The Ent greets you and says, \"Welcome, travelers. I have a riddle for you. Solve it, and I will guide you to the treasure.\"\n";
    cout << "\"I am always hungry, I must always be fed. The finger I touch, will soon turn red. What am I?\"\n";

    int answer;
    bool answered_correctly = false;

    while (!answered_correctly)
    {
        cout << "Do you:\n";
        cout << "1) Answer 'fire'\n";
        cout << "2) Answer 'water'\n";
        cout << "3) Answer 'wind'\n";

        cin >> answer;

        if (answer == 1)
        {
            cout << "The Ent nods approvingly. \"Well done! The treasure lies at the foot of the mountain to the west.\"\n";
            // Code for finding the treasure in the west mountain
        }
        else
        {
            cout << "The Ent shakes its head. \"I'm sorry, that's incorrect. Please try again.\"\n";
            // Code for giving the player another chance to answer the riddle
        }
    }
    cout << "Finally, you reach the spot where the treasure was said to be hidden.\n";
    cout << "But to your surprise, you find that it's not a chest filled with gold and jewels, but a small tree that glows with a magical light.\n";
    cout << "As you approach it, the tree begins to pulse with a warm energy, filling you with a sense of peace and fulfillment.\n";
    cout << "Realizing that this is the treasure you've been seeking, " << myHuman.getName() << " and " << myElf.getName() << " reach out to touch the tree.\n";
    cout << "As you do, you are enveloped in a bright light.\n";
    cout << "When you emerge, you find yourselves standing at the edge of the forest, the treasure in your hearts and memories that you will never forget.\n";
    cout << "Congratulations on completing your adventure!\n";
}