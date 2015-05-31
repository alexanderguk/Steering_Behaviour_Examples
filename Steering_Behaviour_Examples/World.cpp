#include "World.h"
#include "Seek.h"
#include <SFML/Graphics.hpp>

sbe::World::World(std::shared_ptr<sf::RenderWindow> window) : window(window), modelManager(window), 
viewManager(window, modelManager), controllerManager(modelManager)
{
	
}

void sbe::World::run()
{
	init();

	sf::Clock clock;
	while (window->isOpen())
	{
		update(static_cast<float>(clock.restart().asMicroseconds()) / 1000000);
		draw();
	}
}

void sbe::World::init()
{
	modelManager.deleteAllUnits();
	modelManager.addUnit(150);
	for (auto object : modelManager.getUpdatableObjects())
	{
		if (typeid(*object) == typeid(Unit))
		{
			auto unit = std::dynamic_pointer_cast<Unit>(object);
			unit->setStrategy(std::shared_ptr<Seek>(new Seek()));
		}
	}
}

void sbe::World::update(float delta)
{
	controllerManager.update(*window);
	modelManager.update(delta);
}

void sbe::World::draw()
{
	window->clear(sf::Color(200, 200, 200, 255));
	viewManager.draw();
	window->display();
}

int sbe::World::getWidth() const
{
	return window->getSize().x;
}

int sbe::World::getHeight() const
{
	return window->getSize().y;
}