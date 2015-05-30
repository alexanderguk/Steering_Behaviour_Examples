#define _USE_MATH_DEFINES
#include "Wander.h"

#include <random>
#include "AdvMath.h"
#include "Unit.h"

sbe::Wander::Wander()
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<float> disDouble;
	wanderAngle = disDouble(gen) * 2 * M_PI;
}

sf::Vector2f sbe::Wander::use(Unit& unit, double delta)
{
	float CIRCLE_DISTANCE = 70;
	float CIRCLE_RADIUS = 40;

	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<float> disDouble;

	sf::Vector2f circleCenter = sbe::AdvMath::normalize(unit.getVelocity());
	circleCenter.x *= CIRCLE_DISTANCE;
	circleCenter.y *= CIRCLE_DISTANCE;

	sf::Vector2f displacement(cos(wanderAngle), sin(wanderAngle));
	displacement.x *= CIRCLE_RADIUS;
	displacement.y *= CIRCLE_RADIUS;

	const float ANGLE_CHANGE = 3 * delta;
	wanderAngle += (disDouble(gen) * ANGLE_CHANGE) - ANGLE_CHANGE / 2;

	sf::Vector2f wanderForce = circleCenter + displacement;

	wanderForce.x /= unit.getMass();
	wanderForce.y /= unit.getMass();
	sf::Vector2f newVelocity = unit.getVelocity() + wanderForce;
	if (sbe::AdvMath::magnitude(newVelocity) > unit.getMaxVelocity())
	{
		newVelocity = sbe::AdvMath::normalize(newVelocity);
		newVelocity.x *= unit.getMaxVelocity();
		newVelocity.y *= unit.getMaxVelocity();
	}

	return newVelocity;
}