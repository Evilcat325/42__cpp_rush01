#include <iostream>
#include "System.hpp"

int main(void) {
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