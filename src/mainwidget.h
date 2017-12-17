#ifndef _MAINWIDGET_
#define _MAINWIDGET_
#include "buttonwidget.h"
#include <QWidget>
#include <QRadioButton>

struct Button_Info
{
  QStringList button_icon_string_list_;
  QStringList soft_exe_file_path_list_;
};


class MainWidget:public QWidget
{
  Q_OBJECT
public:
  MainWidget();
  ~MainWidget();
public slots:
//  QStringList SetIconAndExeFilePath();
private:
  void SetUi();
  void SetConnect();
  void ExcuteSoft(QString n);
  void AddIconFilePathText(QString icon);
  void AddExeFilePathText(QString exe);
  ButtonWidget *button_widget_;
  QPushButton *add_new_one_button_;
  QPushButton *delete_one_button_;
  QRadioButton *config_radio_button_;
  QRadioButton *use_radio_button_;
  bool check_config_or_use_;
  Button_Info button_info_struct_;


};



#endif   //_MAINWIDGET_