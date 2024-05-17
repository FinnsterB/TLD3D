#include "render.h"

#include <QMainWindow>

class Window : public QMainWindow
{
private:
    Renderer renderer;
protected:
    void paintEvent(QPaintEvent *event);

public:
    Renderer& getRenderer();

    Window(QWidget* parent);
    ~Window();
};