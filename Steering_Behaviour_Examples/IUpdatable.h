#ifndef IUPDATABLE_H_
#define IUPDATABLE_H_

namespace sbe
{
	class IUpdatable
	{
	public:
		virtual void update(double delta) = 0;
		virtual ~IUpdatable() {};
	};
}

#endif