#ifndef CONTROLLER_MANAGER_H_
#define CONTROLLER_MANAGER_H_

#include <SFML/Graphics.hpp>
#include "ModelManager.h"

namespace sbe
{
	class ControllerManager
	{
	private:
		ModelManager& modelManager;
		int currentBehaviour;

	public:
		ControllerManager(ModelManager& modelManager);
		void update(sf::RenderWindow& window);
	};
}

#endif