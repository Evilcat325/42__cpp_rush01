#include "HostStat.hpp"

HostStat::HostStat()
		: curr_host(mach_host_self())
{
	vm_count = HOST_VM_INFO64_COUNT;
	load_count = HOST_CPU_LOAD_INFO_COUNT;
	host_statistics64(curr_host, HOST_CPU_LOAD_INFO,
										reinterpret_cast<host_info64_t>(&cpu_stat.p_cpu), &load_count);
	loadCPUInfo();
	loadHostInfo();
}

void HostStat::loadCPUInfo()
{
	/* reading brand string*/
	char buf[128];
	size_t len = 128;
	size_t int_size = sizeof(int);
	sysctlbyname("machdep.cpu.brand_string", &buf, &len, NULL, 0);
	cpu_stat.brand_string = buf;
	sysctlbyname("machdep.cpu.vendor", &buf, &len, NULL, 0);
	cpu_stat.vendor = buf;
	sysctlbyname("machdep.cpu.core_count", &cpu_stat.core_count, &int_size, NULL, 0);
	sysctlbyname("machdep.cpu.thread_count", &cpu_stat.thread_count, &int_size, NULL, 0);
}

void HostStat::loadHostInfo()
{
	static char buf[1024];
	gethostname(buf, 1024);
	host_stat.hostname = buf;
	host_stat.username = getenv("USER");
}

void HostStat::snapVM()
{
	host_statistics64(curr_host, HOST_VM_INFO64,
										reinterpret_cast<host_info64_t>(&vm_stat), &vm_count);
}

void HostStat::snapCPUUsage()
{
	host_statistics64(curr_host, HOST_CPU_LOAD_INFO,
										reinterpret_cast<host_info64_t>(&cpu_stat.cpu), &load_count);
	unsigned long long userticks, systicks, idleticks;
	double totalticks;
	userticks = cpu_stat.cpu.cpu_ticks[CPU_STATE_USER] + cpu_stat.cpu.cpu_ticks[CPU_STATE_NICE];
	systicks = cpu_stat.cpu.cpu_ticks[CPU_STATE_SYSTEM];
	idleticks = cpu_stat.cpu.cpu_ticks[CPU_STATE_IDLE];
	userticks -= (cpu_stat.p_cpu.cpu_ticks[CPU_STATE_USER] +
								cpu_stat.p_cpu.cpu_ticks[CPU_STATE_NICE]);
	systicks -= cpu_stat.p_cpu.cpu_ticks[CPU_STATE_SYSTEM];
	idleticks -= cpu_stat.p_cpu.cpu_ticks[CPU_STATE_IDLE];
	totalticks = userticks + systicks + idleticks + 0.0000001;
	cpu_stat.usage_user = 100.0 * userticks / totalticks;
	cpu_stat.usage_sys = 100.0 * systicks / totalticks;
	cpu_stat.usage_idle = 100.0 * idleticks / totalticks;
	cpu_stat.p_cpu = cpu_stat.cpu;
}

void HostStat::snapCPULoad()
{
	getloadavg(cpu_stat.loadavg, sizeof(cpu_stat.loadavg));
}

void HostStat::print()
{
	std::cout << std::fixed << std::setprecision(4)
						<< cpu_stat.loadavg[0] << " "
						<< cpu_stat.loadavg[1] << " "
						<< cpu_stat.loadavg[2] << " "
						<< std::endl
						<< std::setprecision(2)
						<< cpu_stat.usage_user << "% user\t"
						<< cpu_stat.usage_sys << "% sys\t"
						<< cpu_stat.usage_idle << "% idle\t"
						<< std::endl
						<< cpu_stat.brand_string << std::endl
						<< cpu_stat.vendor << " vendor\t"
						<< cpu_stat.core_count << " core\t"
						<< cpu_stat.thread_count << " thread\t"
						<< std::endl
						<< host_stat.hostname << " "
						<< host_stat.username
						<< std::endl;
}

void HostStat::update()
{
	snapCPULoad();
	snapCPUUsage();
	snapVM();
}

std::string const &HostStat::get_hostname()
{
	return host_stat.hostname;
}
std::string const &HostStat::get_username()
{
	return host_stat.username;
}

std::string const &HostStat::get_cpuname()
{
	return cpu_stat.brand_string;
}

std::string const &HostStat::get_cpuload()
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(4)
		 << cpu_stat.loadavg[0] << " "
		 << cpu_stat.loadavg[1] << " "
		 << cpu_stat.loadavg[2] << " "
		 << std::endl;
	return ss.str();
}

std::string const &HostStat::get_cpuusage()
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2)
		 << cpu_stat.usage_user << "% user\t"
		 << cpu_stat.usage_sys << "% sys\t"
		 << cpu_stat.usage_idle << "% idle\t"
		 << std::endl;
	return ss.str();
}
