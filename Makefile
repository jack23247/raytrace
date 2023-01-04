all: debug release
debug:
	cc -g -DLIBERROR_ENABLED -Wall --pedantic main.c vec3.c -o rt.debug -lm
release:
	cc -O2 -DNDEBUG main.c vec3.c -o rt.release -lm
clean:
	rm rt.*
