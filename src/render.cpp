#include "render.h"
#include "projector.h"
#include "triangle.cpp"

void Renderer::render(QPainter& painter)
{
    //Setup QPainter
    painter.setPen(QPen(Qt::black));



    //Project shape with hardcoded values for now.
    Projector p(100.0, 90.0, painter.window().height()/painter.window().width());

    Shape s = Shape::createCube(1.0f);
    Shape sOut;

    auto end = std::chrono::steady_clock::now();
    // Calculate the elapsed time
    auto delta = end - start;

    start = std::chrono::steady_clock::now();

    float delta_s = std::chrono::duration_cast<std::chrono::microseconds>(delta).count()/1000000.0;

    p.projectShape(s, sOut, thetaX+=delta_s, thetaZ+=delta_s);

    scaleProjectionToScreen(sOut, painter.window().width(), painter.window().height());


    for(auto tri : sOut.tris){
        
        drawTriangle(painter, tri);
    }

    painter.setFont(QFont("Arial", 20));
    float fps = 1.0f/(std::chrono::duration_cast<std::chrono::microseconds>(delta).count()/ 1000000.0);
    std::string fpsStr = "FPS: " + std::to_string(fps);
    painter.drawText(QPoint(30,30), QString(fpsStr.c_str()));
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
        //Move projection into the screen space
        //Move X                Move Y
        tri.at(0).at(0) += 1.0; tri.at(0).at(1) += 1.0;
        tri.at(1).at(0) += 1.0; tri.at(1).at(1) += 1.0;
        tri.at(2).at(0) += 1.0; tri.at(2).at(1) += 1.0;

        // Scale projection to screen size
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
    font.setPointSize(10);
    font.setFamily("Times");
}

Renderer::~Renderer()
{
}

