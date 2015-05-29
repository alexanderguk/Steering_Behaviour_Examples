#include "Unit.h"
#include "AdvMath.h"

sbe::Unit::Unit()
{
	setPosition(20, 20);
	setVelocity(sf::Vector2f(0.2f, 0.1f));
	setMaxVelocity(10);
}

void sbe::Unit::update(double delta)
{
	sf::Vector2f newPosition = getPosition();
	newPosition.x += sbe::AdvMath::normalize(velocity).x * getMaxVelocity() * delta;
	newPosition.y += sbe::AdvMath::normalize(velocity).y * getMaxVelocity() * delta;
	setPosition(newPosition);
}

sf::Vector2f sbe::Unit::getVelocity() const
{
	return velocity;
}

void sbe::Unit::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}

double sbe::Unit::getMaxVelocity() const
{
	return maxVelocity;
}

void sbe::Unit::setMaxVelocity(double maxVelocity)
{
	this->maxVelocity = maxVelocity;
}