#include "ControllerManager.h"

#include "Wander.h"
#include "Seek.h"
#include "Flee.h"
#include "Pursuit.h"
#include "Evade.h"
#include <memory>

sbe::ControllerManager::ControllerManager()
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
		if (currentBehaviour.getCurrentDemoName() == "Seek")
		{
			seek(modelManager);
		}
		else if (currentBehaviour.getCurrentDemoName() == "Flee")
		{
			flee(modelManager);
		}
		else if (currentBehaviour.getCurrentDemoName() == "Wander")
		{
			wander(modelManager);
		}
		else if (currentBehaviour.getCurrentDemoName() == "Pursuit")
		{
			pursuit(modelManager);
		}
		else if (currentBehaviour.getCurrentDemoName() == "Evade")
		{
			evade(modelManager);
		}
		viewManager.setDemoName(currentBehaviour.getCurrentDemoName());
	}
	else if (ev.key.code == sf::Keyboard::Add)
	{
		if (currentBehaviour.getCurrentDemoName() == "Seek")
		{
			modelManager.addUnit()->setStrategy(std::shared_ptr<Seek>(new Seek()));
		}
		else if (currentBehaviour.getCurrentDemoName() == "Flee")
		{
			modelManager.addUnit()->setStrategy(std::shared_ptr<Flee>(new Flee()));
		}
		else if (currentBehaviour.getCurrentDemoName() == "Wander")
		{
			modelManager.addUnit()->setStrategy(std::shared_ptr<Wander>(new Wander()));
		}
		else if (currentBehaviour.getCurrentDemoName() == "Pursuit")
		{

		}
		else if (currentBehaviour.getCurrentDemoName() == "Evade")
		{

		}
	}
	else if (ev.key.code == sf::Keyboard::Subtract)
	{
		if (currentBehaviour.getCurrentDemoName() == "Seek")
		{
			modelManager.deleteUnit();
		}
		else if (currentBehaviour.getCurrentDemoName() == "Flee")
		{
			modelManager.deleteUnit();
		}
		else if (currentBehaviour.getCurrentDemoName() == "Wander")
		{
			modelManager.deleteUnit();
		}
		else if (currentBehaviour.getCurrentDemoName() == "Pursuit")
		{

		}
		else if (currentBehaviour.getCurrentDemoName() == "Evade")
		{

		}
	}
}

void sbe::ControllerManager::seek(ModelManager& modelManager) const
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

void sbe::ControllerManager::flee(ModelManager& modelManager) const
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

void sbe::ControllerManager::wander(ModelManager& modelManager) const
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

void sbe::ControllerManager::pursuit(ModelManager& modelManager) const
{
	modelManager.deleteAllUnits();
	auto targetUnit = modelManager.addUnit(150, 50);
	targetUnit->setStrategy(std::shared_ptr<Seek>(new Seek()));
	modelManager.addUnit(100, 50)->setStrategy(std::shared_ptr<Pursuit>(new Pursuit(targetUnit)));
}

void sbe::ControllerManager::evade(ModelManager& modelManager) const
{
	modelManager.deleteAllUnits();
	auto targetUnit = modelManager.addUnit(100, 50);
	targetUnit->setStrategy(std::shared_ptr<Seek>(new Seek()));
	for (auto i = 0; i < 10; ++i)
	{
		modelManager.addUnit(100, 50)->setStrategy(std::shared_ptr<Evade>(new Evade(targetUnit)));
	}
}