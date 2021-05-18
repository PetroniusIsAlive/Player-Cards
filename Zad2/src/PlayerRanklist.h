#pragma once
#include"Player.h"




class PLayerRanklist
{
	Player* players;
	int size = 0, capacity = 0;
	void resizeArray();
	
public:
	PLayerRanklist();
	PLayerRanklist(const int capacity);
	~PLayerRanklist();
	void printData();
	void addPlayers(const Player& other);
	void savePlayers();
	void loadPlayers();
	
	
};