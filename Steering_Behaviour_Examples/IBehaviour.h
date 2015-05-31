#ifndef IBEHAVIOUR_H_
#define IBEHAVIOUR_H_

#include <memory>
#include "IStrategy.h"

namespace sbe
{
	class IBehaviour
	{
	protected:
		std::shared_ptr<IStrategy> strategy;

	public:
		virtual sf::Vector2f useStrategy() = 0;
		virtual void setStrategy(std::shared_ptr<IStrategy> strategy) = 0;
		virtual ~IBehaviour() {}
		virtual std::shared_ptr<IStrategy> getStrategy() const { return strategy; };
	};
}

#endif