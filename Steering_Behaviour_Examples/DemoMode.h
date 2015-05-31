#ifndef DEMO_MODE_H_
#define DEMO_MODE_H_

#include <vector>
#include <string>

namespace sbe
{
	class DemoMode
	{
	private:
		int currentDemo;
		std::vector<std::string> demoNames;

	public:
		DemoMode();

		int getCurrentDemo() const;
		std::string getCurrentDemoName() const;

		DemoMode operator++(int);
	};
}

#endif