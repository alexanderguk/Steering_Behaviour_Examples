#include "ControllerManager.h"

sbe::ControllerManager::ControllerManager(ModelManager& modelManager) : modelManager(modelManager)
{

}

void sbe::ControllerManager::update(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::MouseMoved:
			for (auto object : modelManager.getUpdatableObjects())
			{
				if (typeid(*object) == typeid(Unit))
				{
					auto unit = std::dynamic_pointer_cast<Unit>(object);
					unit->setTarget(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
				}
			}
			break;
		}
	}
}