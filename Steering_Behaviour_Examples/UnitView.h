#ifndef UNIT_VIEW_H_
#define UNIT_VIEW_H_

#include <memory>
#include "IDrawable.h"
#include "Unit.h"

namespace sbe
{
	class UnitView : public IDrawable
	{
	private:
		std::shared_ptr<Unit> unit;

	public:
		UnitView(std::shared_ptr<Unit> unit);
		void draw(sf::RenderWindow& window) override;
	};
}

#endif