#include "ModelManager.h"

#include <memory>
#include "Unit.h"

sbe::ModelManager::ModelManager(std::shared_ptr<sf::RenderWindow> window) : window(window)
{
	this->window = std::move(window);
}

void sbe::ModelManager::update(float delta)
{
	for (auto object : updatableObjects)
	{
		object->update(*window, delta);
	}
}

void sbe::ModelManager::addUnit()
{
	std::shared_ptr<Unit> unit(new Unit());
	updatableObjects.push_back(unit);
	if (notify != nullptr)
	{
		notify(unit);
	}
}

void sbe::ModelManager::setSubscriber(std::function<void(std::shared_ptr<Unit>)> f)
{
	notify = f;
}

std::vector<std::shared_ptr<sbe::IUpdatable>> sbe::ModelManager::getUpdatableObjects() const
{
	return updatableObjects;
}