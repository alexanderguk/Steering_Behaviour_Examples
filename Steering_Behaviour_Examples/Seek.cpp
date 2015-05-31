#include "Seek.h"

#include <random>
#include "AdvMath.h"
#include "Unit.h"

sbe::Seek::Seek() : Seek(15)
{

}

sbe::Seek::Seek(float slowingRadius) : slowingRadius(slowingRadius)
{

}

sf::Vector2f sbe::Seek::use(Unit& unit)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> disInt;

	sf::Vector2f desiredVelocity = target - unit.getPosition();
	float distance = sbe::AdvMath::magnitude(desiredVelocity);

	desiredVelocity = sbe::AdvMath::normalize(desiredVelocity);
	desiredVelocity = sbe::AdvMath::multiply(desiredVelocity, unit.getMaxVelocity());

	if (distance < slowingRadius) // arrival
	{
		desiredVelocity = sbe::AdvMath::multiply(desiredVelocity, distance / slowingRadius);
	}

	sf::Vector2f steering = desiredVelocity - unit.getVelocity();
	steering = sbe::AdvMath::multiply(steering, 1.f / unit.getMass());

	sf::Vector2f newVelocity = unit.getVelocity() + steering;
	if (sbe::AdvMath::magnitude(newVelocity) > unit.getMaxVelocity())
	{
		newVelocity = sbe::AdvMath::normalize(newVelocity);
		newVelocity = sbe::AdvMath::multiply(newVelocity, unit.getMaxVelocity());
	}

	return newVelocity;
}

sf::Vector2f sbe::Seek::getTarget() const
{
	return target;
}

void sbe::Seek::setTarget(sf::Vector2f target)
{
	this->target = target;
}

float sbe::Seek::getSlowingRadius() const
{
	return slowingRadius;
}

void sbe::Seek::setSlowingRadius(float slowingRadius)
{
	this->slowingRadius = slowingRadius;
}