#include "Pokemon.h"
#include "ElectricPokemon.h"
#include "GrassPokemon.h"
#include "FirePokemon.h"
#include "WaterPokemon.h"

int main()
{
	Pokemon* pikachu = new ElectricPokemon("Pikachu");
	Pokemon* bulbasur = new GrassPokemon("Bulbasur");
	Pokemon* charmander = new FirePokemon("Charmander");
	Pokemon* squirtle = new WaterPokemon("Squirtle");

	std::cout << "-- Damage Attacks --" << std::endl;
	std::cout << pikachu->getName() << " -> " << bulbasur->getName() << " = " << pikachu->damageAttack(bulbasur) << " units\n";
	std::cout << bulbasur->getName() << " -> " << squirtle->getName() << " = " << bulbasur->damageAttack(squirtle) << " units\n";
	std::cout << squirtle->getName() << " -> " << charmander->getName() << " = " << squirtle->damageAttack(charmander) << " units\n";
	std::cout << charmander->getName() << " -> " << pikachu->getName() << " = " << charmander->damageAttack(pikachu) << " units\n\n";

	delete pikachu;
	delete bulbasur;
	delete charmander;
	delete squirtle;

	system("pause");
	return 0;
}