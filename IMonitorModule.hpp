#ifndef FT_IMONITORMODULE_HPP
#define FT_IMONITORMODULE_HPP

#include <string>

class IMonitorModule
{
private:
	/* data */
public:
	// this is not oop, this is badly designed interface
	virtual void render() const = 0;
};

#endif /* FT_IMonitorModule_HPP */
