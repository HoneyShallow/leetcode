src = $(wildcard ./*.cpp) # 获取指定路径下的特定类型的文件
obj = $(patsubst %.cpp, %, $(src))

CC = g++
CFLAGS = -std=c++11 -Wall -g 

all:$(obj)

$(obj):%:%.cpp
	$(CC) $< -o $@ $(CFLAGS)


.PHONY:clean all
clean:
	-rm -rf $(obj)
# 将.cpp文件编译为.o文件
#%.o:%.cpp
#	$(CC) -c $< -o $@
