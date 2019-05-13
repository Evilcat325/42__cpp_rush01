#ifndef FT_Datetime_HPP
#define FT_Datetime_HPP

#include "BaseModule.hpp"

class Datetime : virtual public BaseModule
{
private:
	/* data */
	Datetime();

public:
	Datetime(HostStat &);
	~Datetime();
	virtual void render() const;
};

#endif /* FT_Datetime_HPP */
