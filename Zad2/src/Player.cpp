#include"Player.h"

Player::Player(): victories(0), losses(0)
{
	playerName = new char[8];
	strcpy_s(this->playerName, 7, "D name");

	teamName = new char[7];
	strcpy_s(this->teamName, 7, "D name");

}

Player::Player(const char* playerName, const char* teamName, const size_t victories, const size_t losses)
{
	this->victories = victories;
	this->losses = losses;

	this->playerName = new char[strlen(playerName) + 1];
	strcpy_s(this->playerName, strlen(playerName) + 1, playerName);

	this->teamName = new char[strlen(teamName) + 1];
	strcpy_s(this->teamName, strlen(teamName) + 1, teamName);	
}

Player::Player(const Player& other)
{
	replace(other);
}

Player::~Player()
{
	delete[] this->playerName;
	delete[] this->teamName;
}

Player& Player::operator++(const int victories)
{
	this->victories += 1;

	return *this;
}

Player& Player::operator--(const int losses)
{
	this->losses += 1;
	return *this;
}

bool Player::compareson(const Player& other)
{
	bool sub = true;
	if (strlen(this->playerName) == strlen(other.playerName) || strlen(this->teamName) == strlen(other.teamName) )
	{
		
		sub = looper(this->playerName, other.playerName);
		if (sub == false) return false;
		sub = looper(this->teamName, other.playerName);
		if (sub == false) return false;
	}
	else return true;
}

bool Player::looper(char *arr1, char* arr2)
{
	for (int i = 0; i < strlen(arr1); i++)
	{
		if (arr1[i] != arr2[i]) 
		{
			return false;
		}
			

	}

}

bool Player::operator==(const Player& other)
{
	return compareson(other);	
}

bool Player::operator!=(const Player& other)
{
	return  !compareson(other);
}

Player& Player::operator=(const Player& other)
{
	delete[] playerName;
	delete[] teamName;

	replace(other);
	return *this;
}

void Player::savePlayer() 
{
	std::fstream myFile(this->playerName , std::ios::out);
	if (myFile)
	{
		playerCount++;
		myFile << this->playerName << '\n';
		myFile << this->teamName << '\n';
		myFile << this->victories << '\n';
		myFile << this->losses << '\n';
		myFile.close();
	}
}

Player& Player::load(const std::string pName)
{
	int counter = 0;

	char* buffer = new char[256];

	std::ifstream file(pName, std::ios::in);
	Player player;


	if (file)
		while (file.getline(buffer, 256))
		{

			switch (counter)
			{
			case 0:

				this->playerName = new char[strlen(buffer) + 1];
				strcpy_s(this->playerName, strlen(buffer) + 1, buffer);
				break;

			case 1:
				this->teamName = new char[strlen(buffer) + 1];
				strcpy_s(this->teamName, strlen(buffer) + 1, buffer);
				break;
			case 2:
			{
				std::stringstream ss(buffer);
				int i;
				if (ss >> i)
					this->victories = i;
				else
					std::cout << "error";

				break;
			}
			case 3:
			{
				std::stringstream ss(buffer);
				int i;
				if (ss >> i)
					this->losses = i;
				else
					std::cout << "error";

				break;
			}
			default:
				break;
			}

			counter++;
		}

	return *this;
}



void Player::print()
{
	this->print(std::cout);


}

void Player::print(std::ostream& os)
{
	os << '\n'
	 << "Player name: " << playerName << std::endl
	 << "Team name: " << teamName << std::endl
	 << "Victories: " << victories << std::endl
	 << "Losses: " << losses << std::endl
	 << '\n';
}

void Player::replace(const Player& other)
{
	this->playerName = new char[strlen(other.playerName) + 1];
	strcpy_s(this->playerName, strlen(other.playerName) + 1, other.playerName);
	this->teamName = new char[strlen(other.teamName) + 1];
	strcpy_s(this->teamName, strlen(other.teamName) + 1, other.teamName);

	this->victories = other.victories;
	this->losses = other.losses;
}

void Player::setPlayerName(const char* name)
{
	strcpy_s(this->playerName, strlen(name) + 1, name);
}

void Player::setTeamName(const char* name)
{
	strcpy_s(this->teamName, strlen(name) + 1, name);
}

void Player::setVictories(const int victories)
{
	this->victories = victories;
}

void Player::setLosses(const int losses)
{
	this->losses = losses;
}

std::ostream& operator<<(std::ostream& os, Player& player)
{
	player.print(os);
	return os;
}

std::istream& operator>>(std::istream& is, Player& player)
{
	delete[] player.playerName;
	delete[] player.teamName;

	
	std::cout << '\n';

	std::cout << "Enter player name(not bigger than 10 charecters): ";
	std::cin.getline(player.playerName, 10);
	std::cout << '\n';
	std::cout << "Enter team name(not bigger than 10 charecters): ";
	std::cin.getline(player.teamName, 10);
	std::cout << '\n';
	std::cout << "Enter victories count: ";
	std::cin >> player.victories;
	std::cout << '\n';
	std::cout << "Enter losses count: ";
	std::cin >> player.losses;
	std::cout << '\n';
	
	return is;
}