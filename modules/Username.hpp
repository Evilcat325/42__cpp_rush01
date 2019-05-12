#ifndef FT_USERNAME_HPP
#define FT_USERNAME_HPP

#include "BaseModule.hpp"

class Username : virtual public BaseModule
{
private:
	/* data */
	Username();

public:
	Username(HostStat &);
	~Username();
	virtual void render() const;
};

#endif /* FT_Username_HPP */
