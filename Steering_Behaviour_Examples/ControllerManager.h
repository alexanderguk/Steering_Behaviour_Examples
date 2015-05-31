#ifndef CONTROLLER_MANAGER_H_
#define CONTROLLER_MANAGER_H_

#include <SFML/Graphics.hpp>
#include "ModelManager.h"
#include "ViewManager.h"

namespace sbe
{
	class ControllerManager
	{
	private:
		int currentBehaviour;

	public:
		ControllerManager();
		void update(sf::RenderWindow& window, ModelManager& modelManager, ViewManager& viewManager);

	private:
		void onMouseMoved(sf::Event ev, sf::RenderWindow& window, ModelManager& modelManager) const;
		void onKeyPressed(sf::Event ev, ModelManager& modelManager, ViewManager& viewManager);

		void seek(ModelManager& modelManager, ViewManager& viewManager) const;
		void flee(ModelManager& modelManager, ViewManager& viewManager) const;
		void wander(ModelManager& modelManager, ViewManager& viewManager) const;
		void pursuit(ModelManager& modelManager, ViewManager& viewManager) const;
		void evade(ModelManager& modelManager, ViewManager& viewManager) const;
	};
}

#endif