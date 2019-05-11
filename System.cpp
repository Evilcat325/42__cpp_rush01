#include "System.hpp"

#include <unistd.h>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <sys/sysctl.h>

/*
** constructors
*/
System::System(void)
{
}

System::~System(void)
{
}

/*
** funcs
*/
void System::update(void)
{
	update_hostname();
	update_username();
	update_date_time();
	update_cpu_model();
	update_cpu_cores();
	update_cpu_usage();
	update_ram_total();
	update_ram_used();
	update_net_down();
	update_net_up();
}

/*
** updaters
*/
void System::update_hostname(void)
{
	char host[1024];
	gethostname(host, 1024);
	_hostname = host;
}

void System::update_username(void)
{
	_username = getenv("USER");
}

void System::update_date_time(void)
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
	_date_time = ss.str();
}

void System::update_cpu_model(void)
{
	char name[1024];
	size_t len;
	if (sysctlbyname("machdep.cpu.brand_string", &name, &len, NULL, 0) < 0)
		_cpu_model = "err getting cpu";
	else
		_cpu_model = name;
}

void System::update_cpu_cores(void)
{
	auto cores = 0;
	auto size = sizeof(cores);
	std::stringstream ss;

	if (sysctlbyname("machdep.cpu.core_count", &cores, &size, NULL, 0) < 0)
		ss << -1;
	else
		ss << cores;
	_cpu_cores = ss.str();
}

void System::update_cpu_usage(void)
{
	double averages[3];
	std::stringstream ss;

	getloadavg(averages, 3);
	ss << averages[0] << " " << averages[1] << " " << averages[2];
	_cpu_usage = ss.str();
}

void System::update_ram_total(void)
{
	auto total = 0;
	auto size = sizeof(total);
	std::stringstream ss;

	if (sysctlbyname("hw.memsize", &total, &size, NULL, 0) < 0)
		ss << "8";
	else
		ss << total;
	_ram_total = ss.str();

	kern_return_t kr;
	vm_statistics64_data_t vm;
	mach_msg_type_number_t count = sizeof(vm_statistics64_data_t) / sizeof(natural_t);
	kr = host_statistics64(mach_host_self(), HOST_VM_INFO64, (host_info64_t)&vm, &count);
	if (kr != KERN_SUCCESS)
		return;
	std::stringstream ss;
	ss << std::fixed << std::setprecision(4);
	ss << vm.wire_count * 4.0 / (1024.0 * 1024.0);
	ss >> _ram_wired;
	ss.clear();
	ss << vm.free_count * 4.0 / (1024.0 * 1024.0);
	ss >> _ram_free;
	ss.clear();
	ss << 8 - vm.free_count * 4.0 / (1024.0 * 1024.0);
	ss >> _ram_used;
}

void System::update_ram_used(void)
{
	_ram_used = "-1";
}

void System::update_net_down(void)
{
	_net_down = "-1";
}

void System::update_net_up(void)
{
	_net_up = "-1";
}

/*
** getters
*/
std::string System::get_hostname(void) const
{
	return _hostname;
}
std::string System::get_username(void) const
{
	return _username;
}
std::string System::get_date_time(void) const
{
	return _date_time;
}
std::string System::get_cpu_model(void) const
{
	return _cpu_model;
}
std::string System::get_cpu_cores(void) const
{
	return _cpu_cores;
}
std::string System::get_cpu_usage(void) const
{
	return _cpu_usage;
}
std::string System::get_ram_total(void) const
{
	return _ram_total;
}
std::string System::get_ram_used(void) const
{
	return _ram_used;
}
std::string System::get_net_down(void) const
{
	return _net_down;
}
std::string System::get_net_up(void) const
{
	return _net_up;
}
