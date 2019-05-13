#ifndef FT_MemUsage_HPP
#define FT_MemUsage_HPP

#include "BaseModule.hpp"

class MemUsage : virtual public BaseModule
{
private:
	/* data */
	MemUsage();

public:
	MemUsage(HostStat &);
	~MemUsage();
	virtual void render() const;
};

#endif /* FT_MemUsage_HPP */
