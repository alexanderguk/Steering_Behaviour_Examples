#ifndef CONTROLLER_MANAGER_H_
#define CONTROLLER_MANAGER_H_

#include <SFML/Graphics.hpp>
#include "ModelManager.h"
#include "ViewManager.h"
#include "DemoMode.h"

namespace sbe
{
	class ControllerManager
	{
	private:
		DemoMode currentBehaviour;

	public:
		ControllerManager();
		void update(sf::RenderWindow& window, ModelManager& modelManager, ViewManager& viewManager);

	private:
		void onMouseMoved(sf::Event ev, sf::RenderWindow& window, ModelManager& modelManager) const;
		void onKeyPressed(sf::Event ev, ModelManager& modelManager, ViewManager& viewManager);

		void seek(ModelManager& modelManager) const;
		void flee(ModelManager& modelManager) const;
		void wander(ModelManager& modelManager) const;
		void pursuit(ModelManager& modelManager) const;
		void evade(ModelManager& modelManager) const;
	};
}

#endif