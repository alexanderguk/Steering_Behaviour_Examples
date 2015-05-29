#include <random>
#include "Unit.h"
#include "AdvMath.h"

sbe::Unit::Unit()
{
	mode = 0;
	slowingRadius = 30;
	mass = 1000;

	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> dis;

	setPosition(dis(gen) % 640, dis(gen) % 480);
	setVelocity(sf::Vector2f(0.2f, 0.1f));
	setMaxVelocity(50);
}

void sbe::Unit::update(double delta)
{
	sf::Vector2f desiredVelocity = sbe::AdvMath::normalize(target - position);
	desiredVelocity.x *= maxVelocity;
	desiredVelocity.y *= maxVelocity;
	if (mode == 0 && sbe::AdvMath::magnitude(target - position) < slowingRadius) // seek
	{
		desiredVelocity.x *= sbe::AdvMath::magnitude(target - position) / slowingRadius;
		desiredVelocity.y *= sbe::AdvMath::magnitude(target - position) / slowingRadius;
	}
	if (mode == 1) // flee
	{
		desiredVelocity.x *= -1;
		desiredVelocity.y *= -1;
	}
	sf::Vector2f steering = desiredVelocity - velocity;
	steering.x /= mass;
	steering.y /= mass;
	velocity += steering;
	sf::Vector2f step(velocity.x * delta, velocity.y * delta);
	setPosition(getPosition() + step);
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

sf::Vector2f sbe::Unit::getTarget() const
{
	return target;
}

void sbe::Unit::setTarget(const sf::Vector2f& target)
{
	this->target = target;
}

void sbe::Unit::nextMode()
{
	if (mode == maxMode)
	{
		mode = 0;
	}
	else
	{
		mode++;
	}
}