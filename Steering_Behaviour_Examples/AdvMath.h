#ifndef ADV_MATH_H_
#define ADV_MATH_H_

#define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/System.hpp>

namespace sbe
{
	class AdvMath
	{
	public:
		static const float toDegrees;

		static sf::Vector2f normalize(sf::Vector2f v);
		static float magnitude(sf::Vector2f v);
	};
}

#endif