#include "render.h"

#include <QMainWindow>
#include <QTimer>

class Window : public QMainWindow
{
private:
    Renderer renderer;
    QTimer timer;
protected:
    void paintEvent(QPaintEvent *event);

public:
    Renderer& getRenderer();

    Window(QWidget* parent);
    ~Window();
};