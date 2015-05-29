#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <SFML/System.hpp>

namespace sbe
{
	class GameObject
	{
	protected:
		sf::Vector2f position;
	public:
		sf::Vector2f getPosition() const;
		void setPosition(sf::Vector2f position);
		void setPosition(float x, float y);
	};
}

#endif