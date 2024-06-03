#include "triangle.h"

#include <QStylePainter>
#include <chrono>



class Renderer
{
private:
    std::chrono::steady_clock::time_point start;
    QFont font;
    float thetaX;
    float thetaZ;

public:
    void render(QPainter& painter);
    void drawTriangle(QPainter& painter, Triangle& triangle);
    void scaleProjectionToScreen(Shape& projection, int screenWidth, int screenHeight);
    Renderer(/* args */);
    ~Renderer();

};
