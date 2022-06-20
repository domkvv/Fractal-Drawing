#include <QApplication>
#include <QVBoxLayout>
#include "ui_gui.h"

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);

    QApplication app (argc, argv);
    Ui_MainWindow mainWindow;
    QMainWindow* qMainWindow = new QMainWindow;
    mainWindow.setupUi(qMainWindow);
    qMainWindow->show();

    return app.exec();
}
