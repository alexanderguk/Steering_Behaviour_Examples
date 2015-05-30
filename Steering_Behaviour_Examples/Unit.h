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
		float maxVelocity;

		sf::Vector2f target;

		float mass;
		float slowingRadius;

		int mode;
		const int maxMode = 1;

		int targetMode;
		const int maxTargetMode = 2;
		sf::Clock randomTargetClock;

	private:
		sf::Vector2f useStrategy(float delta) override;

	public:
		Unit();

		void update(const sf::RenderWindow& window, float delta) override;

		sf::Vector2f getVelocity() const;
		void setVelocity(const sf::Vector2f& velocity);

		float getMass() const;
		float getSlowingRadius() const;

		float sbe::Unit::getMaxVelocity() const;
		void sbe::Unit::setMaxVelocity(float maxVelocity);

		sf::Vector2f getTarget() const;
		void setTarget(const sf::Vector2f& target);

		void nextMode();
		void nextTargetMode();

		int getTargetMode() const;

		void setStrategy(std::shared_ptr<IStrategy> strategy) override;
	};
}

#endif