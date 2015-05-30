#ifndef MODEL_MANAGER_H_
#define MODEL_MANAGER_H_

#include <vector>
#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>
#include "IUpdatable.h"
#include "Unit.h"

namespace sbe
{
	class ModelManager
	{
	private:
		std::shared_ptr<sf::RenderWindow> window;
		std::vector<std::shared_ptr<IUpdatable>> updatableObjects;
		std::function<void(std::shared_ptr<Unit>)> notify;

	public:
		ModelManager(std::shared_ptr<sf::RenderWindow> window);
		void update(float delta);
		void addUnit();
		void setSubscriber(std::function<void(std::shared_ptr<Unit>)> f);
		std::vector<std::shared_ptr<IUpdatable>> getUpdatableObjects() const;
	};
}

#endif