# Makefile for COS30008 Problem Set 1 (Linux/WSL version)
# Fixed for directories with spaces

CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Define directories (with quotes)
P1_DIR = Problem\ 1
P2_DIR = Problem\ 2
P3_DIR = Problem\ 3
P4_DIR = Problem\ 4

# Define executables
P1_EXE = polygon_test
P2_EXE = polynomial_test
P3_EXE = combination_test
P4_EXE = bernstein_test

# Default target
all: problem1 problem2 problem3 problem4

# Problem 1: Polygon
problem1: $(P1_DIR)/$(P1_EXE)

$(P1_DIR)/$(P1_EXE): Main_P1.cpp $(P1_DIR)/Polygon.cpp $(P1_DIR)/PolygonPS1.cpp $(P1_DIR)/Vector2D.cpp
	$(CXX) $(CXXFLAGS) -o "$@" Main_P1.cpp "Problem 1/Polygon.cpp" "Problem 1/PolygonPS1.cpp" "Problem 1/Vector2D.cpp" -I"Problem 1"

Main_P1.cpp: Main.cpp
	@echo "Creating Main_P1.cpp with P1 defined..."
	@sed 's|//\s*#define\s*P1|#define P1|; s|#define\s*P2|//#define P2|; s|#define\s*P3|//#define P3|; s|#define\s*P4|//#define P4|' Main.cpp > Main_P1.cpp

# Problem 2: Polynomial
problem2: $(P2_DIR)/$(P2_EXE)

$(P2_DIR)/$(P2_EXE): Main_P2.cpp $(P2_DIR)/Polynomial.cpp $(P2_DIR)/PolynomialPS1.cpp
	$(CXX) $(CXXFLAGS) -o "$@" Main_P2.cpp "Problem 2/Polynomial.cpp" "Problem 2/PolynomialPS1.cpp" -I"Problem 2"

Main_P2.cpp: Main.cpp
	@echo "Creating Main_P2.cpp with P2 defined..."
	@sed 's|//\s*#define\s*P2|#define P2|; s|#define\s*P1|//#define P1|; s|#define\s*P3|//#define P3|; s|#define\s*P4|//#define P4|' Main.cpp > Main_P2.cpp

# Problem 3: Combination
problem3: $(P3_DIR)/$(P3_EXE)

$(P3_DIR)/$(P3_EXE): Main_P3.cpp $(P3_DIR)/Combination.cpp
	$(CXX) $(CXXFLAGS) -o "$@" Main_P3.cpp "Problem 3/Combination.cpp" -I"Problem 3"

Main_P3.cpp: Main.cpp
	@echo "Creating Main_P3.cpp with P3 defined..."
	@sed 's|//\s*#define\s*P3|#define P3|; s|#define\s*P1|//#define P1|; s|#define\s*P2|//#define P2|; s|#define\s*P4|//#define P4|' Main.cpp > Main_P3.cpp

# Problem 4: Bernstein
problem4: $(P4_DIR)/$(P4_EXE)

$(P4_DIR)/$(P4_EXE): Main_P4.cpp $(P4_DIR)/BernsteinBasisPolynomial.cpp $(P4_DIR)/Combination.cpp
	@if [ ! -f "Problem 4/Combination.cpp" ]; then cp "Problem 3/Combination.cpp" "Problem 4/"; fi
	@if [ ! -f "Problem 4/Combination.h" ]; then cp "Problem 3/Combination.h" "Problem 4/"; fi
	$(CXX) $(CXXFLAGS) -o "$@" Main_P4.cpp "Problem 4/BernsteinBasisPolynomial.cpp" "Problem 4/Combination.cpp" -I"Problem 4"

Main_P4.cpp: Main.cpp
	@echo "Creating Main_P4.cpp with P4 defined..."
	@sed 's|//\s*#define\s*P4|#define P4|; s|#define\s*P1|//#define P1|; s|#define\s*P2|//#define P2|; s|#define\s*P3|//#define P3|' Main.cpp > Main_P4.cpp

# Run targets
run1: problem1
	@echo "Running Problem 1 with Parallelogram.txt..."
	@cd "Problem 1" && ./$(P1_EXE) Parallelogram.txt
	@echo ""
	@echo "Running Problem 1 with Data.txt..."
	@cd "Problem 1" && ./$(P1_EXE) Data.txt

run2: problem2
	@echo "Running Problem 2..."
	@cd "Problem 2" && ./$(P2_EXE)

run3: problem3
	@echo "Running Problem 3..."
	@cd "Problem 3" && ./$(P3_EXE)

run4: problem4
	@echo "Running Problem 4..."
	@cd "Problem 4" && ./$(P4_EXE)

# Run all problems
runall: run1 run2 run3 run4

# Clean targets
clean:
	@echo "Cleaning temporary files..."
	@rm -f Main_P*.cpp
	@rm -f "$(P1_DIR)/$(P1_EXE)"
	@rm -f "$(P2_DIR)/$(P2_EXE)"
	@rm -f "$(P3_DIR)/$(P3_EXE)"
	@rm -f "$(P4_DIR)/$(P4_EXE)"

# Help target
help:
	@echo "Available targets:"
	@echo "  make all       - Compile all problems"
	@echo "  make problem1  - Compile Problem 1"
	@echo "  make problem2  - Compile Problem 2"
	@echo "  make problem3  - Compile Problem 3"
	@echo "  make problem4  - Compile Problem 4"
	@echo "  make run1      - Compile and run Problem 1"
	@echo "  make run2      - Compile and run Problem 2"
	@echo "  make run3      - Compile and run Problem 3"
	@echo "  make run4      - Compile and run Problem 4"
	@echo "  make runall    - Compile and run all problems"
	@echo "  make clean     - Remove all executables and temp files"

.PHONY: all problem1 problem2 problem3 problem4 run1 run2 run3 run4 runall clean help