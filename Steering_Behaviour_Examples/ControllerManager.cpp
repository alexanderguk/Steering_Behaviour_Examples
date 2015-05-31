#include "ControllerManager.h"

#include "Wander.h"
#include "Seek.h"
#include "Flee.h"
#include "Pursuit.h"
#include "Evade.h"
#include <memory>

sbe::ControllerManager::ControllerManager(ModelManager& modelManager) : modelManager(modelManager), currentBehaviour(0)
{

}

void sbe::ControllerManager::update(sf::RenderWindow& window)
{
	sf::Event ev;
	while (window.pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseMoved:
			onMouseMoved(ev, window);
			break;
		case::sf::Event::KeyPressed:
			onKeyPressed(ev);
			break;
		}
	}
}

void sbe::ControllerManager::onMouseMoved(sf::Event ev, sf::RenderWindow& window) const
{
	for (auto object : modelManager.getUpdatableObjects())
	{
		if (typeid(*object) == typeid(Unit))
		{
			auto unit = std::dynamic_pointer_cast<Unit>(object);
			if (unit->getStrategy() != nullptr)
			{
				if (typeid(*unit->getStrategy()) == typeid(sbe::Seek))
				{
					auto seek = std::dynamic_pointer_cast<Seek>(unit->getStrategy());
					seek->setTarget(sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(window).x),
						static_cast<float>(sf::Mouse::getPosition(window).y)));
				}
				else if (typeid(*unit->getStrategy()) == typeid(sbe::Flee))
				{
					auto flee = std::dynamic_pointer_cast<Flee>(unit->getStrategy());
					flee->setTarget(sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(window).x),
						static_cast<float>(sf::Mouse::getPosition(window).y)));
				}
			}
		}
	}
}

void sbe::ControllerManager::onKeyPressed(sf::Event ev)
{
	if (ev.key.code == sf::Keyboard::Space)
	{
		currentBehaviour++;
		switch (currentBehaviour)
		{
		case 0:
			seek();
			break;
		case 1:
			flee();
			break;
		case 2:
			wander();
			break;
		case 3:
			pursuit();
			break;
		case 4:
			evade();
			break;
		default:
			currentBehaviour = 0;
			seek();
			break;
		}
	}
}

void sbe::ControllerManager::seek() const
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

void sbe::ControllerManager::flee() const
{
	modelManager.deleteAllUnits();
	modelManager.addUnit(150);
	for (auto object : modelManager.getUpdatableObjects())
	{
		if (typeid(*object) == typeid(Unit))
		{
			auto unit = std::dynamic_pointer_cast<Unit>(object);
			unit->setStrategy(std::shared_ptr<Flee>(new Flee()));
		}
	}
}

void sbe::ControllerManager::wander() const
{
	modelManager.deleteAllUnits();
	modelManager.addUnit(150);
	for (auto object : modelManager.getUpdatableObjects())
	{
		if (typeid(*object) == typeid(Unit))
		{
			auto unit = std::dynamic_pointer_cast<Unit>(object);
			unit->setStrategy(std::shared_ptr<Wander>(new Wander()));
		}
	}
}

void sbe::ControllerManager::pursuit() const
{
	modelManager.deleteAllUnits();
	auto targetUnit = modelManager.addUnit(150, 50);
	targetUnit->setStrategy(std::shared_ptr<Seek>(new Seek()));
	modelManager.addUnit(100, 50)->setStrategy(std::shared_ptr<Pursuit>(new Pursuit(targetUnit)));
}

void sbe::ControllerManager::evade() const
{
	modelManager.deleteAllUnits();
	auto targetUnit = modelManager.addUnit(100, 50);
	targetUnit->setStrategy(std::shared_ptr<Seek>(new Seek()));
	for (auto i = 0; i < 10; ++i)
	{
		modelManager.addUnit(100, 50)->setStrategy(std::shared_ptr<Evade>(new Evade(targetUnit)));
	}
}