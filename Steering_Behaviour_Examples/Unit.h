#ifndef UNIT_H_
#define UNIT_H_

#include "SFML/System.hpp"
#include "GameObject.h"
#include "IUpdatable.h"

namespace sbe
{
	class Unit : public GameObject, public IUpdatable
	{
	private:
		sf::Vector2f velocity;
		double maxVelocity;

		sf::Vector2f target;

		double mass;
		double slowingRadius;

		int mode;
		const int maxMode = 1;

		int targetMode;
		const int maxTargetMode = 2;
		sf::Clock randomTargetClock;

		double wanderAngle;

	public:
		sf::Vector2f wanderForce;

	public:
		const double CIRCLE_DISTANCE = 70;
		const double CIRCLE_RADIUS = 40;

	private:
		sf::Vector2f wander();

	public:
		Unit();

		void update(double delta) override;

		sf::Vector2f getVelocity() const;
		void setVelocity(const sf::Vector2f& velocity);

		double sbe::Unit::getMaxVelocity() const;
		void sbe::Unit::setMaxVelocity(double maxVelocity);

		sf::Vector2f getTarget() const;
		void setTarget(const sf::Vector2f& target);

		void nextMode();
		void nextTargetMode();

		int getTargetMode() const;
	};
}

#endif