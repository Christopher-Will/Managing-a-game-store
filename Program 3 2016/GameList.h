#ifndef GAME_LIST 
#define GAME_LIST 
#include <string>
#include <vector>
#include "Game.h"
using namespace std;

class GameList {
public: 
	GameList(); // the default constructor
	~GameList(); // the destructor

	void insert(string gn, int gc, double gp, double gs); // insert a new game into the list
	void search(string Gname); //search the list for any games that contain Gname in them
	void remove(string Gname); //deletee the board game Gname from the list if it exists
	void display(Game obj);
	void print(); //print the the game records based on lexicographical order

private:
	bool inlist; // bool to see if a game is currently in the vector of game objects
	int gameCount; // total number of games in stock
	vector<Game> glist; // vector to store the Game objects currently in stock
};
#endif 