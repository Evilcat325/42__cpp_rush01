#include "System.hpp"
#include "Curses.hpp"
#include "cpptk-1.0.2/cpptk.h"

#include <iostream>
#include <unistd.h>

using namespace Tk;
using namespace std;

void guitest(void)
{
}

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
		try
		{
			init(argv[0]);

			label(".l") - text("Hello C++/Tk!");
			pack(".l") - padx(20) - pady(6);

			runEventLoop();
		}
		catch (exception const &e)
		{
			cerr << "Error: " << e.what() << '\n';
		}
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
