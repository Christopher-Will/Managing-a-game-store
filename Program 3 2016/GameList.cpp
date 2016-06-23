#include "GameList.h"
#include "Game.h"
#include <iostream>
using namespace std;

GameList::GameList() //default constructor
{
	gameCount = 0; // set game count to 0
	glist; // initialize the vector to hold game objects
	inlist = false; // initialize this bool to false since the game is likely not in the list
}

void GameList::insert(string gn, int gc, double gp, double gs)
{
	int i = 0; // iteration variable
	int vec_length = glist.size(); // variable to hold current size of the game list
	while( i < vec_length && !inlist)
	{
		if(glist[i].name==gn) // see if the board game is already in the list
		{ // update all the values of the game to the most recent values given by user
			gameCount-=glist[i].count;
			gameCount+=gc;
			glist[i].count = gc;
			glist[i].price = gp;
			glist[i].score = gs;
			inlist = true; // game was in the list so change this bool to true
		}
		i++;
	}
 	if(!inlist) // game isn't in list already, so must add it to the list in lexicographical order
	{
		Game max("holder",0,0,0); // object to hold game name with highest lexicographical value
		Game mygame(gn,gc,gp,gs); // create a game object with values provided by the user
		gameCount = gameCount + gc; // update the value of gameCount
		glist.push_back(mygame); // add this new game to the vector
		int new_vec_length = glist.size();
		for(int  i = 0; i < new_vec_length; i++) // arrange the objects in alphabetical order based on their game name
		{
			for(int j = 0; j < new_vec_length; j++)
				{
					if(glist[i].name < glist[j].name) //swap the ith and jth elements 
					{
						max = glist[i];
						glist[i] = glist[j];
						glist[j] = max;
					}
				}
		}

	}
}
void GameList::print()  
{
	int gc = gameCount;
	int vec_length = glist.size(); // variable to hold current size of the game list
	cout << "--------------Total: " << gameCount << " copies of games in Stock------------" << endl;
	for(int i = 0; i < vec_length; i++) //loop over each object in the glist vector
	{
		cout << "Game name: "<< glist[i].name << " # of copies: " << glist[i].count << endl;
		cout << "Price: " << glist[i].price << " User score: " << glist[i].score << endl; 
	}
	cout << "----------------------------------------------------------" << endl;
}

void GameList::remove(string GName)
{
	int vec_length = glist.size(); // variable to hold current size of the game list
	int i = 0; // iteration variable
	while(i < vec_length && !inlist) //loop over the vector until GName was found, or the contents have been exhausted
	{
		if(glist[i].name==GName)
		{
			gameCount = gameCount - glist[i].count; // update the value of the gameCount
			inlist = true; // game to be removed was found in the list
			int pos = i; 
			for(int j = pos+1; j < vec_length; j++) // shift all the elements down so that this game object can be removed
				glist[j-1]=glist[j];
			glist.pop_back();
			cout << "Game with name " << GName << " has been deleted " << endl;
		}
		i++;
	}
	if(!inlist) // game was not found in the list
		cout << "Game with name " << GName << " is not in the list. Deletion failed " << endl;
}

void GameList::search(string Gname)
{
	int games_found = 0; // int to hold how many games with the Gname have been found in the list
	int vec_length = glist.size(); // variable to hold current size of the game list
	for(int i = 0; i < vec_length; i++) // search each object in the vector of Game objects
	{
		if(glist[i].name.find(Gname) != string::npos)
		{
			cout << "Game name:  "<< glist[i].name << " # of copies: " << glist[i].count << endl;
			cout << "Price: " << glist[i].price << " User score: " << glist[i].score << endl; 	
			games_found++; // found a game, so increment this counter by 1
		}
	}
	if(games_found==0)
		cout << "No Matched Game is in stock" << endl;
}

GameList::~GameList() 
{
}