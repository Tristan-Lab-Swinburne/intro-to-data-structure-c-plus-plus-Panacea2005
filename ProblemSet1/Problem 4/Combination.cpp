// COS30008, Problem Set 1, 2022
// Implementation of Combination class

#include "Combination.h"

// Constructor
Combination::Combination( size_t aN, size_t aK )
{
    fN = aN;
    fK = aK;
}

// Getter for n
size_t Combination::getN() const
{
    return fN;
}

// Getter for k
size_t Combination::getK() const
{
    return fK;
}

// Calculate n choose k using the iterative method
unsigned long long Combination::operator()() const
{
    // Handle edge cases
    if (fK > fN)
    {
        return 0;  // n choose k is 0 when k > n
    }
    
    if (fK == 0 || fK == fN)
    {
        return 1;  // n choose 0 = n choose n = 1
    }
    
    // Optimize by using the property: C(n,k) = C(n,n-k)
    // This reduces the number of iterations
    size_t k = fK;
    if (k > fN - k)
    {
        k = fN - k;
    }
    
    unsigned long long result = 1;
    
    // Calculate using the formula:
    // C(n,k) = n/1 * (n-1)/2 * (n-2)/3 * ... * (n-k+1)/k
    for (size_t i = 0; i < k; i++)
    {
        result *= (fN - i);
        result /= (i + 1);
    }
    
    return result;
}