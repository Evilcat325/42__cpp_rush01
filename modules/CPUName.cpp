#include "CPUName.hpp"

CPUName::CPUName(HostStat &hs)
		: BaseModule(hs)
{
}

CPUName::~CPUName()
{
}

void CPUName::render() const
{
	mvwaddstr(stdscr, line, 0, hs.get_cpuname().c_str());
}
