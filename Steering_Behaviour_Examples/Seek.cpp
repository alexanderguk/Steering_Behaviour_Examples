#include "Seek.h"

#include <random>
#include "AdvMath.h"
#include "Unit.h"

sf::Vector2f sbe::Seek::use(Unit& unit, float delta)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> disInt;

	sf::Vector2f desiredVelocity = sbe::AdvMath::normalize(unit.getTarget() - unit.getPosition());
	desiredVelocity.x *= unit.getMaxVelocity();
	desiredVelocity.y *= unit.getMaxVelocity();
	if (sbe::AdvMath::magnitude(unit.getTarget() - unit.getPosition()) < unit.getSlowingRadius()) // seek
	{
		desiredVelocity.x *= sbe::AdvMath::magnitude(unit.getTarget() - unit.getPosition()) / unit.getSlowingRadius();
		desiredVelocity.y *= sbe::AdvMath::magnitude(unit.getTarget() - unit.getPosition()) / unit.getSlowingRadius();
	}
	sf::Vector2f steering = desiredVelocity - unit.getVelocity();
	steering.x /= unit.getMass();
	steering.y /= unit.getMass();

	sf::Vector2f newVelocity = unit.getVelocity() + steering;
	if (sbe::AdvMath::magnitude(newVelocity) > unit.getMaxVelocity())
	{
		newVelocity = sbe::AdvMath::normalize(newVelocity);
		newVelocity.x *= unit.getMaxVelocity();
		newVelocity.y *= unit.getMaxVelocity();
	}

	return newVelocity;
}