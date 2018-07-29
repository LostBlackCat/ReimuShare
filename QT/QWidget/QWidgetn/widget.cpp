#include "widget.h"
#include<qapplication.h>
#include<qpushbutton.h>
#include<qfont.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<windows.h>
Widget::Widget(QWidget *parent)
  : QWidget(parent)
{
  setMinimumSize(200,120);
  setMaximumSize(200,120);

  srand(time(0));
  QPushButton *button=new QPushButton("",this);
      button->setGeometry(rand()%100,rand()%100,rand()%100,rand()%100);
  QPushButton *quit =new QPushButton("Quit",this);
  quit->setGeometry(62,40,75,30);
  quit->setFont(QFont("Times",18,QFont::Bold));
  connect(quit,SIGNAL(clicked(bool)),qApp,SLOT(quit()));
}

Widget::~Widget()
{

}
