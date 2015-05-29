#include "World.h"
#include <SFML/Graphics.hpp>

sbe::World::World(std::shared_ptr<sf::RenderWindow> window) : modelManager(), viewManager(window, modelManager)
{
	this->window = std::move(window);
}

void sbe::World::run()
{
	init();

	sf::Clock clock;
	while (window->isOpen())
	{
		update(static_cast<double>(clock.restart().asMicroseconds()) / 1000000);
		draw();
	}
}

void sbe::World::init()
{
	modelManager.addUnit();
}

void sbe::World::update(double delta)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
	modelManager.update(delta);
}

void sbe::World::draw()
{
	window->clear(sf::Color(60, 60, 60, 255));
	viewManager.draw();
	window->display();
}