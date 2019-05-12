#include "BaseModule.hpp"

int BaseModule::module_counts = 0;

BaseModule::BaseModule(HostStat &hs)
		: hs(hs)
{
	line = module_counts++;
}

BaseModule::~BaseModule()
{
	module_counts--;
}

BaseModule::BaseModule(BaseModule const &rhs)
		: hs(rhs.hs)
{
	*this = rhs;
}

BaseModule &BaseModule::operator=(BaseModule const &)
{
	return *this;
}

void BaseModule::render() const
{
}
