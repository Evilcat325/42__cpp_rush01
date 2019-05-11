#include "system.hpp"
/*
** constructors
*/
System(/* args */) {

}

~System() {

}

/*
** funcs
*/


/*
** getters
*/
std::string get_hostname(void) const {
	return _hostname;
}
std::string get_username(void) const {
	return _username;
}
std::string get_date(void) const {
	return _date;
}
std::string get_time(void) const {
	return _time;
}
std::string get_cpu_model(void) const {
	return _cpu_model;
}
std::string get_cpu_speed(void) const {
	return _cpu_speed;
}
std::string get_cpu_cores(void) const {
	return _cpu_cores;
}
std::string get_cpu_usage(void) const {
	return _cpu_usage;
}
std::string get_ram_total(void) const {
	return _ram_total;
}
std::string get_ram_used(void) const {
	return _ram_used;
}
std::string get_net_down(void) const {
	return _net_down;
}
std::string get_net_up(void) const {
	return _net_up;
}