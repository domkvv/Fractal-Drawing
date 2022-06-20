#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow{
public:
    QWidget *centralwidget;
    QRadioButton *JuliaButton;
    QRadioButton *JuliaAnimButton;
    QRadioButton *MandelbrotButton;
    QRadioButton *NewtonButton;
    QLineEdit *JuliaRadius;
    QLineEdit *JuliaC;
    QPushButton *pushButton;
    QLabel *label;
    glWidget *openGLWidget;

    void setupUi(QMainWindow *MainWindow){
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("Menu"));

        MainWindow->resize(308, 384);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        JuliaButton = new QRadioButton(centralwidget);
        JuliaButton->setObjectName(QString::fromUtf8("JuliaButton"));
        JuliaButton->setGeometry(QRect(60, 70, 161, 21));
        JuliaAnimButton = new QRadioButton(centralwidget);
        JuliaAnimButton->setObjectName(QString::fromUtf8("JuliaAnimButton"));
        JuliaAnimButton->setGeometry(QRect(60, 130, 271, 17));
        MandelbrotButton = new QRadioButton(centralwidget);
        MandelbrotButton->setObjectName(QString::fromUtf8("MandelbrotButton"));
        MandelbrotButton->setGeometry(QRect(60, 250, 121, 17));
        NewtonButton = new QRadioButton(centralwidget);
        NewtonButton->setObjectName(QString::fromUtf8("NewtonButton"));
        NewtonButton->setGeometry(QRect(60, 190, 211, 21));
        JuliaRadius = new QLineEdit(centralwidget);
        JuliaRadius->setObjectName(QString::fromUtf8("JuliaRadius"));
        JuliaRadius->setGeometry(QRect(80, 150, 113, 20));
        JuliaC = new QLineEdit(centralwidget);
        JuliaC->setObjectName(QString::fromUtf8("JuliaC"));
        JuliaC->setGeometry(QRect(80, 90, 113, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 290, 80, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 211, 41));
        openGLWidget = new glWidget;
        openGLWidget->inputC = JuliaC;
        openGLWidget->inputR = JuliaRadius;

        MainWindow->setCentralWidget(centralwidget);
        JuliaRadius->setVisible(false);
        JuliaC->setVisible(false);
        JuliaC->setPlaceholderText("re im");
        JuliaRadius->setPlaceholderText("radius");

        retranslateUi(MainWindow);

        QObject::connect(JuliaButton, &QRadioButton::released, JuliaC, qOverload<>(&QLineEdit::show));
        QObject::connect(JuliaButton, &QRadioButton::toggled, JuliaC, qOverload<>(&QLineEdit::hide));

        QObject::connect(JuliaAnimButton, &QRadioButton::released, JuliaRadius, qOverload<>(&QLineEdit::show));
        QObject::connect(JuliaAnimButton, &QRadioButton::toggled, JuliaRadius, qOverload<>(&QLineEdit::hide));

        QObject::connect(NewtonButton, &QRadioButton::toggled, openGLWidget, qOverload<>(&glWidget::isNewton));
        QObject::connect(JuliaButton, &QRadioButton::toggled, openGLWidget, qOverload<>(&glWidget::isJulia));
        QObject::connect(JuliaAnimButton, &QRadioButton::toggled, openGLWidget, qOverload<>(&glWidget::isJuliaAnim));
        QObject::connect(MandelbrotButton, &QRadioButton::toggled, openGLWidget, qOverload<>(&glWidget::isMandelbrot));

        QObject::connect(JuliaAnimButton, &QRadioButton::toggled, JuliaRadius, qOverload<>(&QLineEdit::clear));
        QObject::connect(JuliaButton, &QRadioButton::toggled, JuliaC, qOverload<>(&QLineEdit::clear));

        QObject::connect(JuliaC, &QLineEdit::editingFinished, openGLWidget, qOverload<>(&glWidget::getC));
        QObject::connect(JuliaRadius, &QLineEdit::editingFinished, openGLWidget, qOverload<>(&glWidget::getRadius));

        QObject::connect(pushButton, &QPushButton::clicked, openGLWidget, qOverload<>(&QOpenGLWidget::show));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("Menu", "Menu", nullptr));
        JuliaButton->setText(QCoreApplication::translate("MainWindow", "Julia set (z^2 + c)", nullptr));
        JuliaAnimButton->setText(QCoreApplication::translate("MainWindow", "Julia set (animated) (z^2 + r*e^{ai})", nullptr));
        MandelbrotButton->setText(QCoreApplication::translate("MainWindow", "Mandelbrot set", nullptr));
        NewtonButton->setText(QCoreApplication::translate("MainWindow", "Newton's Fractal (z^3 - 1)", nullptr));
        JuliaRadius->setText(QCoreApplication::translate("MainWindow", "radius", nullptr));
        JuliaC->setText(QCoreApplication::translate("MainWindow", "Re Im", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "draw", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select fractal you want to draw", nullptr));
    } // retranslateUi


};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

