#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>

class System {
  private:
	std::string _hostname;
	std::string _username;
	std::string _date;
	std::string _time;
	std::string _cpu_model;
	std::string _cpu_speed;
	std::string _cpu_cores;
	std::string _cpu_usage;
	std::string _ram_total;
	std::string _ram_used;
	std::string _net_down;
	std::string _net_up;
  public:
	System(/* args */);
	~System();

	// funcs
	void update(void);

	std::string get_hostname(void) const;
	std::string get_username(void) const;
	std::string get_date(void) const;
	std::string get_time(void) const;
	std::string get_cpu_model(void) const;
	std::string get_cpu_speed(void) const;
	std::string get_cpu_cores(void) const;
	std::string get_cpu_usage(void) const;
	std::string get_ram_total(void) const;
	std::string get_ram_used(void) const;
	std::string get_net_down(void) const;
	std::string get_net_up(void) const;
};

#endif // SYSTEM_HPP