#ifndef CLIPPING_H
#define CLIPPING_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class clipping; }
QT_END_NAMESPACE

class clipping : public QMainWindow
{
    Q_OBJECT

public:
    clipping(QWidget *parent = nullptr);
    ~clipping();
    enum
    {
       top = 8,bottom = 4,right = 2,left = 1
    };
    int xl,yl,xh,yh,x1,y1,x2,y2;
    void Rect();
    void clipLine();
    int outcode(int,int);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::clipping *ui;
};
#endif // CLIPPING_H


