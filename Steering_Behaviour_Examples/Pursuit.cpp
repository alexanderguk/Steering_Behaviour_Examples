#include "Pursuit.h"

#include <random>
#include "AdvMath.h"
#include "Unit.h"

sbe::Pursuit::Pursuit(std::shared_ptr<Unit> targetUnit) : Seek(), targetUnit(targetUnit)
{

}

sbe::Pursuit::Pursuit(std::shared_ptr<Unit> targetUnit, float slowingRadius) : Seek(slowingRadius), targetUnit(targetUnit)
{

}

sf::Vector2f sbe::Pursuit::use(Unit& unit)
{
	if (targetUnit.get() != nullptr)
	{
		float T = sbe::AdvMath::magnitude(unit.getPosition() - targetUnit->getPosition()) / targetUnit->getMaxVelocity();
		sf::Vector2f futurePosition = targetUnit->getPosition() + sbe::AdvMath::multiply(targetUnit->getVelocity(), T);

		setTarget(futurePosition);

		return Seek::use(unit);
	}
	return sf::Vector2f(0, 0);
}

std::shared_ptr<sbe::Unit> sbe::Pursuit::getTargetUnit() const
{
	return targetUnit;
}

void sbe::Pursuit::setTargetUnit(std::shared_ptr<Unit> targetUnit)
{
	this->targetUnit = targetUnit;
}