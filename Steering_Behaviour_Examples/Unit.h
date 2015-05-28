#ifndef UNIT_H_
#define UNIT_H_

#include "GameObject.h"
#include "IUpdatable.h"

namespace sbe
{
	class Unit : public GameObject, public IUpdatable
	{
	public:
		Unit();
		void update(double delta) override;
	};
}

#endif