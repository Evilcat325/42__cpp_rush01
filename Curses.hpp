#ifndef CURSES_HPP
#define CURSES_HPP

#include "IMonitorDisplay.hpp"
#include "BaseModule.hpp"
#include "HostStat.hpp"
#include "Hostname.hpp"
#include "Username.hpp"
#include <vector>

class Curses
{
private:
	void _init(void);
	HostStat hs;
	std::vector<std::unique_ptr<IMonitorModule>> modules;

public:
	Curses(/* args */);
	~Curses();

	void run(void);
};

#endif // CURSES_HPP
