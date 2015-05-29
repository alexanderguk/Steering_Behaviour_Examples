#ifndef MODEL_MANAGER_H_
#define MODEL_MANAGER_H_

#include <vector>
#include <memory>
#include <functional>
#include "IUpdatable.h"
#include "Unit.h"

namespace sbe
{
	class ModelManager
	{
	private:
		std::vector<std::shared_ptr<IUpdatable>> updatableObjects;
		std::function<void(std::shared_ptr<Unit>)> notify;

	public:
		void update(double delta);
		void addUnit();
		void setSubscriber(std::function<void(std::shared_ptr<Unit>)> f);

		std::vector<std::shared_ptr<IUpdatable>> getUpdatableObjects() const;
	};
}

#endif