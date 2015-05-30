#define _USE_MATH_DEFINES
#include "Wander.h"

#include <random>
#include "AdvMath.h"
#include "Unit.h"
#include <iostream>

sbe::Wander::Wander()
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<float> disDouble;
	wanderAngle = static_cast<float>(disDouble(gen) * 2 * M_PI);
}

sf::Vector2f sbe::Wander::use(Unit& unit, float delta)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<float> disDouble;

	sf::Vector2f circleCenter = sbe::AdvMath::normalize(unit.getVelocity());
	circleCenter = sbe::AdvMath::multiply(circleCenter, circleDistance);

	sf::Vector2f displacement(cos(wanderAngle), sin(wanderAngle));
	displacement = sbe::AdvMath::multiply(displacement, circleRadius);

	wanderAngle += (disDouble(gen) * angleChange) - angleChange / 2;
	//std::cout << wanderAngle << std::endl;

	sf::Vector2f wanderForce = circleCenter + displacement;
	this->wanderForce = wanderForce;
	wanderForce = sbe::AdvMath::multiply(wanderForce, 1.0 / unit.getMass());

	sf::Vector2f newVelocity = unit.getVelocity() + wanderForce;
	if (sbe::AdvMath::magnitude(newVelocity) > unit.getMaxVelocity())
	{
		newVelocity = sbe::AdvMath::normalize(newVelocity);
		newVelocity = sbe::AdvMath::multiply(newVelocity, unit.getMaxVelocity());
	}

	return newVelocity;
}

float sbe::Wander::getCircleDistance() const
{
	return circleDistance;
}

float sbe::Wander::getCircleRadius() const
{
	return circleRadius;
}

float sbe::Wander::getAngleChange() const
{
	return angleChange;
}

sf::Vector2f sbe::Wander::getWanderForce() const
{
	return wanderForce;
}