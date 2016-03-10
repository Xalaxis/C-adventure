//Main function for the game
//Let's begin with our imports
#include <iostream>
#include <string> //Remove later if not needed?
using namespace std;

//Global var setup
int hp, food, hasshovel, hasmagic;
int ispoison, isparalyzed;
string location = "at the bottom of a ladder";
string look = "DEBUG";
string name;

int resetVar() //Resets the game's settings (soft-reset)
{
	//Define our initial variables
	hp = 100; //HealthPoints
	food = 100; //Food/Hunger
	name = "Adventurer"; //The player's name
	//And now inventory items
	hasshovel = 0, hasmagic = 0;
	//And now status conditions
	ispoison = 0, isparalyzed = 0;
	//Okay, that should be it
	return 0;
}

void whereAmI() //Where is the player?
{
	//return location; //Yeah, perhaps I shouldn't have this as a function

	cout << "You are currently " << location << endl;
}

void status() //What is the player's current status?
{
	cout << "Your name is " << name << endl; //Name
	cout << "Your HP is " << hp << "/100" << endl; //HP
	cout << "============================" << endl;
	cout << "Status effects: " << endl << endl;
	if (ispoison == 1 || isparalyzed == 1)
		cout << "Your movement is impaired" << endl;
	else
		cout << "Movement normal" << endl;
	if (ispoison == 1)
		cout << "You are poisoned" << endl;
	if (isparalyzed == 1)
		cout << "You are paralyzed" << endl;
	cout << "============================" << endl;
	cout << "Inventory:  " << endl;
}


void initialSetup() //Sets up the player's name amongst other things
{
	cout << "Okay player!  Let's get you setup." << endl << endl;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Thank you!" << endl;
	cout << "Initial setup is now complete." << endl << endl;

}

int main()
{
	resetVar(); //Setup our variables (technically shouldn't be needed unless after a reset, but worth having anyway)
	system("cls");
	system("color 0A");
	system("title An Adventure");
	initialSetup(); //Sets up settings
	status(); //Call to show the player their status
	whereAmI(); //Call to show the player where they are

	int gamecomplete = 0;
	while (gamecomplete != 1)
	{
		cout << "> ";
		string whatamidoing;
		getline(cin, whatamidoing);
		if (whatamidoing == "status") //The player is asking for their status
		{
			status();
		}
		else if (whatamidoing == "where am i?") //The player wants to know where they are
		{
			whereAmI();
		}
		else if (whatamidoing == "credits") //The player wants to see the credits
		{
			cout << "Matthew Wolffsohn" << endl;
			cout << "Leo Head" << endl;
			cout << "Ryan Cochrane" << endl;
		}
		else if (whatamidoing == "exit") //The player wants to exit the game
		{
			break;
		}
	}
	//Okay, that should be it
	cout << endl; //Cause otherwise the text will be strange
	return 0;
}

