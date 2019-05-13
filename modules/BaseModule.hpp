#ifndef FT_BASEMODULE_HPP
#define FT_BASEMODULE_HPP

#include "IMonitorModule.hpp"
#include <curses.h>
#include "HostStat.hpp"

class BaseModule : public IMonitorModule
{

public:
	BaseModule(HostStat &hs);
	virtual ~BaseModule();
	BaseModule(BaseModule const &rhs);
	BaseModule &operator=(BaseModule const &rhs);
	virtual void render() const;

protected:
	static int module_counts;
	HostStat &hs;
	int line;
};

#endif /* FT_BaseModule_HPP */
