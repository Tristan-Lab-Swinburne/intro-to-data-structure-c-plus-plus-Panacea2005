// COS30008, Problem Set 1, 2025
// Implementation of getSignedArea() method for Polygon class

#include "Polygon.h"
#include <cmath>  // for fabs()

float Polygon::getSignedArea() const
{
    float area = 0.0f;
    
    // Need at least 3 vertices to form a polygon
    if (fNumberOfVertices < 3)
    {
        return 0.0f;
    }
    
    // Apply the shoelace formula
    // Area = 1/2 * Σ(x[i] * y[i+1] - y[i] * x[i+1])
    
    // Sum from vertex 0 to vertex n-2
    for (size_t i = 0; i < fNumberOfVertices - 1; i++)
    {
        float xi = fVertices[i].getX();
        float yi = fVertices[i].getY();
        float xi_plus_1 = fVertices[i + 1].getX();
        float yi_plus_1 = fVertices[i + 1].getY();
        
        area += (xi * yi_plus_1 - yi * xi_plus_1);
    }
    
    // Add the last term connecting the last vertex to the first
    float xn = fVertices[fNumberOfVertices - 1].getX();
    float yn = fVertices[fNumberOfVertices - 1].getY();
    float x0 = fVertices[0].getX();
    float y0 = fVertices[0].getY();
    
    area += (xn * y0 - yn * x0);
    
    // Divide by 2 to get the final area
    area = area / 2.0f;
    
    return area;
}