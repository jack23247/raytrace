SRCS := $(shell find . -name '*.c')
DCFLAGS = -g -O0 -Wall -Werror -Wextra
RCFLAGS = -O2 -march=native -DNDEBUG
CFLAGS = -std=c99 -pedantic
LDFLAGS = -lm

.PHONY: all debug release clean

all: debug release

debug:
	cc $(DCFLAGS) $(CFLAGS) $(SRCS) -o rt.debug $(LDFLAGS)

release:
	cc $(RCFLAGS) $(CFLAGS) $(SRCS) -o rt.release $(LDFLAGS)

clean:
	rm rt.*
