#ifndef VIEW_MANAGER_H_
#define VIEW_MANAGER_H_

#include <vector>
#include <memory>
#include <string>
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
		sf::Texture texture;
		sf::Font font;
		sf::Clock fpsClock;
		sf::Clock updateFpsClock;
		int fps;
		std::string demoName;
		
	public:
		ViewManager(std::shared_ptr<sf::RenderWindow> window, ModelManager& modelManager);
		void draw();
		void updateUnitView(std::shared_ptr<Unit> unit, bool isAdded);
		void setDemoName(std::string demoName);
	};
}

#endif