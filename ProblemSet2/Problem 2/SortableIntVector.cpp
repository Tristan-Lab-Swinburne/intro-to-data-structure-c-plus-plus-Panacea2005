// SortableIntVector.cpp
// Implementation of SortableIntVector with Bubble Sort

#include "SortableIntVector.h"

// Constructor using member initializer for base class
SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
    : IntVector(aArrayOfIntegers, aNumberOfElements)
{
    // Base class constructor handles the initialization
}

// Bubble Sort implementation
void SortableIntVector::sort(Comparable aOrderFunction)
{
    size_t n = size();
    
    // Bubble Sort algorithm
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            // Compare adjacent elements using the order function
            // If they are not in the correct order, swap them
            if (!aOrderFunction((*this)[j], (*this)[j + 1]))
            {
                swap(j, j + 1);
            }
        }
    }
}