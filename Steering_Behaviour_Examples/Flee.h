#ifndef FLEE_H_
#define FLEE_H_

#include "IStrategy.h"

namespace sbe
{
	class Flee : public IStrategy
	{
	private:
		sf::Vector2f target;

	public:
		sf::Vector2f use(Unit& unit) override;

		sf::Vector2f getTarget() const;
		void setTarget(sf::Vector2f target);
	};
}

#endif