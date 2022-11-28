#ifndef FRACTAL_H
#define FRACTAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class fractal; }
QT_END_NAMESPACE

class fractal : public QMainWindow
{
    Q_OBJECT

public:
    fractal(QWidget *parent = nullptr);
    ~fractal();

protected:
    void paintEvent(QPaintEvent *event);
    void gencurve(QPainter *qp);
    void koch(QPainter *qp , int x1,int y1 , int x2, int y2 , int d);
    //d = will contain how many times curve is going to repeat
private:
    Ui::fractal *ui;
};
#endif // FRACTAL_H
