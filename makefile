CXXFLAGS=-Wall -Wextra -std=c++11
LDFLAGS=-lncurses -lcurl
ft_gkrellm: System.o Curses.o

clean:
	rm *.o ft_gkrellm
