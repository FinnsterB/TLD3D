#include "triangle.h"


// Matrix given in rows x columns
struct mat4x4
{
    std::array<std::array<float, 4>, 4> m = {0};
    float& at(unsigned int row, unsigned int col){
        return m.at(row).at(col);
    };
};

class Projector
{
private:
    mat4x4 matProj;
    //This function is specific for applying projection to the vector.
    void MultiplyMatrixVector(Vec3f& i, Vec3f& o, mat4x4& m);
public:
    Projector(float aFar, float aFov, float aAspectRatio);
    ~Projector();

    void projectShape(Shape& input, Shape& output, float thetaX, float thetaZ);
};

