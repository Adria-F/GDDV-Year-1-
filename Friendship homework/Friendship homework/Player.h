#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Item.h"
#include <iostream>
using namespace std;

class Player
{
private:
	char name[15];
	unsigned short numLifes;
	bool invincible;
	bool* capabilities = (bool*)malloc(3 * sizeof(bool));
	bool* weapon = (bool*)malloc(3 * sizeof(bool));

public:

	Player(char iName[])
	{
		sprintf_s(name, iName);

		numLifes = 3;
		invincible = false;
		for (int i = 0; i < 3; i++)
		{
			weapon[i] = false;
			capabilities[i] = false;
		}
		capabilities[1] = true;
	}

	~Player()
	{
		free(capabilities);
		free(weapon);
	}

	char* getName()
	{
		return name;
	}

	void PrintNumLifes() const
	{
		cout << "Number of lifes: " << numLifes << endl;
	}

	void PrintInvincible() const
	{
		cout << "Is player invincible?: " << ((invincible) ? "Yes" : "No") << endl;
	}

	void PrintCapabilities() const
	{
		for (int i = 0; i < 3; i++)
		{
			if (capabilities[i] == true)
			{
				cout << "Capability on: ";
				switch (i)
				{
				case 0:
					cout << "Mini Mario" << endl;
					break;
				case 1:
					cout << "Normal Mario" << endl;
					break;
				case 2:
					cout << "Super Mario" << endl;
					break;
				}
				break;
			}
		}
	}

	void printWeapon() const
	{
		for (int i = 0; i < 3; i++)
		{
			if (weapon[i] == true)
			{
				cout << "Weapon on: ";
				switch (i)
				{
				case 0:
					cout << "Fire Ball" << endl;
					break;
				case 1:
					cout << "Ice Ball" << endl;
					break;
				case 2:
					cout << "Golden Fire Ball" << endl;
					break;
				}
				break;
			}
		}
	}

	bool operator==(const Player& player2)
	{
		return (*this->name == * player2.name);
	}

	void useItem(Item item)
	{
		if (strncmp(item.name, "One_Up", 6) == 0)
		{
			this->numLifes++;
		}
		else if (strncmp(item.name, "Mini_Mario", 10) == 0)
		{
			for (int i = 0; i < 3; i++)
			{
				capabilities[i] = false;
			}
			capabilities[0] = true;
		}
		else if (strncmp(item.name, "Super_Mario", 11) == 0)
		{
			for (int i = 0; i < 3; i++)
			{
				capabilities[i] = false;
			}
			capabilities[2] = true;
		}
		else if (strncmp(item.name, "Fire_Flower", 11) == 0)
		{
			for (int i = 0; i < 3; i++)
			{
				weapon[i] = false;
			}
			weapon[0] = true;
		}
		else if (strncmp(item.name, "Ice_Flower", 10) == 0)
		{
			for (int i = 0; i < 3; i++)
			{
				weapon[i] = false;
			}
			weapon[1] = true;
		}
		else if (strncmp(item.name, "Golden_Flower", 13) == 0)
		{
			for (int i = 0; i < 3; i++)
			{
				weapon[i] = false;
			}
			weapon[2] = true;
		}
	}

	friend void starTouched(Player& player);
};

#endif // !__PLAYER_H__