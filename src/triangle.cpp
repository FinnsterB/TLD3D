#include "triangle.h"

Shape::Shape(/* args */)
{
}

Shape::~Shape()
{
}

Shape Shape::createTetrahedron(Vec3f& scale)
{
    Shape res = Shape();
    Vec3f p0 = {0.0f*scale.at(0),0.0f*scale.at(1),0.0f*scale.at(2)};
    Vec3f p1 = {1.0f*scale.at(0),0.0f*scale.at(1),1.0f*scale.at(2)};
    Vec3f p2 = {0.5f*scale.at(0),0.0f*scale.at(1),1.0f*scale.at(2)};
    Vec3f p3 = {0.5f*scale.at(0),1.0f*scale.at(1),0.5f*scale.at(2)};
    Triangle t0 = {p0,p1,p2};
    Triangle t1 = {p1,p2,p3};
    Triangle t2 = {p2,p0,p3};
    Triangle t3 = {p0,p1,p3};
    res.tris.push_back(t0);
    res.tris.push_back(t1);
    res.tris.push_back(t2);
    res.tris.push_back(t3);
    return res;
}

Shape Shape::createTetrahedron(float scale){
    Vec3f scaleVec = {scale, scale, scale};
    return createTetrahedron(scaleVec);
}

Shape Shape::createCube(Vec3f& scale)
{
    Shape res = Shape();
    
    // Define the 8 vertices of the cube
    Vec3f p0 = {0.0f * scale.at(0), 0.0f * scale.at(1), 0.0f * scale.at(2)};
    Vec3f p1 = {1.0f * scale.at(0), 0.0f * scale.at(1), 0.0f * scale.at(2)};
    Vec3f p2 = {1.0f * scale.at(0), 1.0f * scale.at(1), 0.0f * scale.at(2)};
    Vec3f p3 = {0.0f * scale.at(0), 1.0f * scale.at(1), 0.0f * scale.at(2)};
    Vec3f p4 = {0.0f * scale.at(0), 0.0f * scale.at(1), 1.0f * scale.at(2)};
    Vec3f p5 = {1.0f * scale.at(0), 0.0f * scale.at(1), 1.0f * scale.at(2)};
    Vec3f p6 = {1.0f * scale.at(0), 1.0f * scale.at(1), 1.0f * scale.at(2)};
    Vec3f p7 = {0.0f * scale.at(0), 1.0f * scale.at(1), 1.0f * scale.at(2)};
    
    // Define the 12 triangles of the cube (2 per face)
    Triangle t0 = {p0, p1, p2}; Triangle t1 = {p0, p2, p3}; // Front face
    Triangle t2 = {p4, p5, p6}; Triangle t3 = {p4, p6, p7}; // Back face
    Triangle t4 = {p0, p1, p5}; Triangle t5 = {p0, p5, p4}; // Bottom face
    Triangle t6 = {p2, p3, p7}; Triangle t7 = {p2, p7, p6}; // Top face
    Triangle t8 = {p0, p3, p7}; Triangle t9 = {p0, p7, p4}; // Left face
    Triangle t10 = {p1, p2, p6}; Triangle t11 = {p1, p6, p5}; // Right face
    
    // Add the triangles to the shape
    res.tris.push_back(t0);
    res.tris.push_back(t1);
    res.tris.push_back(t2);
    res.tris.push_back(t3);
    res.tris.push_back(t4);
    res.tris.push_back(t5);
    res.tris.push_back(t6);
    res.tris.push_back(t7);
    res.tris.push_back(t8);
    res.tris.push_back(t9);
    res.tris.push_back(t10);
    res.tris.push_back(t11);
    
    return res;
}

Shape Shape::createCube(float scale){
    Vec3f scaleVec = {scale, scale, scale};
    return createCube(scaleVec);
}