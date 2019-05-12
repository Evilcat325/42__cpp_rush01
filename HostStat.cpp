#include "HostStat.hpp"

HostStat::HostStat()
		: curr_host(mach_host_self())
{
	vm_count = HOST_VM_INFO64_COUNT;
	load_count = HOST_CPU_LOAD_INFO_COUNT;
}

void HostStat::snapVM()
{
	host_statistics64(curr_host, HOST_VM_INFO64,
										reinterpret_cast<host_info64_t>(&vm_stat), &vm_count);
}

void HostStat::snapCPUUsage()
{
	host_statistics(curr_host, HOST_CPU_LOAD_INFO,
									reinterpret_cast<host_info64_t>(&host_stat.cpu), &load_count);
}

void HostStat::snapCPULoad()
{
	getloadavg(host_stat.loadavg, sizeof(host_stat.loadavg));
}

void HostStat::print()
{
	std::cout << std::fixed << std::setprecision(4);
	std::cout << host_stat.loadavg[0] << " "
						<< host_stat.loadavg[1] << " "
						<< host_stat.loadavg[2] << " "
						<< std::endl;
}
