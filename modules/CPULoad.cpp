#include "CPULoad.hpp"

CPULoad::CPULoad(HostStat &hs)
		: BaseModule(hs)
{
}

CPULoad::~CPULoad()
{
}

void CPULoad::render() const
{
	mvwaddstr(stdscr, line, 0, hs.get_cpuload().c_str());
}
