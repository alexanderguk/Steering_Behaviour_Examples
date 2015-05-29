#include "UnitView.h"
#include "AdvMath.h"

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
	if (unit->getTargetMode() == 2)
	{
		sf::CircleShape circle(unit->CIRCLE_RADIUS);
		sf::Vector2f circleCenter = sbe::AdvMath::normalize(unit->getVelocity());
		circleCenter.x *= unit->CIRCLE_DISTANCE;
		circleCenter.y *= unit->CIRCLE_DISTANCE;
		circle.setPosition(unit->getPosition() + circleCenter);
		circle.setOrigin(circle.getRadius(), circle.getRadius());
		circle.setFillColor(sf::Color::Blue);
		window.draw(circle);
	}

	sf::Vertex line[] =
	{
		sf::Vertex(unit->getPosition()),
		sf::Vertex(unit->getPosition() + unit->getVelocity())
	};

	window.draw(line, 2, sf::Lines);

	sf::Vertex line2[] =
	{
		sf::Vertex(unit->getPosition()),
		sf::Vertex(unit->getPosition() + unit->wanderForce)
	};

	window.draw(line2, 2, sf::Lines);
	*/
}