# Variables
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
BUILD_DIR := build

# Default target
all:
	@echo "Usage: make <day_number> (e.g., make 1)"

# Compile and run
%:
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) day$*/day$*.cpp -o $(BUILD_DIR)/day$*
	./$(BUILD_DIR)/day$* < day$*/inputs.txt