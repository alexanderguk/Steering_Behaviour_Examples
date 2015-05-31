#ifndef EVADE_H_
#define EVADE_H_

#include <memory>
#include "Flee.h"

namespace sbe
{
	class Evade : public Flee
	{
	private:
		std::shared_ptr<Unit> targetUnit;

	public:
		Evade(std::shared_ptr<Unit> target);
		Evade(std::shared_ptr<Unit> target, float slowingRadius);

		sf::Vector2f use(Unit& unit) override;

		std::shared_ptr<Unit> getTargetUnit() const;
		void setTargetUnit(std::shared_ptr<Unit> targetUnit);
	};
}

#endif