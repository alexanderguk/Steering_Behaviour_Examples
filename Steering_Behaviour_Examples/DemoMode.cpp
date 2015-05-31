#include "DemoMode.h"

sbe::DemoMode::DemoMode() : currentDemo(0)
{
	demoNames.push_back("Seek");
	demoNames.push_back("Flee");
	demoNames.push_back("Wander");
	demoNames.push_back("Pursuit");
	demoNames.push_back("Evade");
}

int sbe::DemoMode::getCurrentDemo() const
{
	return currentDemo;
}

std::string sbe::DemoMode::getCurrentDemoName() const
{
	return demoNames[currentDemo];
}

sbe::DemoMode sbe::DemoMode::operator++(int)
{
	currentDemo = ++currentDemo % demoNames.size();
	return *this;
}