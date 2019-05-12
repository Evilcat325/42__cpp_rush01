#include <mach/mach.h>

int main()
{
	host_info_t r_load;
	mach_msg_type_number_t count;

	count = HOST_CPU_LOAD_INFO_COUNT;
	host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, r_load, &count);

	return 0;
}
