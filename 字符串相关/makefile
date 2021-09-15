src = $(wildcard ./*.cpp)
obj = $(patsubst %.cpp, %, $(src))

CC = g++
CFLAGS = -std=c++11 -g -Wall

all:$(obj)

$(obj):%:%.cpp
	$(CC) $< -o $@ $(CFLAGS)

.PHONY:clean all
clean:
	-rm -rf $(obj)
