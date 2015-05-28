#include "ViewManager.h"
#include "UnitView.h"
#include "ModelManager.h"

sbe::ViewManager::ViewManager(std::shared_ptr<sf::RenderWindow> window, ModelManager& modelManager) : window(window)
{
	modelManager.setSubscriber(std::bind(&ViewManager::addUnitView, this, std::placeholders::_1));
}

void sbe::ViewManager::draw()
{
	for (auto object : drawableObjects)
	{
		object->draw(*window.get());
	}
}

void sbe::ViewManager::addUnitView(std::shared_ptr<Unit> unit)
{
	std::shared_ptr<UnitView> unitView(new UnitView(unit));
	drawableObjects.push_back(unitView);
}