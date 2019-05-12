#ifndef FT_HOSTSTAT_HPP
#define FT_HOSTSTAT_HPP

#include <cstdlib>
#include <mach/host_info.h>
#include <mach/mach.h>
#include <sys/time.h>
#include <iostream>
#include <iomanip>

typedef struct
{
	/* Number of processes. */
	uint32_t nprocs;

	/* CPU loads. */
	host_cpu_load_info_data_t cpu;

	/* Load averages for 1, 5, and 15 minutes. */
	double loadavg[3];

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

class HostStat
{
private:
	mach_port_t curr_host;
	unsigned int host_count;
	unsigned int vm_count;
	unsigned int load_count;
	hoststat_t host_stat;
	vm_statistics64_data_t vm_stat;

	HostStat(HostStat const &rhs);
	HostStat &operator=(HostStat const &rhs);

public:
	HostStat();
	~HostStat() {}

	void snapVM();
	void snapCPUUsage();
	void snapCPULoad();
	void print();
};

#endif /* FT_HostStat_HPP */
