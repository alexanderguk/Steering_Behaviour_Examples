#include "ViewManager.h"
#include "UnitView.h"
#include "ModelManager.h"

sbe::ViewManager::ViewManager(std::shared_ptr<sf::RenderWindow> window, ModelManager& modelManager) : window(window)
{
	texture.loadFromFile("unit.png");
	font.loadFromFile("tahoma.ttf");

	modelManager.setSubscriber(std::bind(&ViewManager::addUnitView, this, std::placeholders::_1));
}

void sbe::ViewManager::draw()
{
	for (auto object : drawableObjects)
	{
		object->draw(*window.get());
	}

	if (updateFpsClock.getElapsedTime().asSeconds() >= 0.5)
	{
		fps = static_cast<int>(1.0 / fpsClock.restart().asSeconds());
		updateFpsClock.restart();
	}
	else
	{
		fpsClock.restart();
	}
	sf::Text text;
	text.setString(std::string("FPS: ") + std::to_string(fps));
	text.setPosition(30, 30);
	text.setFont(font);
	window->draw(text);
}

void sbe::ViewManager::addUnitView(std::shared_ptr<Unit> unit)
{
	std::shared_ptr<UnitView> unitView(new UnitView(unit, sf::Sprite(texture, sf::IntRect(0, 0, 32, 32))));
	drawableObjects.push_back(unitView);
}