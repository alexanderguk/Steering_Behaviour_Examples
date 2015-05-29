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
					if (unit->getTargetMode() == 0)
					{
						unit->setTarget(
							sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
					}
				}
			}
			break;

		case::sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space)
			{
				for (auto object : modelManager.getUpdatableObjects())
				{
					if (typeid(*object) == typeid(Unit))
					{
						auto unit = std::dynamic_pointer_cast<Unit>(object);
						unit->nextMode();
					}
				}
			}
			else if (event.key.code == sf::Keyboard::LAlt)
			{
				for (auto object : modelManager.getUpdatableObjects())
				{
					if (typeid(*object) == typeid(Unit))
					{
						auto unit = std::dynamic_pointer_cast<Unit>(object);
						unit->nextTargetMode();
					}
				}
			}
			break;
		}
	}
}