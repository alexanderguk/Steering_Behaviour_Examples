#include "GameObject.h"

sf::Vector2f sbe::GameObject::getPosition() const
{
	return position;
}

void sbe::GameObject::setPosition(sf::Vector2f position)
{
	this->position = position;
}

void sbe::GameObject::setPosition(float x, float y)
{
	this->position = sf::Vector2f(x, y);
}