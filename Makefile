# g++ Complier
CXX = g++;
# Complie option
CXXFLAGS = -Wall -std = c++11 -I./libs

SRC = $(wildcard src/*.cpp) main.cpp
OBJ = $(SRC:.cpp = .o)

TARGERT = preProcessor

all : $(TARGERT)

$(TARGERT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGERT)

.PHONY: all clean