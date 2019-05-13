#include "Datetime.hpp"

Datetime::Datetime(HostStat &hs)
		: BaseModule(hs)
{
}

Datetime::~Datetime()
{
}

void Datetime::render() const
{
	mvwaddstr(stdscr, line, 0, hs.get_datetime().c_str());
}
