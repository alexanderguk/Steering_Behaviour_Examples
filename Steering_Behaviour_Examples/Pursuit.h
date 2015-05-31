#ifndef PURSUIT_H_
#define PURSUIT_H_

#include <memory>
#include "Seek.h"

namespace sbe
{
	class Pursuit : public Seek
	{
	private:
		std::shared_ptr<Unit> targetUnit;

	public:
		Pursuit(std::shared_ptr<Unit> target);
		Pursuit(std::shared_ptr<Unit> target, float slowingRadius);

		sf::Vector2f use(Unit& unit) override;

		std::shared_ptr<Unit> getTargetUnit() const;
		void setTargetUnit(std::shared_ptr<Unit> targetUnit);
	};
}

#endif