#ifndef IDRAWABLE_H_
#define IDRAWABLE_H_

#include <SFML/Graphics.hpp>

namespace sbe
{
	class IDrawable
	{
	public:
		virtual void draw(sf::RenderWindow& window) = 0;
		virtual ~IDrawable() {};
	};
}

#endif