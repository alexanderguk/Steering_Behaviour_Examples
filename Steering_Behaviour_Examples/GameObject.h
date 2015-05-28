#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

namespace sbe
{
	class GameObject
	{
	private:
		double x;
		double y;
	public:
		double getX() const;
		double getY() const;
		void setX(double x);
		void setY(double y);
	};
}

#endif