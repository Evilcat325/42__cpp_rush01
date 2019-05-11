
#include <mach/mach.h>
#include <mach/vm_page_size.h>
#include <iostream>
#include <sstream>
#include <iomanip>

int main()
{
	kern_return_t kr;
	vm_statistics64_data_t vm;
	mach_msg_type_number_t count = sizeof(vm_statistics64_data_t) / sizeof(natural_t);
	kr = host_statistics64(mach_host_self(), HOST_VM_INFO64, (host_info64_t)&vm, &count);
	if (kr != KERN_SUCCESS)
		return kr;
	std::string _ram_wired, _ram_free, _ram_used;
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
	std::cout << _ram_used << std::endl
						<< _ram_wired << std::endl
						<< _ram_free << std::endl;
}
