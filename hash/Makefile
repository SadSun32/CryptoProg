.PHONY: all debug release clean

all: debug release

debug: hash-dbg

hello-dbg: hash.cpp
	g++ -g -O0 hash.cpp -o hash-dbg -Wall

release: hash

hello: hash.cpp
	g++ -O2 hash.cpp -o hash -DNDEBUG -Wall

clean:
	rm -f hash-dbg hash
