CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = main

# Source files
SRCS = main.cpp online.cpp offline.cpp brute_force.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Include directories
INCLUDES = -I.

# Compile rule for .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
