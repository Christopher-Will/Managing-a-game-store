#include "Game.h"

Game::Game() //default constructor
{
	name = "";
	count = 0;
	price = 0;
	score = 0;
}

Game::Game(string n, int c, double p, double s) // overloaded constructor
{
	name = n;
	count = c;
	price = p;
	score = s;
}

