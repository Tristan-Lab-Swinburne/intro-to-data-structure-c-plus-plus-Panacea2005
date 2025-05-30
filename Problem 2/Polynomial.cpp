// COS30008, Tutorial 3, 2025
// Implementation of Polynomial class

#include "Polynomial.h"
#include <algorithm>  // for max()

using namespace std;

// Default constructor - initializes polynomial to 0
Polynomial::Polynomial()
{
    fDegree = 0;
    
    // Initialize all coefficients to 0
    for (size_t i = 0; i <= MAX_DEGREE; i++)
    {
        fCoeffs[i] = 0.0;
    }
}

// Multiply two polynomials
Polynomial Polynomial::operator*( const Polynomial& aRHS ) const
{
    Polynomial result;
    
    // The degree of the product is the sum of the degrees
    result.fDegree = fDegree + aRHS.fDegree;
    
    // Make sure we don't exceed MAX_DEGREE
    if (result.fDegree > MAX_DEGREE)
    {
        result.fDegree = MAX_DEGREE;
    }
    
    // Multiply polynomials: (a0 + a1*x + a2*x^2 + ...) * (b0 + b1*x + b2*x^2 + ...)
    // The coefficient of x^k in the product is the sum of ai*bj where i+j=k
    for (size_t i = 0; i <= fDegree; i++)
    {
        for (size_t j = 0; j <= aRHS.fDegree; j++)
        {
            if (i + j <= result.fDegree)
            {
                result.fCoeffs[i + j] += fCoeffs[i] * aRHS.fCoeffs[j];
            }
        }
    }
    
    return result;
}

// Compare two polynomials for equality
bool Polynomial::operator==( const Polynomial& aRHS ) const
{
    // First check if degrees are equal
    if (fDegree != aRHS.fDegree)
    {
        return false;
    }
    
    // Check all coefficients up to the degree
    for (size_t i = 0; i <= fDegree; i++)
    {
        if (fCoeffs[i] != aRHS.fCoeffs[i])
        {
            return false;
        }
    }
    
    return true;
}

// Input operator - reads polynomial from highest degree to lowest
istream& operator>>( istream& aIStream, Polynomial& aObject )
{
    // Read the degree first
    aIStream >> aObject.fDegree;
    
    // Make sure degree is within bounds
    if (aObject.fDegree > MAX_POLYNOMIAL)
    {
        aObject.fDegree = MAX_POLYNOMIAL;
    }
    
    // Initialize all coefficients to 0
    for (size_t i = 0; i <= MAX_DEGREE; i++)
    {
        aObject.fCoeffs[i] = 0.0;
    }
    
    // Read coefficients from highest degree to lowest
    // For example, for degree 2, read coeff of x^2, then x^1, then x^0
    for (int i = aObject.fDegree; i >= 0; i--)
    {
        aIStream >> aObject.fCoeffs[i];
    }
    
    return aIStream;
}

// Output operator - writes polynomial from highest degree to lowest
ostream& operator<<( ostream& aOStream, const Polynomial& aObject )
{
    bool firstTerm = true;
    
    // Output from highest degree to lowest
    for (int i = aObject.fDegree; i >= 0; i--)
    {
        // Skip zero coefficients except for the constant term of a zero polynomial
        if (aObject.fCoeffs[i] != 0.0 || (aObject.fDegree == 0 && i == 0))
        {
            // Add + or - between terms
            if (!firstTerm)
            {
                if (aObject.fCoeffs[i] > 0)
                {
                    aOStream << " + ";
                }
                else
                {
                    aOStream << " - ";
                    // Make the coefficient positive for output
                }
            }
            else
            {
                firstTerm = false;
                if (aObject.fCoeffs[i] < 0)
                {
                    aOStream << "-";
                }
            }
            
            // Output the coefficient (use absolute value if we already printed the sign)
            double coeff = aObject.fCoeffs[i];
            if (!firstTerm && aObject.fCoeffs[i] < 0)
            {
                coeff = -coeff;
            }
            else if (firstTerm && aObject.fCoeffs[i] < 0)
            {
                coeff = -coeff;
            }
            
            aOStream << coeff;
            
            // Always output x^degree, even for x^0
            aOStream << "x^" << i;
        }
    }
    
    // Handle the case of zero polynomial
    if (firstTerm)
    {
        aOStream << "0";
    }
    
    return aOStream;
}