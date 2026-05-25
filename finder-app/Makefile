SHELL = /usr/bin/env bash
.PHONY: clean

#CROSS_COMPILE = 1

ifndef CROSS_COMPILE

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

else
CC = aarch64-linux-gnu-gcc
CCFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

endif

writer: writer.o
	$(CC) $(CCFLAGS) -o writer writer.o

clean:
	rm -f writer writer.o

