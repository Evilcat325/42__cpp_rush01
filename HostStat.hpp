#ifndef FT_HOSTSTAT_HPP
#define FT_HOSTSTAT_HPP

#include <cstdlib>
#include <mach/host_info.h>
#include <mach/mach.h>
#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <cstdlib>
#include <unistd.h>
#include <curl/curl.h>

typedef struct
{
	std::string hostname;
	std::string username;

	/* Number of processes. */
	uint32_t nprocs;

	/* Total number of threads. */
	uint32_t threads;

	/* VM page size. */
	vm_size_t pagesize;

	/* Physical memory size. */
	uint64_t memsize;

	/* network traffic */
	uint64_t net_ipackets;
	uint64_t net_opackets;
	uint64_t net_ibytes;
	uint64_t net_obytes;

	/* Disk statistics. */
	uint64_t disk_rops;
	uint64_t disk_wops;
	uint64_t disk_rbytes;
	uint64_t disk_wbytes;
} hoststat_t;

typedef struct
{
	/* CPU loads. */
	host_cpu_load_info_data_t cpu;
	host_cpu_load_info_data_t p_cpu;

	/* Load averages for 1, 5, and 15 minutes. */
	double loadavg[3];
	double usage_user;
	double usage_sys;
	double usage_idle;

	/* sysctl only read once */
	std::string brand_string;
	std::string vendor;
	int core_count;
	int thread_count;

} cpustat_t;

class HostStat
{
private:
	mach_port_t curr_host;
	unsigned int host_count;
	unsigned int vm_count;
	unsigned int load_count;
	hoststat_t host_stat;
	cpustat_t cpu_stat;
	vm_statistics64_data_t vm_stat;

	HostStat(HostStat const &rhs);
	HostStat &operator=(HostStat const &rhs);

public:
	HostStat();
	~HostStat() {}

	void loadCPUInfo();
	void loadHostInfo();
	void snapVM();
	void snapCPUUsage();
	void snapCPULoad();
	void update();
	void print();

	std::string const &get_hostname();
	std::string const &get_username();

private:
	static void cpu_percent(unsigned long long ticks, unsigned long long totalticks,
													unsigned long long &whole, unsigned long long &part);
};

#endif /* FT_HostStat_HPP */
