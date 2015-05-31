#include "Evade.h"

#include <random>
#include "AdvMath.h"
#include "Unit.h"

sbe::Evade::Evade(std::shared_ptr<Unit> targetUnit) : Flee(), targetUnit(targetUnit)
{

}

sf::Vector2f sbe::Evade::use(Unit& unit)
{
	if (targetUnit.get() != nullptr)
	{
		float T = sbe::AdvMath::magnitude(unit.getPosition() - targetUnit->getPosition()) / targetUnit->getMaxVelocity();
		sf::Vector2f futurePosition = targetUnit->getPosition() + sbe::AdvMath::multiply(targetUnit->getVelocity(), T);

		setTarget(futurePosition);

		return Flee::use(unit);
	}
	return sf::Vector2f(0, 0);
}

std::shared_ptr<sbe::Unit> sbe::Evade::getTargetUnit() const
{
	return targetUnit;
}

void sbe::Evade::setTargetUnit(std::shared_ptr<Unit> targetUnit)
{
	this->targetUnit = targetUnit;
}