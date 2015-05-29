#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "ModelManager.h"
#include "ViewManager.h"
#include "ControllerManager.h"

namespace sbe
{
	class World
	{
	private:
		std::shared_ptr<sf::RenderWindow> window;
		ModelManager modelManager;
		ViewManager viewManager;
		ControllerManager controllerManager;

	private:
		void init();
		void update(double delta);
		void draw();

	public:
		World(std::shared_ptr<sf::RenderWindow> window);
		void run();
	};
}

#endif