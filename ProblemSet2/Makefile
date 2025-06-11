# Makefile for Problem Set 2
# Supports building all problems or individual ones

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

# Directory structure (with spaces)
PROB1_DIR = Problem 1
PROB2_DIR = Problem 2
PROB3_DIR = Problem 3

# Targets
.PHONY: all clean prob1 prob2 prob3 run1 run2 run3 runall

# Default target - build all
all: prob1 prob2 prob3
	@echo "All problems built successfully!"

# Problem 1
prob1:
	@echo "Building Problem 1..."
	$(CXX) $(CXXFLAGS) -o "$(PROB1_DIR)/prob1" \
		"$(PROB1_DIR)/IntVector.cpp" \
		"$(PROB1_DIR)/Main_PS2.cpp"
	@echo "Problem 1 built: $(PROB1_DIR)/prob1"

# Problem 2
prob2:
	@echo "Building Problem 2..."
	$(CXX) $(CXXFLAGS) -I"$(PROB1_DIR)" -o "$(PROB2_DIR)/prob2" \
		"$(PROB1_DIR)/IntVector.cpp" \
		"$(PROB2_DIR)/SortableIntVector.cpp" \
		"$(PROB2_DIR)/Main_PS2.cpp"
	@echo "Problem 2 built: $(PROB2_DIR)/prob2"

# Problem 3
prob3:
	@echo "Building Problem 3..."
	$(CXX) $(CXXFLAGS) -I"$(PROB1_DIR)" -I"$(PROB2_DIR)" -o "$(PROB3_DIR)/prob3" \
		"$(PROB1_DIR)/IntVector.cpp" \
		"$(PROB2_DIR)/SortableIntVector.cpp" \
		"$(PROB3_DIR)/ShakerSortableIntVector.cpp" \
		"$(PROB3_DIR)/Main_PS2.cpp"
	@echo "Problem 3 built: $(PROB3_DIR)/prob3"

# Run targets
run1: prob1
	@echo "\n=== Running Problem 1 ==="
	@cd "$(PROB1_DIR)" && ./prob1

run2: prob2
	@echo "\n=== Running Problem 2 ==="
	@cd "$(PROB2_DIR)" && ./prob2

run3: prob3
	@echo "\n=== Running Problem 3 ==="
	@cd "$(PROB3_DIR)" && ./prob3

# Run all problems
runall: all
	@echo "\n=== Running All Problems ==="
	@echo "\n--- Problem 1 ---"
	@cd "$(PROB1_DIR)" && ./prob1
	@echo "\n--- Problem 2 ---"
	@cd "$(PROB2_DIR)" && ./prob2
	@echo "\n--- Problem 3 ---"
	@cd "$(PROB3_DIR)" && ./prob3

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	@rm -f "$(PROB1_DIR)/prob1"
	@rm -f "$(PROB2_DIR)/prob2"
	@rm -f "$(PROB3_DIR)/prob3"
	@echo "Clean complete!"

# Help target
help:
	@echo "Available targets:"
	@echo "  make all    - Build all problems"
	@echo "  make prob1  - Build Problem 1 only"
	@echo "  make prob2  - Build Problem 2 only"
	@echo "  make prob3  - Build Problem 3 only"
	@echo "  make run1   - Build and run Problem 1"
	@echo "  make run2   - Build and run Problem 2"
	@echo "  make run3   - Build and run Problem 3"
	@echo "  make runall - Build and run all problems"
	@echo "  make clean  - Remove all build artifacts"
	@echo "  make help   - Show this help message"