#include "System.hpp"
#include "Curses.hpp"
#include "HostStat.hpp"

#include <iostream>
#include <unistd.h>

void print_stats(void)
{
	System s;
	s.update();
	s.print();
}

int main(int argc, char *argv[])
{
	char c;
	bool gui, curs = false;

	while ((c = getopt(argc, argv, "cg")) != -1)
	{
		switch (c)
		{
		case 'c':
			curs = true;
			break;
		case 'g':
			gui = true;
			break;
		case '?':
			std::cout << "usage ./ft_gkrellm [c|g]" << std::endl;
		default:
			abort();
		}
	}
	if (gui)
	{
		HostStat hs;
		hs.snapCPULoad();
		hs.snapCPUUsage();
		hs.snapVM();
		hs.print();
	}
	else if (curs)
	{
		Curses c;
		c.run();
	}
	else
	{
		print_stats();
	}
}
