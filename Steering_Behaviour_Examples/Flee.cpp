#include "Flee.h"

#include <random>
#include "AdvMath.h"
#include "Unit.h"

sf::Vector2f sbe::Flee::use(Unit& unit)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> disInt;

	sf::Vector2f desiredVelocity = sbe::AdvMath::normalize(target - unit.getPosition());
	desiredVelocity = sbe::AdvMath::multiply(desiredVelocity, -unit.getMaxVelocity());

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

sf::Vector2f sbe::Flee::getTarget() const
{
	return target;
}

void sbe::Flee::setTarget(sf::Vector2f target)
{
	this->target = target;
}