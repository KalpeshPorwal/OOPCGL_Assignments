#include "fractal.h"
#include<QPainter>
#include<math.h>
#include "ui_fractal.h"

fractal::fractal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fractal)
{
    ui->setupUi(this);
}

fractal::~fractal()
{
    delete ui;
}

void fractal:: paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter qp(this);
    gencurve(&qp);
}

void fractal::koch(QPainter *qp , int x1 , int y1, int x2 , int y2 , int d)
{
    double angle = 60*3.14/180;
    double x3 , y3 , x4, y4, x, y;
    x3 = (2*x1+x2)/3;
    y3 = (2*y1+y2)/3;

    x4 = (x1+2*x2)/3;
    y4 = (y1+2*y2)/3;

    x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);
    y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);

    if(d>0)
    {
        koch(qp,x1,y1,x3,y3,d-1);
        koch(qp,x3,y3,x,y,d-1);
        koch(qp,x,y,x4,y4,d-1);
        koch(qp,x4,y4,x2,y2,d-1);
    }
    else
    {
        qp->drawLine(x1,y1,x3,y3);
        qp->drawLine(x3,y3,x,y);
        qp->drawLine(x,y,x4,y4);
        qp->drawLine(x4,y4,x2,y2);
    }
}

void fractal:: gencurve(QPainter *qp)
{
    QPen pen(Qt::blue , 2 ,Qt::SolidLine);
    qp->setPen(pen);
    koch(qp,50,300,600,300,2);
}

