#include "ControllerManager.h"

#include "Wander.h"
#include "Seek.h"
#include "Flee.h"
#include <memory>

sbe::ControllerManager::ControllerManager(ModelManager& modelManager) : modelManager(modelManager), currentBehaviour(0)
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
						unit->setTarget(sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(window).x), 
							static_cast<float>(sf::Mouse::getPosition(window).y)));
					}
				}
			}
			break;

		case::sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space)
			{
				currentBehaviour++;
				for (auto object : modelManager.getUpdatableObjects())
				{
					if (typeid(*object) == typeid(Unit))
					{
						auto unit = std::dynamic_pointer_cast<Unit>(object);
						switch (currentBehaviour)
						{
						case 0:
							unit->setStrategy(std::unique_ptr<Seek>(new Seek()));
							break;
						case 1:
							unit->setStrategy(std::unique_ptr<Flee>(new Flee()));
							break;
						case 2:
							unit->setStrategy(std::unique_ptr<Wander>(new Wander()));
							break;
						default:
							currentBehaviour = 0;
							unit->setStrategy(std::unique_ptr<Seek>(new Seek()));
							break;
						}
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