#ifndef WANDER_H_
#define WANDER_H_

#include "IStrategy.h"

namespace sbe
{
	class Wander : public IStrategy
	{
	private:
		float wanderAngle;

	public:
		Wander();
		sf::Vector2f use(Unit& unit, double delta) override;
	};
}

#endif