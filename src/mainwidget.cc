#include "mainwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <fstream>
#include <iostream>
#include <QStringList>
#include <QProcess>
#include <QFileDialog>
#include <QDir>

using namespace std;

MainWidget::MainWidget()
           : check_config_or_use_(false)
{
  SetUi();
  SetConnect();
}

MainWidget::~MainWidget()
{
  button_info_struct_.button_icon_string_list_.clear();
  button_info_struct_.soft_exe_file_path_list_.clear();
}

//QStringList MainWidget::SetIconAndExeFilePath()
//{
// 
//  QString icon_file_path;
//  icon_file_path = QFileDialog::getOpenFileName(this, tr("get icon file path"),".",tr("Images (*.png *.jpg *.bmp)"));
//  icon_file_path = QDir::fromNativeSeparators(icon_file_path);
//
//  QString exe_file_path;
//  exe_file_path =   QFileDialog::getOpenFileName(this,tr("get exe file path"),tr(".exe"));
//
//  QStringList icon_and_exe_file_path;
//  icon_and_exe_file_path.push_back(icon_file_path);
//  icon_and_exe_file_path.push_back(exe_file_path);
//}



void MainWidget::SetUi()
{
  QHBoxLayout *main_layout = new QHBoxLayout(this);
  QVBoxLayout *right_radio_button_layout = new QVBoxLayout;
  QVBoxLayout *left_push_button_layout = new QVBoxLayout;

  button_widget_ = new ButtonWidget;
  button_widget_->setFixedSize(100,100);
  left_push_button_layout->addWidget(button_widget_);
  left_push_button_layout->addStretch(1);
  config_radio_button_ = new QRadioButton;
  config_radio_button_->setText(tr("Configure"));
  use_radio_button_ = new QRadioButton;
  use_radio_button_->setText(tr("Use"));


  right_radio_button_layout->addWidget(config_radio_button_);
  right_radio_button_layout->addWidget(use_radio_button_);
  right_radio_button_layout->addStretch(1); 
  main_layout->addLayout(left_push_button_layout);
  main_layout->addStretch(1);
  main_layout->addLayout(right_radio_button_layout);

  this->setLayout(main_layout);
  this->setMinimumSize(600,800);

}

void MainWidget::SetConnect()
{
  connect(config_radio_button_, &QRadioButton::toggled, [=]()
  {
  if(config_radio_button_->isChecked())
  {

    use_radio_button_->setChecked(false);
    disconnect(button_widget_,SIGNAL(clicked()),0,0);
    connect(button_widget_,&ButtonWidget::clicked,[=]()
    {
      //get icon file
      QString temp_icon_file_path;
      temp_icon_file_path = QFileDialog::getOpenFileName(this,tr("get icon file path"),".",
        tr("Images (*.png *.jpg *.bmp)"));
     temp_icon_file_path = QDir::fromNativeSeparators(temp_icon_file_path);
     button_info_struct_.button_icon_string_list_.push_back(temp_icon_file_path);
     button_widget_->GetIconFilePath(temp_icon_file_path);
     AddIconFilePathText(temp_icon_file_path);
     //get exe file
     QString temp_soft_exe_file_path;
     temp_soft_exe_file_path = QFileDialog::getOpenFileName(this,"tr(get exe file path)",tr("*.exe"));
     temp_soft_exe_file_path = QDir::fromNativeSeparators(temp_soft_exe_file_path);
     button_info_struct_.soft_exe_file_path_list_.push_back(temp_soft_exe_file_path);
     AddExeFilePathText(temp_soft_exe_file_path);
    });
  }
});

connect(use_radio_button_,&QRadioButton::toggled,[=]()
{
  if (use_radio_button_->isChecked())
  {
    disconnect(button_widget_, SIGNAL(clicked()), 0, 0);
    config_radio_button_->setChecked(false);
    connect(button_widget_, &ButtonWidget::clicked, [=]()
    {

      ifstream in("excute_path.txt");
      string temp_exe_path;
      while(getline(in,temp_exe_path))
      {
        
      }
      QString temp_excute_exe_file_path;
      temp_excute_exe_file_path = button_info_struct_.soft_exe_file_path_list_[0];
      bool a = QProcess::startDetached(temp_excute_exe_file_path);

    });
  }
});
}

void MainWidget::ExcuteSoft(QString n)
{
  n = QDir::fromNativeSeparators(n);
  QProcess::startDetached(n);
}

void MainWidget::AddIconFilePathText(QString icon)
{
  ofstream out("icon_path.txt");
  string temp_icon_string = icon.toStdString(); 
  out<<temp_icon_string;
}

void MainWidget::AddExeFilePathText(QString exe)
{
  ofstream out("exe_path.txt");
  string temp_exe_string = exe.toStdString();
  out<<temp_exe_string;
}
