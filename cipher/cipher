.PHONY: all debug release clean

all: debug release

debug: cipher-dbg

hello-dbg: cipher.cpp
	g++ -g -O0 cipher.cpp -o cipher-dbg -Wall

release: cipher

hello: cipher.cpp
	g++ -O2 cipher.cpp -o cipher -DNDEBUG -Wall

clean:
	rm -f cipher-dbg cipher
