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
		float mass;

	private:
		sf::Vector2f useStrategy() override;
		void moveToCenter(const sf::RenderWindow& window);
		void moveToBorder(const sf::RenderWindow& window);

	public:
		Unit();
		Unit(float maxVelocity, float mass);

		void setStrategy(std::shared_ptr<IStrategy> strategy) override;

		void update(const sf::RenderWindow& window, float delta) override;

		sf::Vector2f getVelocity() const;
		void setVelocity(const sf::Vector2f& velocity);

		float getMass() const;

		float sbe::Unit::getMaxVelocity() const;
		void sbe::Unit::setMaxVelocity(float maxVelocity);
	};
}

#endif