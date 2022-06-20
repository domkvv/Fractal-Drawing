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
#include <QWidget>
#include "fractaldraw.h"

QT_BEGIN_NAMESPACE
namespace Ui { class glWidget; }
QT_END_NAMESPACE

class glWidget : public QOpenGLWidget {

public:
    QLineEdit * inputC;
    QLineEdit * inputR;

    explicit glWidget(QWidget *parent = nullptr){}

    ~glWidget(){}

     void initializeGL() override {
         if(ftype == JULIA_A){
             animInitialize();
         }else{
             initFractal();
         }
    }

    void paintGL() override{
        if(ftype == JULIA_A){
            animateFractal();
            update();
        }
        else{
            displayFractal();
        }
    }

    void isJulia(){
        ftype = JULIA;
        xmin = -2, xmax = 2, ymin = -1.5, ymax = 1.5;
        maxIterations = 1200;
    }

    void isJuliaAnim(){
        ftype = JULIA_A;
        xmin = -1.5, xmax = 1.5, ymin = -1, ymax = 1;
        maxIterations = 70;
        radius = 0.8;
        c = Complex(radius, 0) * exp(Complex(0, 1) * Complex(a, 0));
    }

    void isNewton(){
        ftype = NEWTON;
        xmin = -1.5, xmax = 1.5, ymin = -1, ymax = 1;
        maxIterations = 50;
    }

    void isMandelbrot(){
        ftype = MANDELBROT;
        xmin = -2.5, xmax = 1.5, ymin = -1.5, ymax = 1.5;
        maxIterations = 150;
    }

    void getC(){
        std::string s = inputC->text().toStdString();
        int gap;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                gap = i;
                break;
            }
        }
        if(s != ""){
            std::string first = s.substr(0, gap);
            std::string second = s.substr(gap+1, s.length());
            double re, im;
            re = std::stod(first);
            im = std::stod(second);
            c = Complex(re, im);
        }

    }

    void getRadius(){
        radius = inputR->text().toDouble();
    }

};