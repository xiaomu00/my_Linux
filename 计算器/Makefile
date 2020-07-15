#我的第一个makefile

#   $@ : 目标文件
#   $< : 第一个依赖文件
#   $^ : 所有依赖文件
#   %.c :所有的 .c 文件
#   %.o :所有的 .o 文件
.PHONY:clean  main   #不管clean main 是不是最新的，都要执行


# 使用变量
CC=gcc
#  调用函数： $(, , ,……) 第一个参数是函数名，后面的参数是函数的参数

SRCS=$(wildcard *.c)  #weldcard 过滤函数    将所有的.c文件过滤出来

BASEDIR=$(shell pwd)  #  = 是在运行过程中展开
OBJDIR:=$(BASEDIR)/obj   # := 是在编译过程中展开

$(shell mkdir -p $(OBJDIR))
#SO=main.o parse.o add.o sub.o mul.o

OBJ=$(SRCS:.c=.o)    #将SC变量中的所有.c文件换成相应的.o文件
# 将所有的.o文件装到obj 文件夹中
OBJS:=$(addprefix $(OBJDIR)/, $(OBJ))     #  addprefix 增加i前缀

main : $(OBJS)
	$(CC) -o $@  $^

#  %通配符 
$(OBJS) : $(SRCS)
	$(CC) -c $< -o $@

clean:
	rm -rf  $(OBJS)   #可用make clean 命令删除所有的  .o文件
