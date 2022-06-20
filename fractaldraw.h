#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <QtOpenGLWidgets>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include "fractalform.h"

void colorFractal(){
    glBegin(GL_POINTS);
    const double w = 1200;
    const double h = 800;
    double r, g, b;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            Complex z = scaleToComplex(x, y, w, h);

            int n = -1;
            switch(ftype){
                case JULIA:
                case JULIA_A:
                    n = Julia(z, c);
                    break;
                case MANDELBROT:
                    n = Mandelbrot(z);
                    break;
                case NEWTON:
                    n = Newton(z);
                    break;
                default:
                    break;
            }

            if (n != -1 && ftype != NEWTON) {
                r = (1.0) * (double) n / maxIterations;
                g = (0.0) * (double) n / maxIterations;
                b = (1.0) * (double) n / maxIterations;

            }else if(n != -1){
                double colors[3][3] = { {1.0, 0.75, 0.8} ,
                                        {0.55, 0.13, 0.32},
                                        {(double) 57/255, 0.0, (double) 14/255}};

                r = colors[n][0]; g = colors[n][1]; b = colors[n][2];

            } else {
                r = 1; g = 1; b = 1;
            }
            glColor3f(r, g, b);
            glVertex2i(x, y);
        }
    }
    glEnd();
}

void displayFractal() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    const double w = 1200;
    const double h = 800;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0f);
    colorFractal();
}

void initFractal(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    const double w = 1200;
    const double h = 800;
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0.0, w, 0.0, h);
    glColor3f(0.0, 0.0, 0.0);
}

void animInitialize() {
    const double w = 1200;
    const double h = 800;
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
}

void animateFractal() {
    const double w = 1200;
    const double h = 800;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(0.05f);
    glBegin(GL_POINTS);

    double r, g, b;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            Complex z = scaleToComplex(x, y, w, h);
            int n = Julia(z, c);

            if (n != -1) {
                r = (1.0) * (double) n / maxIterations;
                g = ((double) 0.0) * (double) n / maxIterations;
                b = ((double) 1.0) * (double) n / maxIterations;
            } else {
                r = 1; g = 1; b = 1;
            }
            glColor3f(r, g, b);
            glVertex2i(x, y);
        }
    }
    glEnd();
    glFlush();
    a += 0.07;
    if (a >= 0 && a <= 2 * M_PI) {
        c = Complex(radius, 0) * exp(Complex(0, 1) * Complex(a, 0));
    } else a = 0.0;

}


