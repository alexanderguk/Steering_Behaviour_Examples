#include "UnitView.h"

sbe::UnitView::UnitView(std::shared_ptr<Unit> unit)
{
	this->unit = unit;
}

void sbe::UnitView::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle(10);
	circle.setPosition(static_cast<float>(unit->getX()), static_cast<float>(unit->getY()));
	window.draw(circle);
}