#include "UnitView.h"

#include "AdvMath.h"
#include "Wander.h"

sbe::UnitView::UnitView(std::shared_ptr<Unit> unit, sf::Sprite newSprite) : unit(unit), sprite(newSprite)
{
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

void sbe::UnitView::draw(sf::RenderWindow& window)
{
	sprite.setPosition(unit->getPosition());
	sprite.setRotation(static_cast<float>(atan2(unit->getVelocity().y, unit->getVelocity().x) * sbe::AdvMath::toDegrees));
	window.draw(sprite);
	/*
	if (unit->getStrategy() != nullptr && typeid(*unit->getStrategy()) == typeid(sbe::Wander))
	{
 		auto wander = std::dynamic_pointer_cast<sbe::Wander>(unit->getStrategy());

		sf::CircleShape circle(wander->getCircleRadius());
		sf::Vector2f circleCenter = sbe::AdvMath::normalize(unit->getVelocity());
		circleCenter.x *= wander->getCircleDistance();
		circleCenter.y *= wander->getCircleDistance();
		circle.setPosition(unit->getPosition() + circleCenter);
		circle.setOrigin(circle.getRadius(), circle.getRadius());
		circle.setFillColor(sf::Color::Blue);
		window.draw(circle);

		sf::Vertex line2[] =
		{
			sf::Vertex(unit->getPosition()),
			sf::Vertex(unit->getPosition() + wander->getWanderForce())
		};

		window.draw(line2, 2, sf::Lines);
	}

	sf::Vertex line[] =
	{
		sf::Vertex(unit->getPosition()),
		sf::Vertex(unit->getPosition() + unit->getVelocity())
	};

	window.draw(line, 2, sf::Lines);
	*/
}

std::shared_ptr<sbe::Unit> sbe::UnitView::getUnit() const
{
	return unit;
}