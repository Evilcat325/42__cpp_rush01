#include "CPUUsage.hpp"

CPUUsage::CPUUsage(HostStat &hs)
		: BaseModule(hs)
{
}

CPUUsage::~CPUUsage()
{
}

void CPUUsage::render() const
{
	mvwaddstr(stdscr, line, 0, hs.get_cpuusage().c_str());
}
