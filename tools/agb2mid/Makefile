CXX := g++

CXXFLAGS := -std=c++11 -O2 -Wall -Wno-switch -Werror -g

SRCS := agb.cpp error.cpp main.cpp midi.cpp tables.cpp

HEADERS := agb.h error.h main.h midi.h tables.h

.PHONY: all clean

all: agb2mid
	@:

agb2mid: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) agb2mid agb2mid.exe
