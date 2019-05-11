#include "Curses.hpp"
#include "System.hpp"

#include <curses.h>
#include <unistd.h>

Curses::Curses(/* args */)
{
}

Curses::~Curses()
{
}

void Curses::run(void) {
	_init();
	System s;
mainloop:
	s.update();
	mvwaddstr(stdscr, 0, 0, s.get_hostname().c_str());
	mvwaddstr(stdscr, 1, 0, s.get_username().c_str());
	mvwaddstr(stdscr, 2, 0, s.get_date_time().c_str());
	mvwaddstr(stdscr, 3, 0, s.get_cpu_model().c_str());
	mvwaddstr(stdscr, 4, 0, s.get_cpu_cores().c_str());
	mvwaddstr(stdscr, 5, 0, s.get_cpu_usage().c_str());
	mvwaddstr(stdscr, 6, 0, s.get_ram_total().c_str());
	mvwaddstr(stdscr, 7, 0, s.get_ram_used().c_str());
	mvwaddstr(stdscr, 8, 0, s.get_net_down().c_str());
	mvwaddstr(stdscr, 9, 0, s.get_net_up().c_str());
	wrefresh(stdscr);
	sleep(1);
	goto mainloop;
}

/*
** private funcs
*/
void Curses::_init(void) {
	initscr();
	noecho();
	clear();
}