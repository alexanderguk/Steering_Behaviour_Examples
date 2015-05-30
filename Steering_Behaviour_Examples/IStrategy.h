#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <SFML/System.hpp>

namespace sbe
{
	class Unit;

	class IStrategy
	{
	public:
		virtual sf::Vector2f use(Unit& unit, float delta) = 0;
		virtual ~IStrategy() {}
	};
}

#endif