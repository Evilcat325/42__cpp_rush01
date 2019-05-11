#include "System.hpp"
#include "Curses.hpp"

#include <iostream>
#include <unistd.h>

void print_stats(void) {
	System s;
	s.update();
	std::cout << "host:\t" << s.get_hostname() << std::endl;
	std::cout << "user:\t" << s.get_username() << std::endl;
	std::cout << "time:\t" << s.get_date_time() << std::endl;
	std::cout << "cpu:\t" << s.get_cpu_model() << std::endl;
	std::cout << "cpu cores:\t" << s.get_cpu_cores() << std::endl;
	std::cout << "cpu usage:\t" << s.get_cpu_usage() << std::endl;
	std::cout << "mem:\t" << s.get_ram_total() << std::endl;
	std::cout << "used mem:\t" << s.get_ram_used() << std::endl;
	std::cout << "net down:\t" << s.get_net_down() << std::endl;
	std::cout << "net up:\t" << s.get_net_up() << std::endl;
}

int main(int argc, char *argv[]) {
	char c;
	bool gui, curs = false;
	
	while ((c = getopt(argc, argv, "cg")) != -1 ) {
		switch (c) {
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
	if (gui) {
		std::cout << "not ready tm" << std::endl;
	} else if (curs) {
		Curses c;
		c.run();
	} else {
		print_stats();
	}
}