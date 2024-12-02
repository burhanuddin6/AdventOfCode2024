# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I/mnt/c/CppRival/include
LDFLAGS = -L/mnt/c/CppRival/build -lMyLibrary

# Default target
.PHONY: build clean run

# To keep it simple, we'll extract the source file from the second argument
SRC = $(word 2, $(MAKECMDGOALS))  # second argument is the source file
OUT = $(basename $(SRC))           # output file name is the base of the source filename
OBJ = $(SRC:.cpp=.o)               # object file name

# Command for building
build: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

# Command for cleaning
clean:
	rm -f *.o *.out $(OUT)

# Command for running
run: build
	./$(OUT)
