// COS30008, Problem Set 1, 2022
// Implementation of BernsteinBasisPolynomial class

#include "BernsteinBasisPolynomial.h"
#include <cmath>  // for pow()

// Constructor - note the reversed order: aV, aN maps to Combination(aN, aV)
BernsteinBasisPolynomial::BernsteinBasisPolynomial( unsigned int aV, unsigned int aN )
    : fFactor(aN, aV)  // Initialize Combination with n and v (reversed order!)
{
    // The Combination object is initialized in the initializer list
}

// Calculate Bernstein basis polynomial for a given x
// Formula: b(v,n)(x) = C(n,v) * x^v * (1-x)^(n-v)
double BernsteinBasisPolynomial::operator()( double aX ) const
{
    // Get n and v from the combination object
    size_t n = fFactor.getN();
    size_t v = fFactor.getK();
    
    // Calculate the binomial coefficient C(n,v)
    unsigned long long binomialCoeff = fFactor();
    
    // Calculate x^v
    double xPowerV = pow(aX, v);
    
    // Calculate (1-x)^(n-v)
    double oneMinusXPowerNMinusV = pow(1.0 - aX, n - v);
    
    // Return the product
    return binomialCoeff * xPowerV * oneMinusXPowerNMinusV;
}