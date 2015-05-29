#include <random>
#include "Unit.h"
#include "AdvMath.h"

sbe::Unit::Unit() : mode(0), targetMode(0), slowingRadius(30), mass(1000), wanderAngle(0), maxVelocity(50)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> dis;

	setPosition(dis(gen) % 640, dis(gen) % 480);
	setVelocity(sf::Vector2f(0.2f, 0.1f));
}

void sbe::Unit::update(double delta)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> disInt;

	if (targetMode == 1 && randomTargetClock.getElapsedTime().asSeconds() > 1.5) // random target
	{
		randomTargetClock.restart();
		setTarget(sf::Vector2f(disInt(gen) % 640, disInt(gen) % 480));
	}
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
	sf::Vector2f steering;
	if (targetMode == 2)
	{
		steering = wander();
	}
	else
	{
		steering = desiredVelocity - velocity;
	}
	steering.x /= mass;
	steering.y /= mass;
	velocity += steering;
	if (sbe::AdvMath::magnitude(velocity) > maxVelocity)
	{
		velocity = sbe::AdvMath::normalize(velocity);
		velocity.x *= maxVelocity;
		velocity.y *= maxVelocity;
	}
	sf::Vector2f step(velocity.x * delta, velocity.y * delta);
	setPosition(getPosition() + step);
}

sf::Vector2f sbe::Unit::wander()
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<double> disDouble;

	sf::Vector2f circleCenter = sbe::AdvMath::normalize(velocity);
	circleCenter.x *= CIRCLE_DISTANCE;
	circleCenter.y *= CIRCLE_DISTANCE;

	sf::Vector2f displacement(cos(wanderAngle), sin(wanderAngle));
	displacement.x *= CIRCLE_RADIUS;
	displacement.y *= CIRCLE_RADIUS;

	const double ANGLE_CHANGE = 0.1;
	wanderAngle += (disDouble(gen) * ANGLE_CHANGE) - ANGLE_CHANGE / 2;

	wanderForce = circleCenter + displacement;

	return wanderForce;
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

void sbe::Unit::nextTargetMode()
{
	if (targetMode == maxTargetMode)
	{
		targetMode = 0;
	}
	else
	{
		targetMode++;
	}
}

int sbe::Unit::getTargetMode() const
{
	return targetMode;
}