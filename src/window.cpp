#include "window.h"

#include <QWidget>
#include <QStylePainter>

void Window::paintEvent(QPaintEvent *event)
{
    // unused
    Q_UNUSED(event);

    // pass "this" pointer to painter
    QPainter painter(this); 

    renderer.render(painter);
    QMainWindow::paintEvent(event);
}

Renderer& Window::getRenderer()
{
    return renderer;
}

Window::Window(QWidget *parent) : QMainWindow(parent)
{
    QMainWindow::setGeometry(0,0,500,500);
    QMainWindow::connect(&timer, &QTimer::timeout, this, QOverload<>::of(&QMainWindow::update));
    timer.start(16);
}

Window::~Window()
{
}