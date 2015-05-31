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

	private:
		void onMouseMoved(sf::Event ev, sf::RenderWindow& window) const;
		void onKeyPressed(sf::Event ev);

		void seek() const;
		void flee() const;
		void wander() const;
		void pursuit() const;
		void evade() const;
	};
}

#endif