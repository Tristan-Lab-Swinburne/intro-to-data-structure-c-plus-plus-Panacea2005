// ShakerSortableIntVector.cpp
// Implementation of Cocktail Shaker Sort

#include "ShakerSortableIntVector.h"

// Constructor using member initializer for base class
ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
    : SortableIntVector(aArrayOfIntegers, aNumberOfElements)
{
    // Base class constructor handles the initialization
}

// Cocktail Shaker Sort implementation
void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{
    size_t n = size();
    size_t left = 0;
    size_t right = n - 1;
    
    while (left < right)
    {
        // Forward pass (left to right)
        for (size_t i = left; i < right; i++)
        {
            // For decreasing order, we need to reverse the logic
            // The default function checks if left <= right (for increasing)
            // For decreasing, we want larger elements to move left
            if (aOrderFunction((*this)[i + 1], (*this)[i]))
            {
                swap(i, i + 1);
            }
        }
        right--;
        
        // Backward pass (right to left)
        for (size_t i = right; i > left; i--)
        {
            // Same reversed logic for decreasing order
            if (aOrderFunction((*this)[i], (*this)[i - 1]))
            {
                swap(i - 1, i);
            }
        }
        left++;
    }
}