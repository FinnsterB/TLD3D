#include "projector.h"

#include <math.h>


void Projector::MultiplyMatrixVector(Vec3f &input, Vec3f &output, mat4x4 &mat)
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

void Projector::projectShape(Shape &input, Shape &output, float thetaX, float thetaZ)
{
    mat4x4 matRotX, matRotZ;

    matRotZ.at(0,0) = cosf(thetaZ);
    matRotZ.at(0,1) = sinf(thetaZ);
    matRotZ.at(1,0) = -sinf(thetaZ);
    matRotZ.at(1,1) = cosf(thetaZ);
    matRotZ.at(2,2) = 1;
    matRotZ.at(3,3) = 1;

    matRotX.at(0,0) = 1;
    matRotX.at(1,1) = cosf(thetaX);
    matRotX.at(1,2) = sinf(thetaX);
    matRotX.at(2,1) = -sinf(thetaX);
    matRotX.at(2,2) = cosf(thetaX);
    matRotX.at(3,3) = 1;

    for (unsigned int i = 0; i < input.tris.size(); ++i)
    {
        Triangle zRotatedTriangle = input.tris.at(i);
        Triangle zAndxRotatedTriangle;
        Triangle translatedTriangle;
        Triangle projectedTriangle;
        for (int j = 0; j < 3; j++)
        {
            MultiplyMatrixVector(input.tris.at(i).at(j), zRotatedTriangle.at(j), matRotZ);
            MultiplyMatrixVector(zRotatedTriangle.at(j), zAndxRotatedTriangle.at(j), matRotX);

            translatedTriangle = zAndxRotatedTriangle;

            translatedTriangle.at(j).at(2) = zAndxRotatedTriangle.at(j).at(2) + 3.0f;

            MultiplyMatrixVector(translatedTriangle.at(j), projectedTriangle.at(j), matProj);
        }
        output.tris.push_back(projectedTriangle);
    }
}
