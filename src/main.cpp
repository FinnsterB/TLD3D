#include "window.h"

#include <QApplication>
#include <QGraphicsView>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);
 Window w(nullptr);
 w.show();
 return app.exec();
}