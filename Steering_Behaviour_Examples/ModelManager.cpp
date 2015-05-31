#include "ModelManager.h"

#include <memory>
#include "Unit.h"

sbe::ModelManager::ModelManager(std::shared_ptr<sf::RenderWindow> window) : window(window)
{
	this->window = window;
}

void sbe::ModelManager::update(float delta)
{
	for (auto object : updatableObjects)
	{
		object->update(*window, delta);
	}
}

std::shared_ptr<sbe::Unit> sbe::ModelManager::addUnit(float maxVelocity, float mass)
{
	std::shared_ptr<Unit> unit(new Unit(maxVelocity, mass));
	updatableObjects.push_back(unit);
	if (notify != nullptr)
	{
		notify(unit, true);
	}
	return unit;
}

std::shared_ptr<sbe::Unit> sbe::ModelManager::addUnit()
{
	return addUnit(50, 50);
}

void sbe::ModelManager::addUnit(int n)
{
	for (auto i = 0; i < n; ++i)
	{
		addUnit();
	}
}

void sbe::ModelManager::deleteUnit()
{
	auto i = std::begin(updatableObjects);
	while (i != std::end(updatableObjects))
	{
		if (typeid(**i) == typeid(Unit))
		{
			auto unit = std::dynamic_pointer_cast<Unit>(*i);
			notify(unit, false);
			updatableObjects.erase(i);
			break;
		}
	}
}

void sbe::ModelManager::deleteAllUnits()
{
	for (auto object : updatableObjects)
	{
		if (typeid(*object) == typeid(Unit))
		{
			auto unit = std::dynamic_pointer_cast<Unit>(object);
			notify(unit, false);
		}
	}
	updatableObjects.clear();
}

void sbe::ModelManager::setSubscriber(std::function<void(std::shared_ptr<Unit>, bool)> f)
{
	notify = f;
}

std::vector<std::shared_ptr<sbe::IUpdatable>> sbe::ModelManager::getUpdatableObjects() const
{
	return updatableObjects;
}