#ifndef FT_CPUUsage_HPP
#define FT_CPUUsage_HPP

#include "BaseModule.hpp"

class CPUUsage : virtual public BaseModule
{
private:
	/* data */
	CPUUsage();

public:
	CPUUsage(HostStat &);
	~CPUUsage();
	virtual void render() const;
};

#endif /* FT_CPUUsage_HPP */
