#include "AdvMath.h"

const float sbe::AdvMath::toDegrees = static_cast<float>(180 / M_PI);

sf::Vector2f sbe::AdvMath::normalize(sf::Vector2f v)
{
	float magnitude = sbe::AdvMath::magnitude(v);
	return sf::Vector2f(v.x / magnitude, v.y / magnitude);
}

sf::Vector2f sbe::AdvMath::multiply(sf::Vector2f v, float n)
{
	return sf::Vector2f(v.x * n, v.y * n);
}

float sbe::AdvMath::magnitude(sf::Vector2f v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}