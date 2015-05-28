#ifndef VIEW_MANAGER_H_
#define VIEW_MANAGER_H_

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "Unit.h"
#include "ModelManager.h"

namespace sbe
{
	class ViewManager
	{
	private:
		std::shared_ptr<sf::RenderWindow> window;
		std::vector<std::shared_ptr<IDrawable>> drawableObjects;
		
	public:
		ViewManager(std::shared_ptr<sf::RenderWindow> window, ModelManager& modelManager);
		void draw();
		void addUnitView(std::shared_ptr<Unit> unit);
	};
}

#endif