#include <random>
#include "Unit.h"
#include "AdvMath.h"
#include "Wander.h"

sbe::Unit::Unit() : Unit(50, 50)
{

}

sbe::Unit::Unit(float maxVelocity, float mass) : maxVelocity(maxVelocity), mass(mass)
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> dis;

	setPosition(static_cast<float>(dis(gen) % 1280), static_cast<float>(dis(gen) % 768));
	setVelocity(sf::Vector2f(0.2f, 0.1f));
}

void sbe::Unit::update(const sf::RenderWindow& window, float delta)
{
	velocity = useStrategy();
	position += sf::Vector2f(velocity.x * delta, velocity.y * delta);

	if (typeid(*strategy) == typeid(Wander))
	{
		moveToBorder(window);
	}
	else
	{
		moveToCenter(window);
	}
}

void sbe::Unit::moveToBorder(const sf::RenderWindow& window)
{
	if (position.x < 0)
	{
		position.x += window.getSize().x;
	}
	if (position.x > window.getSize().x)
	{
		position.x -= window.getSize().x;
	}
	if (position.y < 0)
	{
		position.y += window.getSize().y;
	}
	if (position.y > window.getSize().y)
	{
		position.y -= window.getSize().y;
	}
}

void sbe::Unit::moveToCenter(const sf::RenderWindow& window)
{
	if (position.x < 0 || position.x > window.getSize().x ||position.y < 0 ||position.y > window.getSize().y)
	{
		position.x = window.getSize().x / 2.f;
		position.y = window.getSize().y / 2.f;
	}
}

sf::Vector2f sbe::Unit::getVelocity() const
{
	return velocity;
}

void sbe::Unit::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}

float sbe::Unit::getMass() const
{
	return mass;
}

float sbe::Unit::getMaxVelocity() const
{
	return maxVelocity;
}

void sbe::Unit::setMaxVelocity(float maxVelocity)
{
	this->maxVelocity = maxVelocity;
}

sf::Vector2f sbe::Unit::useStrategy()
{
	if (strategy != nullptr)
	{
		return strategy->use(*this);
	}
	return sf::Vector2f(0, 0);
}

void sbe::Unit::setStrategy(std::shared_ptr<IStrategy> strategy)
{
	this->strategy = strategy;
}