#include "UnitView.h"
#include "AdvMath.h"

sbe::UnitView::UnitView(std::shared_ptr<Unit> unit, sf::Sprite sprite) : unit(unit), sprite(sprite)
{
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

void sbe::UnitView::draw(sf::RenderWindow& window)
{
	sprite.setPosition(unit->getPosition());
	sprite.setRotation(static_cast<float>(atan2(unit->getVelocity().y, unit->getVelocity().x) * sbe::AdvMath::toDegrees));
	window.draw(sprite);
}