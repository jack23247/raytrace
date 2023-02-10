SRCS := $(shell find ./ -maxdepth 1 -name '*.c')
DCFLAGS = -g -O0 -Wall -Werror -Wextra
RCFLAGS = -O2 -march=native -DNDEBUG
CFLAGS = -std=c99 -pedantic -I./openlibm/include -I./openlibm/src
LDFLAGS = -L./openlibm -l:libopenlibm.a

.PHONY: all debug release clean

all: debug release

debug:
	cc $(DCFLAGS) $(CFLAGS) $(SRCS) -o rt.debug $(LDFLAGS)

release:
	cc $(RCFLAGS) $(CFLAGS) $(SRCS) -o rt.release $(LDFLAGS)

clean:
	rm rt.*
