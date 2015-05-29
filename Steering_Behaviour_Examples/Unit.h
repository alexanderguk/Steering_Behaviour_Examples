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

	public:
		Unit();

		void update(double delta) override;

		sf::Vector2f getVelocity() const;
		void setVelocity(const sf::Vector2f& velocity);

		double sbe::Unit::getMaxVelocity() const;
		void sbe::Unit::setMaxVelocity(double maxVelocity);
	};
}

#endif