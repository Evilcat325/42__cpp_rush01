#include "Hostname.hpp"

Hostname::Hostname(HostStat &hs)
		: BaseModule(hs)
{
}

Hostname::~Hostname()
{
}

void Hostname::render() const
{
	mvwaddstr(stdscr, line, 0, hs.get_hostname().c_str());
}
