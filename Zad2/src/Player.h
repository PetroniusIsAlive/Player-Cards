#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
#include<sstream>
#include <cstdlib>
#include <filesystem>





class Player
{
private:
	char* playerName = nullptr;
	char* teamName = nullptr;
	int victories = 0;
	int losses = 0;
    bool looper( char* arr1, char* arr2);
	bool compareson(const Player& other);
	int playerCount = 1;
	

public:
	Player();
	Player(const char* playerName, const char* teamName, const size_t victories, const size_t losses );
	Player(const Player& other);
	~Player();
	Player& operator ++(const int victories);
	Player& operator --(const int losses);
	bool operator ==(const Player& other);
	bool operator !=(const Player& other);
	friend std::ostream& operator <<(std::ostream& os, Player& player);
	friend std::istream& operator >>(std::istream& is, Player& player);
	Player& operator =(const Player& other);
	void savePlayer();
	Player& load(const std::string pName);
	void print();
	void print(std::ostream& os);
	void replace(const Player& other);
	void setPlayerName(const char* name);
	void setTeamName(const char* name);
	void setVictories(const int victories);
	void setLosses(const int losses);

};