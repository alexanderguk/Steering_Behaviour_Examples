#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "World.h"

int main()
{
	std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(1280, 768), "SFML works!"));
	window->setVerticalSyncEnabled(true);

	sbe::World world(window);
	world.run();

	return 0;
}