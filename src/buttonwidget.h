#ifndef BUTTONWIDGET_
#define BUTTONWIDGET_
#include <QPushButton>
#include <QWidget>

class ButtonWidget:public QPushButton
{
public:
  ButtonWidget();
  ~ButtonWidget();
  void GetIconFilePath(QString n);
private:
  void paintEvent(QPaintEvent *event);
  QString exe_file_path_;

};




#endif    //BUTTONWIDGET_
