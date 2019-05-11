#ifndef CURSES_HPP
#define CURSES_HPP

class Curses {
  private:
	void _init(void);
  public:
	Curses(/* args */);
	~Curses();

	void run(void);
};



#endif // CURSES_HPP