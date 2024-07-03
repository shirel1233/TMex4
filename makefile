# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Wextra -I.

# Sources and headers
SOURCES = main.cpp demo.cpp test.cpp Complex.cpp
HEADERS = Node.hpp Tree.hpp TreeIterators.hpp Complex.hpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable names
TARGETS = tree demo test

# Default target
all: $(TARGETS)

# Link the object files to create the executable for tree
tree: main.o Complex.o
	$(CXX) $(CXXFLAGS) main.o Complex.o -o tree

# Link the object files to create the executable for demo
demo: demo.o Complex.o
	$(CXX) $(CXXFLAGS) demo.o Complex.o -o demo

# Link the object files to create the executable for test
test: test.o Complex.o
	$(CXX) $(CXXFLAGS) test.o Complex.o -o test

# Compile Complex.cpp into Complex.o
Complex.o: Complex.cpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Complex.cpp -o Complex.o

# Compile each source file into an object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGETS) $(OBJECTS) Complex.o

# Run the main program
run: tree
	./tree

# Rebuild the project
rebuild: clean all

.PHONY: all clean run rebuild tree demo test
