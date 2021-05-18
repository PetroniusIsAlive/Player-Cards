#include"PlayerRanklist.h"


void PLayerRanklist::resizeArray()
{
	this->capacity *= 2;
	 
	Player *sub = new Player[this->capacity];
	for (int i = 0; i < size; i++)
	{
		sub[i] = this->players[i];
	}

	delete[] this->players;
	players = sub;
}

PLayerRanklist::PLayerRanklist(): size(0), capacity(3)
{
	this->players = new Player[this->capacity];
}

PLayerRanklist::PLayerRanklist(const int capacity): size(0)
{
	this->capacity = capacity;
	this->players = new Player[this->capacity];
}

PLayerRanklist::~PLayerRanklist()
{
	delete[] this->players;
}

void PLayerRanklist::printData()
{
	for (int i = 0; i < size; i++) 
	{
		std::cout << players[i];
	}
	
}

void PLayerRanklist::addPlayers(const Player& other)
{
	if (size >= capacity)
	{
		resizeArray();
        players[size++] = other;
		
	}
	else 
	{
		players[size++] = other;
		
	}
	
}

void PLayerRanklist::savePlayers()
{
	
	
	for (int i = 0; i < size; i++) 
	{
		players[i].savePlayer();
	}
}

void PLayerRanklist::loadPlayers()
{
	int pCount = 0;
	int counter = 0;
	std::string name;
	std::cout << "Loadable players: " << this->size << std::endl;
		std::cout << "How many to load: ";
		std::cin >> pCount;
		std::cout << '\n';

	for (int i = 0; i < pCount; i++)
	{
		std::cout << "Enter player name number " << ++counter << ':';
		std::cin >> name;
		players[i].load(name);


	}

		
		
}


