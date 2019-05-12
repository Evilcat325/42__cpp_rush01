#ifndef FT_HOSTNAME_HPP
#define FT_HOSTNAME_HPP

#include "BaseModule.hpp"

class Hostname : virtual public BaseModule
{
private:
	/* data */
	Hostname();

public:
	Hostname(HostStat &);
	~Hostname();
	virtual void render() const;
};

#endif /* FT_Hostname_HPP */
