#include "Player.h"
#include "Item.h"

void starTouched(Player& player)
{
	player.invincible = true;
}

int main()
{
	cout << "Write the name of the player: ";
	char str[15];
	cin >> str;
	Player player(str);

	bool running = true;
	while (running)
	{
		cout << "Introduce the name of an Item, 'Star' or 'Quit' : ";
		cin >> str;
		if (strncmp(str, "Star", 4) == 0)
		{
			starTouched(player);
		}
		else if (strncmp(str, "Quit", 4) == 0)
		{
			running = false;
			continue;
		}
		else
		{
			Item item(str);
			player.useItem(item);
		}
		cout << "Player name: " << player.getName() << endl;
		player.PrintNumLifes();
		player.PrintInvincible();
		player.PrintCapabilities();
		player.printWeapon();
		cout << endl;
	}

	return 0;
}