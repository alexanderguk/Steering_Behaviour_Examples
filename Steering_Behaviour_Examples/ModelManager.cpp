#include "ModelManager.h"
#include "Unit.h"
#include <memory>

void sbe::ModelManager::update(double delta)
{
	for (auto object : updatableObjects)
	{
		object->update(delta);
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