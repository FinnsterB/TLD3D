#include "render.h"
#include "projector.h"
#include "triangle.cpp"

void Renderer::render(QPainter& painter)
{
    //Setup QPainter
    painter.setPen(QPen(Qt::black));



    //Project shape with hardcoded values for now.
    Projector p(1000.0, 90.0, painter.window().width()/painter.window().height());

    Shape s = Shape::createTetrahedron(1.0f);
    Shape sOut;

    auto end = std::chrono::steady_clock::now();
    // Calculate the elapsed time
    auto delta = end - start;

    start = std::chrono::steady_clock::now();

    auto delta_s = std::chrono::duration_cast<std::chrono::seconds>(delta);


    p.projectShape(s, sOut, 1.0f*delta_s.count(), 0.5*delta_s.count());

    scaleProjectionToScreen(sOut, painter.window().width(), painter.window().height());


    for(auto tri : sOut.tris){
        
        drawTriangle(painter, tri);
    }
    float fps = 1.0f/std::chrono::duration_cast<std::chrono::microseconds>(delta).count();
    std::string fpsStr = "FPS: " + std::to_string(fps);
    painter.drawText(QPoint(0,0), QString(fpsStr.c_str()));

}

void Renderer::drawTriangle(QPainter& painter, Triangle& triangle)
{
    painter.drawLine(triangle.at(0).at(0),triangle.at(0).at(1), triangle.at(1).at(0), triangle.at(1).at(1));
    painter.drawLine(triangle.at(1).at(0),triangle.at(1).at(1), triangle.at(2).at(0), triangle.at(2).at(1));
    painter.drawLine(triangle.at(0).at(0),triangle.at(0).at(1), triangle.at(2).at(0), triangle.at(2).at(1));
     
}


void Renderer::scaleProjectionToScreen(Shape &projection, int screenWidth, int screenHeight)
{
    for(auto& tri : projection.tris){
        //Move X                Move Y
        tri.at(0).at(0) += 1.0; tri.at(0).at(1) += 1.0;
        tri.at(1).at(0) += 1.0; tri.at(1).at(1) += 1.0;
        tri.at(2).at(0) += 1.0; tri.at(2).at(1) += 1.0;

        
        tri.at(0).at(0) *= 0.5f * (float)screenWidth;   //x
        tri.at(0).at(1) *= 0.5f * (float)screenHeight;  //y

        tri.at(1).at(0) *= 0.5f * (float)screenWidth;   //x
        tri.at(1).at(1) *= 0.5f * (float)screenHeight;  //y

        tri.at(2).at(0) *= 0.5f * (float)screenWidth;   //x
        tri.at(2).at(1) *= 0.5f * (float)screenHeight;  //y


    }
}

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

