//Date: 11/17/2015
//Purpose: Maintain a list of board games and allow to insert, search, or delete games
// from this list
//Author: Christopher Will
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Game.h"
#include "GameList.h"

void pause_215(bool have_newline) //prompt user to press ENTER before quiting the program
{
    if (have_newline) {
        // Ignore the newline after the user's previous input.
        cin.ignore(256, '\n');
    }

    // Prompt for the user to press ENTER, then wait for a newline.
    cout << endl << "Press ENTER to continue." << endl;
    cin.ignore(256, '\n');
}

void ask_input() { // function to ask the user what they want to do 
	cout << "select from: " << endl;
	cout << "1. Insert a game record " << endl;
	cout << "2. Delete a game record " << endl;
	cout << "3. Print the game list " << endl;
	cout << "4. Search the game list " <<endl;
	cout << "5. Quit " << endl;
}

void validate_count(int &game_count) { // function to make sure they user gave a valid number for the game count
	while(game_count < 1 || cin.fail()) // see if user gave a non-intger input or input that was less than 1
	{
		if(cin.fail()) // reset the fail flag if they have a non-integer input
		{
			cin.clear();
			cin.ignore(256,'\n'); // ask for more input
			cout << "Must have at least 1 game in stock. Please enter again" << endl;
			cout << "Quantity: ";
			cin >> game_count;
		}
		else //tell the user that they have to have at least 1 game in stock
		{
			cout << "Must have at least 1 game in stock. Please enter again" << endl;
			cout << "Quantity: ";
			cin >> game_count;
		}
	}
}

void validate_price(double &game_price) { // function to make sure they user gave a valid number for the game price
	while(game_price < 1 || cin.fail()) 
	{
		if(cin.fail()) 
		{
			cin.clear();
			cin.ignore(256,'\n');
			cout << "Invalid price. Please try again." << endl;
			cout << "Price: ";
			cin >> game_price;
		}
		else 
		{
			cout << "Invalid price. Please try again." << endl;
			cout << "Price: ";
			cin >> game_price;
		}
	}
}

void validate_score(double &game_score) {// function to make sure they user gave a valid number for the game score
	while(game_score < 0 || game_score > 10 || cin.fail()) 
	{
		if(cin.fail()) 
		{
			cin.clear();
			cin.ignore(256,'\n');
			cout << "Invalid score. Must be in range of [0.0,10.0] Please try again." << endl;
			cout << "User score: ";
			cin >> game_score;
		}
		else 
		{
			cout << "Invalid score. Must be in range of [0.0,10.0] Please try again." << endl;
			cout << "User score: ";
			cin >> game_score;
		}
	}
}

int main() 
{

	GameList list; // create an object of the GameList class 
	cout << "This application stores a list of board games in stock for Wildcats Store." << endl;
	int user_choice;
	do // will ask for the users input at least 1 time with do-while loop
	{
		ask_input();
		cin >> user_choice;
		while(user_choice > 5 || user_choice < 1 || cin.fail()) // validate the user input
		{
			if(cin.fail()) 
			{
				cin.clear();
				cin.ignore(256,'\n');
				cout << "Invalid option. Please try again" << endl;
				ask_input();
				cin >> user_choice;
			}
			else
			{
				cout << "Invalid option. Please try again" << endl;
				ask_input();
				cin >> user_choice;
			}
		}
		
		if(user_choice==1) // insert the users game into the list
		{
			cout << "Please enter the name of the game: ";
			cin.ignore();
			string get_name;
			getline(cin,get_name); //get users input and store it in get_name

			cout << "Quantity in stock: ";
			int game_count;
			cin >> game_count;
			validate_count(game_count); // get the game_count and make sure it is valid

			cout << "Price: ";
			double game_price;
			cin >> game_price;
			validate_price(game_price); // get the price and make sure it is valid

			cout << "User score: ";
			double game_score;
			cin.ignore();
			cin.clear();
			cin >> game_score;
			validate_score(game_score); //get the score and then make sure it was valid

			list.insert(get_name,game_count,game_price,game_score); // insert the users game into the list object
		}
		if(user_choice==2) // delete the game from the list if it is actually in the list
		{
			string delete_game;
			cout << "Enter the name of the game you want to delete: ";
			cin.ignore();
			getline(cin,delete_game);
			list.remove(delete_game);
		}
		if(user_choice==3) // output the all the Game objects and their values 
		{
			list.print();
		}
		if(user_choice==4) // search for a game in the list
		{
			cout << "What is the key from the game name you want to search for? ";
			string search_str;
			cin.ignore();
			getline(cin,search_str);
			cout << "Searching '" << search_str << "':" << endl;
			list.search(search_str);
		}
	}while(user_choice!=5); // keep getting inputs so long as the user doesn't enter 5
	cout << "Thank you for using my program. " << endl;
	pause_215(true);
	return 0;
}