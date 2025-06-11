// COS30008, Problem Set 1, 2025
// Implementation of polynomial operations

#include "Polynomial.h"
#include <cmath>  // for pow()

// Call operator to evaluate polynomial at a given x value
double Polynomial::operator()( double aX ) const
{
    double result = 0.0;
    
    // Calculate polynomial value using Horner's method (more efficient)
    // or direct calculation
    for (size_t i = 0; i <= fDegree; i++)
    {
        // Calculate x^i and multiply by coefficient
        result += fCoeffs[i] * pow(aX, i);
    }
    
    return result;
}

// Compute derivative of the polynomial
Polynomial Polynomial::getDerivative() const
{
    Polynomial derivative;
    
    // Handle the case of constant polynomial (degree 0)
    if (fDegree == 0)
    {
        derivative.fDegree = 0;
        derivative.fCoeffs[0] = 0.0;
        return derivative;
    }
    
    // Derivative has degree n-1
    derivative.fDegree = fDegree - 1;
    
    // Derivative of x^n is n*x^(n-1)
    // So coefficient of x^i in derivative is (i+1) * coefficient of x^(i+1) in original
    for (size_t i = 0; i <= derivative.fDegree; i++)
    {
        derivative.fCoeffs[i] = (i + 1) * fCoeffs[i + 1];
    }
    
    // Initialize remaining coefficients to 0
    for (size_t i = derivative.fDegree + 1; i <= MAX_DEGREE; i++)
    {
        derivative.fCoeffs[i] = 0.0;
    }
    
    return derivative;
}

// Compute indefinite integral of the polynomial
Polynomial Polynomial::getIndefiniteIntegral() const
{
    Polynomial integral;
    
    // Integral has degree n+1
    integral.fDegree = fDegree + 1;
    
    // Constant of integration is 0
    integral.fCoeffs[0] = 0.0;
    
    // Integral of x^n is x^(n+1)/(n+1)
    // So coefficient of x^i in integral is coefficient of x^(i-1) in original divided by i
    for (size_t i = 1; i <= integral.fDegree; i++)
    {
        integral.fCoeffs[i] = fCoeffs[i - 1] / i;
    }
    
    // Initialize remaining coefficients to 0
    for (size_t i = integral.fDegree + 1; i <= MAX_DEGREE; i++)
    {
        integral.fCoeffs[i] = 0.0;
    }
    
    return integral;
}

// Calculate definite integral between two bounds
double Polynomial::getDefiniteIntegral( double aXLow, double aXHigh ) const
{
    // Get the indefinite integral
    Polynomial integral = getIndefiniteIntegral();
    
    // Calculate F(xHigh) - F(xLow) where F is the indefinite integral
    double valueAtHigh = integral(aXHigh);
    double valueAtLow = integral(aXLow);
    
    return valueAtHigh - valueAtLow;
}