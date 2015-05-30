#ifndef IUPDATABLE_H_
#define IUPDATABLE_H_

#include <SFML/Graphics.hpp>

namespace sbe
{
	class IUpdatable
	{
	public:
		virtual void update(const sf::RenderWindow& window, float delta) = 0;
		virtual ~IUpdatable() {};
	};
}

#endif