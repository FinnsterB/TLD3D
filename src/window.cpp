#include "window.h"

#include <QWidget>
#include <QStylePainter>

void Window::paintEvent(QPaintEvent *event)
{
    // unuse
    Q_UNUSED(event);

    // pass "this" pointer to painter
    QPainter painter(this); 

    renderer.render(painter);
}

Renderer& Window::getRenderer()
{
    return renderer;
}

Window::Window(QWidget *parent) : QMainWindow(parent)
{
    QMainWindow::setGeometry(0,0,500,500);
}

Window::~Window()
{
}