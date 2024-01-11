CC = g++
CFLAGS = -g -Wall -Wextra -Wpedantic

# Executable names
TARGET = parking_checker

# Source files
SRCS = main.cpp parking_checker.cpp vehicle.cpp car.cpp van.cpp
TEST_SRCS = vehicle_tests.cpp

# Header files
HDRS = parking_checker.hpp vehicle.hpp car.hpp van.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o) $(filter-out main.o, $(OBJS))

# Rule to build the main executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to build object files
%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build test object files
%.o: %.cpp $(HDRS) $(TEST_HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean compiled files
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

.PHONY: clean check
