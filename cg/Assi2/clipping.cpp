#include "clipping.h"
#include "ui_clipping.h"
#include<QLabel>
#include<iostream>
using namespace std;
QImage img(600,600,QImage::Format_RGB888);
clipping::clipping(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::clipping)
{
    ui->setupUi(this);
}

clipping::~clipping()
{
    delete ui;
}
int Sign(float a)
{
    if(a>0)
        return 1;
    else if(a<0)
        return -1;
    else
        return 0;
}
void dda(int x1,int y1,int x2,int y2)
{
    int len;
    if(abs(x1-x2)>=abs(y1-y2))
        len=abs(x1-x2);
    else
        len=abs(y1-y2);
    float dx,dy;
    dx=(x2-x1)/(float)len;
    dy=(y2-y1)/(float)len;
    float x,y;
    x=x1+0.5*Sign(dx);
    y=y1+0.5*Sign(dy);
    int i=0;
    while(i<=len)
    {
        img.setPixel((int)x,(int)y,qRgb(255,0,255));
        x+=dx;
        y+=dy;
        i++;
    }
}
void clipping::Rect()
{
   dda(xl,yl,xh,xl);
   dda(xl,yl,xl,xh);
   dda(xh,yh,xl,yh);
   dda(xh,yh,xh,yl);
}
void clipping :: clipLine()
{
    int line_1,line_2,line_n;
    int accept=0;
    int done=0;
    line_1 = outcode(x1,y1);
    line_2 = outcode(x2,y2);
    do{
        if(!(line_1 | line_2))
        {
            accept=1;
            done=1;
        }
        else{
            if(line_1 & line_2){
                cout<<"The line is completely visible";
                done = 1;
            }
            else{
                double x,y;
                if(line_1){
                    line_n = line_1;
                }
                else{
                    line_n = line_2;
                }
                if(line_n & top){
                    y=yh;
                    x=x1+((x2-x1)*(yh-y1))/(y2-y1);
                }
                else if(line_n & bottom)
                {
                    y=yl;
                    y=y1+((x2-x1)*(yl-y1))/(y2-y1);
                }
                else if(line_n & right){
                    x=xh;
                    y=y1+((xh-x1)*(y2-y1))/(x2-x1);
                }
                else if(line_n & left){
                    x=xl;
                    y=y1+((xl-x1)*(y2-y1))/(x2-x1);
                }
                if(line_n==line_1)
                {
                    x1=x;
                    y1=y;
                    line_1 = outcode(x1,y1);
                }
                else{
                    x2=x;
                    y2=y;
                    line_2 = outcode(x2,y2);
                }
            }
        }
    }while(done==0);
    if(accept==1)
    {
      dda(x1,y1,x2,y2);
     }
}
int clipping::outcode(int x,int y)
{
    unsigned int code = 0;
    if(y>yh)
        code=code|top;
    else if(y<yl)
            code=code|bottom;
    else if(x>xh)
        code=code|right;
    else if(x<xl)
        code=code|left;
  return code;
}



void clipping::on_pushButton_clicked()
{
    xh = ui->textEdit->toPlainText().toInt();
    yh = ui->textEdit_2->toPlainText().toInt();
    xl = ui->textEdit_3->toPlainText().toInt();
    yl = ui->textEdit_4->toPlainText().toInt();
    Rect();
    ui->label_9->setPixmap(QPixmap::fromImage(img));
}


void clipping::on_pushButton_2_clicked()
{
    x1 = ui->textEdit_5->toPlainText().toInt();
    y1 = ui->textEdit_6->toPlainText().toInt();
    x2 = ui->textEdit_7->toPlainText().toInt();
    y2 = ui->textEdit_8->toPlainText().toInt();
    clipLine();
    ui->label_9->setPixmap(QPixmap::fromImage(img));
}
