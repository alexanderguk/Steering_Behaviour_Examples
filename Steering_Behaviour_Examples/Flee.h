#ifndef FLEE_H_
#define FLEE_H_

#include "IStrategy.h"

namespace sbe
{
	class Flee : public IStrategy
	{
	public:
		sf::Vector2f use(Unit& unit, double delta) override;
	};
}

#endif