
#include <array>
#include <vector>

// X, y and z are at elements 0,1 and 2 respectively.
typedef std::array<float, 3> Vec3f;

// X, y and z are at elements 0,1 and 2 respectively.
typedef std::array<float, 4> Vec4f;

typedef std::array<Vec3f, 3> Triangle;

class Shape
{
private:
    /* data */
public:
    Shape(/* args */);
    ~Shape();
};

