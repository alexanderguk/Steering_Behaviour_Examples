#ifndef IBEHAVIOUR_H_
#define IBEHAVIOUR_H_

#include <memory>
#include "IStrategy.h"

namespace sbe
{
	class IBehaviour
	{
	protected:
		std::unique_ptr<IStrategy> strategy;

	public:
		virtual sf::Vector2f useStrategy(double delta) = 0;
		virtual void setStrategy(std::unique_ptr<IStrategy> strategy) = 0;
		virtual ~IBehaviour() {}
	};
}

#endif