#include "MemUsage.hpp"

MemUsage::MemUsage(HostStat &hs)
		: BaseModule(hs)
{
}

MemUsage::~MemUsage()
{
}

void MemUsage::render() const
{
	mvwaddstr(stdscr, line, 0, hs.get_memusage().c_str());
}
