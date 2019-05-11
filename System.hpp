#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>
#include <mach/mach.h>
#include <mach/vm_page_size.h>

class System
{
private:
	std::string _hostname;
	std::string _username;
	std::string _date_time;
	std::string _cpu_model;
	std::string _cpu_cores;
	std::string _cpu_usage;
	std::string _ram_total;
	std::string _ram_used;
	std::string _ram_wired;
	std::string _ram_free;
	std::string _net_down;
	std::string _net_up;

	// funcs
	void update_hostname(void);
	void update_username(void);
	void update_date_time(void);
	void update_cpu_model(void);
	void update_cpu_cores(void);
	void update_cpu_usage(void);
	void update_ram_total(void);
	void update_ram_used(void);
	void update_net_down(void);
	void update_net_up(void);

public:
	System(/* args */);
	~System();

	// funcs
	void update(void);

	std::string get_hostname(void) const;
	std::string get_username(void) const;
	std::string get_date_time(void) const;
	std::string get_cpu_model(void) const;
	std::string get_cpu_cores(void) const;
	std::string get_cpu_usage(void) const;
	std::string get_ram_total(void) const;
	std::string get_ram_used(void) const;
	std::string get_net_down(void) const;
	std::string get_net_up(void) const;
};

#endif // SYSTEM_HPP
