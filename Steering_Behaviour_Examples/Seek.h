#ifndef SEEK_H_
#define SEEK_H_

#include "IStrategy.h"

namespace sbe
{
	class Seek : public IStrategy
	{
	private:
		sf::Vector2f target;
		float slowingRadius;

	protected:
		sf::Vector2f seek(Unit& unit);

	public:
		Seek();
		Seek(float slowingRadius);
		sf::Vector2f use(Unit& unit) override;

		sf::Vector2f getTarget() const;
		void setTarget(sf::Vector2f target);

		float getSlowingRadius() const;
		void setSlowingRadius(float slowingRadius);
	};
}

#endif