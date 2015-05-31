#ifndef WANDER_H_
#define WANDER_H_

#include "IStrategy.h"

namespace sbe
{
	class Wander : public IStrategy
	{
	private:
		float wanderAngle;
		float circleDistance = 70;
		float circleRadius = 60;
		float angleChange = 1.2f;
		sf::Vector2f wanderForce;

	public:
		Wander();
		sf::Vector2f use(Unit& unit) override;

		float getCircleDistance() const;
		float getCircleRadius() const;
		float getAngleChange() const;
		sf::Vector2f getWanderForce() const;
	};
}

#endif