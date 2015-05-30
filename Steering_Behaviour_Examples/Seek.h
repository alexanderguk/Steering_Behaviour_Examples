#ifndef SEEK_H_
#define SEEK_H_

#include "IStrategy.h"

namespace sbe
{
	class Seek : public IStrategy
	{
	public:
		sf::Vector2f use(Unit& unit, double delta) override;
	};
}

#endif