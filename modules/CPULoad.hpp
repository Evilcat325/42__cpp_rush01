#ifndef FT_CPULoad_HPP
#define FT_CPULoad_HPP

#include "BaseModule.hpp"

class CPULoad : virtual public BaseModule
{
private:
	/* data */
	CPULoad();

public:
	CPULoad(HostStat &);
	~CPULoad();
	virtual void render() const;
};

#endif /* FT_CPULoad_HPP */
