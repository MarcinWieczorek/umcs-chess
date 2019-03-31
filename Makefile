CPP=ccache g++
CPPFLAGS=-Wall -ggdb -fdiagnostics-color=always
CPP_SOURCES=$(shell find . -name "*.cc")
OBJALL=$(CPP_SOURCES:.cc=.o)
# OBJ-=./Chess.o
OBJ=$(filter-out ./Chess.o,$(OBJALL))

all: chess

chess: Chess.cc $(OBJ)
	$(CPP) -o $@ $< $(OBJ)

%.o: %.cc $(CPP_SOURCES)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm *.o chess
