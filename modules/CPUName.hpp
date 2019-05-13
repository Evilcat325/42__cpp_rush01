#ifndef FT_CPUName_HPP
#define FT_CPUName_HPP

#include "BaseModule.hpp"

class CPUName : virtual public BaseModule
{
private:
	/* data */
	CPUName();

public:
	CPUName(HostStat &);
	~CPUName();
	virtual void render() const;
};

#endif /* FT_CPUName_HPP */
