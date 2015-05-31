#include "ControllerManager.h"

#include "Wander.h"
#include "Seek.h"
#include "Flee.h"
#include "Pursuit.h"
#include "Evade.h"
#include <memory>

sbe::ControllerManager::ControllerManager() : currentBehaviour(0)
{

}

void sbe::ControllerManager::update(sf::RenderWindow& window, ModelManager& modelManager, ViewManager& viewManager)
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
			onMouseMoved(ev, window, modelManager);
			break;
		case::sf::Event::KeyPressed:
			onKeyPressed(ev, modelManager, viewManager);
			break;
		}
	}
}

void sbe::ControllerManager::onMouseMoved(sf::Event ev, sf::RenderWindow& window, ModelManager& modelManager) const
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

void sbe::ControllerManager::onKeyPressed(sf::Event ev, ModelManager& modelManager, ViewManager& viewManager)
{
	if (ev.key.code == sf::Keyboard::Space)
	{
		currentBehaviour++;
		switch (currentBehaviour)
		{
		case 0:
			seek(modelManager, viewManager);
			break;
		case 1:
			flee(modelManager, viewManager);
			break;
		case 2:
			wander(modelManager, viewManager);
			break;
		case 3:
			pursuit(modelManager, viewManager);
			break;
		case 4:
			evade(modelManager, viewManager);
			break;
		default:
			currentBehaviour = 0;
			seek(modelManager, viewManager);
			break;
		}
	}
}

void sbe::ControllerManager::seek(ModelManager& modelManager, ViewManager& viewManager) const
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
	viewManager.setDemoName("Seek");
}

void sbe::ControllerManager::flee(ModelManager& modelManager, ViewManager& viewManager) const
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
	viewManager.setDemoName("Flee");
}

void sbe::ControllerManager::wander(ModelManager& modelManager, ViewManager& viewManager) const
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
	viewManager.setDemoName("Wander");
}

void sbe::ControllerManager::pursuit(ModelManager& modelManager, ViewManager& viewManager) const
{
	modelManager.deleteAllUnits();
	auto targetUnit = modelManager.addUnit(150, 50);
	targetUnit->setStrategy(std::shared_ptr<Seek>(new Seek()));
	modelManager.addUnit(100, 50)->setStrategy(std::shared_ptr<Pursuit>(new Pursuit(targetUnit)));
	viewManager.setDemoName("Pursuit");
}

void sbe::ControllerManager::evade(ModelManager& modelManager, ViewManager& viewManager) const
{
	modelManager.deleteAllUnits();
	auto targetUnit = modelManager.addUnit(100, 50);
	targetUnit->setStrategy(std::shared_ptr<Seek>(new Seek()));
	for (auto i = 0; i < 10; ++i)
	{
		modelManager.addUnit(100, 50)->setStrategy(std::shared_ptr<Evade>(new Evade(targetUnit)));
		viewManager.setDemoName("Evade");
	}
}