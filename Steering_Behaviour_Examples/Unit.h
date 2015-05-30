#ifndef UNIT_H_
#define UNIT_H_

#include <SFML/System.hpp>
#include "GameObject.h"
#include "IUpdatable.h"
#include "IBehaviour.h"

namespace sbe
{
	class Unit : public GameObject, public IUpdatable, public IBehaviour
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

	private:
		sf::Vector2f useStrategy(double delta) override;

	public:
		Unit();

		void update(double delta) override;

		sf::Vector2f getVelocity() const;
		void setVelocity(const sf::Vector2f& velocity);

		double getMass() const;
		double getSlowingRadius() const;

		double sbe::Unit::getMaxVelocity() const;
		void sbe::Unit::setMaxVelocity(double maxVelocity);

		sf::Vector2f getTarget() const;
		void setTarget(const sf::Vector2f& target);

		void nextMode();
		void nextTargetMode();

		int getTargetMode() const;

		void setStrategy(std::unique_ptr<IStrategy> strategy) override;
	};
}

#endif