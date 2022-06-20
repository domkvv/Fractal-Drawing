#include <gl/glut.h>
#include <iostream>
#include <complex>
#include <string>
#include <cmath>
#define JULIA 0
#define JULIA_A 1
#define MANDELBROT 2
#define NEWTON 3

using namespace std;
typedef std::complex<double> Complex;

double xmin = -2, xmax = 2, ymin = -1.5, ymax = 1.5;
int maxIterations;
Complex c;
double a = 0.0, radius;
int ftype = -1;

Complex scaleToComplex(int x, int y, int imageWidth, int imageHeight){
    return Complex(xmin + (double)x / imageWidth * (xmax - xmin), ymin + (double)y / imageHeight * (ymax - ymin)); }

int Mandelbrot(Complex c){
    Complex z = 0;
    for (int i = 1; i <= maxIterations; i++){
        z = z*z + c;
        if(norm(z) >= 2) return i;
    }
    return -1;
}

int Julia(Complex z, Complex c){
    for (int i = 1; i <= maxIterations; i++){
        z = z*z + c;
        if(norm(z) >= 2) return i;
    }
    return -1;
}

int Newton(Complex z){
    double tolerance = 1e-5;
    Complex roots[3] = {Complex(1, 0), Complex(-0.5, -sqrt(3)/2), Complex(-0.5, sqrt(3)/2)};

    for (int i = 1; i <= maxIterations; i++){
        z = z - ((z*z*z-Complex(1, 0))/(Complex(3, 0)*z*z));
        for(int j = 0; j < 3; j++){
            Complex diff = z - roots[j];
            if (abs(real(diff)) < tolerance && abs(imag(diff)) < tolerance){
                return j;
            }
        }
    }
    return -1;
}

