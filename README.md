# COS30008 Data Structures and Patterns - Problem Set 1

**Student**: Le Truong Thien Nguyen  
**Student ID**: 104974280  
**Semester**: 1, 2025  
**Institution**: Swinburne University of Technology

## 📋 Overview

This repository contains my solutions for Problem Set 1 of COS30008 Data Structures and Patterns. The assignment focuses on implementing mathematical algorithms in C++ while adhering to object-oriented design principles.

### Problems Implemented

1. **Polygon Signed Area** - Shoelace algorithm implementation
2. **Polynomial Operations** - Derivative, integral, and evaluation operations
3. **Combination Calculator** - Efficient binomial coefficient computation
4. **Bernstein Basis Polynomials** - Foundation for Bézier curves

## 🗂️ Repository Structure

```
Problem Set 1/
│
├── README.md                   # This file
├── Main.cpp                    # Shared test driver with conditional compilation
├── runall.ps1                  # PowerShell script for automated testing
├── Makefile                    # GNU Make build automation
│
├── Problem 1/                  # Polygon Signed Area
│   ├── Polygon.h              # Provided header
│   ├── Polygon.cpp            # Provided implementation
│   ├── PolygonPS1.cpp         # ★ My implementation of getSignedArea()
│   ├── Vector2D.h             # Provided vector class
│   ├── Vector2D.cpp           # Provided vector implementation
│   ├── Parallelogram.txt      # Test data (4 vertices)
│   └── Data.txt               # Test data (21 vertices - dinosaur)
│
├── Problem 2/                  # Polynomial Operations
│   ├── Polynomial.h           # Provided header
│   ├── Polynomial.cpp         # ★ My base implementation
│   └── PolynomialPS1.cpp      # ★ My calculus operations
│
├── Problem 3/                  # Combination
│   ├── Combination.h          # ★ My header
│   └── Combination.cpp        # ★ My implementation
│
└── Problem 4/                  # Bernstein Basis Polynomials
    ├── BernsteinBasisPolynomial.h    # ★ My header
    ├── BernsteinBasisPolynomial.cpp  # ★ My implementation
    ├── Combination.h                 # Reused from Problem 3
    └── Combination.cpp               # Reused from Problem 3

★ = Files created/implemented for this assignment
```

## 🚀 Quick Start

### Prerequisites

- **C++ Compiler**: g++ (MinGW/MSYS2 on Windows, or native on Linux/macOS)
- **Make** (optional): For Makefile usage
- **PowerShell** (Windows): For automated script execution
- **WSL** (optional): For Linux environment on Windows

### Compilation & Execution

#### Option 1: Individual Problem Compilation (Windows PowerShell)

```powershell
# Problem 1
cd "Problem 1"
g++ -static -o polygon_test.exe Main.cpp Polygon.cpp PolygonPS1.cpp Vector2D.cpp -std=c++11
.\polygon_test.exe Parallelogram.txt
.\polygon_test.exe Data.txt

# Problem 2
cd "..\Problem 2"
g++ -static -o polynomial_test.exe Main.cpp Polynomial.cpp PolynomialPS1.cpp -std=c++11
.\polynomial_test.exe

# Problem 3
cd "..\Problem 3"
g++ -static -o combination_test.exe Main.cpp Combination.cpp -std=c++11
.\combination_test.exe

# Problem 4
cd "..\Problem 4"
Copy-Item "..\Problem 3\Combination.*" .  # Copy required files
g++ -static -o bernstein_test.exe Main.cpp BernsteinBasisPolynomial.cpp Combination.cpp -std=c++11
.\bernstein_test.exe
```

#### Option 2: Automated PowerShell Script

```powershell
# From the root directory (Problem Set 1)
.\runall.ps1
```

#### Option 3: Using Makefile (Linux/WSL)

```bash
# Compile all problems
make all

# Run all tests
make runall

# Run individual problems
make run1
make run2
make run3
make run4

# Clean build artifacts
make clean
```

## 📝 Problem Descriptions

### Problem 1: Polygon Signed Area (38 marks)

Implements the shoelace algorithm (Gauss-Jacobi formula) to calculate the signed area of a polygon. The sign indicates vertex ordering:
- Positive area = Counterclockwise vertices
- Negative area = Clockwise vertices

**Key Features:**
- Handles polygons with any number of vertices (minimum 3)
- Uses Vector2D class for vertex representation
- O(n) time complexity

### Problem 2: Polynomial Operations (60 marks)

Extends the Polynomial class with mathematical operations:
- `operator()`: Evaluate polynomial at given x
- `getDerivative()`: Calculate derivative polynomial
- `getIndefiniteIntegral()`: Calculate antiderivative
- `getDefiniteIntegral()`: Calculate definite integral between bounds

**Key Features:**
- Supports polynomials up to degree 21
- Implements fundamental theorem of calculus
- Verifies derivative of integral returns original polynomial

### Problem 3: Combination (38 marks)

Calculates binomial coefficients C(n,k) without factorial overflow:
- Uses iterative algorithm with alternating multiplication/division
- Optimizes using symmetry property: C(n,k) = C(n,n-k)
- Supports large values (e.g., C(52,5))

**Key Features:**
- Avoids factorial calculation
- Uses 64-bit unsigned integers
- Generates Pascal's triangle for verification

### Problem 4: Bernstein Basis Polynomials (20 marks)

Implements Bernstein polynomials used in Bézier curves:
- Formula: b(v,n)(x) = C(n,v) × x^v × (1-x)^(n-v)
- Reuses Combination class from Problem 3
- Verifies partition of unity property

**Key Features:**
- Demonstrates code reuse
- Parameter order follows mathematical convention
- Essential for computer graphics applications

## ⚙️ Build Configuration

### Static Linking

All compilations use `-static` flag to avoid runtime DLL dependencies. This resolves the "ld returned 116 exit status" error encountered with MSYS2/MinGW on Windows.

### Conditional Compilation

The `Main.cpp` file uses preprocessor directives to select which problem to compile:
```cpp
#define P1    // Enable Problem 1
//#define P2  // Disable Problem 2
//#define P3  // Disable Problem 3
//#define P4  // Disable Problem 4
```

The automated build scripts handle this automatically.

## 🧪 Test Data

### Problem 1
- **Parallelogram.txt**: 4-vertex parallelogram (Area: 16, Clockwise)
- **Data.txt**: 21-vertex dinosaur shape (Area: 38.5, Counterclockwise)

### Problem 2
- Automated test with polynomial: -0.25x + 4
- Tests evaluation at x=16, derivatives, and integrals

### Problem 3
- Generates first 10 rows of Pascal's triangle
- Tests large combinations: C(28,14) and C(52,5)

### Problem 4
- Verifies sum of Bernstein polynomials equals 1
- Tests at x = 0, 0.2, 0.4, 0.6, 0.8, 1.0

## 🐛 Troubleshooting

### Compilation Errors

1. **"ld returned 116 exit status"**
   - Solution: Use `-static` flag in compilation
   - Caused by DLL linking issues on Windows

2. **"No such file or directory"**
   - Ensure you're in the correct directory
   - Copy Main.cpp to each problem folder if needed

3. **Spaces in directory names**
   - Use quotes around paths: `"Problem 1"`
   - Or rename folders to Problem1, Problem2, etc.

### Runtime Errors

1. **"Arguments missing"** (Problem 1)
   - Provide filename: `.\polygon_test.exe Parallelogram.txt`

2. **Missing Combination files (Problem 4)**
   - Copy from Problem 3: `Copy-Item "..\Problem 3\Combination.*" .`

## 📚 Learning Outcomes

This assignment demonstrates:
- Implementation of mathematical algorithms in C++
- Object-oriented design principles (extending without modifying)
- Cross-platform build system development
- Numerical precision and overflow handling
- Code reuse and modular design

## 📄 License

This project is submitted as coursework for COS30008 at Swinburne University of Technology. Please refer to the university's academic integrity policies.

## 🙏 Acknowledgments

- Mr. Tristan Nguyen - Course Coordinator
- Swinburne University of Technology
- Mathematical algorithms based on established formulas (shoelace, power rule, etc.)

---

**Note**: The `-static` flag is crucial for Windows compilation to avoid linking errors. For development, increase terminal font size for better readability of output.
