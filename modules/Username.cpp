#include "Username.hpp"

Username::Username(HostStat &hs)
		: BaseModule(hs)
{
}

Username::~Username()
{
}

void Username::render() const
{
	mvwaddstr(stdscr, line, 0, hs.get_username().c_str());
}
