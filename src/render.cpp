#include "render.h"
#include "projector.h"
#include "triangle.cpp"

void Renderer::render(QPainter& painter)
{
    //Setup QPainter
    painter.setPen(QPen(Qt::black));



    //Project shape with hardcoded values for now.
    Projector p(1000.0, 90.0, painter.window().width()/painter.window().height());


    lastRenderComplete = std::chrono::steady_clock::now();
}

void Renderer::drawTriangle(QPainter& painter, Triangle& triangle)
{
    painter.drawLine(triangle.at(0).at(0),triangle.at(0).at(1), triangle.at(1).at(0), triangle.at(1).at(1));
    painter.drawLine(triangle.at(1).at(0),triangle.at(1).at(1), triangle.at(2).at(0), triangle.at(2).at(1));
    painter.drawLine(triangle.at(0).at(0),triangle.at(0).at(1), triangle.at(2).at(0), triangle.at(2).at(1));
     
}

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

