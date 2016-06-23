// Game class to store the attributes of each game

#ifndef GAME_H
#define GAME_H 
#include <string>
using namespace std;
class Game
{
public:
	Game(string n, int c, double p, double s); // overloaded constructor
	Game(); //default constructor

private:
	string name; //game name
	int count; //number of copies in stock
	double price; //game price
	double score; //user score, in the range [0, 10.0]
friend class GameList; //allow the GameList class to implicitly access the Games class private data
};
#endif

