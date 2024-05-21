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