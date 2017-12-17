#include "buttonwidget.h"
#include <QPainter>

ButtonWidget::ButtonWidget()
           :exe_file_path_(" ")
{

}

ButtonWidget::~ButtonWidget()
{

}

void ButtonWidget::paintEvent(QPaintEvent* event)
{
  QPainter painter(this); 
  QPixmap pix;
  if(exe_file_path_ != " " && !exe_file_path_.isEmpty())
  {
    bool a = exe_file_path_.isEmpty();
    pix.load(exe_file_path_);
  }
  else
  {
    pix.load("C:/Users/Nikola/Desktop/1.png"); 
  }
    painter.drawPixmap(rect(), pix);

}

void ButtonWidget::GetIconFilePath(QString n)
{
   exe_file_path_ = n;
   update();
}
