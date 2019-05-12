#include "System.hpp"
#include "Curses.hpp"
#include "cpptk-1.0.2/cpptk.h"

#include <iostream>
#include <unistd.h>

void guitest(void) {
	Tk::init("hello");
	Tk::button(".b") -Tk::text("Say Hello") -Tk::command(hello);
	Tk::pack(".b") -Tk::padx(20) -Tk::pady(7);
	Tk::runEventLoop();
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
		guitest();
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
