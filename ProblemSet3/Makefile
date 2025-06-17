# Makefile for Problem Set 3
# Supports building all problems (P0-P5) or individual ones

# ── Compiler and flags ───────────────────────────────────────
CXX      = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g

# Single translation unit; everything else is header-only
SRC      = Main.cpp

# Executable names
PROB1_EXE = prob1
PROB2_EXE = prob2
PROB3_EXE = prob3
PROB4_EXE = prob4
PROB5_EXE = prob5
ALL_EXE   = ps3_all

# ── Phony targets ────────────────────────────────────────────
.PHONY: all clean prob1 prob2 prob3 prob4 prob5 run1 run2 run3 run4 run5 runall help

# Default target – build ALL problems in one go
all: prob1 prob2 prob3 prob4 prob5
	@echo "All Problem-Set 3 executables built successfully!"

# -------- Problem-specific build targets --------------------
prob1:
	@echo "Building Problem 1..."
	$(CXX) $(CXXFLAGS) -DP1            $(SRC) -o $(PROB1_EXE)
	@echo "Built: ./$(PROB1_EXE)"

prob2:
	@echo "Building Problem 2..."
	$(CXX) $(CXXFLAGS) -DP2            $(SRC) -o $(PROB2_EXE)
	@echo "Built: ./$(PROB2_EXE)"

prob3:
	@echo "Building Problem 3..."
	$(CXX) $(CXXFLAGS) -DP3            $(SRC) -o $(PROB3_EXE)
	@echo "Built: ./$(PROB3_EXE)"

prob4:
	@echo "Building Problem 4..."
	$(CXX) $(CXXFLAGS) -DP4            $(SRC) -o $(PROB4_EXE)
	@echo "Built: ./$(PROB4_EXE)"

prob5:
	@echo "Building Problem 5..."
	$(CXX) $(CXXFLAGS) -DP5            $(SRC) -o $(PROB5_EXE)
	@echo "Built: ./$(PROB5_EXE)"

# -------- Convenience “build-and-run” targets ---------------
run1: prob1
	@echo "\n=== Running Problem 1 ==="
	./$(PROB1_EXE)

run2: prob2
	@echo "\n=== Running Problem 2 ==="
	./$(PROB2_EXE)

run3: prob3
	@echo "\n=== Running Problem 3 ==="
	./$(PROB3_EXE)

run4: prob4
	@echo "\n=== Running Problem 4 ==="
	./$(PROB4_EXE)

run5: prob5
	@echo "\n=== Running Problem 5 ==="
	./$(PROB5_EXE)

# -------- Build + run every test with all macros on ----------
runall:
	@echo "Building and running ALL problems (P0-P5 at once)…"
	$(CXX) $(CXXFLAGS) -DP0 -DP1 -DP2 -DP3 -DP4 -DP5 $(SRC) -o $(ALL_EXE)
	@echo "\n=== Running combined test ==="
	./$(ALL_EXE)

# -------- House-keeping --------------------------------------
clean:
	@echo "Cleaning build artifacts…"
	@rm -f $(PROB1_EXE) $(PROB2_EXE) $(PROB3_EXE) $(PROB4_EXE) $(PROB5_EXE) $(ALL_EXE)
	@echo "Clean complete!"

# -------- Help -----------------------------------------------
help:
	@echo "Available targets:"
	@echo "  make all     – Build executables for P1-P5"
	@echo "  make probN   – Build Problem N only   (N = 1-5)"
	@echo "  make runN    – Build and run Problem N"
	@echo "  make runall  – Build one binary with P0-P5 and run it"
	@echo "  make clean   – Remove all executables"
	@echo "  make help    – Show this help message"
