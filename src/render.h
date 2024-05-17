#include "triangle.h"

#include <QStylePainter>
#include <chrono>



class Renderer
{
private:
    std::chrono::steady_clock::time_point lastRenderComplete;
    
public:
    void render(QPainter& painter);
    void drawTriangle(QPainter& painter, Triangle& triangle);
    Renderer(/* args */);
    ~Renderer();

};
