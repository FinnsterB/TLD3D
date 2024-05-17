#include "projector.h"

#include <math.h>


void Projector::MultiplyMatrixVector(Vec4f &input, Vec4f &output, mat4x4 &mat)
{
    // Hardcoded 3 because we only need to calculate for x,y,z.
    // X,y and z are at elements 0,1 and 2 respectively.
    // The last element is seperate from our calculation and used to divide x,y and z for our resulting projection.
    for (int i = 0; i < 3; ++i)
    {
        output.at(i) = input.at(0) * mat.at(0,i) + input.at(1) * mat.at(1,i) + input.at(2) * mat.at(2,i) + mat.at(3, i);
    }

    float w = input.at(0) * mat.at(0,3) + input.at(1) * mat.at(1,3) + input.at(2) * mat.at(2,3) + mat.at(3,3);

    if(w != 0.0f){
        for (int i = 0; i < 3; i++)
        {
            output.at(i) /= w;
        }
        
    }
    
}

Projector::Projector(float aFar, float aFov, float aAspectRatio)
{
    float near = 0.1f;
    float fovRad = 1.0f / tanf(aFov * 0.5f / 180.0f * 3.14159f);

    matProj.at(0,0) = aAspectRatio * fovRad;
    matProj.at(1,1) = fovRad;
    matProj.at(2,2) = aFar / (aFar-near);
    matProj.at(3,2) = (-aFar * near) / (aFar - near);
    matProj.at(2,3) = 1.0f;
    matProj.at(3,3) = 0.0f;
}

Projector::~Projector()
{
}
