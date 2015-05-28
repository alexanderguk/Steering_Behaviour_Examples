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
		sf::Time delta = clock.restart();

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		modelManager.update(static_cast<double>(delta.asMicroseconds()) / 1000);

		window->clear();
		viewManager.draw();
		window->display();
	}
}

void sbe::World::init()
{
	modelManager.addUnit();
}

void sbe::World::update(double delta)
{

}

void sbe::World::draw()
{

}