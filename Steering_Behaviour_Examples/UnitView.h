#ifndef UNIT_VIEW_H_
#define UNIT_VIEW_H_

#include <memory>
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "Unit.h"

namespace sbe
{
	class UnitView : public IDrawable
	{
	private:
		std::shared_ptr<Unit> unit;
		sf::Sprite sprite;

	public:
		UnitView(std::shared_ptr<Unit> unit, sf::Sprite sprite);
		void draw(sf::RenderWindow& window) override;
	};
}

#endif