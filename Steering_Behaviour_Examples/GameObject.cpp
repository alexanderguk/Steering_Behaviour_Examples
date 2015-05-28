#include "GameObject.h"

double sbe::GameObject::getX() const
{
	return x;
}

double sbe::GameObject::getY() const
{
	return y;
}

void sbe::GameObject::setX(double x)
{
	this->x = x;
}

void sbe::GameObject::setY(double y)
{
	this->y = y;
}